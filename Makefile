CXX := g++
CXXFLAGS := -Wall -std=c++11 -g
OBJECTS_MAIN := Main.o Population.o IO.o
OBJECTS_PRE := PreMain.o Preprocess.o IO.o

all: main preprocess

main: GA-HMM

preprocess: preprocess-GA-HMM

GA-HMM: $(OBJECTS_MAIN) 
	$(CXX) $(CXXFLAGS) $(OBJECTS_MAIN) -o $@	

preprocess-GA-HMM: $(OBJECTS_PRE)
	$(CXX) $(CXXFLAGS) $(OBJECTS_PRE) -o $@

PreMain.o: PreMain.cpp Preprocess.h
	$(CXX) $(CXXFLAGS) -c PreMain.cpp

Preprocess.o: Preprocess.cpp Preprocess.h IO.h
	$(CXX) $(CXXFLAGS) -c Preprocess.cpp

Main.o: Main.cpp Main.h Globals.h IO.h Population.h
	$(CXX) $(CXXFLAGS) -c Main.cpp

Population.o: Population.cpp Population.h IO.h Globals.h
	$(CXX) $(CXXFLAGS) -c Population.cpp

IO.o: IO.cpp IO.h Globals.h
	$(CXX) $(CXXFLAGS) -c IO.cpp
	
clean:
	rm -f $(OBJECTS_MAIN) $(OBJECTS_PRE) GA-HMM preprocess-GA-HMM
