#include <QApplication>
#include <QLCDNumber>

int main(int argc, char **argv)
{
  QApplication app(argc,argv);

  QLCDNumber *lcd = new QLCDNumber();
  lcd->setDecMode();
  lcd->setSegmentStyle(QLCDNumber::Flat);
  lcd->display(2007);
  lcd->show();
  return app.exec();

}
