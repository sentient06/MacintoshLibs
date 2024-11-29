# Path to RETRO68
RETRO68 := ../../Retro68-build/toolchain

# Tools
# CXX     := $(RETRO68)/bin/powerpc-apple-macos-g++
CXX     := $(RETRO68)/bin/m68k-apple-macos-g++
# CXXFLAGS = -Wall -Wextra -std=c++98 -I./include
CXXFLAGS = -I./include
# AR       = $(RETRO68)/bin/powerpc-apple-macos-gcc-ar
AR       = $(RETRO68)/bin/m68k-apple-macos-gcc-ar
SRCDIR   = src
BUILDDIR = build
SOURCES  = $(SRCDIR)/LFiles.cpp
OBJECTS  = $(SOURCES:.cpp=.o)
LIBRARY  = $(BUILDDIR)/libLFiles.a

all: $(LIBRARY)

$(BUILDDIR)/%.a: $(OBJECTS)
	@mkdir -p $(BUILDDIR)
	$(AR) rcs $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILDDIR)/*.a $(SRCDIR)/*.o

install:
	mkdir -p ../../Pinakes/libs/LFiles/lib/
	mkdir -p ../../Pinakes/libs/LFiles/include/
	cp $(LIBRARY) ../../Pinakes/libs/LFiles/lib/
	cp include/LFiles.h ../../Pinakes/libs/LFiles/include/

.PHONY: all clean install
