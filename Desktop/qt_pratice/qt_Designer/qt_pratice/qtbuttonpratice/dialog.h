#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void SignSlot();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
public slots:
     void action();
};

#endif // DIALOG_H
