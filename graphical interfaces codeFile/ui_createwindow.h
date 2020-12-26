/********************************************************************************
** Form generated from reading UI file 'createwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEWINDOW_H
#define UI_CREATEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateWindow
{
public:
    QTableWidget *tableWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout;
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
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_append;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_remove;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_confirm;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_cancel;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QDialog *CreateWindow)
    {
        if (CreateWindow->objectName().isEmpty())
            CreateWindow->setObjectName(QString::fromUtf8("CreateWindow"));
        CreateWindow->resize(1035, 621);
        tableWidget = new QTableWidget(CreateWindow);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(20, 20, 621, 571));
        widget = new QWidget(CreateWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(660, 20, 338, 568));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_name = new QLabel(widget);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));

        verticalLayout_2->addWidget(label_name);

        label_number = new QLabel(widget);
        label_number->setObjectName(QString::fromUtf8("label_number"));
        label_number->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));

        verticalLayout_2->addWidget(label_number);

        label_sex = new QLabel(widget);
        label_sex->setObjectName(QString::fromUtf8("label_sex"));
        label_sex->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));

        verticalLayout_2->addWidget(label_sex);

        label_birthday = new QLabel(widget);
        label_birthday->setObjectName(QString::fromUtf8("label_birthday"));
        label_birthday->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));

        verticalLayout_2->addWidget(label_birthday);

        label_phonenum = new QLabel(widget);
        label_phonenum->setObjectName(QString::fromUtf8("label_phonenum"));
        label_phonenum->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));

        verticalLayout_2->addWidget(label_phonenum);

        label_addr = new QLabel(widget);
        label_addr->setObjectName(QString::fromUtf8("label_addr"));
        label_addr->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));

        verticalLayout_2->addWidget(label_addr);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit_name = new QLineEdit(widget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        verticalLayout->addWidget(lineEdit_name);

        lineEdit_number = new QLineEdit(widget);
        lineEdit_number->setObjectName(QString::fromUtf8("lineEdit_number"));

        verticalLayout->addWidget(lineEdit_number);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboBox_sex = new QComboBox(widget);
        comboBox_sex->addItem(QString());
        comboBox_sex->addItem(QString());
        comboBox_sex->addItem(QString());
        comboBox_sex->setObjectName(QString::fromUtf8("comboBox_sex"));

        horizontalLayout->addWidget(comboBox_sex);

        horizontalSpacer = new QSpacerItem(100, 15, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        dateEdit_birthday = new QDateEdit(widget);
        dateEdit_birthday->setObjectName(QString::fromUtf8("dateEdit_birthday"));

        verticalLayout->addWidget(dateEdit_birthday);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        lineEdit_phonenum = new QLineEdit(widget);
        lineEdit_phonenum->setObjectName(QString::fromUtf8("lineEdit_phonenum"));

        verticalLayout->addWidget(lineEdit_phonenum);

        lineEdit_addr = new QLineEdit(widget);
        lineEdit_addr->setObjectName(QString::fromUtf8("lineEdit_addr"));

        verticalLayout->addWidget(lineEdit_addr);


        horizontalLayout_2->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 2, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_append = new QPushButton(widget);
        pushButton_append->setObjectName(QString::fromUtf8("pushButton_append"));

        horizontalLayout_3->addWidget(pushButton_append);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_remove = new QPushButton(widget);
        pushButton_remove->setObjectName(QString::fromUtf8("pushButton_remove"));

        horizontalLayout_3->addWidget(pushButton_remove);


        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_confirm = new QPushButton(widget);
        pushButton_confirm->setObjectName(QString::fromUtf8("pushButton_confirm"));

        horizontalLayout_4->addWidget(pushButton_confirm);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        pushButton_cancel = new QPushButton(widget);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        horizontalLayout_4->addWidget(pushButton_cancel);


        verticalLayout_3->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout_3, 2, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 2, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 3, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout);

        verticalSpacer_4 = new QSpacerItem(20, 158, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);


        retranslateUi(CreateWindow);

        QMetaObject::connectSlotsByName(CreateWindow);
    } // setupUi

    void retranslateUi(QDialog *CreateWindow)
    {
        CreateWindow->setWindowTitle(QCoreApplication::translate("CreateWindow", "\346\226\260\345\273\272\351\200\232\350\256\257\345\275\225", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("CreateWindow", "\345\247\223\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("CreateWindow", "\345\255\246\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("CreateWindow", "\346\200\247\345\210\253", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("CreateWindow", "\347\224\237\346\227\245", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("CreateWindow", "\346\211\213\346\234\272\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("CreateWindow", "\345\234\260\345\235\200", nullptr));
        label_name->setText(QCoreApplication::translate("CreateWindow", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_number->setText(QCoreApplication::translate("CreateWindow", "\345\255\246\345\217\267\357\274\232", nullptr));
        label_sex->setText(QCoreApplication::translate("CreateWindow", "\346\200\247\345\210\253\357\274\232", nullptr));
        label_birthday->setText(QCoreApplication::translate("CreateWindow", "\345\207\272\347\224\237\346\227\245\346\234\237\357\274\232", nullptr));
        label_phonenum->setText(QCoreApplication::translate("CreateWindow", "\346\211\213\346\234\272\345\217\267\357\274\232", nullptr));
        label_addr->setText(QCoreApplication::translate("CreateWindow", "\345\234\260\345\235\200\357\274\232", nullptr));
        comboBox_sex->setItemText(0, QString());
        comboBox_sex->setItemText(1, QCoreApplication::translate("CreateWindow", "\347\224\267", nullptr));
        comboBox_sex->setItemText(2, QCoreApplication::translate("CreateWindow", "\345\245\263", nullptr));

        pushButton_append->setText(QCoreApplication::translate("CreateWindow", "\346\267\273\345\212\240", nullptr));
        pushButton_remove->setText(QCoreApplication::translate("CreateWindow", "\347\247\273\351\231\244", nullptr));
        pushButton_confirm->setText(QCoreApplication::translate("CreateWindow", "\347\241\256\345\256\232", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("CreateWindow", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateWindow: public Ui_CreateWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEWINDOW_H
