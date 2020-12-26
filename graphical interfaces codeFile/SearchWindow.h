#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include <QDialog>
#include "Student.h"
#include "CompleteBinaryTree.h"
namespace Ui {
class SearchWindow;
}

class SearchWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SearchWindow(CompleteBinaryTree<Student> *c , QWidget *parent = nullptr);
    ~SearchWindow();

private slots:
    void on_pushButton_search_clicked();

    void on_pushButton_del_clicked();

    void on_pushButton_close_clicked();

private:
    Ui::SearchWindow *ui;
    CompleteBinaryTree<Student> *bt;
    BinTreeNode<Student> *temp;
};

#endif // SEARCHWINDOW_H
