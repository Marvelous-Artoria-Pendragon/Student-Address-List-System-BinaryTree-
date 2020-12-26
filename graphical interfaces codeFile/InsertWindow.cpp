#include "InsertWindow.h"
#include "ui_insertwindow.h"
#include <QRegExpValidator>
#include <QMessageBox>
#include <QDebug>

InsertWindow::InsertWindow(CompleteBinaryTree<Student> *c, QWidget *parent) : QDialog(parent), ui(new Ui::InsertWindow), bt(c)
{
    ui->setupUi(this);
    QWidget::setFixedSize(450, 300);    //设置固定宽高
    QRegExp rxNumber("\\d+$");
    QRegExp rxChar("[^0-9]+$");
    QRegExpValidator *number_validator = new QRegExpValidator(rxNumber);
    QRegExpValidator *char_validator = new QRegExpValidator(rxChar);
    //设置合法输入
    ui->lineEdit_name->setValidator(char_validator);
    ui->lineEdit_phonenum->setValidator(number_validator);
    ui->lineEdit_number->setValidator(number_validator);
    ui->lineEdit_addr->setValidator(char_validator);
}

InsertWindow::~InsertWindow()
{
    delete ui;
}

void InsertWindow::on_pushButton_insert_clicked()
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
        Student stu;
        strcpy_s(stu.name, ui->lineEdit_name->text().toUtf8().data());
        strcpy_s(stu.number, ui->lineEdit_number->text().toUtf8().data());
        strcpy_s(stu.sex, ui->comboBox_sex->currentText().toUtf8().data());
        QString strYear = ui->dateEdit_birthday->sectionText(QDateEdit::YearSection);
        QString strMonth = ui->dateEdit_birthday->sectionText(QDateEdit::MonthSection);
        QString strDay = ui->dateEdit_birthday->sectionText(QDateEdit::DaySection);
        stu.birthday = strYear.toInt();
        stu.birthday = (stu.birthday << 4) + strMonth.toInt();
        stu.birthday = (stu.birthday << 5) + strDay.toInt();
        strcpy_s(stu.phonenum, ui->lineEdit_phonenum->text().toUtf8().data());
        strcpy_s(stu.addr, ui->lineEdit_addr->text().toUtf8().data());
        bt->insert(stu);
        QMessageBox::information(NULL, "提示", "插入成功！");
    }
}

void InsertWindow::on_pushButton_cancel_clicked()
{
    this->close();
}
