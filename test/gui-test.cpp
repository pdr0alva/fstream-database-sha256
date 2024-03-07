#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <openssl/sha.h>
#include <wx/wx.h>

#include "./source/class.h"
#include "./source/searchFile.c"
#include "./source/modifyFile.c"
#include "./GUI/GUI_def.h"

#include <wx/wx.h>

class GraphicFrame: public wxFrame 
{
private:

public: 
    GraphicFrame(): wxFrame(NULL, wxID_ANY, "C++ SHA256 Database (with wxWidgets GUI)") 
    {
        wxButton *test = new wxButton(this, wxID_ANY, wxT("Button Test"), wxPoint(30, 30), wxSize(200, 30));
        test -> Bind();
    }
}

class GraphicInterface: public wxApp
{
public:
    virtual bool OnInit();
}

virtual bool GraphicInterface::OnInit()
{
    GraphicFrame *graphic_frame = new GraphicFrame;
    graphic_frame -> Show(true);
    return true;
}

wxIMPLEMENT_APP(GraphicInterface);

