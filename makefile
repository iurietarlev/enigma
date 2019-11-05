OBJ = main.o mainUtils.o rotClass.o posClass.o pbClass.o rfClass.o classUtils.o
CXX = g++
CXXFLAGS = -Wall -g #-Wextra
EXE = enigma


$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@ 

main.o: main.cpp rotClass.h posClass.h
	$(CXX) $(CXXFLAGS) -c $<

mainUtils.o: mainUtils.cpp mainUtils.h pbClass.h
	$(CXX) $(CXXFLAGS) -c $<

rotClass.o: rotClass.cpp rotClass.h classUtils.h
	$(CXX) $(CXXFLAGS) -c $<

posClass.o: posClass.cpp posClass.h classUtils.h
	$(CXX) $(CXXFLAGS) -c $<

pbClass.o: pbClass.cpp pbClass.h classUtils.h
	$(CXX) $(CXXFLAGS) -c $<

rfClass.o: rfClass.cpp rfClass.h classUtils.h
	$(CXX) $(CXXFLAGS) -c $<

classUtils.o: classUtils.cpp classUtils.h errors.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o $(EXE)
