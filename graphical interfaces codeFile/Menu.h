#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "CompleteBinaryTree.h"
#include "Student.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Menu; }
QT_END_NAMESPACE

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_create_triggered();

    void on_insert_triggered();

    void on_readFromFile_triggered();

    void on_writeToFile_triggered();

    void on_display_triggered();

    void on_search_triggered();

    void on_remove_triggered();

    void on_youngest_triggered();

private:
    Ui::Menu *ui;
    CompleteBinaryTree<Student> *bt;
};
#endif // MENU_H
