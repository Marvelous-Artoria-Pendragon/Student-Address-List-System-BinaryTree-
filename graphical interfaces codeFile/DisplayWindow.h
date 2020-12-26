#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QDialog>
#include "Student.h"
#include "CompleteBinaryTree.h"
namespace Ui {
class DisplayWindow;
}

class DisplayWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DisplayWindow(CompleteBinaryTree<Student> *c, QWidget *parent = nullptr);
    ~DisplayWindow();

private slots:
    void on_pushButton_display_clicked();

    void on_pushButton_YoungestStu_clicked();

private:
    Ui::DisplayWindow *ui;
    CompleteBinaryTree<Student> *bt;

};

#endif // DISPLAYWINDOW_H
