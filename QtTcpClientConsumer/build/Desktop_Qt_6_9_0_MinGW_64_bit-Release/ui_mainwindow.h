/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "plotter.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEditIP;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonConnect;
    QPushButton *pushButtonDisconnect;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonUpdate;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QSlider *horizontalSliderTiming;
    QLabel *label_timing;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonStop;
    Plotter *widget_plotter;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(794, 618);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 20, 291, 531));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        lineEditIP = new QLineEdit(layoutWidget);
        lineEditIP->setObjectName("lineEditIP");

        verticalLayout->addWidget(lineEditIP);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButtonConnect = new QPushButton(layoutWidget);
        pushButtonConnect->setObjectName("pushButtonConnect");

        horizontalLayout->addWidget(pushButtonConnect);

        pushButtonDisconnect = new QPushButton(layoutWidget);
        pushButtonDisconnect->setObjectName("pushButtonDisconnect");

        horizontalLayout->addWidget(pushButtonDisconnect);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName("listWidget");

        verticalLayout_2->addWidget(listWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(148, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButtonUpdate = new QPushButton(layoutWidget);
        pushButtonUpdate->setObjectName("pushButtonUpdate");

        horizontalLayout_3->addWidget(pushButtonUpdate);


        verticalLayout_2->addLayout(horizontalLayout_3);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSliderTiming = new QSlider(layoutWidget);
        horizontalSliderTiming->setObjectName("horizontalSliderTiming");
        horizontalSliderTiming->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_4->addWidget(horizontalSliderTiming);

        label_timing = new QLabel(layoutWidget);
        label_timing->setObjectName("label_timing");

        horizontalLayout_4->addWidget(label_timing);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButtonStart = new QPushButton(layoutWidget);
        pushButtonStart->setObjectName("pushButtonStart");

        horizontalLayout_2->addWidget(pushButtonStart);

        pushButtonStop = new QPushButton(layoutWidget);
        pushButtonStop->setObjectName("pushButtonStop");

        horizontalLayout_2->addWidget(pushButtonStop);


        verticalLayout_2->addLayout(horizontalLayout_2);

        widget_plotter = new Plotter(centralWidget);
        widget_plotter->setObjectName("widget_plotter");
        widget_plotter->setGeometry(QRect(320, 20, 441, 531));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 794, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSliderTiming, &QSlider::valueChanged, label_timing, qOverload<int>(&QLabel::setNum));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "IP do servidor ", nullptr));
        pushButtonConnect->setText(QCoreApplication::translate("MainWindow", "Connect ", nullptr));
        pushButtonDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        pushButtonUpdate->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Timing ", nullptr));
        label_timing->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButtonStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        pushButtonStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
