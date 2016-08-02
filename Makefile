CXX = $(shell wx-config --cxx)

PROGRAM = KmlCompanion

OBJECTS = KmlCompanion.o KmlHelper.o KmlCompanionFrame.o

$(PROGRAM): $(OBJECTS)
	$(CXX) -o $(PROGRAM) $(OBJECTS) `wx-config --libs` -lkmlbase -lkmldom

KmlCompanion.o: KmlCompanion.cpp KmlCompanion.h KmlCompanionFrame.h
	$(CXX) -c `wx-config --cxxflags` -o $@ $<

KmlCompanionFrame.o: KmlCompanionFrame.cpp KmlCompanionFrame.h
	$(CXX) -c `wx-config --cxxflags` -o $@ $<

KmlHelper.o: KmlHelper.cpp KmlHelper.h
	$(CXX) -c `wx-config --cxxflags` -o $@ $<

clean:
				rm -f *.o $(PROGRAM)
