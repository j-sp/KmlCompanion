#include "model.h"

FeaturePtr Model::GetKmlFileRootFeature(const std::string& kmlfile) {
  //cout << "entering GetKmlFileRootFeature\n" << std::flush;
  // Read the file.
  std::string file_data;
  if (!kmlbase::File::ReadFileToString(kmlfile, &file_data)) {
    cout << kmlfile << " read failed" << endl;
    return NULL;
  }

  // If the file was KMZ, extract the KML file.
  std::string kml;
  if (KmzFile::IsKmz(file_data)) {
    KmzFilePtr kmz_file = KmzFile::OpenFromString(file_data);
    if (!kmz_file) {
      cout << "Failed opening KMZ file" << endl;
      return NULL;
    }
    if (!kmz_file->ReadKml(&kml)) {
      cout << "Failed to read KML from KMZ" << endl;
      return NULL;
    }
  } else {
    kml = file_data;
  }

  // Parse it.
  std::string errors;
  KmlFilePtr kml_file = KmlFile::CreateFromParse(kml, &errors);
  if (!kml_file) {
    cout << errors << endl;
    return FeaturePtr();
  }

  // Get the root
  return kmlengine::GetRootFeature(kml_file->get_root());
}

void Model::SavePlacemarks(const FeaturePtr& feature,
                           kml_placemark_vector_t* kml_placemarks) {
  //cout << "entering SavePlacemarks\n" << std::flush;
  if (PlacemarkPtr kml_placemark = kmldom::AsPlacemark(feature)) {
    kml_placemarks->push_back(kml_placemark);
  } else if (const ContainerPtr container = kmldom::AsContainer(feature)) {
    for (size_t i = 0; i < container->get_feature_array_size(); ++i) {
      SavePlacemarks(container->get_feature_array_at(i), kml_placemarks);
    }
  }
}

void Model::ReadFile(const std::string& filename){
  kml_placemark_vector.clear();
  SavePlacemarks(GetKmlFileRootFeature(filename), &kml_placemark_vector);
  placemarks.clear();
  kmldom::PointPtr pt;
  for(int i = 0; i < kml_placemark_vector.size(); i++){
    if (kml_placemark_vector[i]->has_geometry())
     if (kml_placemark_vector[i]->get_geometry()->IsA(kmldom::Type_Point)) {
      pt = kmldom::AsPoint(kml_placemark_vector[i]->get_geometry());
      placemarks.push_back(SimplePlacemark(kml_placemark_vector[i]->get_name(),
       pt->get_coordinates()->get_coordinates_array_at(0).get_latitude(),
       pt->get_coordinates()->get_coordinates_array_at(0).get_longitude(),
       pt->get_coordinates()->get_coordinates_array_at(0).get_altitude()));
   }
  }


  //kml_helper.ReadKmlFile(filename, &placemarks);
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

std::vector<SimplePlacemark> Model::GetPlacemarks() const{
  return placemarks;
}
