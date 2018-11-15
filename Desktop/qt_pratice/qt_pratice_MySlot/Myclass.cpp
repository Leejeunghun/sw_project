#include <QApplication>
#include <QPushButton>
class MyClass: public QWidget
{
  public:
    MyClass();
};

MyClass::MyClass()
{
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
