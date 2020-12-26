/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QAction *create;
    QAction *insert;
    QAction *search;
    QAction *youngest;
    QAction *readFromFile;
    QAction *writeToFile;
    QAction *display;
    QAction *remove;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->resize(525, 371);
        create = new QAction(Menu);
        create->setObjectName(QString::fromUtf8("create"));
        create->setCheckable(false);
        insert = new QAction(Menu);
        insert->setObjectName(QString::fromUtf8("insert"));
        search = new QAction(Menu);
        search->setObjectName(QString::fromUtf8("search"));
        youngest = new QAction(Menu);
        youngest->setObjectName(QString::fromUtf8("youngest"));
        readFromFile = new QAction(Menu);
        readFromFile->setObjectName(QString::fromUtf8("readFromFile"));
        writeToFile = new QAction(Menu);
        writeToFile->setObjectName(QString::fromUtf8("writeToFile"));
        display = new QAction(Menu);
        display->setObjectName(QString::fromUtf8("display"));
        remove = new QAction(Menu);
        remove->setObjectName(QString::fromUtf8("remove"));
        centralwidget = new QWidget(Menu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Menu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Menu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 525, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        Menu->setMenuBar(menubar);
        statusbar = new QStatusBar(Menu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Menu->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(create);
        menu->addAction(insert);
        menu->addAction(search);
        menu->addAction(display);
        menu->addAction(remove);
        menu->addAction(youngest);
        menu_2->addAction(readFromFile);
        menu_2->addAction(writeToFile);

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QMainWindow *Menu)
    {
        Menu->setWindowTitle(QCoreApplication::translate("Menu", "\345\255\246\347\224\237\351\200\232\350\256\257\345\275\225\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        create->setText(QCoreApplication::translate("Menu", "\346\226\260\345\273\272", nullptr));
        insert->setText(QCoreApplication::translate("Menu", "\346\217\222\345\205\245", nullptr));
        search->setText(QCoreApplication::translate("Menu", "\346\237\245\346\211\276", nullptr));
        youngest->setText(QCoreApplication::translate("Menu", "\350\276\223\345\207\272\345\271\264\351\276\204\346\234\200\345\260\217\347\232\204\345\255\246\347\224\237", nullptr));
        readFromFile->setText(QCoreApplication::translate("Menu", "\350\257\273\345\217\226", nullptr));
        writeToFile->setText(QCoreApplication::translate("Menu", "\345\206\231\345\207\272", nullptr));
        display->setText(QCoreApplication::translate("Menu", "\346\230\276\347\244\272\346\211\200\346\234\211\344\277\241\346\201\257", nullptr));
        remove->setText(QCoreApplication::translate("Menu", "\345\210\240\351\231\244", nullptr));
        menu->setTitle(QCoreApplication::translate("Menu", "\350\217\234\345\215\225", nullptr));
        menu_2->setTitle(QCoreApplication::translate("Menu", "\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
