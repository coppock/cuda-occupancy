CUDA = /usr/local/cuda

CFLAGS = -I$(CUDA)/include
CXXFLAGS = $(CFLAGS)
LDFLAGS = -L$(CUDA)/lib64
LDLIBS = -lcuda -lcudart
