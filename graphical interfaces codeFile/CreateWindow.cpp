#include "CreateWindow.h"
#include "ui_createwindow.h"
#include <QMessageBox>
#include <QRegExpValidator>
#include <QDebug>

CreateWindow::CreateWindow(CompleteBinaryTree<Student> *c, QWidget *parent) : QDialog(parent), ui(new Ui::CreateWindow), bt(c)
{
    ui->setupUi(this);
    QWidget::setFixedSize(1035, 620);    //设置固定宽高
    QRegExp rxNumber("\\d+$");
    QRegExp rxChar("[^0-9]+$");
    QRegExpValidator *number_validator = new QRegExpValidator(rxNumber);
    QRegExpValidator *char_validator = new QRegExpValidator(rxChar);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);           //选中整行
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);          //只能单选
    //设置合法输入
    ui->lineEdit_name->setValidator(char_validator);
    ui->lineEdit_phonenum->setValidator(number_validator);
    ui->lineEdit_number->setValidator(number_validator);
    ui->lineEdit_addr->setValidator(char_validator);

}

CreateWindow::~CreateWindow()
{
    delete ui;
}

void CreateWindow::on_pushButton_append_clicked()
{
    if (ui->lineEdit_name->text().isEmpty() |
            ui->comboBox_sex->currentText().isEmpty() |
            ui->lineEdit_number->text().isEmpty() |
            ui->dateEdit_birthday->text().isEmpty() |
            ui->lineEdit_phonenum->text().isEmpty() |
            ui->lineEdit_addr->text().isEmpty())
         QMessageBox::warning(NULL, "提示", "填入信息不能为空!");
    else
    {
//        int col = ui->tableWidget->columnCount();
        int row = ui->tableWidget->rowCount();                      //当前行数
        ui->tableWidget->insertRow(row);                            //插入最后一个
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(ui->lineEdit_name->text()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(ui->lineEdit_number->text()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(ui->comboBox_sex->currentText()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(ui->dateEdit_birthday->text()));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(ui->lineEdit_phonenum->text()));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(ui->lineEdit_addr->text()));
    }
}

void CreateWindow::on_pushButton_remove_clicked()
{
    QTableWidgetItem *item = ui->tableWidget->currentItem();
    if (item == Q_NULLPTR) return;
    ui->tableWidget->removeRow(item->row());
}

void CreateWindow::on_pushButton_confirm_clicked()
{
    int row = ui->tableWidget->rowCount();
    Student *stu = new Student[row]();

    for (int i = 0; i < row; i++)
    {
        strcpy_s(stu[i].name, ui->tableWidget->item(i, 0)->text().toUtf8().data());
        strcpy_s(stu[i].number, ui->tableWidget->item(i, 1)->text().toUtf8().data());
        strcpy_s(stu[i].sex, ui->tableWidget->item(i,2)->text().toUtf8().data());

        QRegExp r("(\\d+)/(\\d+)/(\\d+)");
        int pos = r.indexIn(ui->tableWidget->item(i, 3)->text());                   //使用正则获取匹配的年、月、日
        if (pos < 0) {qDebug() << pos; exit(1);}
        stu[i].birthday = r.cap(1).toInt();                                      //年份
        stu[i].birthday = (stu[i].birthday << 4) + r.cap(2).toInt();             //月份
        stu[i].birthday = (stu[i].birthday << 5) + r.cap(3).toInt();             //日期

        strcpy_s(stu[i].phonenum, ui->tableWidget->item(i, 4)->text().toUtf8().data());
        strcpy_s(stu[i].addr, ui->tableWidget->item(i, 5)->text().toUtf8().data());
    }
    bt->CreateBinTree(stu, row);
    QMessageBox::information(NULL, "提示", "创建成功!");
    this->close();
}

void CreateWindow::on_pushButton_cancel_clicked()
{
    this->close();
}
