#include "SearchWindow.h"
#include "ui_searchwindow.h"
#include <QMessageBox>
#include <string.h>

SearchWindow::SearchWindow(CompleteBinaryTree<Student> *c, QWidget *parent) : QDialog(parent), ui(new Ui::SearchWindow),
    bt(c), temp(NULL)
{
    ui->setupUi(this);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);           //选中整行
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);          //只能单选
}

SearchWindow::~SearchWindow()
{
    delete ui;
}

void SearchWindow::on_pushButton_search_clicked()
{

    ui->tableWidget->clearContents(); ui->tableWidget->setRowCount(0);
    if (bt->isEmpty()) {QMessageBox::critical(NULL, "错误", "当前未有任何通讯录记录！"); return;}
    if (ui->lineEdit_info->text().isEmpty()) {QMessageBox::critical(NULL, "错误", "输入信息为空！"); return;}
    char info[3][21];
    ui->buttonGroup->setId(ui->radioButton_number, 0);
    ui->buttonGroup->setId(ui->radioButton_name, 1);
    ui->buttonGroup->setId(ui->radioButton_phonenum, 2);

    int index = ui->buttonGroup->checkedId();
    if (index < 0) {QMessageBox::critical(NULL, "错误！", "请选择一种显示方式！"); return;}
    strcpy(info[index], ui->lineEdit_info->text().toUtf8().data());
//    BinTreeNode<Student> *temp = NULL;
    temp = bt->find(info[index]);
//    switch(index)
//    {
//    case 0: {
//        auto cmp1 = [&](const Student &item) {return strcmp(item.number, info[index]) ? false : true;};
//        temp = bt->find(cmp1); break;
//    }
//    case 1: {
//        auto cmp2 = [&](const Student &item) {return strcmp(item.name, info[index]) ? false : true;};
//        temp = bt->find(cmp2); break;
//    }
//    case 2: {
//        auto cmp3 = [&](const Student &item) {return strcmp(item.phonenum, info[index]) ? false : true;};
//        temp = bt->find(cmp3); break;
//    }
//    }

    if (temp != NULL)
    {
        ui->tableWidget->insertRow(0);

        ui->tableWidget->setItem(0, 0, new QTableWidgetItem(QString::fromUtf8(temp->data.name)));
        ui->tableWidget->setItem(0, 1, new QTableWidgetItem(QString::fromUtf8(temp->data.number)));
        ui->tableWidget->setItem(0, 2, new QTableWidgetItem(QString::fromUtf8(temp->data.sex)));
        QString birthday = QString::number(temp->data.birthday >> 9) + "/"
                + QString::number(temp->data.birthday << 23 >> 28) + "/"
                + QString::number(temp->data.birthday << 27 >> 27);
        ui->tableWidget->setItem(0, 3, new QTableWidgetItem(birthday));
        ui->tableWidget->setItem(0, 4, new QTableWidgetItem(QString::fromUtf8(temp->data.phonenum)));
        ui->tableWidget->setItem(0, 5, new QTableWidgetItem(QString::fromUtf8(temp->data.addr)));
    }
    else QMessageBox::warning(NULL, "错误", "当前未找到任何记录！");
}
void SearchWindow::on_pushButton_del_clicked()
{
    if (temp == NULL) QMessageBox::critical(NULL, "错误", "当前未查找到任何通讯录记录！");
    else if(bt->remove(temp->data)) {temp = NULL; QMessageBox::information(NULL, "提示", "删除成功！");}
}

void SearchWindow::on_pushButton_close_clicked()
{
    this->close();
}
