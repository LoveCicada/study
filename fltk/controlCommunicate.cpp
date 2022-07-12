
/**
 * @file controlCommunicate.cpp
 * @author your name (you@domain.com)
 * @brief 控件间通信
 * @version 0.1
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

void copy_cb(Fl_Widget*, void*);
void close_cb(Fl_Widget*, void*);
void make_window();

int main(int argc, char** argv)
{
    make_window();

    return Fl::run();
}

void make_window()
{
    Fl_Window* win = new Fl_Window(300, 200, "Testing 2");
    win->begin();
    //child 0, 1st widget
    Fl_Button* copy = new Fl_Button(10, 150, 70, 30, "C&opy");

    //child 1, 2nd widget
    Fl_Button* close = new Fl_Button(100, 150, 70, 30, "&Quit");

    //child 2, 3rd widget
    Fl_Input* input = new Fl_Input(50, 50, 140, 30, "In");

    //child 3, 4th widget
    Fl_Output* out = new Fl_Output(50, 100, 140, 30, "Out");

    win->end();
    copy->callback(copy_cb);
    close->callback(close_cb);

    win->show();
}

void copy_cb(Fl_Widget* o, void* data) {
    Fl_Button* b = static_cast<Fl_Button*>(o);
    Fl_Input* iw = static_cast<Fl_Input*>(b->parent()->child(2));
    // Fl_Input* iw = (Fl_Input*)b->parent()->child(2);
    Fl_Output* ow = static_cast<Fl_Output*>(b->parent()->child(3));
    ow->value(iw->value());
}

void close_cb(Fl_Widget* o, void* data) {
    exit(0);
}