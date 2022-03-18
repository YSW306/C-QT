#include "smallwidget.h"
#include "ui_smallwidget.h"

Smallwidget::Smallwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Smallwidget)
{
    ui->setupUi(this);
    void (QSpinBox:: * spinSignal)(int) = &QSpinBox::valueChanged;
    //Qspinbox移动 Qslider跟着移动
    connect(ui->spinBox,spinSignal,ui->horizontalSlider,&QSlider::setValue);
    //QSlider移动 Qspinbox跟着移动
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);

}

void Smallwidget::setData(int val){
    ui->spinBox->setValue(val);
}
int Smallwidget::getData(){

    return ui->spinBox->value();
}



Smallwidget::~Smallwidget()
{
    delete ui;
}
