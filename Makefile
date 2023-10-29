PROG = test

CC   = clang
CXX  = clang++

LIB  = 
LIB += 
SYSLIB   = -ldl -lpthread

INCLUDE  = -I ./ -I ./include/

FLAGS = -Debug
LFLAGS =
#LFLAGS = -shared -fPIC
MACRO = -DSNOW

CFLAGS = $(FLAGS) $(INCLUDE) $(MACRO)
CPPFLAGS = $(FLAGS) $(INCLUDE) $(MACRO) -std=c++17
TARGET_ARCH =

CFILES  = $(wildcard *.c)

CXXFILES  = $(wildcard *.cc)

OBJS = $(patsubst %.c,%.o,$(CFILES)) $(patsubst %.cc,%.o,$(CXXFILES))

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cc
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(PROG): $(OBJS)
	$(CXX) $(LFLAGS) -o $(PROG) $(OBJS) $(LIB) $(SYSLIB)

.PHONY : clean
clean:
	rm -f $(PROG) $(OBJS)