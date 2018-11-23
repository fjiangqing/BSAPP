#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //加载图片
    QPixmap pixmap("copy-get-123.png");
    //设置显示图片
    ui->label->setPixmap(pixmap);
    ui->label->show();

}

Dialog::~Dialog()
{
    delete ui;
}
