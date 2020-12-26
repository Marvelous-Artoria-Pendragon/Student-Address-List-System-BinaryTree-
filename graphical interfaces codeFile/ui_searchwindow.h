/********************************************************************************
** Form generated from reading UI file 'searchwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHWINDOW_H
#define UI_SEARCHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchWindow
{
public:
    QTableWidget *tableWidget;
    QPushButton *pushButton_close;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_prompt;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEdit_info;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_number;
    QRadioButton *radioButton_name;
    QRadioButton *radioButton_phonenum;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_search;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_del;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *SearchWindow)
    {
        if (SearchWindow->objectName().isEmpty())
            SearchWindow->setObjectName(QString::fromUtf8("SearchWindow"));
        SearchWindow->resize(973, 327);
        tableWidget = new QTableWidget(SearchWindow);
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
        tableWidget->setGeometry(QRect(30, 30, 631, 221));
        pushButton_close = new QPushButton(SearchWindow);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setGeometry(QRect(450, 270, 93, 28));
        layoutWidget = new QWidget(SearchWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(700, 30, 242, 206));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_prompt = new QLabel(layoutWidget);
        label_prompt->setObjectName(QString::fromUtf8("label_prompt"));
        label_prompt->setStyleSheet(QString::fromUtf8("font: 16pt \"Adobe \344\273\277\345\256\213 Std R\";"));

        horizontalLayout_2->addWidget(label_prompt);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_2);

        lineEdit_info = new QLineEdit(layoutWidget);
        lineEdit_info->setObjectName(QString::fromUtf8("lineEdit_info"));
        lineEdit_info->setMinimumSize(QSize(0, 21));

        verticalLayout_2->addWidget(lineEdit_info);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        radioButton_number = new QRadioButton(layoutWidget);
        buttonGroup = new QButtonGroup(SearchWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(radioButton_number);
        radioButton_number->setObjectName(QString::fromUtf8("radioButton_number"));
        radioButton_number->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\245\267\344\275\223\";"));

        verticalLayout->addWidget(radioButton_number);

        radioButton_name = new QRadioButton(layoutWidget);
        buttonGroup->addButton(radioButton_name);
        radioButton_name->setObjectName(QString::fromUtf8("radioButton_name"));
        radioButton_name->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\245\267\344\275\223\";"));

        verticalLayout->addWidget(radioButton_name);

        radioButton_phonenum = new QRadioButton(layoutWidget);
        buttonGroup->addButton(radioButton_phonenum);
        radioButton_phonenum->setObjectName(QString::fromUtf8("radioButton_phonenum"));
        radioButton_phonenum->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\245\267\344\275\223\";"));

        verticalLayout->addWidget(radioButton_phonenum);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_search = new QPushButton(layoutWidget);
        pushButton_search->setObjectName(QString::fromUtf8("pushButton_search"));

        horizontalLayout->addWidget(pushButton_search);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_del = new QPushButton(layoutWidget);
        pushButton_del->setObjectName(QString::fromUtf8("pushButton_del"));

        horizontalLayout->addWidget(pushButton_del);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(SearchWindow);

        QMetaObject::connectSlotsByName(SearchWindow);
    } // setupUi

    void retranslateUi(QDialog *SearchWindow)
    {
        SearchWindow->setWindowTitle(QCoreApplication::translate("SearchWindow", "\346\237\245\346\211\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("SearchWindow", "\345\247\223\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("SearchWindow", "\345\255\246\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("SearchWindow", "\346\200\247\345\210\253", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("SearchWindow", "\347\224\237\346\227\245", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("SearchWindow", "\346\211\213\346\234\272\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("SearchWindow", "\345\234\260\345\235\200", nullptr));
        pushButton_close->setText(QCoreApplication::translate("SearchWindow", "\345\205\263\351\227\255", nullptr));
        label_prompt->setText(QCoreApplication::translate("SearchWindow", "\345\255\246\347\224\237\344\277\241\346\201\257", nullptr));
        radioButton_number->setText(QCoreApplication::translate("SearchWindow", "\345\255\246\345\217\267", nullptr));
        radioButton_name->setText(QCoreApplication::translate("SearchWindow", "\345\247\223\345\220\215", nullptr));
        radioButton_phonenum->setText(QCoreApplication::translate("SearchWindow", "\347\224\265\350\257\235\345\217\267\347\240\201", nullptr));
        pushButton_search->setText(QCoreApplication::translate("SearchWindow", "\346\237\245\350\257\242", nullptr));
        pushButton_del->setText(QCoreApplication::translate("SearchWindow", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchWindow: public Ui_SearchWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHWINDOW_H
