#include <stdint.h>
#include <ap_int.h>

#define MAX_TRANSFER_SIZE  256
const int max_depth = MAX_TRANSFER_SIZE;

int setMem_rmt(float value_to_add,
			   volatile float *addrMasterReadFrom,
			   volatile float *addrMasterWriteTo,
			   uint16_t size,
			   volatile ap_uint<1> *output_debug)
{
#pragma HLS INTERFACE 	m_axi     depth=max_depth  port=addrMasterReadFrom  offset=slave bundle=MASTER_CNTRL
#pragma HLS INTERFACE 	m_axi     depth=max_depth  port=addrMasterWriteTo   offset=slave bundle=MASTER_CNTRL
#pragma HLS INTERFACE 	s_axilite port=size  		bundle=CRTL_BUS
#pragma HLS INTERFACE 	s_axilite port=value_to_add bundle=CRTL_BUS
#pragma HLS INTERFACE 	s_axilite port=return 		bundle=CRTL_BUS
#pragma HLS INTERFACE   ap_none   port=output_debug

static ap_uint<1> output_flag = 0;

	if (size <= MAX_TRANSFER_SIZE)
	{
		for (unsigned int idxMemAddr = 0; idxMemAddr < size; idxMemAddr++)
		{
			addrMasterWriteTo[idxMemAddr] = addrMasterReadFrom[idxMemAddr] + value_to_add;
		}
		output_flag = output_flag + 1; //toggle flag
		*output_debug = output_flag;
		return 0;
	}
	else
	{
		return -1;
	}

}
