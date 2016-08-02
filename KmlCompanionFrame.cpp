#include "KmlCompanionFrame.h"
#include<wx/grid.h>

enum
{
    ID_Hello = 1
};

wxBEGIN_EVENT_TABLE(KmlCompanionFrame, wxFrame)
    EVT_MENU(ID_Hello,   KmlCompanionFrame::OnHello)
    EVT_MENU(wxID_EXIT,  KmlCompanionFrame::OnExit)
    EVT_MENU(wxID_ABOUT, KmlCompanionFrame::OnAbout)
wxEND_EVENT_TABLE()

KmlCompanionFrame::KmlCompanionFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
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
    //wxMessageBox( "This is a wxWidgets' Hello world sample",
    //              "About Hello World", wxOK | wxICON_INFORMATION );
    my_helper.HelloKml(true);
}
void KmlCompanionFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}
