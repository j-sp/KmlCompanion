#include <assert.h>
#include <iostream>
#include "kml/dom.h"

using std::cout;
using std::endl;
using kmldom::CoordinatesPtr;
using kmldom::KmlFactory;
using kmldom::PlacemarkPtr;
using kmldom::PointPtr;

class KmlHelper {
public:
  void HelloKml (bool);
};
