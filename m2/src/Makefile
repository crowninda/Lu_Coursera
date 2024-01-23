#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
# It's a simple cross-compile system, target platform are HOST and MSP432.
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#      <FILE>.i - Generate the preprocesses output of all c-program 
#      		  implementation file
#      <FILE>.asm - Generate assembly output of c-program implementation files 
#                   and the final output executable 
#      <FILE>.o - Generate the object file for all c-source files (but do not
#                  link) by specifying the object file that want to compile
#      compile-all - Compile all object files, but DO NOT link, needs to have 
#                    .PHONY protection.
#      build - Compile all object files and link into a final executable, needs
#              to have .PHONY protection
#      clean - removes all generated files, needs to have .PHONY protection
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#      PLATFORM - Target platform (HOST, MSP432)
#
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM ?= HOST

# Architectures Specific Flags, compiler Flags and Defines
ifeq ($(PLATFORM), HOST)
CC = gcc
CFLAGS = -Wall -g -O0
LDFLAGS = 
CPPFLAGS = -D$(PLATFORM) -MMD -MP

else ifeq ($(PLATFORM), MSP432)
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
LDFLAGS = -Wl,-Map=output.map -T ../msp432p401r.lds
CFLAGS = -mcpu=cortex-m4 -mthumb -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nosys.specs -Wall
CPPFLAGS = -D$(PLATFORM) -MMD -MP 

endif
 
# Platform-specific source files
ifeq ($(PLATFORM), HOST)
SRCS = $(SOURCES)
INCS = $(INCLUDES)

else ifeq ($(PLATFORM), MSP432)
SRCS = $(SOURCES) interrupts_msp432p401r_gcc.c startup_msp432p401r_gcc.c system_msp432p401r.c
INCS = $(INCLUDES) -I../include/msp432 -I../include/CMSIS

endif

# Object file list
OBJS = $(SRCS:.c=.o)

# Target executable file
TARGET = c1m2.out

# Link and generate the executable
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(CFLAGS) $(OBJS) -o $@

# Parttern rule: generate .i from .c/.h  --> Preprocessor
%.i : %.c
	$(CC) -E $< $(CFLAGS) $(INCS) $(CPPFLAGS) -o $@

# Pattern rule: generate .s/.asm from .c --> compiler proper
%.asm : %.c
	$(CC) $(CFLAGS) $(INCS) $(CPPFLAGS) -S $< -o $@ 

# Pattern rules: generate .o from .c --> preprocessing + compilation + Assembly
%.o : %.c
	$(CC) -c $< $(CFLAGS) $(INCS) $(CPPFLAGS) -o $@ 


# .PHONY
# compile-all
.PHONY: compile-all
compile-all: $(OBJS)

# Build
.PHONY: build
build: $(TARGET)

# Clean
.PHONY: clean
clean:
	rm -f *.o *.d *.out *.map $(SRCS:.c=.i) $(SRCS:.c=.asm)
 
.PHONY: print-vars
print-vars:
	@echo "INCS: $(INCS)"
	@echo "SRCS: $(SRCS)"
