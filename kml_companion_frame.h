#ifndef KML_COMPANION_FRAME_H
#define KML_COMPANION_FRAME_H

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "model.h"
#include "view.h"
#include "id_list.h"


class KmlCompanionFrame: public wxFrame
{
public:

    KmlCompanionFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

private:

    Model data_model;
    View *view;

    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnOpen(wxCommandEvent& event);
    void OnGo(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
};

#endif
