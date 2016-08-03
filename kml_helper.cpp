#include "kml_helper.h"

void KmlHelper::ReadKmlFile(const std::string& filename) {
  SavePlacemarks(GetKmlFileRootFeature(filename), &placemark_vector);
  cout << "The size of the vector is " << placemark_vector.size() << "\n" << std::flush;
}

FeaturePtr KmlHelper::GetKmlFileRootFeature(const std::string& kmlfile) {
  cout << "entering GetKmlFileRootFeature\n" << std::flush;
  // Read the file.
  std::string file_data;
  if (!kmlbase::File::ReadFileToString(kmlfile, &file_data)) {
    cout << kmlfile << " read failed" << endl;
    return NULL;
  }

  // If the file was KMZ, extract the KML file.
  std::string kml;
  if (KmzFile::IsKmz(file_data)) {
    KmzFilePtr kmz_file = KmzFile::OpenFromString(kmlfile);
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

void KmlHelper::SavePlacemarks(const FeaturePtr& feature,
                           placemark_vector_t* placemarks) {
  cout << "entering SavePlacemarks\n" << std::flush;
  if (PlacemarkPtr placemark = kmldom::AsPlacemark(feature)) {
    placemarks->push_back(placemark);
  } else if (const ContainerPtr container = kmldom::AsContainer(feature)) {
    for (size_t i = 0; i < container->get_feature_array_size(); ++i) {
      SavePlacemarks(container->get_feature_array_at(i), placemarks);
    }
  }
}
