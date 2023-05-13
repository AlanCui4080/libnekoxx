#	libnekoxx
#	Makefile for libnekoxx
#	By MIT License.
#	Copyright (c) 2023 Ziyao and AlanCui4080.

export CXX		= gcc -xc++ 
export CXXDEP		= gcc -xc++ -MM *.cpp
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
		  -std=c++17 -g -O0 -fsanitize=undefined -fsanitize=address -fsanitize=thread
export LDFLAGS		=
all : 
	@$(MAKE) -C src
	@cd tests && ./run.sh
clean : 
	@$(MAKE) -C src clean
format:
	@echo Formatting CXX Codes...
	@$(FIND) src -name "*.cpp" -type f | $(XARGS) $(CLANG_FORMAT) -style=file --verbose -i
	@echo Formatting Headers...
	@$(FIND) include -name "*" -type f | $(XARGS) $(CLANG_FORMAT) -style=file --verbose -i
dist: format clean all
	@echo "\033[32m"
	@echo Codebase is ready to release.
	@echo "\033[39m"

