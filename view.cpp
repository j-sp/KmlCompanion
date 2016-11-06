#include "view.h"

View::View(wxWindow *parent)
        : wxPanel(parent)
{
    const int cols = 4;
    rows = default_rows;
    wxBoxSizer *topSizer = new wxBoxSizer( wxHORIZONTAL );

    topSizer->Add(
    new wxButton( this, KmlC_ID_GO, "Go!" ),
    0,           // make horizontally unstretchable
    wxALL,       // make border all around (implicit top alignment)
    10 );        // set border width to 10

    grid_view = new wxGrid(this, wxID_ANY);
    grid_view->CreateGrid(default_rows, cols);

    for (int i = 0; i<cols; i++)
      grid_view->SetColSize(i, 200);

    grid_view->SetColLabelValue(0, "Latitude (deg)");
    grid_view->SetColFormatFloat(0, -1, 6);

    grid_view->SetColLabelValue(1, "Longitude (deg)");
    grid_view->SetColFormatFloat(1, -1, 6);

    grid_view->SetColLabelValue(2, "Name");

    grid_view->SetColLabelValue(3, "Value");
    grid_view->SetColFormatFloat(3, -1, 6);

    topSizer->Add(grid_view, 1, wxEXPAND | wxALL, 10);

    SetSizerAndFit(topSizer);
}

void View::UpdateUI(const Model &data_model) {
  std::vector<SimplePlacemark> placemarks = data_model.GetPlacemarks();
  //int current_rows = grid_view->GetNumberRows();
  int used_rows = placemarks.size();

  //std::cout << "used_rows = " << used_rows << std::endl << std::flush;
  // Leave size at default_rows if we need less than default_rows
  if (used_rows < default_rows){
    if (rows > default_rows)
      grid_view->DeleteRows(0, rows - default_rows, true);
    else
      grid_view->AppendRows(default_rows - rows, true);
  }

  // Otherwise grow to accommodate extra rows
  if (used_rows >= default_rows){
    if (rows > used_rows)
      grid_view->DeleteRows(0, rows - used_rows, true);
    else
      grid_view->AppendRows(used_rows - rows, true);
  }

  grid_view->ClearGrid();

  rows = grid_view->GetNumberRows();

  for (int i = 0; i < used_rows; i++) {
    grid_view->SetCellValue(i, 0, wxString::Format(wxT("%f"),
      placemarks[i].GetLat()));
    grid_view->SetCellValue(i, 1, wxString::Format(wxT("%f"),
      placemarks[i].GetLong()));
    grid_view->SetCellValue(i, 2, placemarks[i].GetName());

  }
}

void View::DumpView() {
  std::cout << "DumpView called" << std::endl;
  wxString cell = grid_view->GetCellValue(0,0);
  std::cout << "Contents of cell (0, 0): " << cell << std::endl;
}
