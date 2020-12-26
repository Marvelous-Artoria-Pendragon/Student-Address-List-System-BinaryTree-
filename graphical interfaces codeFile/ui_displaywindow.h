/********************************************************************************
** Form generated from reading UI file 'displaywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYWINDOW_H
#define UI_DISPLAYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DisplayWindow
{
public:
    QTableWidget *tableWidget;
    QLabel *label_prompt;
    QFontComboBox *fontComboBox;
    QPushButton *pushButton_YoungestStu;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_preOrder;
    QRadioButton *radioButton_inOrder;
    QRadioButton *radioButton_postOrder;
    QPushButton *pushButton_display;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *DisplayWindow)
    {
        if (DisplayWindow->objectName().isEmpty())
            DisplayWindow->setObjectName(QString::fromUtf8("DisplayWindow"));
        DisplayWindow->resize(922, 459);
        tableWidget = new QTableWidget(DisplayWindow);
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
        tableWidget->setGeometry(QRect(30, 40, 651, 371));
        label_prompt = new QLabel(DisplayWindow);
        label_prompt->setObjectName(QString::fromUtf8("label_prompt"));
        label_prompt->setGeometry(QRect(710, 40, 111, 51));
        label_prompt->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        fontComboBox = new QFontComboBox(DisplayWindow);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));
        fontComboBox->setGeometry(QRect(-190, 610, 279, 22));
        pushButton_YoungestStu = new QPushButton(DisplayWindow);
        pushButton_YoungestStu->setObjectName(QString::fromUtf8("pushButton_YoungestStu"));
        pushButton_YoungestStu->setGeometry(QRect(710, 280, 161, 41));
        widget = new QWidget(DisplayWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(710, 98, 127, 131));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        radioButton_preOrder = new QRadioButton(widget);
        buttonGroup = new QButtonGroup(DisplayWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(radioButton_preOrder);
        radioButton_preOrder->setObjectName(QString::fromUtf8("radioButton_preOrder"));
        radioButton_preOrder->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\245\267\344\275\223\";"));

        verticalLayout->addWidget(radioButton_preOrder);

        radioButton_inOrder = new QRadioButton(widget);
        buttonGroup->addButton(radioButton_inOrder);
        radioButton_inOrder->setObjectName(QString::fromUtf8("radioButton_inOrder"));
        radioButton_inOrder->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\245\267\344\275\223\";"));

        verticalLayout->addWidget(radioButton_inOrder);

        radioButton_postOrder = new QRadioButton(widget);
        buttonGroup->addButton(radioButton_postOrder);
        radioButton_postOrder->setObjectName(QString::fromUtf8("radioButton_postOrder"));
        radioButton_postOrder->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\245\267\344\275\223\";"));

        verticalLayout->addWidget(radioButton_postOrder);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton_display = new QPushButton(widget);
        pushButton_display->setObjectName(QString::fromUtf8("pushButton_display"));

        verticalLayout_2->addWidget(pushButton_display);


        retranslateUi(DisplayWindow);

        QMetaObject::connectSlotsByName(DisplayWindow);
    } // setupUi

    void retranslateUi(QDialog *DisplayWindow)
    {
        DisplayWindow->setWindowTitle(QCoreApplication::translate("DisplayWindow", "\346\230\276\347\244\272\346\211\200\346\234\211\344\277\241\346\201\257", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DisplayWindow", "\345\247\223\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DisplayWindow", "\345\255\246\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DisplayWindow", "\346\200\247\345\210\253", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DisplayWindow", "\347\224\237\346\227\245", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("DisplayWindow", "\346\211\213\346\234\272\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("DisplayWindow", "\345\234\260\345\235\200", nullptr));
        label_prompt->setText(QCoreApplication::translate("DisplayWindow", "\350\276\223\345\207\272\346\226\271\345\274\217:", nullptr));
        pushButton_YoungestStu->setText(QCoreApplication::translate("DisplayWindow", "\345\271\264\351\276\204\346\234\200\345\260\217\345\255\246\347\224\237\347\232\204\344\277\241\346\201\257", nullptr));
        radioButton_preOrder->setText(QCoreApplication::translate("DisplayWindow", "\345\211\215\345\272\217\351\201\215\345\216\206", nullptr));
        radioButton_inOrder->setText(QCoreApplication::translate("DisplayWindow", "\344\270\255\345\272\217\351\201\215\345\216\206", nullptr));
        radioButton_postOrder->setText(QCoreApplication::translate("DisplayWindow", "\345\220\216\345\272\217\351\201\215\345\216\206", nullptr));
        pushButton_display->setText(QCoreApplication::translate("DisplayWindow", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DisplayWindow: public Ui_DisplayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYWINDOW_H
