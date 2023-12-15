# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -g
DYLIB_FLAGS = -shared -fPIC

# Source files
SRC = user_auth.c
TEST_SRC = test_user_auth.c

# Output files
LIB_OUTPUT = libuserauth.dylib
LIB_OUTPUT_SO = libuserauth.so
TEST_OUTPUT = test_user_auth

# dSYM files
DSYM_OUTPUT = $(LIB_OUTPUT).dSYM $(LIB_OUTPUT_SO).dSYM $(TEST_OUTPUT).dSYM

# Default target
all: dylib so test

# Target for building the dynamic library
dylib: $(SRC)
	$(CC) $(CFLAGS) $(DYLIB_FLAGS) -o $(LIB_OUTPUT) $(SRC)

# Target for building the Linux shared library
so: $(SRC)
	$(CC) $(CFLAGS) $(DYLIB_FLAGS) -o $(LIB_OUTPUT_SO) $(SRC)

# Target for compiling the test program
test: $(SRC) $(TEST_SRC)
	$(CC) $(CFLAGS) -o $(TEST_OUTPUT) $(SRC) $(TEST_SRC)

# Target for cleaning up
clean:
	rm -f $(LIB_OUTPUT) $(LIB_OUTPUT_SO) $(TEST_OUTPUT)
	rm -rf $(DSYM_OUTPUT)

# Phony targets
.PHONY: all dylib test clean
