#include "placemark.h"

Placemark::Placemark(const std::string& aName, double aLatitude,
                     double aLongitude, double aAltitude = 0.0) {
  name = aName;
  latitude = aLatitude;
  longitude = aLongitude;
  altitude = aAltitude;
}

void Placemark::SetName(const std::string& aName) {
  name = aName;
}

std::string Placemark::GetName(){
  return name;
}

void Placemark::SetLat(double lat) {
  latitude = lat;
}

double Placemark::GetLat(){
  return latitude;
}

void Placemark::SetLong(double aLongitude){
  longitude = aLongitude;
}

double Placemark::GetLong(){
  return longitude;
}

void Placemark::SetAlt(double aAltitude){
  altitude = aAltitude;
}

double Placemark::GetAlt(){
  return altitude;
}
