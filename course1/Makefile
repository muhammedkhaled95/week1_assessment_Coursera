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
# This Makefile is used to make a build automation system for 2 different target using the compile time switch concept
# these 2 targets are:
# * Native target which is the host machine using the gcc compiler toolchain
# * Cross target which is the MSP432P401r ARM based microcontroller using the arm-none-eabi-gcc compiler toolchain
#
#How to Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#     <FILE>.o : generates <FILE>.o object file for specific source file
#     <FILE>.i : generates <FILE>.i preprocessed file for specific source file
#     <FILE>.asm : generates the assembly file for a specific source file and
#     the assembly code for the final executable file using the objdump utility
#     <FILE>.dep : generates the dependency file for each source file.
#     compile-all : compile all object files but don't link
#     build: builds and links all the source files and output an executable file
#     and a map file.
#     clean: clean all the generated files
#
# Platform Overrides:
#      PLATFROM = HOST OR MSP432
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST
#general flags for both platforms
GENERALFLAGS = -Wall -Werror -g -O0 -std=c99
TARGET = c1m2

ifeq ($(PLATFORM),HOST)
   CC = gcc
   LD = ld
# compiler, linker, preprocessor flags
   CFLAGS = $(GENERALFLAGS)
   LDFLAGS = -Wl,-Map=$(TARGET).map 
endif

ifeq ($(PLATFORM),MSP432)
   CC = arm-none-eabi-gcc
   LD = arm-none-eabi-ld
# Architectures Specific Flags
   LINKER_FILE = msp432p401r.lds 
   CPU = cortex-m4 
   ARCH = thumb
   ARM = armv7e-m
   SPECS = nosys.specs
   FLOAT = hard
   FPU = fpv4-sp-d16
# compiler, linker, and preprocessor flags
   CFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -march=$(ARM) -mfloat-abi=$(FLOAT) -mfpu=$(FPU) $(GENERALFLAGS)
   LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)  
endif


OBJECTS := $(SOURCES:.c=.o)
DEPENDENCIES := $(SOURCES:.c=.dep)

#RULES for build targets

%.i : %.c 
	$(CC) -D$(PLATFORM) -E $^ -o $@ 

%.o : %.c
	$(CC) $(CFLAGS) -D$(PLATFORM) -O $@ -c $^

%.asm : %.c
	$(CC) $(CFLAGS) -D$(PLATFORM) -S $^ -o $@

%.dep : %.c
	$(CC) $(CFLAGS) -D$(PLATFORM) -MM $^ -o $@

.PHONY:  compile-all
compile-all: $(OBJECTS)
$(OBJECTS): $(SOURCES)
	$(CC) -D$(PLATFORM) $(CFLAGS) -c $^ 

.PHONY: build
build: $(TARGET).out
$(TARGET).out: $(OBJECTS)
	$(CC) -D$(PLATFORM) $(CFLAGS) $(LDFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm *.o $(TARGET).map *.dep *.i *.s $(TARGET).out

