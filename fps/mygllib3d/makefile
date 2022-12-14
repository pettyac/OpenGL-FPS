 #------------------------------------------------------------------------------
# Makefile for object code in mygllib
# Y. Liow
#------------------------------------------------------------------------------
# Macros
#------------------------------------------------------------------------------
CXX 	= g++
CXXFLAGS= -g -Wall
LINK = g++
LINKFLAGS = -lGL -lGLU -lglut -lGLEW -lglfw3
OBJS = config.o reshape.o Keyboard.o DisplayLists.o Mouse.o Light.o Material.o 

#------------------------------------------------------------------------------
# Build all object code
#------------------------------------------------------------------------------
all:	$(OBJS)
	$(NOOP)

#------------------------------------------------------------------------------
# Object codes
#------------------------------------------------------------------------------
config.o: config.h config.cpp
	$(CXX) $(CXXFLAGS) config.cpp -c -o config.o

reshape.o: reshape.h reshape.cpp
	$(CXX) $(CXXFLAGS) reshape.cpp -c -o reshape.o
	
Keyboard.o: Keyboard.h Keyboard.cpp
	$(CXX) $(CXXFLAGS) Keyboard.cpp -c -o Keyboard.o

DisplayLists.o: DisplayLists.h
	$(CXX) $(CXXFLAGS) DisplayLists.h -c -o DisplayLists.o
	
Mouse.o: Mouse.h Mouse.cpp
	$(CXX) $(CXXFLAGS) Mouse.cpp -c -o Mouse.o

Light.o: Light.h Light.cpp
	$(CXX) $(CXXFLAGS) Light.cpp -c -o Light.o

Material.o: Material.h Material.cpp
	$(CXX) $(CXXFLAGS) Material.cpp -c -o Material.o

#------------------------------------------------------------------------------
# Utilities
#------------------------------------------------------------------------------
clean:
	rm -f $(OBJS)
c:
	rm -f $(OBJS)
