#include <string>
#include <vector>
#include "placemark.h"
#include "kml_helper.h"

class Model {
public:
  void ReadFile(const std::string& filename);

private:
  std::vector<Placemark> placemarks;
  KmlHelper kml_helper;
};
