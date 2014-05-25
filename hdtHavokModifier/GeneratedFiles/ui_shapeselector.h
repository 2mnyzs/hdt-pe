/********************************************************************************
** Form generated from reading UI file 'shapeselector.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHAPESELECTOR_H
#define UI_SHAPESELECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShapeSelector
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;

    void setupUi(QWidget *ShapeSelector)
    {
        if (ShapeSelector->objectName().isEmpty())
            ShapeSelector->setObjectName(QStringLiteral("ShapeSelector"));
        ShapeSelector->resize(82, 23);
        gridLayout = new QGridLayout(ShapeSelector);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(ShapeSelector);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);


        retranslateUi(ShapeSelector);

        QMetaObject::connectSlotsByName(ShapeSelector);
    } // setupUi

    void retranslateUi(QWidget *ShapeSelector)
    {
        ShapeSelector->setWindowTitle(QApplication::translate("ShapeSelector", "Form", 0));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ShapeSelector: public Ui_ShapeSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHAPESELECTOR_H
