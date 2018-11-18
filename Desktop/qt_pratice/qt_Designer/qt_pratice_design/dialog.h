#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFile>
#include <QTextStream>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_pressed();

    void on_spinBox_editingFinished();

    void on_textEdit_2_textChanged();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
