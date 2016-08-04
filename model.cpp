#include "model.h"

void Model::ReadFile(const std::string& filename){
  kml_helper.ReadKmlFile(filename);
}
