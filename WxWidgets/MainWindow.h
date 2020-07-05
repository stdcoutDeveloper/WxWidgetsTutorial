#pragma once

#include "pch.h"

enum
{
    ID_Hello = 1,
    ID_OK_BUTTON = wxID_HIGHEST + 1
};

class MainWindow : public wxFrame
{
public:
    MainWindow(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame(
        nullptr, wxID_ANY, title, pos, size)
    {
        SetupWindow();
    }

private:
    void SetupWindow()
    {
        // Create a menu bar
        wxMenu* menuFile = new wxMenu();
        menuFile->Append(ID_Hello, "&Hello...\tCtrl-H", "Help string shown in status bar for this menu item");
        menuFile->AppendSeparator();
        menuFile->Append(wxID_EXIT, "E&xit\tAlt-X", "Quit this program");

        // The "About" item should be in the help menu
        wxMenu* menuHelp = new wxMenu();
        menuHelp->Append(wxID_ABOUT, "&About...\tF1", "Show about dialog");

        // Now append the freshly created menu to the menu bar
        wxMenuBar* menuBar = new wxMenuBar();
        menuBar->Append(menuFile, "&File");
        menuBar->Append(menuHelp, "&Help");

        // Attach this menu bar to the frame
        SetMenuBar(menuBar);

        // Add Ok button
        wxButton* okButton = new wxButton(this, ID_OK_BUTTON, "OK", wxPoint(200, 200));

        // Create a status bar
        CreateStatusBar(2); // 2: The number of fields to create.
        SetStatusText("Welcome to wxWidgets!");
    }

    // Event handlers
    void OnHello(wxCommandEvent& event)
    {
        wxLogMessage("Hello world from wxWidgets!");
    }

    void OnExit(wxCommandEvent& event)
    {
        // Destroy the frame
        Close(true);
    }

    void OnAbout(wxCommandEvent& event)
    {
        wxMessageBox("This is a wxWidgets' Hello world sample", "About Hello World", wxOK | wxICON_INFORMATION);
    }

    void OnResize(wxSizeEvent& event)
    {
    }

    void OnButtonOk(wxCommandEvent& event)
    {
    }

	// @formatter:off
	// This class handles events
	wxDECLARE_EVENT_TABLE();
    // @formatter:on
};

// Event table for MainWindow
wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
    EVT_MENU(ID_Hello, MainWindow::OnHello)
    EVT_MENU(wxID_EXIT, MainWindow::OnExit)
    EVT_MENU(wxID_ABOUT, MainWindow::OnAbout)
    EVT_SIZE(MainWindow::OnResize)
    EVT_BUTTON(ID_OK_BUTTON, MainWindow::OnButtonOk)
wxEND_EVENT_TABLE()
