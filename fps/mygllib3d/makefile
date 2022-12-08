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
OBJS = config.o reshape.o SingletonView.o Keyboard.o DisplayLists.o Camera.o Mouse.o

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
	
SingletonView.o: SingletonView.h SingletonView.cpp
	$(CXX) $(CXXFLAGS) SingletonView.cpp -c -o Camera.o

reshape.o: reshape.h reshape.cpp
	$(CXX) $(CXXFLAGS) reshape.cpp -c -o reshape.o
	
Keyboard.o: Keyboard.h Keyboard.cpp
	$(CXX) $(CXXFLAGS) Keyboard.cpp -c -o Keyboard.o

DisplayLists.o: DisplayLists.h
	$(CXX) $(CXXFLAGS) DisplayLists.h -c -o DisplayLists.o
	
Mouse.o: Mouse.h Mouse.cpp
	$(CXX) $(CXXFLAGS) Mouse.cpp -c -o Mouse.o


#------------------------------------------------------------------------------
# Utilities
#------------------------------------------------------------------------------
clean:
	rm -f $(OBJS)
c:
	rm -f $(OBJS)
