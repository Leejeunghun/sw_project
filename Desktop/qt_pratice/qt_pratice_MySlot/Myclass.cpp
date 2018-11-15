#include <QApplication>
#include <QPushButton>
#include<unistd.h>
#include <iostream>

#include <fstream>

using namespace std;

class MyClass: public QWidget
{
  public:
    MyClass();
};

MyClass::MyClass()
{
    ofstream output("output.txt");

    output << "test" << endl;

    output.close();
    QPushButton *quit=new QPushButton("Quit",this);
    quit->resize(75,35);
    

    QObject::connect(quit,SIGNAL(clicked()),qApp,SLOT(quit()));
}

int main(int argc,char **argv)
{
    QApplication app(argc,argv);
    MyClass *quit=new MyClass();
    quit->show();
    return app.exec();

}
