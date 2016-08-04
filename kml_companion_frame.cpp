#include "kml_companion_frame.h"
#include<wx/grid.h>
#include <wx/filedlg.h>

enum
{
    KmlC_ID_Hello = wxID_HIGHEST + 1,
    KmlC_ID_Open
};

wxBEGIN_EVENT_TABLE(KmlCompanionFrame, wxFrame)
    EVT_MENU(KmlC_ID_Hello, KmlCompanionFrame::OnHello)
    EVT_MENU(KmlC_ID_Open, KmlCompanionFrame::OnOpen)
    EVT_MENU(wxID_EXIT, KmlCompanionFrame::OnExit)
    EVT_MENU(wxID_ABOUT, KmlCompanionFrame::OnAbout)
wxEND_EVENT_TABLE()

KmlCompanionFrame::KmlCompanionFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(KmlC_ID_Open, "&Open file...\tCtrl-O");
    menuFile->Append(KmlC_ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText( "Welcome to wxWidgets!" );

    wxGrid *myGrid = new wxGrid(this, wxID_ANY);
    myGrid->CreateGrid(10, 10);
}
void KmlCompanionFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}
void KmlCompanionFrame::OnAbout(wxCommandEvent& event)
{

}
void KmlCompanionFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}

void KmlCompanionFrame::OnOpen(wxCommandEvent& event)
{
  wxFileDialog dialog
               (
                  this,
                  wxT("Testing open file dialog"),
                  wxEmptyString,
                  wxEmptyString,
                  wxT("KML files (*.kml;*.kmz)|*.kml;*.kmz")
               );

  dialog.CentreOnParent();
  dialog.SetDirectory(wxGetHomeDir());

  if (dialog.ShowModal() == wxID_OK)
  {
      std::string path;
      path = dialog.GetPath().ToStdString();
      data_model.ReadFile(path);
      data_model.Print();
  }
}
