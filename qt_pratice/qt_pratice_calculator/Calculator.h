#include <QPushButton>
#include <QVBoxLayout>
#include <QGrdLayout>
#include <QLabel>

class Calculator : pulic QWidget{
    Q_OBJECT
    public:
    calculator(QWidget *parent =0);

    private:
        QPushButton *pushbutton[16];
	Qlabel *m_OutLabel;
	QString number1;
	QString number2;
	QString output;

	char flag;
	char operate;

	public slot:
	void click_0();
        void click_1();
	void click_2();
	void click_3();
	void click_4();
	void click_5();
	void click_6();
	void click_7();
	void click_8();
	void click_9();
	void click_10();
	void click_11();
	void click_12();
	void click_13();
        void click_14();
	void click_15();
	};


