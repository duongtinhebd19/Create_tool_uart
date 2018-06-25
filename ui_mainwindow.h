/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btnconnect;
    QComboBox *comboboxbaudrate;
    QComboBox *comboboxport;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *textstatus;
    QLineEdit *linetype;
    QPushButton *btnsend;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(745, 499);
        MainWindow->setAnimated(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btnconnect = new QPushButton(centralWidget);
        btnconnect->setObjectName(QStringLiteral("btnconnect"));
        btnconnect->setGeometry(QRect(460, 190, 181, 28));
        comboboxbaudrate = new QComboBox(centralWidget);
        comboboxbaudrate->setObjectName(QStringLiteral("comboboxbaudrate"));
        comboboxbaudrate->setGeometry(QRect(436, 150, 221, 22));
        comboboxport = new QComboBox(centralWidget);
        comboboxport->setObjectName(QStringLiteral("comboboxport"));
        comboboxport->setGeometry(QRect(436, 110, 221, 22));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(663, 110, 60, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(663, 150, 58, 16));
        textstatus = new QTextEdit(centralWidget);
        textstatus->setObjectName(QStringLiteral("textstatus"));
        textstatus->setGeometry(QRect(40, 60, 361, 221));
        linetype = new QLineEdit(centralWidget);
        linetype->setObjectName(QStringLiteral("linetype"));
        linetype->setGeometry(QRect(40, 320, 361, 28));
        btnsend = new QPushButton(centralWidget);
        btnsend->setObjectName(QStringLiteral("btnsend"));
        btnsend->setGeometry(QRect(447, 320, 93, 28));
        btnsend->setAutoDefault(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 745, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        btnconnect->setText(QApplication::translate("MainWindow", "CONNECT", 0));
        label->setText(QApplication::translate("MainWindow", "Serial Port", 0));
        label_2->setText(QApplication::translate("MainWindow", "Baud Rate", 0));
        btnsend->setText(QApplication::translate("MainWindow", "SEND", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
