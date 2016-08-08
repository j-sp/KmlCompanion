CXX = $(shell wx-config --cxx)

PROGRAM = kml_companion

OBJECTS = kml_companion.o kml_helper.o kml_companion_frame.o simple_placemark.o \
          model.o view.o

$(PROGRAM): $(OBJECTS)
	$(CXX) -o $(PROGRAM) $(OBJECTS) `wx-config --libs` -lkmlbase -lkmldom -lkmlengine

kml_companion.o: kml_companion.cpp kml_companion.h kml_companion_frame.h
	$(CXX) -c `wx-config --cxxflags` -o $@ $<

view.o: view.cpp view.h
		$(CXX) -c `wx-config --cxxflags` -o $@ $<

kml_companion_frame.o: kml_companion_frame.cpp kml_companion_frame.h
	$(CXX) -c `wx-config --cxxflags` -o $@ $<

kml_helper.o: kml_helper.cpp kml_helper.h
	$(CXX) -c `wx-config --cxxflags` -o $@ $<

simple_placemark.o: simple_placemark.cpp simple_placemark.h
	$(CXX) -c -o $@ $<

model.o: model.cpp model.h
	$(CXX) -c -o $@ $<

clean:
				rm -f *.o $(PROGRAM)
