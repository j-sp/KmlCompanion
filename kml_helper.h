#include <iostream>
#include <string>
#include <vector>
#include "kml/dom.h"
#include "kml/engine.h"
#include "kml/base/file.h"

using kmldom::ContainerPtr;
using kmldom::ElementPtr;
using kmldom::FeaturePtr;
using kmldom::KmlPtr;
using kmldom::PlacemarkPtr;
using kmlengine::KmlFile;
using kmlengine::KmlFilePtr;
using kmlengine::KmzFile;
using kmlengine::KmzFilePtr;
using std::cout;
using std::endl;

typedef std::vector<PlacemarkPtr> placemark_vector_t;

class KmlHelper {
public:
  void ReadKmlFile(const std::string&);

private:
  placemark_vector_t placemark_vector;
  FeaturePtr GetKmlFileRootFeature(const std::string&);
  void SavePlacemarks(const FeaturePtr&, placemark_vector_t* );
};
