#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>
#include <vector>
#include "kml/dom.h"
#include "kml/engine.h"
#include "kml/base/file.h"
#include "simple_placemark.h"

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

typedef std::vector<PlacemarkPtr> kml_placemark_vector_t;
typedef std::vector<SimplePlacemark> simple_placemark_vector_t;

class Model {
public:
  void ReadFile(const std::string& filename);
  std::vector<SimplePlacemark> GetPlacemarks() const;
  void Print();

private:
  std::vector<SimplePlacemark> placemarks;
  kml_placemark_vector_t kml_placemark_vector;
  //KmlHelper kml_helper;

  FeaturePtr GetKmlFileRootFeature(const std::string&);
  void SavePlacemarks(const FeaturePtr&, kml_placemark_vector_t* );
};

#endif
