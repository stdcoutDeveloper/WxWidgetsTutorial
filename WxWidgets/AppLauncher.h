#pragma once

#include "MainWindow.h"

class AppLauncher : public wxApp
{
public:
    AppLauncher() : window_(nullptr)
    {
    }

    ~AppLauncher() = default;

    bool OnInit() override
    {
        window_ = new MainWindow("Hello World", wxPoint(50, 50), wxSize(450, 340));
        window_->Show(true);

        return true;
    }

private:
    MainWindow* window_;
};
