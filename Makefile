# # # # # # # # # # # 
# Makefile:CIS2500  #
# # # # # # # # # # #

# compiler flags
# -g --Enable debugging
# -Wall --Turn on all warnings
# -D_USE_FIXED_PROTOTYPES_
# --Force the compiler to use the correct headers
# -ansi --Don't use GNU ext; do use ansi standard.

CXX = gcc 
CXXFLAGS = -ansi -Wall -lncurses
DEBUGFLAGS = -g -ansi -Wall
INCLUDE = -Iinclude
#Link command:
rogue: rogue.o roguefunctions.o
	$(CXX) $(CXXFLAGS) $(INCLUDE) bin/rogue.o bin/roguefunctions.o -o bin/rogue

#Compilation commands:
rogue.o: src/rogue.c 
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c  src/rogue.c -o bin/rogue.o 

roguefunctions.o: src/roguefunctions.c 
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c src/roguefunctions.c -o bin/roguefunctions.o
#make clean
clean:
	rm -f *.o bin/rogue