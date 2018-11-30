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
    QPushButton *pushButton_Raise;
    QPushButton *pushButton_commit;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QPushButton *pushButton_Down;
    QLCDNumber *lcdNumber_bet;
    QLCDNumber *lcdNumber_coin;
    QLCDNumber *lcdNumber_random;
    QLabel *label_beting;
    QLabel *label_OppentCard;
    QLabel *label_Coin;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(468, 346);
        gridLayoutWidget = new QWidget(Dialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(60, 210, 281, 101));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_Raise = new QPushButton(gridLayoutWidget);
        pushButton_Raise->setObjectName(QStringLiteral("pushButton_Raise"));

        gridLayout->addWidget(pushButton_Raise, 0, 0, 1, 1);

        pushButton_commit = new QPushButton(gridLayoutWidget);
        pushButton_commit->setObjectName(QStringLiteral("pushButton_commit"));

        gridLayout->addWidget(pushButton_commit, 0, 2, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 1, 0, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        pushButton_Down = new QPushButton(gridLayoutWidget);
        pushButton_Down->setObjectName(QStringLiteral("pushButton_Down"));

        gridLayout->addWidget(pushButton_Down, 0, 1, 1, 1);

        lcdNumber_bet = new QLCDNumber(Dialog);
        lcdNumber_bet->setObjectName(QStringLiteral("lcdNumber_bet"));
        lcdNumber_bet->setGeometry(QRect(40, 100, 111, 71));
        lcdNumber_coin = new QLCDNumber(Dialog);
        lcdNumber_coin->setObjectName(QStringLiteral("lcdNumber_coin"));
        lcdNumber_coin->setGeometry(QRect(320, 20, 111, 31));
        lcdNumber_random = new QLCDNumber(Dialog);
        lcdNumber_random->setObjectName(QStringLiteral("lcdNumber_random"));
        lcdNumber_random->setGeometry(QRect(210, 102, 131, 61));
        label_beting = new QLabel(Dialog);
        label_beting->setObjectName(QStringLiteral("label_beting"));
        label_beting->setGeometry(QRect(50, 60, 101, 31));
        label_OppentCard = new QLabel(Dialog);
        label_OppentCard->setObjectName(QStringLiteral("label_OppentCard"));
        label_OppentCard->setGeometry(QRect(210, 60, 111, 31));
        label_Coin = new QLabel(Dialog);
        label_Coin->setObjectName(QStringLiteral("label_Coin"));
        label_Coin->setGeometry(QRect(336, 0, 101, 21));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        pushButton_Raise->setText(QApplication::translate("Dialog", "Raise", nullptr));
        pushButton_commit->setText(QApplication::translate("Dialog", "Commit", nullptr));
        pushButton_4->setText(QApplication::translate("Dialog", "Random", nullptr));
        pushButton->setText(QApplication::translate("Dialog", "Bet", nullptr));
        pushButton_Down->setText(QApplication::translate("Dialog", "Down", nullptr));
        label_beting->setText(QApplication::translate("Dialog", "Betting coin", nullptr));
        label_OppentCard->setText(QApplication::translate("Dialog", "Oppent Card", nullptr));
        label_Coin->setText(QApplication::translate("Dialog", "Your coin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
