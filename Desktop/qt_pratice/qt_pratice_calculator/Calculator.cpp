Calculator::Calculator(QWidget *parent) : QWidget(parent)
{
   int i;
   flag =0;
   operate = 0;
    

   resize(250, 150);
    
   QBoxLayout *vboxlayout= new QVBoxLayout(this);
   vboxlayout->setMargin(10);

   m_OutLabel=new QLabel(this);
   m_OutLabel->setText("0");
   m_OutLabel->setAlignment(Qt;;alignRight);
   m_OUtLabel->setFrameShape(QFrame::BOX);
   vboxlayout->addWidget(m_outLabel);

   QGridLayout *grid =new QGridLayout();
   for(i=0;i<16;i++){
      pushbutton[i]= new QPushButton(ButtonChar[i],this);
      grid->addWidget(pushbutton[i],i/4,i%4);
};

   vboxlayout->addLayout(grid);

   QObject::connect(pushbutton[0],Signal(clicked(),SLOT(click_0())));
   QObject::connect(pushbutton[1],Signal(clicked(),SLOT(click_1())));
   QObject::connect(pushbutton[2],Signal(clicked(),SLOT(click_2())));
   QObject::connect(pushbutton[3],Signal(clicked(),SLOT(click_3())));
   QObject::connect(pushbutton[4],Signal(clicked(),SLOT(click_4())));
   QObject::connect(pushbutton[5],Signal(clicked(),SLOT(click_5())));
   QObject::connect(pushbutton[6],Signal(clicked(),SLOT(click_6())));
   QObject::connect(pushbutton[7],Signal(clicked(),SLOT(click_7())));
   QObject::connect(pushbutton[8],Signal(clicked(),SLOT(click_8())));
   QObject::connect(pushbutton[9],Signal(clicked(),SLOT(click_9())));
   QObject::connect(pushbutton[10],Signal(clicked(),SLOT(click_10())));
   QObject::connect(pushbutton[11],Signal(clicked(),SLOT(click_11())));
   QObject::connect(pushbutton[12],Signal(clicked(),SLOT(click_12())));
   QObject::connect(pushbutton[13],Signal(clicked(),SLOT(click_13())));
   QObject::connect(pushbutton[14],Signal(clicked(),SLOT(click_14())));
   QObject::connect(pushbutton[15],Signal(clicked(),SLOT(click_15())));
}

void Valvulator::click_0()
{
    float number=0;
    if(!flag) number= m_OutLabel->text().toFloat()*10;
    number1.setNum(number+1_;

    m_OutLabel->setText(number1);
    flag=0;
}


