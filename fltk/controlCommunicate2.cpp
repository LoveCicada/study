
/**
 * @file controlCommunicate.cpp
 * @author your name (you@domain.com)
 * @brief 控件间通信 设置回调数据
 * @version 0.2
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
    Fl_Button* copy = new Fl_Button(50, 100, 140, 30, "change me");

    //child 1, 2nd widget
    Fl_Button* close = new Fl_Button(100, 150, 70, 30, "&Quit");

    //child 2, 3rd widget
    Fl_Input* input = new Fl_Input(50, 50, 140, 30, "In");

    win->end();
    copy->callback(copy_cb, input);
    close->callback(close_cb);

    win->show();
}

void copy_cb(Fl_Widget* o, void* data) {
    Fl_Button* b = static_cast<Fl_Button*>(o);
    Fl_Input* iw = static_cast<Fl_Input*>(data);

    b->copy_label(iw->value());
}

void close_cb(Fl_Widget* o, void* data) {
    exit(0);
}