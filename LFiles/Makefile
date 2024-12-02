# Path to RETRO68
RETRO68 := ../../Retro68-build/toolchain

# Tools
CC      := $(RETRO68)/bin/m68k-apple-macos-gcc
# CXX     := $(RETRO68)/bin/m68k-apple-macos-g++
# CXXFLAGS = -Wall -Wextra -std=c++98 -I./include
CFLAGS   = -I./include
# CXXFLAGS = -I./include
# AR       = $(RETRO68)/bin/powerpc-apple-macos-gcc-ar
AR       = $(RETRO68)/bin/m68k-apple-macos-gcc-ar
SRCDIR   = src
BUILDDIR = build

# Source files
C_SRCS   = $(SRCDIR)/LFiles.c
# CXX_SRCS = $(SRCDIR)/LFiles.cpp

# Object files
C_OBJS   = $(C_SRCS:.c=.o)
# CXX_OBJS = $(CXX_SRCS:.cpp=.o)
OBJECTS  = $(C_OBJS)
# $(CXX_OBJS)

LIBRARY  = $(BUILDDIR)/libLFiles.a

all: $(LIBRARY)

$(BUILDDIR)/%.a: $(OBJECTS)
	@mkdir -p $(BUILDDIR)
	$(AR) rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# %.o: %.cpp
#	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILDDIR)/*.a $(SRCDIR)/*.o

install:
	mkdir -p ../../Pinakes/libs/LFiles/lib/
	mkdir -p ../../Pinakes/libs/LFiles/include/
	cp $(LIBRARY) ../../Pinakes/libs/LFiles/lib/
	cp include/LFiles.h ../../Pinakes/libs/LFiles/include/
	cp include/LFiles.r ../../Pinakes/libs/LFiles/include/

.PHONY: all clean install
