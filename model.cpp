#include "model.h"

void Model::ReadFile(const std::string& filename){
  kml_helper.ReadKmlFile(filename, &placemarks);
}

void Model::Print(){
  for(int i = 0; i < placemarks.size(); i++) {
    cout << "Name     : " << placemarks[i].GetName() << std::endl;
    cout << "Latitude : " << placemarks[i].GetLat() << std::endl;
    cout << "Longitude: " << placemarks[i].GetLong() << std::endl;
    cout << "Altitude : " << placemarks[i].GetAlt() << std::endl;
    cout << "Value    : " << placemarks[i].GetValue() << std::endl;
    cout << std::endl << std::flush;
  }
}

std::vector<SimplePlacemark> Model::GetPlacemarks(){
  return placemarks;
}
