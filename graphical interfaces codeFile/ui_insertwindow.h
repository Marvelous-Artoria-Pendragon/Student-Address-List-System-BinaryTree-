/********************************************************************************
** Form generated from reading UI file 'insertwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTWINDOW_H
#define UI_INSERTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InsertWindow
{
public:
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_name;
    QLabel *label_number;
    QLabel *label_sex;
    QLabel *label_birthday;
    QLabel *label_phonenum;
    QLabel *label_addr;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_number;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox_sex;
    QSpacerItem *horizontalSpacer;
    QDateEdit *dateEdit_birthday;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit_phonenum;
    QLineEdit *lineEdit_addr;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_insert;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_cancel;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_7;

    void setupUi(QDialog *InsertWindow)
    {
        if (InsertWindow->objectName().isEmpty())
            InsertWindow->setObjectName(QString::fromUtf8("InsertWindow"));
        InsertWindow->resize(462, 349);
        gridLayout_3 = new QGridLayout(InsertWindow);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer_6 = new QSpacerItem(45, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_name = new QLabel(InsertWindow);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));

        verticalLayout_2->addWidget(label_name);

        label_number = new QLabel(InsertWindow);
        label_number->setObjectName(QString::fromUtf8("label_number"));
        label_number->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));

        verticalLayout_2->addWidget(label_number);

        label_sex = new QLabel(InsertWindow);
        label_sex->setObjectName(QString::fromUtf8("label_sex"));
        label_sex->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));

        verticalLayout_2->addWidget(label_sex);

        label_birthday = new QLabel(InsertWindow);
        label_birthday->setObjectName(QString::fromUtf8("label_birthday"));
        label_birthday->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));

        verticalLayout_2->addWidget(label_birthday);

        label_phonenum = new QLabel(InsertWindow);
        label_phonenum->setObjectName(QString::fromUtf8("label_phonenum"));
        label_phonenum->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));

        verticalLayout_2->addWidget(label_phonenum);

        label_addr = new QLabel(InsertWindow);
        label_addr->setObjectName(QString::fromUtf8("label_addr"));
        label_addr->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));

        verticalLayout_2->addWidget(label_addr);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit_name = new QLineEdit(InsertWindow);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        verticalLayout->addWidget(lineEdit_name);

        lineEdit_number = new QLineEdit(InsertWindow);
        lineEdit_number->setObjectName(QString::fromUtf8("lineEdit_number"));

        verticalLayout->addWidget(lineEdit_number);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboBox_sex = new QComboBox(InsertWindow);
        comboBox_sex->addItem(QString());
        comboBox_sex->addItem(QString());
        comboBox_sex->addItem(QString());
        comboBox_sex->setObjectName(QString::fromUtf8("comboBox_sex"));

        horizontalLayout->addWidget(comboBox_sex);

        horizontalSpacer = new QSpacerItem(100, 15, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        dateEdit_birthday = new QDateEdit(InsertWindow);
        dateEdit_birthday->setObjectName(QString::fromUtf8("dateEdit_birthday"));

        verticalLayout->addWidget(dateEdit_birthday);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        lineEdit_phonenum = new QLineEdit(InsertWindow);
        lineEdit_phonenum->setObjectName(QString::fromUtf8("lineEdit_phonenum"));

        verticalLayout->addWidget(lineEdit_phonenum);

        lineEdit_addr = new QLineEdit(InsertWindow);
        lineEdit_addr->setObjectName(QString::fromUtf8("lineEdit_addr"));

        verticalLayout->addWidget(lineEdit_addr);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_insert = new QPushButton(InsertWindow);
        pushButton_insert->setObjectName(QString::fromUtf8("pushButton_insert"));

        horizontalLayout_3->addWidget(pushButton_insert);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_cancel = new QPushButton(InsertWindow);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        horizontalLayout_3->addWidget(pushButton_cancel);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 2, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);


        gridLayout_3->addLayout(verticalLayout_3, 0, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(45, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_7, 0, 2, 1, 1);


        retranslateUi(InsertWindow);

        QMetaObject::connectSlotsByName(InsertWindow);
    } // setupUi

    void retranslateUi(QDialog *InsertWindow)
    {
        InsertWindow->setWindowTitle(QCoreApplication::translate("InsertWindow", "\346\217\222\345\205\245", nullptr));
        label_name->setText(QCoreApplication::translate("InsertWindow", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_number->setText(QCoreApplication::translate("InsertWindow", "\345\255\246\345\217\267\357\274\232", nullptr));
        label_sex->setText(QCoreApplication::translate("InsertWindow", "\346\200\247\345\210\253\357\274\232", nullptr));
        label_birthday->setText(QCoreApplication::translate("InsertWindow", "\345\207\272\347\224\237\346\227\245\346\234\237\357\274\232", nullptr));
        label_phonenum->setText(QCoreApplication::translate("InsertWindow", "\346\211\213\346\234\272\345\217\267\357\274\232", nullptr));
        label_addr->setText(QCoreApplication::translate("InsertWindow", "\345\234\260\345\235\200\357\274\232", nullptr));
        comboBox_sex->setItemText(0, QString());
        comboBox_sex->setItemText(1, QCoreApplication::translate("InsertWindow", "\347\224\267", nullptr));
        comboBox_sex->setItemText(2, QCoreApplication::translate("InsertWindow", "\345\245\263", nullptr));

        pushButton_insert->setText(QCoreApplication::translate("InsertWindow", "\346\217\222\345\205\245", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("InsertWindow", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InsertWindow: public Ui_InsertWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTWINDOW_H
