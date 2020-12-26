#include "Menu.h"
#include "ui_menu.h"
#include "CreateWindow.h"
#include "InsertWindow.h"
#include "DisplayWindow.h"
#include "SearchWindow.h"
#include <QFileDialog>
#include <QMessageBox>

Menu::Menu(QWidget *parent): QMainWindow(parent), ui(new Ui::Menu), bt(new CompleteBinaryTree<Student>)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}


void Menu::on_create_triggered()
{
   CreateWindow *createUi = new CreateWindow(bt);
   createUi->show();
}

void Menu::on_insert_triggered()
{
    InsertWindow *insertUi = new InsertWindow(bt);
    insertUi->show();
}

void Menu::on_readFromFile_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(NULL, "选择读取路径", "./*.dat", "*.dat");
    if (bt->load(file_name.toUtf8().data())) QMessageBox::information(NULL, "提示", "读取成功！");
    else QMessageBox::critical(NULL, "错误", "文件读取失败!\n请检查文件路径或文件是否为正确的格式！");
}

void Menu::on_writeToFile_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(NULL, "选择存储路径", "./未命名", "*.dat");
    if (bt->save(file_name.toUtf8().data())) QMessageBox::information(NULL, "提示", "写入成功！");
    else QMessageBox::critical(NULL, "错误", "文件读取失败!\n请检查文件路径或通讯录是否为空！");
}

void Menu::on_display_triggered()
{
    DisplayWindow *displayUi = new DisplayWindow(bt);
    displayUi->show();
}

void Menu::on_search_triggered()
{
    SearchWindow *searchUi = new SearchWindow(bt);
    searchUi->show();
}

void Menu::on_remove_triggered()
{
    SearchWindow *delUi = new SearchWindow(bt);
    delUi->show();
}

void Menu::on_youngest_triggered()
{
    DisplayWindow *displayYoungestStuUi = new DisplayWindow(bt);
    displayYoungestStuUi->show();
}
