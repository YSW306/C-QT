#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    //设置按钮
    connect(ui->btn_set,&QPushButton::clicked,[=](){
        ui->widget->setData(50);
    });

    //获取按钮
    connect(ui->btn_get,&QPushButton::clicked,[=](){
        qDebug()<<ui->widget->getData();
    });
}

Widget::~Widget()
{
    delete ui;
}

