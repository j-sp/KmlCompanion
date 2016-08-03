#include <assert.h>
#include <iostream>
#include "kml/dom.h"
#include <kml/base/file.h>

using std::cout;
using std::endl;
using std::string;
using kmldom::CoordinatesPtr;
using kmldom::KmlFactory;
using kmldom::PlacemarkPtr;
using kmldom::PointPtr;
using kmlbase::File;

class KmlHelper {
public:
  void HelloKml (bool);
  void ReadKmlFile(const string&);
};
