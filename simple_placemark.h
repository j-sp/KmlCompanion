#ifndef SIMPLE_PLACEMARK_H
#define SIMPLE_PLACEMARK_H

#include <string>

class SimplePlacemark {
public:
  SimplePlacemark(const std::string&, double,
            double, double);
  void SetName(const std::string&);
  std::string GetName();
  void SetLat(double);
  double GetLat();
  void SetLong(double);
  double GetLong();
  void SetAlt(double);
  double GetAlt();
  void SetValue(double);
  double GetValue();

private:
  double latitude, longitude, altitude, value;
  std::string name;
};

#endif
