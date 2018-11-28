#include <QApplication>
#include <QPushbutton>
#include "MySlotQuit.h"

#include "MySlotQuit.moc"

MyClass::MyClass()
{
    QPushButton *quit =new QPush Button("Quit",this);
    quit->resize(75,35);
    QOBject::connect(quit,SIGNAL(clicked()),SLOT(slotQuit()));
}

void MyClass::slotQuit()
{
   qApp->quit();
}

int main(int argc,char **argv)
{
    QApplication app(argc,argv);
    MyClass *quit=new MyClass();
    quit ->show();
   return app.exec();


}
