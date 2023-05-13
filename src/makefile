#	libnekoxx
#	Makefile for libnekoxx
#	By MIT License.
#	Copyright (c) 2023 Ziyao and AlanCui4080.

CXXCODE_DIR = . ../tests
NOSUFFIX_HEADER_DIR = ../include

all: dep.mk $(LIBS)

dep dep.mk: $(shell ls *.cpp)
	@echo [CXXDEP] $@
	@$(CXXDEP) $(CXXFLAGS) > dep.mk

%.o: %.cpp
	@echo [CXX] $<
	@$(CXX) $(CXXFLAGS) $< -c

%.so: $(OBJS)
	@echo [LD] $@
	@$(LD) $(LDFLAGS) $(OBJS) -shared -o $@

%.a: $(OBJS)
	@echo [AR] $@
	@$(AR) rc $@ $(OBJS)
	@echo [RANLIB] $@
	@$(RANLIB) $@

clean:
	@echo [RM] $(LIBS) $(OBJS) dep.mk
	-@$(RM) -f $(LIBS) $(OBJS) dep.mk

include dep.mk
