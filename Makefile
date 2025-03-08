# Compiler settings
CC      = clang
CFLAGS  = -ansi -pedantic
WARNS   = -Weverything -Wno-poison-system-directories
INCLUDE = -I$(LIB_DIR)
AR      = ar
ARFLAGS = rcs

# Directories
BIN_DIR = bin
LIB_DIR = lib
OBJ_DIR = $(BIN_DIR)/obj/lib
TEST_DIR = tests
TEST_BIN_DIR = $(BIN_DIR)/tests

# Library name
LIB     = $(BIN_DIR)/libhue.a

# Source files
LIB_SRC = $(wildcard $(LIB_DIR)/*.c)
LIB_OBJ = $(LIB_SRC:$(LIB_DIR)/%.c=$(OBJ_DIR)/%.o)

# Test files
TEST_SRC = $(wildcard $(TEST_DIR)/experiment-*.c)
TEST_BIN = $(TEST_SRC:$(TEST_DIR)/%.c=$(TEST_BIN_DIR)/%)

# All C source and header files
C_FILES = $(shell find $(LIB_DIR) $(TEST_DIR) -name "*.c" -o -name "*.h")

# Default target
all: lib test

# Create necessary directories
$(OBJ_DIR) $(BIN_DIR) $(TEST_BIN_DIR):
	mkdir -p $@

# Compile library source files
$(OBJ_DIR)/%.o: $(LIB_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(WARNS) $(INCLUDE) -c $< -o $@

# Build static library - only rebuild if object files are newer
$(LIB): $(LIB_OBJ) | $(BIN_DIR)
	$(AR) $(ARFLAGS) $@ $^

# Library target alias
lib: $(LIB)

# Build test binaries
$(TEST_BIN_DIR)/%: $(TEST_DIR)/%.c $(LIB) | $(TEST_BIN_DIR)
	$(CC) $(CFLAGS) $(WARNS) $(INCLUDE) $< $(LIB) -o $@

# Build and run all tests
test: $(TEST_BIN)
	@for test in $(TEST_BIN); do \
		printf "\nRunning $$test:\n"; \
		$$test; \
	done

# Format source files using BSD style
fmt:
	@for file in $(C_FILES); do \
		echo "Formatting $$file"; \
		indent "$$file"; \
	done
	@find . -iname "*.BAK" -delete

# Clean build artifacts
clean:
	rm -rf $(BIN_DIR)
	find . -iname "*.BAK" -delete

.PHONY: all lib test fmt clean 
