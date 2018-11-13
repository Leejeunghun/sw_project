#include <QApplication>
#include <QLabel>

int main(int argc, char **argv)
{
    QApplication app(argc,argv);
    QLabel *hello = new QLabel("<font color= blue>HELLO <i>QT!</i>""</font>",0);
    
    hello->resize(75,350);
    hello->show();
    return app.exec();


}
