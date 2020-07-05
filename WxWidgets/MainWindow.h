#pragma once

#include "pch.h"

enum
{
    ID_Hello = 1
};

class MainWindow : public wxFrame
{
public:
    MainWindow(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame(
        nullptr, wxID_ANY, title, pos, size)
    {
        wxMenu* menuFile = new wxMenu;
        menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                         "Help string shown in status bar for this menu item");
        menuFile->AppendSeparator();
        menuFile->Append(wxID_EXIT);
        wxMenu* menuHelp = new wxMenu;
        menuHelp->Append(wxID_ABOUT);
        wxMenuBar* menuBar = new wxMenuBar;
        menuBar->Append(menuFile, "&File");
        menuBar->Append(menuHelp, "&Help");
        SetMenuBar(menuBar);
        CreateStatusBar();
        SetStatusText("Welcome to wxWidgets!");
    }

private:
    void OnHello(wxCommandEvent& event)
    {
        wxLogMessage("Hello world from wxWidgets!");
    }

    void OnExit(wxCommandEvent& event)
    {
        Close(true);
    }

    void OnAbout(wxCommandEvent& event)
    {
        wxMessageBox("This is a wxWidgets' Hello world sample",
                     "About Hello World", wxOK | wxICON_INFORMATION);
    }

wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
    EVT_MENU(ID_Hello, MainWindow::OnHello)
    EVT_MENU(wxID_EXIT, MainWindow::OnExit)
    EVT_MENU(wxID_ABOUT, MainWindow::OnAbout)
wxEND_EVENT_TABLE()
