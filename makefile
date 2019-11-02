OBJ = main.o rotor_class.o
CXX = g++
CXXFLAGS = -Wall -g #-Wextra
EXE = enigma


$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@ 


main.o: main.cpp rotor_class.h
	$(CXX) $(CXXFLAGS) -c $<

rotor_class.o: rotor_class.cpp rotor_class.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o $(EXE)
