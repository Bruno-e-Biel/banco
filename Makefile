CXX = gcc

ifeq ($(MODE), debug)
	CXXFLAGS = -I./include -Wall -v -g
else
	CXXFLAGS = -I./include/ -Wall
endif

LIBSOURCES ?= ./include/utils.c

SRC ?= ./src/main.c

BUILD_DIR = ./build

TARGET ?= app

all:
	$(CXX) $(SRC) $(LIBSOURCES) $(CXXFLAGS) -o $(BUILD_DIR)/$(TARGET)

clean:
	rm -f build/*


