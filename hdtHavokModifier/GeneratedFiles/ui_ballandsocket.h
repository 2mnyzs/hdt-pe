/********************************************************************************
** Form generated from reading UI file 'ballandsocket.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BALLANDSOCKET_H
#define UI_BALLANDSOCKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "vec3setter.h"

QT_BEGIN_NAMESPACE

class Ui_BallAndSocket
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    Vec3Setter *widgetPivotA;
    QLabel *label_2;
    Vec3Setter *widgetPivotB;

    void setupUi(QWidget *BallAndSocket)
    {
        if (BallAndSocket->objectName().isEmpty())
            BallAndSocket->setObjectName(QStringLiteral("BallAndSocket"));
        BallAndSocket->resize(315, 30);
        formLayout = new QFormLayout(BallAndSocket);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(BallAndSocket);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        widgetPivotA = new Vec3Setter(BallAndSocket);
        widgetPivotA->setObjectName(QStringLiteral("widgetPivotA"));

        formLayout->setWidget(0, QFormLayout::FieldRole, widgetPivotA);

        label_2 = new QLabel(BallAndSocket);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        widgetPivotB = new Vec3Setter(BallAndSocket);
        widgetPivotB->setObjectName(QStringLiteral("widgetPivotB"));

        formLayout->setWidget(1, QFormLayout::FieldRole, widgetPivotB);


        retranslateUi(BallAndSocket);

        QMetaObject::connectSlotsByName(BallAndSocket);
    } // setupUi

    void retranslateUi(QWidget *BallAndSocket)
    {
        BallAndSocket->setWindowTitle(QApplication::translate("BallAndSocket", "Form", 0));
        label->setText(QApplication::translate("BallAndSocket", "PivotA:", 0));
        label_2->setText(QApplication::translate("BallAndSocket", "PivotB:", 0));
    } // retranslateUi

};

namespace Ui {
    class BallAndSocket: public Ui_BallAndSocket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BALLANDSOCKET_H
