#include "simple_placemark.h"

SimplePlacemark::SimplePlacemark(const std::string& aName, double aLatitude,
                     double aLongitude, double aAltitude = 0.0) {
  name = aName;
  latitude = aLatitude;
  longitude = aLongitude;
  altitude = aAltitude;
}

void SimplePlacemark::SetName(const std::string& aName) {
  name = aName;
}

std::string SimplePlacemark::GetName(){
  return name;
}

void SimplePlacemark::SetLat(double lat) {
  latitude = lat;
}

double SimplePlacemark::GetLat(){
  return latitude;
}

void SimplePlacemark::SetLong(double aLongitude){
  longitude = aLongitude;
}

double SimplePlacemark::GetLong(){
  return longitude;
}

void SimplePlacemark::SetAlt(double aAltitude){
  altitude = aAltitude;
}

double SimplePlacemark::GetAlt(){
  return altitude;
}
