/********************************************************************************
** Form generated from reading UI file 'woshark.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef WOSHARK_H
#define WOSHARK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *stopButton;
    QLabel *label;
    QLineEdit *iplineEdit;
    QPushButton *okButton;
    QFrame *vline;
    QTextBrowser *detailtextBrowser;
    QPushButton *clearButton;
    QPushButton *clearButton2;
    QFrame *hline;
    QLabel *netlabel;
    QTextBrowser *nettextBrowser;
    QPushButton *quitButton;
    QFrame *hline2;
    QPushButton *detailButton;
    QTextBrowser *textBrowser;
    QPushButton *beginButton;
    QLineEdit *lineEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1374, 747);
        MainWindow->setMinimumSize(QSize(1374, 747));
        MainWindow->setMaximumSize(QSize(1374, 747));
        MainWindow->setCursor(QCursor(Qt::PointingHandCursor));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setEnabled(false);
        stopButton->setGeometry(QRect(630, 40, 90, 32));
        stopButton->setStyleSheet(QString::fromUtf8("font: 14pt \"Nimbus Sans [UKWN]\";\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(850, 40, 91, 41));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"Nimbus Sans [UKWN]\";\n"
""));
        iplineEdit = new QLineEdit(centralwidget);
        iplineEdit->setObjectName(QString::fromUtf8("iplineEdit"));
        iplineEdit->setGeometry(QRect(920, 50, 151, 26));
        iplineEdit->setStyleSheet(QString::fromUtf8("font: 81 italic 11pt \"JetBrainsMono Nerd Font Mono\";\n"
"color:rgb(255, 2, 103);\n"
""));
        okButton = new QPushButton(centralwidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(1120, 50, 90, 32));
        okButton->setStyleSheet(QString::fromUtf8("font: 14pt \"Nimbus Sans [UKWN]\";\n"
""));
        vline = new QFrame(centralwidget);
        vline->setObjectName(QString::fromUtf8("vline"));
        vline->setGeometry(QRect(830, -20, 5, 900));
        vline->setMinimumSize(QSize(5, 900));
        vline->setMaximumSize(QSize(5, 900));
        vline->setStyleSheet(QString::fromUtf8("background : rgb(98, 195, 255);\n"
""));
        vline->setFrameShape(QFrame::VLine);
        vline->setFrameShadow(QFrame::Sunken);
        detailtextBrowser = new QTextBrowser(centralwidget);
        detailtextBrowser->setObjectName(QString::fromUtf8("detailtextBrowser"));
        detailtextBrowser->setGeometry(QRect(850, 100, 501, 241));
        detailtextBrowser->setStyleSheet(QString::fromUtf8("font: 81 italic 10pt \"JetBrainsMono Nerd Font Mono\";\n"
"color:rgb(255, 235, 15);\n"
""));
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setEnabled(false);
        clearButton->setGeometry(QRect(730, 40, 61, 31));
        clearButton->setStyleSheet(QString::fromUtf8("font: 14pt \"Nimbus Sans [UKWN]\";\n"
""));
        clearButton2 = new QPushButton(centralwidget);
        clearButton2->setObjectName(QString::fromUtf8("clearButton2"));
        clearButton2->setEnabled(false);
        clearButton2->setGeometry(QRect(1240, 50, 90, 32));
        clearButton2->setStyleSheet(QString::fromUtf8("font: 14pt \"Nimbus Sans [UKWN]\";\n"
""));
        hline = new QFrame(centralwidget);
        hline->setObjectName(QString::fromUtf8("hline"));
        hline->setGeometry(QRect(830, 360, 700, 5));
        hline->setMinimumSize(QSize(700, 5));
        hline->setMaximumSize(QSize(700, 5));
        hline->setStyleSheet(QString::fromUtf8("background : rgb(98, 195, 255);\n"
""));
        hline->setFrameShape(QFrame::HLine);
        hline->setFrameShadow(QFrame::Sunken);
        netlabel = new QLabel(centralwidget);
        netlabel->setObjectName(QString::fromUtf8("netlabel"));
        netlabel->setGeometry(QRect(1036, 380, 71, 20));
        netlabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Nimbus Sans [UKWN]\";\n"
""));
        nettextBrowser = new QTextBrowser(centralwidget);
        nettextBrowser->setObjectName(QString::fromUtf8("nettextBrowser"));
        nettextBrowser->setGeometry(QRect(860, 420, 491, 241));
        quitButton = new QPushButton(centralwidget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setGeometry(QRect(1280, 710, 90, 32));
        quitButton->setStyleSheet(QString::fromUtf8("font: 14pt \"Nimbus Sans [UKWN]\";\n"
""));
        hline2 = new QFrame(centralwidget);
        hline2->setObjectName(QString::fromUtf8("hline2"));
        hline2->setGeometry(QRect(830, 690, 700, 5));
        hline2->setMinimumSize(QSize(700, 5));
        hline2->setMaximumSize(QSize(700, 5));
        hline2->setStyleSheet(QString::fromUtf8("background : rgb(98, 195, 255);\n"
""));
        hline2->setFrameShape(QFrame::HLine);
        hline2->setFrameShadow(QFrame::Sunken);
        detailButton = new QPushButton(centralwidget);
        detailButton->setObjectName(QString::fromUtf8("detailButton"));
        detailButton->setGeometry(QRect(530, 40, 90, 32));
        detailButton->setStyleSheet(QString::fromUtf8("font: 14pt \"Nimbus Sans [UKWN]\";\n"
""));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 80, 801, 631));
        textBrowser->setStyleSheet(QString::fromUtf8("font: 81 italic 11pt \"JetBrainsMono Nerd Font Mono\";\n"
"\n"
"\n"
""));
        beginButton = new QPushButton(centralwidget);
        beginButton->setObjectName(QString::fromUtf8("beginButton"));
        beginButton->setGeometry(QRect(420, 40, 90, 32));
        beginButton->setStyleSheet(QString::fromUtf8("font: 14pt \"Nimbus Sans [UKWN]\";\n"
""));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(40, 40, 341, 26));
        lineEdit->setStyleSheet(QString::fromUtf8("font: 81 italic 11pt \"JetBrainsMono Nerd Font Mono\";\n"
"border-color: rgb(38, 114, 255);\n"
"color:rgb(255, 2, 103);\n"
"\n"
"\n"
""));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "WoShark", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "    IP", nullptr));
        okButton->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        clearButton2->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        netlabel->setText(QCoreApplication::translate("MainWindow", "       net", nullptr));
        quitButton->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        detailButton->setText(QCoreApplication::translate("MainWindow", "Detail", nullptr));
        beginButton->setText(QCoreApplication::translate("MainWindow", "List", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // WOSHARK_H
