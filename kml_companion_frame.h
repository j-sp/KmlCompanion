// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "kml_helper.h"

class KmlCompanionFrame: public wxFrame
{
public:
    KmlCompanionFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    KmlHelper my_helper;
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnOpen(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
};
