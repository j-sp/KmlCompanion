#ifndef VIEW_H
#define VIEW_H

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "model.h"
#include "id_list.h"
#include<wx/grid.h>


class View: public wxPanel
{
public:

    View(wxWindow *parent);
    void UpdateUI(Model data_model);

private:

    wxGrid *grid_view;

};

#endif
