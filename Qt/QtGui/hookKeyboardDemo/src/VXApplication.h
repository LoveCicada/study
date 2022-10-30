
#pragma once
#include <QApplication>
#include <QKeyEvent>

class VXApplication : public QApplication
{
	Q_OBJECT
public:
    
#ifdef Q_QDOC
    VXApplication::VXApplication(int& argc, char** argv)
        :QApplication(argc, argv)
    {

    }
#else
    VXApplication::VXApplication(int& argc, char** argv, int flag = ApplicationFlags)
        : QApplication(argc, argv, flag)
    {
        //connect(this, &VXApplication::signal_keyPress, &w, &MainWindow::slot_keyPressed);
    }
#endif

    VXApplication::~VXApplication()
    {

    }

    bool VXApplication::notify(QObject* obj, QEvent* event)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (!keyNumberPress(keyEvent))
            {
                //emit signal_keyPress(keyEvent);
                return true;
            }
        }
        else if (event->type() == QEvent::KeyRelease)
        {
            return true;
        }

        return QApplication::notify(obj, event);
    }


    bool VXApplication::keyNumberPress(QKeyEvent* keyEvent)
    {
        if (keyEvent->key() == Qt::Key_Tab
            || keyEvent->key() == Qt::Key_Super_L
            || keyEvent->key() == Qt::Key_Super_R)
        {
            return true;
        }

        return false;
    }


};
