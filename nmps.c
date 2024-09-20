#include <cuda.h>

#include <assert.h>
#include <stdio.h>

int main(void) {
	CUresult result;
	CUdevice device;
	int nmps;

	result = cuInit(0);
	assert(result == CUDA_SUCCESS);
	result = cuDeviceGet(&device, 0);
	assert(result == CUDA_SUCCESS);
	result = cuDeviceGetAttribute(
	    &nmps, CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT, device);
	assert(result == CUDA_SUCCESS);
	printf("%d\n", nmps);
	return 0;
}
