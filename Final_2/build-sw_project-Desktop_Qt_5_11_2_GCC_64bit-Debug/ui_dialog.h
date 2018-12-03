/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_commit;
    QPushButton *pushButton_Raise;
    QPushButton *pushButton_Down;
    QPushButton *pushButton_Random;
    QPushButton *pushButton_Bet;
    QLCDNumber *lcdNumber_bet;
    QLCDNumber *lcdNumber_random;
    QLCDNumber *lcdNumber_coin;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(400, 300);
        gridLayoutWidget = new QWidget(Dialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 210, 281, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_commit = new QPushButton(gridLayoutWidget);
        pushButton_commit->setObjectName(QStringLiteral("pushButton_commit"));

        gridLayout->addWidget(pushButton_commit, 0, 2, 1, 1);

        pushButton_Raise = new QPushButton(gridLayoutWidget);
        pushButton_Raise->setObjectName(QStringLiteral("pushButton_Raise"));

        gridLayout->addWidget(pushButton_Raise, 0, 0, 1, 1);

        pushButton_Down = new QPushButton(gridLayoutWidget);
        pushButton_Down->setObjectName(QStringLiteral("pushButton_Down"));

        gridLayout->addWidget(pushButton_Down, 0, 1, 1, 1);

        pushButton_Random = new QPushButton(gridLayoutWidget);
        pushButton_Random->setObjectName(QStringLiteral("pushButton_Random"));

        gridLayout->addWidget(pushButton_Random, 1, 0, 1, 1);

        pushButton_Bet = new QPushButton(gridLayoutWidget);
        pushButton_Bet->setObjectName(QStringLiteral("pushButton_Bet"));

        gridLayout->addWidget(pushButton_Bet, 1, 1, 1, 1);

        lcdNumber_bet = new QLCDNumber(Dialog);
        lcdNumber_bet->setObjectName(QStringLiteral("lcdNumber_bet"));
        lcdNumber_bet->setGeometry(QRect(3, 100, 91, 81));
        lcdNumber_random = new QLCDNumber(Dialog);
        lcdNumber_random->setObjectName(QStringLiteral("lcdNumber_random"));
        lcdNumber_random->setGeometry(QRect(220, 80, 111, 91));
        lcdNumber_random->setFrameShape(QFrame::NoFrame);
        lcdNumber_coin = new QLCDNumber(Dialog);
        lcdNumber_coin->setObjectName(QStringLiteral("lcdNumber_coin"));
        lcdNumber_coin->setGeometry(QRect(300, 32, 81, 31));
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 70, 81, 20));
        QFont font;
        font.setPointSize(13);
        label->setFont(font);
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(300, 6, 101, 21));
        label_2->setFont(font);
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, -10, 211, 71));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/title.PNG")));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(230, 70, 181, 231));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/player.PNG")));
        label_4->raise();
        gridLayoutWidget->raise();
        lcdNumber_bet->raise();
        lcdNumber_random->raise();
        lcdNumber_coin->raise();
        label->raise();
        label_2->raise();
        label_3->raise();

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        pushButton_commit->setText(QApplication::translate("Dialog", "commit", nullptr));
        pushButton_Raise->setText(QApplication::translate("Dialog", "Raise", nullptr));
        pushButton_Down->setText(QApplication::translate("Dialog", "Down", nullptr));
        pushButton_Random->setText(QApplication::translate("Dialog", "Random", nullptr));
        pushButton_Bet->setText(QApplication::translate("Dialog", "Bet", nullptr));
        label->setText(QApplication::translate("Dialog", "BET coin", nullptr));
        label_2->setText(QApplication::translate("Dialog", "Total coin", nullptr));
        label_3->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
