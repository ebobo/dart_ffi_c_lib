# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -g
DYLIB_FLAGS = -shared -fPIC

# Source files
SRC = user_auth.c
TEST_SRC = test_user_auth.c

# Output files
LIB_OUTPUT = libuserauth.dylib
TEST_OUTPUT = test_user_auth

# Default target
all: dylib test

# Target for building the dynamic library
dylib: $(SRC)
	$(CC) $(CFLAGS) $(DYLIB_FLAGS) -o $(LIB_OUTPUT) $(SRC)

# Target for compiling the test program
test: $(SRC) $(TEST_SRC)
	$(CC) $(CFLAGS) -o $(TEST_OUTPUT) $(SRC) $(TEST_SRC)

# Target for cleaning up
clean:
	rm -f $(LIB_OUTPUT) $(TEST_OUTPUT)

# Phony targets
.PHONY: all dylib test clean
