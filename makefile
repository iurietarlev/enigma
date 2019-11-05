OBJ = main.o mainUtils.o rotClass.o posClass.o plgbrdClass.o rfClass.o utils.o
CXX = g++
CXXFLAGS = -Wall -g #-Wextra
EXE = enigma


$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@ 


main.o: main.cpp rotClass.h posClass.h
	$(CXX) $(CXXFLAGS) -c $<

mainUtils.o: mainUtils.cpp mainUtils.h
	$(CXX) $(CXXFLAGS) -c $<

rotClass.o: rotClass.cpp rotClass.h utils.h
	$(CXX) $(CXXFLAGS) -c $<

posClass.o: posClass.cpp posClass.h utils.h
	$(CXX) $(CXXFLAGS) -c $<

plgbrdClass.o: plgbrdClass.cpp plgbrdClass.h utils.h
	$(CXX) $(CXXFLAGS) -c $<

rfClass.o: rfClass.cpp rfClass.h utils.h
	$(CXX) $(CXXFLAGS) -c $<

utils.o: utils.cpp utils.h errors.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o $(EXE)
