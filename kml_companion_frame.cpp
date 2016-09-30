#include "kml_companion_frame.h"
#include <wx/filedlg.h>

wxBEGIN_EVENT_TABLE(KmlCompanionFrame, wxFrame)
    EVT_MENU(KmlC_ID_Hello, KmlCompanionFrame::OnHello)
    EVT_MENU(KmlC_ID_Open, KmlCompanionFrame::OnOpen)
    EVT_MENU(wxID_EXIT, KmlCompanionFrame::OnExit)
    EVT_MENU(wxID_ABOUT, KmlCompanionFrame::OnAbout)
    EVT_BUTTON(KmlC_ID_GO, KmlCompanionFrame::OnGo)
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
    SetStatusText( "Welcome to KML Companion!" );
    view = new View(this);
}
void KmlCompanionFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}
void KmlCompanionFrame::OnAbout(wxCommandEvent& event)
{
  SetStatusText( "About clicked" );
}

void KmlCompanionFrame::OnGo(wxCommandEvent& event)
{
  view->DumpView();
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
                  wxT("Open file dialog"),
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
      //std::cout << "Before data model read file" << std::endl << std::flush;
      data_model.ReadFile(path);
      //std::cout << "After data model read file" << std::endl << std::flush;
      view->UpdateUI(data_model);
      //data_model.Print();

      // insert code here to update the view with the contents of the
      // data model
      // create a View data_view and call data_view.update(data_model);
  }
}
