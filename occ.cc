#include <cuda_occupancy.h>
#include <cuda_runtime.h>

#include <cassert>
#include <iostream>
#include <limits>
#include <sstream>

int main(void) {
	cudaDeviceProp prop;
	cudaError_t error = cudaGetDeviceProperties(&prop, 0);
	assert(error == cudaSuccess);

	for (std::string line; std::getline(std::cin, line);) {
		std::istringstream stream(line);
		int blkX, blkY, blkZ;
		cudaFuncAttributes attr;
		size_t dynamicSmemSize;
		stream >> blkX >> blkY >> blkZ >> attr.numRegs >>
		    attr.sharedSizeBytes >> dynamicSmemSize;
		attr.maxThreadsPerBlock = std::numeric_limits<int>::max();

		cudaOccResult result;
		cudaOccDeviceProp occProp = prop;
		cudaOccFuncAttributes occAttr = attr;
		cudaOccDeviceState state;
		cudaOccError occError =
		    cudaOccMaxActiveBlocksPerMultiprocessor(
			&result, &occProp, &occAttr, &state,
			blkX * blkY * blkZ, dynamicSmemSize);
		assert(occError == CUDA_OCC_SUCCESS);
		std::cout << result.activeBlocksPerMultiprocessor << std::endl;
	}
	return 0;
}
