#	libnekoxx
#	Makefile for libnekoxx
#	By MIT License.
#	Copyright (c) 2023 Ziyao.

CXX		= gcc -xc++
LD		= ld
AR		= ar
RANLIB		= ranlib
RM		= rm

OBJS		:= nekoexception.o libnekoxx.o new.o abi.o

LIBS		:= libnekoxx.so libnekoxx.a

CXXFLAGS	= -fno-exceptions -fno-rtti -fPIC -nostdinc++ -I../include
LDFLAGS		=

all: dep.mk $(LIBS)

dep dep.mk: $(shell ls *.cpp)
	@echo Generating dep.mk...
	@$(CXX) $(CXXFLAGS) -MM *.cpp > dep.mk

%.o: %.cpp
	@echo [CXX] $<
	@$(CXX) $(CXXFLAGS) $< -c

%.so: $(OBJS)
	@echo Linking dynamic library...
	@$(LD) $(LDFLAGS) $(OBJS) -shared -o $@

%.a: $(OBJS)
	@echo Archiving static library...
	@$(AR) rc $@ $(OBJS)
	@echo Running runlib...
	@$(RANLIB) $@

clean:
	@echo Removing object files...
	-@$(RM) $(OBJS)

disbuild: clean
	@echo Removing libraries...
	-@$(RM) $(LIBS)

distclean: disbuild
	@echo Removing dep.mk
	-@$(RM) dep.mk

include dep.mk
