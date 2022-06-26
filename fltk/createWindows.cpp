#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
using namespace std;

void button_cb(Fl_Widget *widget, void* data) {
    Fl_Button *button = static_cast<Fl_Button*>(widget);
    button->label("this is a button");
    button->resize(60, 150, 140, 30);
    button->redraw();
}

int main(int argc, char** argv){
    Fl_Window win(300, 200, "fltk windows");
    win.begin();
    Fl_Button bt(10, 150, 70, 30, "click me");
    win.end();
    bt.callback(button_cb);
    win.show();

    return Fl::run();
}