#include "window.hpp"

Window::Window(const string &title):wxFrame(NULL,wxID_ANY,title,wxDefaultPosition,wxSize(300,200))
{
    Centre();
}

