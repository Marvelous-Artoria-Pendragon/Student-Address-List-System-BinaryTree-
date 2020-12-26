#ifndef INSERTWINDOW_H
#define INSERTWINDOW_H

#include <QDialog>
#include "Student.h"
#include "CompleteBinaryTree.h"

namespace Ui {
class InsertWindow;
}

class InsertWindow : public QDialog
{
    Q_OBJECT

public:
    explicit InsertWindow(CompleteBinaryTree<Student> *c, QWidget *parent = nullptr);
    ~InsertWindow();

private slots:
    void on_pushButton_insert_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::InsertWindow *ui;
    CompleteBinaryTree<Student> *bt;
};

#endif // INSERTWINDOW_H
