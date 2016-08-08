#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <vector>
#include "simple_placemark.h"
#include "kml_helper.h"

class Model {
public:
  void ReadFile(const std::string& filename);
  void Print();

private:
  std::vector<SimplePlacemark> placemarks;
  KmlHelper kml_helper;
};

#endif
