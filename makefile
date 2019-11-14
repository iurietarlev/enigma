OBJ = main.o enigma.o rotClass.o posClass.o pbClass.o rfClass.o classUtils.o
CXX = g++
CXXFLAGS = -Wall -g #-Wextra
EXE = enigma

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@ 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

main.o: enigma.h
enigma.o: enigma.h rotClass.o posClass.h pbClass.o rfClass.o
pbClass.o: pbClass.h classUtils.h		
rotClass.o: rotClass.h classUtils.h
rfClass.o: rfClass.h classUtils.h	
posClass.o: posClass.h classUtils.h	


.PHONY: clean

clean:
	rm -f *.o $(EXE)
