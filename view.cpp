#include "view.h"

View::View(wxWindow *parent)
        : wxPanel(parent)
{
    const int nb_cols = 4;
    wxBoxSizer *topSizer = new wxBoxSizer( wxHORIZONTAL );

    topSizer->Add(
    new wxButton( this, KmlC_ID_GO, "Go!" ),
    0,           // make horizontally unstretchable
    wxALL,       // make border all around (implicit top alignment)
    10 );        // set border width to 10

    grid_view = new wxGrid(this, wxID_ANY);
    grid_view->CreateGrid(default_nb_lines, nb_cols);

    for (int i = 0; i<nb_cols; i++)
      grid_view->SetColSize(i, 200);

    grid_view->SetColLabelValue(0, "Latitude (deg)");
    grid_view->SetColLabelValue(1, "Longitude (deg)");
    grid_view->SetColLabelValue(2, "Name");
    grid_view->SetColLabelValue(3, "Value");

    topSizer->Add(grid_view, 1, wxEXPAND | wxALL, 10);

    SetSizerAndFit(topSizer);
}

void View::UpdateUI(Model data_model) {
  std::vector<SimplePlacemark> placemarks = data_model.GetPlacemarks();
  int current_rows = grid_view->GetNumberRows();
  int new_rows = placemarks.size();

  if (new_rows < default_nb_lines)
    grid_view->DeleteRows(0, current_rows-default_nb_lines, true);

  if (new_rows > default_nb_lines)
    grid_view->AppendRows(new_rows - default_nb_lines, true);

  for (int i = 0; i < new_rows; i++) {
    grid_view->SetCellValue(i, 0, wxString::Format(wxT("%f"),
      placemarks[i].GetLat()));
    grid_view->SetCellValue(i, 1, wxString::Format(wxT("%f"),
      placemarks[i].GetLong()));
    grid_view->SetCellValue(i, 2, placemarks[i].GetName());

  }
}
