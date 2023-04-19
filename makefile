#	libnekoxx
#	Makefile for libnekoxx
#	By MIT License.
#	Copyright (c) 2023 Ziyao and AlanCui4080.

export CXX		= gcc -xc++
export LD		= ld
export AR		= ar
export RANLIB		= ranlib
export RM		= rm
export CLANG_FORMAT	= clang-format
export FIND		= find
export XARGS		= xargs

export OBJS		:= nekoexception.o libnekoxx.o new.o abi.o exception.o

export LIBS		:= libnekoxx.so libnekoxx.a

export CXXFLAGS	+= -fno-exceptions -fno-rtti -fPIC -nostdinc++ -I../include \
		  -std=c++17 -g -O0
export LDFLAGS		=
all : 
	$(MAKE) -C src
	cd tests && ./run.sh
clean : 
	$(MAKE) -C src clean
