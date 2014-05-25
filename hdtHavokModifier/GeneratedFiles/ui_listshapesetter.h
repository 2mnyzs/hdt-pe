/********************************************************************************
** Form generated from reading UI file 'listshapesetter.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTSHAPESETTER_H
#define UI_LISTSHAPESETTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListShapeSetter
{
public:
    QGridLayout *gridLayout;
    QPushButton *buttonRemove;
    QPushButton *buttonAdd;
    QSpacerItem *horizontalSpacer;
    QListWidget *listWidget;

    void setupUi(QWidget *ListShapeSetter)
    {
        if (ListShapeSetter->objectName().isEmpty())
            ListShapeSetter->setObjectName(QStringLiteral("ListShapeSetter"));
        ListShapeSetter->resize(269, 303);
        gridLayout = new QGridLayout(ListShapeSetter);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        buttonRemove = new QPushButton(ListShapeSetter);
        buttonRemove->setObjectName(QStringLiteral("buttonRemove"));

        gridLayout->addWidget(buttonRemove, 1, 2, 1, 1);

        buttonAdd = new QPushButton(ListShapeSetter);
        buttonAdd->setObjectName(QStringLiteral("buttonAdd"));

        gridLayout->addWidget(buttonAdd, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        listWidget = new QListWidget(ListShapeSetter);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout->addWidget(listWidget, 0, 0, 1, 3);


        retranslateUi(ListShapeSetter);

        QMetaObject::connectSlotsByName(ListShapeSetter);
    } // setupUi

    void retranslateUi(QWidget *ListShapeSetter)
    {
        ListShapeSetter->setWindowTitle(QApplication::translate("ListShapeSetter", "Form", 0));
        buttonRemove->setText(QApplication::translate("ListShapeSetter", "Remove", 0));
        buttonAdd->setText(QApplication::translate("ListShapeSetter", "Add", 0));
    } // retranslateUi

};

namespace Ui {
    class ListShapeSetter: public Ui_ListShapeSetter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTSHAPESETTER_H
