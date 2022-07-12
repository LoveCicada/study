
/**
 * @file controlCommunicate.cpp
 * @author your name (you@domain.com)
 * @brief 控件间通信
 * @version 0.3
 * @date 2022-06-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <cstdlib>
#include <string.h>
#include <iostream>
using namespace std;

class SimpleWindow : public Fl_Window {
public:
    SimpleWindow(int w, int h, const char* title);
    ~SimpleWindow();

public:
    Fl_Button*  m_pCopyBtn;
    Fl_Button*  m_pQuitBtn;
    Fl_Input*   m_pInput;
    Fl_Output*  m_pOutput;

private:
    static void cb_copy(Fl_Widget* w, void* v);
    inline void cb_copy_i();

    static void cb_quit(Fl_Widget* w, void* v);
    inline void cb_quit_i();
};

// imp
SimpleWindow::SimpleWindow(int w, int h, const char* title)
        :Fl_Window(w, h, title) {
    begin();

    m_pCopyBtn = new Fl_Button(10, 150, 70, 30, "C&opy");
    m_pCopyBtn->callback(cb_copy, this);

    m_pQuitBtn = new Fl_Button(100, 150, 70, 30, "&Quit");
    m_pQuitBtn->callback(cb_quit, this);

    m_pInput = new Fl_Input(50, 50, 140, 30, "Input");
    m_pOutput = new Fl_Output(50, 100, 140, 30, "Output");

    end();
    resizable(this);
    show();
}

SimpleWindow::~SimpleWindow() {

}

void SimpleWindow::cb_copy(Fl_Widget* w, void* v) {
    ((SimpleWindow*)v)->cb_copy_i();
}

void SimpleWindow::cb_copy_i() {
    m_pOutput->value(m_pInput->value());
}

void SimpleWindow::cb_quit(Fl_Widget* w, void* v) {
    ((SimpleWindow*)v)->cb_quit_i();
}

void SimpleWindow::cb_quit_i() {
    hide();
}

int main(int argc, char** argv)
{
    SimpleWindow win(300, 200, "SimpleWindow");

    return Fl::run();
}

