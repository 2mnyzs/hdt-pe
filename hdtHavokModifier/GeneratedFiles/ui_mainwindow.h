/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonLoad;
    QPushButton *buttonSaveAs;
    QLineEdit *lineEditCurrentFile;
    QToolBox *toolBox;
    QWidget *pageRigidBodies;
    QGridLayout *gridLayout_3;
    QTableWidget *tableRigidBodies;
    QWidget *pageConstraints;
    QGridLayout *gridLayout_4;
    QTableWidget *tableConstraints;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(900, 630);
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
        MainWindow->setStyleSheet(QLatin1String("QWidget{\n"
"	color: rgb(0,0,127);\n"
"}\n"
"\n"
"QTableWidget{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"\n"
"QWidget#centralWidget{\n"
"	background-image: url(:/backgrounds/yande.re 64923.jpg);\n"
"}\n"
"\n"
"QPushButton{\n"
"	background-color: rgba(255, 255, 255, 127);\n"
"	border: 1px solid white;\n"
"	border-radius: 5px;\n"
"	padding: 4 20 4 20px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgba(255, 255, 255, 192);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: rgba(255, 255, 255, 224);\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        buttonLoad = new QPushButton(centralWidget);
        buttonLoad->setObjectName(QStringLiteral("buttonLoad"));

        horizontalLayout->addWidget(buttonLoad);

        buttonSaveAs = new QPushButton(centralWidget);
        buttonSaveAs->setObjectName(QStringLiteral("buttonSaveAs"));
        buttonSaveAs->setFlat(false);

        horizontalLayout->addWidget(buttonSaveAs);

        lineEditCurrentFile = new QLineEdit(centralWidget);
        lineEditCurrentFile->setObjectName(QStringLiteral("lineEditCurrentFile"));
        lineEditCurrentFile->setStyleSheet(QLatin1String("QLineEdit{\n"
"	background-color: rgba(255, 255, 255, 127);\n"
"	border: 1px solid rgba(255, 255, 255, 192);\n"
"	border-radius: 2px;\n"
"	padding: 1 1 1 1px;\n"
"}\n"
"QLineEdit:hover{\n"
"	background-color: rgba(255, 255, 255, 192);\n"
"	border: 1px solid rgba(255, 255, 255, 192);\n"
"	border-radius: 2px;\n"
"	padding: 1 1 1 1px;\n"
"}"));
        lineEditCurrentFile->setText(QStringLiteral(""));
        lineEditCurrentFile->setReadOnly(true);

        horizontalLayout->addWidget(lineEditCurrentFile);


        verticalLayout->addLayout(horizontalLayout);

        toolBox = new QToolBox(centralWidget);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setStyleSheet(QLatin1String("QWidget{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"\n"
"QToolBox{\n"
"	background-color: rgba(255, 255, 255, 127);\n"
"}\n"
"\n"
"QToolBox::Tab{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.5, y2:0.5, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 0));\n"
"}\n"
"\n"
""));
        toolBox->setFrameShape(QFrame::NoFrame);
        pageRigidBodies = new QWidget();
        pageRigidBodies->setObjectName(QStringLiteral("pageRigidBodies"));
        pageRigidBodies->setGeometry(QRect(0, 0, 882, 542));
        pageRigidBodies->setStyleSheet(QStringLiteral("background: transparent;"));
        gridLayout_3 = new QGridLayout(pageRigidBodies);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        tableRigidBodies = new QTableWidget(pageRigidBodies);
        if (tableRigidBodies->columnCount() < 3)
            tableRigidBodies->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableRigidBodies->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableRigidBodies->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableRigidBodies->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableRigidBodies->setObjectName(QStringLiteral("tableRigidBodies"));
        tableRigidBodies->setStyleSheet(QLatin1String("QTableWidget{\n"
"	background-color: rgba(255, 255, 255, 127);\n"
"}\n"
"\n"
"QHeaderView::section{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 0));\n"
"border: 1px solid rgba(0, 0, 0, 32);\n"
"}\n"
"\n"
"QScrollBar::add-page{\n"
"	background:transparent;\n"
"}\n"
"\n"
"QScrollBar::sub-page{\n"
"	background:transparent;\n"
"}"));
        tableRigidBodies->setFrameShape(QFrame::Panel);
        tableRigidBodies->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableRigidBodies->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableRigidBodies->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableRigidBodies->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableRigidBodies->setGridStyle(Qt::DotLine);
        tableRigidBodies->setRowCount(0);
        tableRigidBodies->setColumnCount(3);
        tableRigidBodies->horizontalHeader()->setCascadingSectionResizes(true);
        tableRigidBodies->horizontalHeader()->setDefaultSectionSize(150);
        tableRigidBodies->horizontalHeader()->setHighlightSections(false);
        tableRigidBodies->horizontalHeader()->setMinimumSectionSize(100);
        tableRigidBodies->horizontalHeader()->setStretchLastSection(true);
        tableRigidBodies->verticalHeader()->setVisible(false);

        gridLayout_3->addWidget(tableRigidBodies, 0, 0, 1, 1);

        toolBox->addItem(pageRigidBodies, QStringLiteral("RigdiBodies >>"));
        pageConstraints = new QWidget();
        pageConstraints->setObjectName(QStringLiteral("pageConstraints"));
        pageConstraints->setGeometry(QRect(0, 0, 882, 542));
        gridLayout_4 = new QGridLayout(pageConstraints);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        tableConstraints = new QTableWidget(pageConstraints);
        if (tableConstraints->columnCount() < 2)
            tableConstraints->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableConstraints->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableConstraints->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        tableConstraints->setObjectName(QStringLiteral("tableConstraints"));
        tableConstraints->setStyleSheet(QLatin1String("QTableWidget{\n"
"	background-color: rgba(255, 255, 255, 127);\n"
"}\n"
"\n"
"QHeaderView::section{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 0));\n"
"border: 1px solid rgba(0, 0, 0, 32);\n"
"}\n"
"\n"
"QScrollBar::add-page{\n"
"	background:transparent;\n"
"}\n"
"\n"
"QScrollBar::sub-page{\n"
"	background:transparent;\n"
"}\n"
""));
        tableConstraints->setFrameShape(QFrame::Panel);
        tableConstraints->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableConstraints->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableConstraints->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableConstraints->setGridStyle(Qt::DotLine);
        tableConstraints->horizontalHeader()->setCascadingSectionResizes(true);
        tableConstraints->horizontalHeader()->setDefaultSectionSize(150);
        tableConstraints->horizontalHeader()->setHighlightSections(false);
        tableConstraints->horizontalHeader()->setMinimumSectionSize(100);
        tableConstraints->horizontalHeader()->setStretchLastSection(true);
        tableConstraints->verticalHeader()->setVisible(false);

        gridLayout_4->addWidget(tableConstraints, 0, 0, 1, 1);

        toolBox->addItem(pageConstraints, QStringLiteral("Constraints >>"));

        verticalLayout->addWidget(toolBox);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(buttonLoad, SIGNAL(clicked()), MainWindow, SLOT(onButtonLoad()));
        QObject::connect(buttonSaveAs, SIGNAL(clicked()), MainWindow, SLOT(onButtonSave()));
        QObject::connect(tableRigidBodies, SIGNAL(cellDoubleClicked(int,int)), MainWindow, SLOT(onModifyRigidBody(int,int)));
        QObject::connect(tableConstraints, SIGNAL(cellDoubleClicked(int,int)), MainWindow, SLOT(onModifyConstraint(int,int)));

        toolBox->setCurrentIndex(0);
        toolBox->layout()->setSpacing(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        buttonLoad->setText(QApplication::translate("MainWindow", "Load", 0));
        buttonSaveAs->setText(QApplication::translate("MainWindow", "SaveAs", 0));
        QTableWidgetItem *___qtablewidgetitem = tableRigidBodies->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "name", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableRigidBodies->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "motion type", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableRigidBodies->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "shape", 0));
        toolBox->setItemText(toolBox->indexOf(pageRigidBodies), QApplication::translate("MainWindow", "RigdiBodies >>", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableConstraints->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "type", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableConstraints->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "rigidbodies", 0));
        toolBox->setItemText(toolBox->indexOf(pageConstraints), QApplication::translate("MainWindow", "Constraints >>", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
