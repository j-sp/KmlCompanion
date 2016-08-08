#include "view.h"

View::View(wxWindow *parent)
        : wxPanel(parent)
{
    wxBoxSizer *topSizer = new wxBoxSizer( wxHORIZONTAL );

    topSizer->Add(
    new wxButton( this, KmlC_ID_GO, "Go!" ),
    0,           // make horizontally unstretchable
    wxALL,       // make border all around (implicit top alignment)
    10 );        // set border width to 10

    grid_view = new wxGrid(this, wxID_ANY);
    grid_view->CreateGrid(10, 10);

    topSizer->Add(grid_view, 1, wxEXPAND | wxALL, 10);

    SetSizerAndFit(topSizer);
}
