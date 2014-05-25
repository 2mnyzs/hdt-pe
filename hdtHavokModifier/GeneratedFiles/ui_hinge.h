/********************************************************************************
** Form generated from reading UI file 'hinge.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HINGE_H
#define UI_HINGE_H

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

class Ui_Hinge
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    Vec3Setter *widgetPivotA;
    Vec3Setter *widgetPivotB;
    Vec3Setter *widgetAxisA;
    Vec3Setter *widgetAxisB;

    void setupUi(QWidget *Hinge)
    {
        if (Hinge->objectName().isEmpty())
            Hinge->setObjectName(QStringLiteral("Hinge"));
        Hinge->resize(400, 300);
        formLayout = new QFormLayout(Hinge);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(Hinge);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(Hinge);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(Hinge);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(Hinge);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        widgetPivotA = new Vec3Setter(Hinge);
        widgetPivotA->setObjectName(QStringLiteral("widgetPivotA"));

        formLayout->setWidget(0, QFormLayout::FieldRole, widgetPivotA);

        widgetPivotB = new Vec3Setter(Hinge);
        widgetPivotB->setObjectName(QStringLiteral("widgetPivotB"));

        formLayout->setWidget(1, QFormLayout::FieldRole, widgetPivotB);

        widgetAxisA = new Vec3Setter(Hinge);
        widgetAxisA->setObjectName(QStringLiteral("widgetAxisA"));

        formLayout->setWidget(2, QFormLayout::FieldRole, widgetAxisA);

        widgetAxisB = new Vec3Setter(Hinge);
        widgetAxisB->setObjectName(QStringLiteral("widgetAxisB"));

        formLayout->setWidget(3, QFormLayout::FieldRole, widgetAxisB);


        retranslateUi(Hinge);

        QMetaObject::connectSlotsByName(Hinge);
    } // setupUi

    void retranslateUi(QWidget *Hinge)
    {
        Hinge->setWindowTitle(QApplication::translate("Hinge", "Form", 0));
        label->setText(QApplication::translate("Hinge", "Pivot A:", 0));
        label_2->setText(QApplication::translate("Hinge", "Pivot B:", 0));
        label_3->setText(QApplication::translate("Hinge", "Axis A:", 0));
        label_4->setText(QApplication::translate("Hinge", "Axis B:", 0));
    } // retranslateUi

};

namespace Ui {
    class Hinge: public Ui_Hinge {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HINGE_H
