
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <iostream>
using namespace std;

class MyButton : public Fl_Button {
public:
    static int m_cout;
public: 
    MyButton(int x, int y, int w, int h, const char* t = 0)
        :Fl_Button(x, y, w, h, t) {

    }

    ~MyButton() {

    }

    int handle(int e) {
        int ret = Fl_Button::handle(e);
        cout << endl << m_cout++ << " ***** button " << label() 
             << "receives ";
        switch(e) {
            case FL_PUSH:
                cout << "psuh" << " event and returns: " << ret << endl;
            break;

            case FL_RELEASE:
                cout << "release" << " event and returns: " << ret << endl;
            break;

            case FL_ENTER:
                color(FL_CYAN);
                cout << "enter" << " event and returns: " << ret << endl;
                redraw();
            break;

            case FL_LEAVE:
                color(FL_BACKGROUND_COLOR);
                cout << "leave" << " event and returns: " << ret << endl;
                redraw();
            break;

            case FL_DRAG:
                cout << "drag" << " event and returns: " << ret << endl;
            break;

            case FL_FOCUS:
                cout << "focus" << " event and returns: " << ret << endl;
            break;

            case FL_UNFOCUS:
                cout << "unfocus" << " event and returns: " << ret << endl;
            break;

            case FL_KEYDOWN:
                cout << "keydown" << " event and returns: " << ret << endl;
            break;

            case FL_KEYUP:
                if(Fl::event_key() == shortcut()) {
                    box(FL_UP_BOX);
                    redraw();
                    ret = 1; // return handled so keyup event stops
                             // being sent to ALL other buttons uneccessarily
                }
                cout << "keyup" << " event and returns: " << ret << endl;
            break;

            case FL_CLOSE:
                cout << "close" << " event and returns: " << ret << endl;
            break;

            case FL_MOVE:
                cout << "move" << " event and returns: " << ret << endl;
            break;

            case FL_SHORTCUT:
                if(Fl::event_key() == shortcut()) {
                    box(FL_DOWN_BOX);
                    redraw();
                }
                cout << "shortcut" << " event and returns: " << ret << endl;
            break;

            case FL_ACTIVATE:
                cout << "activate" << " event and returns: " << ret << endl;
            break;

            case FL_HIDE:
                cout << "hide" << " event and returns: " << ret << endl;
            break;

            case FL_SHOW:
                cout << "show" << " event and returns: " << ret << endl;
            break;

            case FL_PASTE:
                cout << "paste" << " event and returns: " << ret << endl;
            break;
    
            case FL_SELECTIONCLEAR:
                cout << "selectionclear" << " event and returns: " << ret << endl;
            break;

            case FL_MOUSEWHEEL:
                cout << "mousewheel" << " event and returns: " << ret << endl;
            break;

            case FL_NO_EVENT:
                cout << "no event" << " event and returns: " << ret << endl;
            break;
        }    

        return ret;
    }

};

int MyButton::m_cout = 0;

void but_a_cb(Fl_Widget* w, void* v) {
    cout << endl << "Button A callback" << endl;
}

void but_b_cb(Fl_Widget* w, void* v) {
    cout << endl << "Button B callback" << endl;
}

void but_c_cb(Fl_Widget* w, void* v) {
    cout << endl << "Button C callback" << endl;
}

int main(int argc, char * argv[]) {

    Fl_Window win(120, 150);
    win.begin();

    MyButton but_a(10, 10, 100, 25, "A");
    but_a.shortcut('a');
    but_a.callback(but_a_cb);

    MyButton but_b(10, 50, 100, 25, "B");
    but_b.shortcut('b');
    but_b.callback(but_b_cb);

    MyButton but_c(10, 90, 100, 25, "C");
    but_c.shortcut('c');
    but_b.callback(but_c_cb);

    win.end();
    win.show();

    return Fl::run();
}

/**
 * @see http://www.cppblog.com/cyantree/archive/2012/05/13/174761.html
 * 
 */