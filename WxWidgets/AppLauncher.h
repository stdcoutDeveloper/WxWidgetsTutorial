// AppLauncher.h : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once

#include "MainWindow.h"

/**
 * \brief Class represents the running application.
 */
class AppLauncher : public wxApp
{
public:
    AppLauncher() : window_(nullptr)
    {
    }

    ~AppLauncher() = default;

    /**
     * \brief This method will be called on application startup.
     * @return true: starts the event loop that processes user input 
     * and runs event handlers.
     * @return false: clean up its internal structures, 
     * and the application will terminate.
     */
    bool OnInit() override
    {
        // create the main window
        window_ = new MainWindow("Hello World", wxPoint(50, 50), wxSize(450, 340));
        // show it
        window_->Show(true);

        // start the event loop
        return true;
    }

private:
    MainWindow* window_;
};

// Implements AppLauncher& wxGetApp()
wxDECLARE_APP(AppLauncher);
