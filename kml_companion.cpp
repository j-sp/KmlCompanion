// Copyright 2016 Javier Serrano and Adrian Serrano
//
// This file is part of KmlCompanion.
//
// KmlCompanion is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// KmlCompanion is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with KmlCompanion.  If not, see <http://www.gnu.org/licenses/>.

#include "kml_companion.h"
#include "kml_companion_frame.h"

wxIMPLEMENT_APP(KmlCompanion);

bool KmlCompanion::OnInit()
{
    int frame_width, frame_height;

    KmlCompanionFrame *frame = new KmlCompanionFrame( "KML Companion", wxPoint(50, 50), wxSize(1024, 768) );

    //Find optimal width and fix height to some reasonable value
    frame->Fit();
    frame->GetSize(&frame_width, &frame_height);
    frame->SetSize(frame_width, 480);
    
    frame->Show( true );
    return true;
}
