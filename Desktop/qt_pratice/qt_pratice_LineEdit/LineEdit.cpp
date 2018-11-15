#include <QApplication>
#include <QLineEdit>

int main (int argc, char **argv)
{
    QApplication app(argc,argv);
    QLineEdit *LE=new QLineEdit(0);

    LE->setEchoMode(QLineEdit::Normal);//Password ,Normal NoEcho
    LE->show();
    return app.exec();

}
