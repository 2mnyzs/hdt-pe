/********************************************************************************
** Form generated from reading UI file 'fixed.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIXED_H
#define UI_FIXED_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "rotationsetter.h"
#include "vec3setter.h"

QT_BEGIN_NAMESPACE

class Ui_Fixed
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    Vec3Setter *widgetPivotA;
    QLabel *label_2;
    Vec3Setter *widgetPivotB;
    QLabel *label_3;
    RotationSetter *widgetBasisA;
    QLabel *label_4;
    RotationSetter *widgetBasisB;

    void setupUi(QWidget *Fixed)
    {
        if (Fixed->objectName().isEmpty())
            Fixed->setObjectName(QStringLiteral("Fixed"));
        Fixed->resize(400, 66);
        formLayout = new QFormLayout(Fixed);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(Fixed);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        widgetPivotA = new Vec3Setter(Fixed);
        widgetPivotA->setObjectName(QStringLiteral("widgetPivotA"));

        formLayout->setWidget(0, QFormLayout::FieldRole, widgetPivotA);

        label_2 = new QLabel(Fixed);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        widgetPivotB = new Vec3Setter(Fixed);
        widgetPivotB->setObjectName(QStringLiteral("widgetPivotB"));

        formLayout->setWidget(1, QFormLayout::FieldRole, widgetPivotB);

        label_3 = new QLabel(Fixed);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        widgetBasisA = new RotationSetter(Fixed);
        widgetBasisA->setObjectName(QStringLiteral("widgetBasisA"));

        formLayout->setWidget(2, QFormLayout::FieldRole, widgetBasisA);

        label_4 = new QLabel(Fixed);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        widgetBasisB = new RotationSetter(Fixed);
        widgetBasisB->setObjectName(QStringLiteral("widgetBasisB"));

        formLayout->setWidget(3, QFormLayout::FieldRole, widgetBasisB);


        retranslateUi(Fixed);

        QMetaObject::connectSlotsByName(Fixed);
    } // setupUi

    void retranslateUi(QWidget *Fixed)
    {
        Fixed->setWindowTitle(QApplication::translate("Fixed", "Form", 0));
        label->setText(QApplication::translate("Fixed", "Pivot A:", 0));
        label_2->setText(QApplication::translate("Fixed", "Pivot B:", 0));
        label_3->setText(QApplication::translate("Fixed", "Basis A:", 0));
        label_4->setText(QApplication::translate("Fixed", "Basis B:", 0));
    } // retranslateUi

};

namespace Ui {
    class Fixed: public Ui_Fixed {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIXED_H
