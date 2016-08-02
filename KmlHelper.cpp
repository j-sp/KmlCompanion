#include "KmlHelper.h"

void KmlHelper::HelloKml(bool verbose) {
  KmlFactory* factory(KmlFactory::GetFactory());
  // <coordinates>
  CoordinatesPtr coordinates(factory->CreateCoordinates());
  coordinates->add_latlngalt(37.123, -122.456, 314.159);
  // <Point><coordinates>...
  PointPtr point(factory->CreatePoint());
  point->set_coordinates(coordinates);
  // <Point><altitudeMode>...<coordinates>...
  point->set_altitudemode(kmldom::ALTITUDEMODE_RELATIVETOGROUND);
  assert(point->get_altitudemode() == kmldom::ALTITUDEMODE_RELATIVETOGROUND);
  // <Placemark><Point><coordinates>...
  PlacemarkPtr placemark(factory->CreatePlacemark());
  placemark->set_geometry(point);

  // A Placemark is (duh) a Placemark
  assert (placemark->Type() == kmldom::Type_Placemark);
  // It's also a Feature.
  assert(placemark->IsA(kmldom::Type_Feature));
  placemark->set_name("point placemark");
  if (verbose) {
    cout << "Placemark's name is " << placemark->get_name() << endl;
  }
  // We know it has some geometry.
  assert(placemark->has_geometry());
  // And we can test to see if that geometry is a Point.
  assert(placemark->get_geometry()->IsA(kmldom::Type_Point));
  // If it is, we can make a point from it. (Yes, API should hide casting.)
  const PointPtr pt = kmldom::AsPoint(placemark->get_geometry());
  assert(pt->get_altitudemode() == kmldom::ALTITUDEMODE_RELATIVETOGROUND);
  if (verbose) {
    cout.precision(6);
    cout << placemark->get_name() << " is located at: ";
    cout << pt->get_coordinates()->get_coordinates_array_at(0).get_latitude()
         << ", ";
    cout << pt->get_coordinates()->get_coordinates_array_at(0).get_longitude()
         << endl;
  }

  // All storage is freed by smart pointers as they go out of scope.
}
