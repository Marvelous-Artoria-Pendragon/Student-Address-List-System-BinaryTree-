#ifndef CREATEWINDOW_H
#define CREATEWINDOW_H

#include <QDialog>
#include "CompleteBinaryTree.h"
#include "Student.h"

namespace Ui {
class CreateWindow;
}

class CreateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CreateWindow(CompleteBinaryTree<Student> *c, QWidget *parent = nullptr);
    ~CreateWindow();

private slots:
    void on_pushButton_append_clicked();

    void on_pushButton_remove_clicked();

    void on_pushButton_confirm_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::CreateWindow *ui;
    CompleteBinaryTree<Student> *bt;
};

#endif // CREATEWINDOW_H
