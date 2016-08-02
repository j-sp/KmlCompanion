CXX = $(shell wx-config --cxx)

PROGRAM = KmlCompanion

OBJECTS = KmlCompanion.o KmlHelper.o

$(PROGRAM): $(OBJECTS)
	$(CXX) -o $(PROGRAM) $(OBJECTS) `wx-config --libs` -lkmlbase -lkmldom

KmlCompanion.o: KmlCompanion.cpp
	$(CXX) -c `wx-config --cxxflags` -o $@ $<

KmlHelper.o: KmlHelper.cpp KmlHelper.h
	$(CXX) -c `wx-config --cxxflags` -o $@ $<

clean:
				rm -f *.o $(PROGRAM)
