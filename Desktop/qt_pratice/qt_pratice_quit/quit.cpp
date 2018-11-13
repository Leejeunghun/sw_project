#include <QApplication>
#include <QLabel>
#include <QPushButton>
int main(int argc, char **argv)
{
    QApplication app(argc,argv);
    QPushButton *quit = new QPushButton("Quit",0);
    quit->resize(75,35);
    quit->show();
    QObject::connect(quit,SIGNAL(clicked()),&app,SLOT(quit()));
    
    return app.exec();


}
