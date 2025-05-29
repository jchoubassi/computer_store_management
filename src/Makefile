# Created makefile because I use C++ often and it is nice to use.
# Do not need to use though!

CXX = g++
CXXFLAGS = -std=c++11 -Wall
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = store

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

clean:
	@echo Cleaning...
	@rm -f $(OBJ) $(TARGET) 2> /dev/null || del /q $(OBJ) $(TARGET)

##rm -f for mac
##del /q for windows
##Use both because built on both