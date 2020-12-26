#include "DisplayWindow.h"
#include "ui_displaywindow.h"
#include <QMessageBox>
#include "Queue.h"

DisplayWindow::DisplayWindow(CompleteBinaryTree<Student> *c, QWidget *parent) : QDialog(parent), ui(new Ui::DisplayWindow), bt(c)
{
    ui->setupUi(this);
}

DisplayWindow::~DisplayWindow()
{
    delete ui;
}

void DisplayWindow::on_pushButton_display_clicked()
{
    ui->tableWidget->clearContents(); ui->tableWidget->setRowCount(0);                //显示前先清空行
    auto show = [&](BinTreeNode<Student> *current){
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);                            //插入最后一个
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromUtf8(current->data.name)));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromUtf8(current->data.number)));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::fromUtf8(current->data.sex)));
        QString birthday = QString::number(current->data.birthday >> 9) + "/"
                + QString::number(current->data.birthday << 23 >> 28) + "/"
                + QString::number(current->data.birthday << 27 >> 27);
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(birthday));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(QString::fromUtf8(current->data.phonenum)));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(QString::fromUtf8(current->data.addr)));};
    if (ui->radioButton_preOrder->isChecked()) bt->preOrder(show);
    else if (ui->radioButton_inOrder->isChecked()) bt->inOrder(show);
    else if (ui->radioButton_postOrder->isChecked()) bt->postOrder(show);
    else QMessageBox::critical(NULL, "错误！", "请选择一种显示方式！");
}

void DisplayWindow::on_pushButton_YoungestStu_clicked()
{
    ui->tableWidget->clearContents(); ui->tableWidget->setRowCount(0);
    if (bt->isEmpty()) {QMessageBox::critical(NULL, "错误", "当前未有任何记录！"); return;}
    BinTreeNode<Student> *root = bt->getRoot(), *temp = NULL, *youngest = root;             //根结点和年龄最小的学生所在结点
    LinkedQueue<BinTreeNode<Student> *> Q; Q.EnQueue(root);
    while (!Q.isEmpty())
    {
        Q.DeQueue(temp);
        for (unsigned i = 0; i < 3; i++)
            if (temp->data.birthday <= youngest->data.birthday) break;      //年长，直接跳过
            else if (temp->data.birthday > youngest->data.birthday) {youngest = temp; break;} //依次比较年、月、日
        if (temp->child[0] != NULL) Q.EnQueue(temp->child[0]);                    //左子女进队
        if (temp->child[1] != NULL) Q.EnQueue(temp->child[1]);                    //右子女进队
    }
    ui->tableWidget->insertRow(0);
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem(QString::fromUtf8(youngest->data.name)));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem(QString::fromUtf8(youngest->data.number)));
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem(QString::fromUtf8(youngest->data.sex)));
    QString birthday = QString::number(youngest->data.birthday >> 9) + "/"
            + QString::number(youngest->data.birthday << 23 >> 28) + "/"
            + QString::number(youngest->data.birthday << 27 >> 27);
    ui->tableWidget->setItem(0, 3, new QTableWidgetItem(birthday));
    ui->tableWidget->setItem(0, 4, new QTableWidgetItem(QString::fromUtf8(youngest->data.phonenum)));
    ui->tableWidget->setItem(0, 5, new QTableWidgetItem(QString::fromUtf8(youngest->data.addr)));
}
