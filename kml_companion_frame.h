// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "model.h"
#include<wx/grid.h>

class KmlCompanionFrame: public wxFrame
{
public:

    KmlCompanionFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

private:

    Model data_model;

    // This will probably be a more complex view component in the future
    wxGrid *grid_view;

    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnOpen(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
};
