/********************************************************************************
** Form generated from reading UI file 'generic.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERIC_H
#define UI_GENERIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "motorselector.h"
#include "rotationsetter.h"
#include "vec3setter.h"

QT_BEGIN_NAMESPACE

class Ui_Generic
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    Vec3Setter *pivotA;
    Vec3Setter *pivotB;
    RotationSetter *linearBasisB;
    Vec3Setter *linearMin;
    Vec3Setter *linearMax;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    MotorSelector *linearMotorX;
    MotorSelector *linearMotorY;
    MotorSelector *linearMotorZ;
    RotationSetter *angularBasisA;
    RotationSetter *angularBasisB;
    Vec3Setter *angularMin;
    Vec3Setter *angularMax;
    MotorSelector *angularMotorX;
    MotorSelector *angularMotorY;
    MotorSelector *angularMotorZ;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radius;
    QRadioButton *degree;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Generic)
    {
        if (Generic->objectName().isEmpty())
            Generic->setObjectName(QStringLiteral("Generic"));
        Generic->resize(400, 288);
        formLayout = new QFormLayout(Generic);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(Generic);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(Generic);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(Generic);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(Generic);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(Generic);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(Generic);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(Generic);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_7);

        label_8 = new QLabel(Generic);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_8);

        label_9 = new QLabel(Generic);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout->setWidget(10, QFormLayout::LabelRole, label_9);

        label_10 = new QLabel(Generic);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout->setWidget(11, QFormLayout::LabelRole, label_10);

        label_11 = new QLabel(Generic);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout->setWidget(13, QFormLayout::LabelRole, label_11);

        pivotA = new Vec3Setter(Generic);
        pivotA->setObjectName(QStringLiteral("pivotA"));

        formLayout->setWidget(0, QFormLayout::FieldRole, pivotA);

        pivotB = new Vec3Setter(Generic);
        pivotB->setObjectName(QStringLiteral("pivotB"));

        formLayout->setWidget(1, QFormLayout::FieldRole, pivotB);

        linearBasisB = new RotationSetter(Generic);
        linearBasisB->setObjectName(QStringLiteral("linearBasisB"));

        formLayout->setWidget(2, QFormLayout::FieldRole, linearBasisB);

        linearMin = new Vec3Setter(Generic);
        linearMin->setObjectName(QStringLiteral("linearMin"));

        formLayout->setWidget(3, QFormLayout::FieldRole, linearMin);

        linearMax = new Vec3Setter(Generic);
        linearMax->setObjectName(QStringLiteral("linearMax"));

        formLayout->setWidget(4, QFormLayout::FieldRole, linearMax);

        label_12 = new QLabel(Generic);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_12);

        label_13 = new QLabel(Generic);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_13);

        label_14 = new QLabel(Generic);
        label_14->setObjectName(QStringLiteral("label_14"));

        formLayout->setWidget(14, QFormLayout::LabelRole, label_14);

        label_15 = new QLabel(Generic);
        label_15->setObjectName(QStringLiteral("label_15"));

        formLayout->setWidget(15, QFormLayout::LabelRole, label_15);

        linearMotorX = new MotorSelector(Generic);
        linearMotorX->setObjectName(QStringLiteral("linearMotorX"));

        formLayout->setWidget(5, QFormLayout::FieldRole, linearMotorX);

        linearMotorY = new MotorSelector(Generic);
        linearMotorY->setObjectName(QStringLiteral("linearMotorY"));

        formLayout->setWidget(6, QFormLayout::FieldRole, linearMotorY);

        linearMotorZ = new MotorSelector(Generic);
        linearMotorZ->setObjectName(QStringLiteral("linearMotorZ"));

        formLayout->setWidget(7, QFormLayout::FieldRole, linearMotorZ);

        angularBasisA = new RotationSetter(Generic);
        angularBasisA->setObjectName(QStringLiteral("angularBasisA"));

        formLayout->setWidget(8, QFormLayout::FieldRole, angularBasisA);

        angularBasisB = new RotationSetter(Generic);
        angularBasisB->setObjectName(QStringLiteral("angularBasisB"));

        formLayout->setWidget(9, QFormLayout::FieldRole, angularBasisB);

        angularMin = new Vec3Setter(Generic);
        angularMin->setObjectName(QStringLiteral("angularMin"));

        formLayout->setWidget(10, QFormLayout::FieldRole, angularMin);

        angularMax = new Vec3Setter(Generic);
        angularMax->setObjectName(QStringLiteral("angularMax"));

        formLayout->setWidget(11, QFormLayout::FieldRole, angularMax);

        angularMotorX = new MotorSelector(Generic);
        angularMotorX->setObjectName(QStringLiteral("angularMotorX"));

        formLayout->setWidget(13, QFormLayout::FieldRole, angularMotorX);

        angularMotorY = new MotorSelector(Generic);
        angularMotorY->setObjectName(QStringLiteral("angularMotorY"));

        formLayout->setWidget(14, QFormLayout::FieldRole, angularMotorY);

        angularMotorZ = new MotorSelector(Generic);
        angularMotorZ->setObjectName(QStringLiteral("angularMotorZ"));

        formLayout->setWidget(15, QFormLayout::FieldRole, angularMotorZ);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radius = new QRadioButton(Generic);
        radius->setObjectName(QStringLiteral("radius"));
        radius->setChecked(true);

        horizontalLayout->addWidget(radius);

        degree = new QRadioButton(Generic);
        degree->setObjectName(QStringLiteral("degree"));

        horizontalLayout->addWidget(degree);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        formLayout->setLayout(12, QFormLayout::FieldRole, horizontalLayout);


        retranslateUi(Generic);

        QMetaObject::connectSlotsByName(Generic);
    } // setupUi

    void retranslateUi(QWidget *Generic)
    {
        Generic->setWindowTitle(QApplication::translate("Generic", "Form", 0));
        label->setText(QApplication::translate("Generic", "Pivot A:", 0));
        label_2->setText(QApplication::translate("Generic", "Pivot B:", 0));
        label_3->setText(QApplication::translate("Generic", "Linear Basis B:", 0));
        label_4->setText(QApplication::translate("Generic", "Angular Basis A:", 0));
        label_5->setText(QApplication::translate("Generic", "Angular Basis B:", 0));
        label_6->setText(QApplication::translate("Generic", "Linear Min Limits:", 0));
        label_7->setText(QApplication::translate("Generic", "Linear Max Limits:", 0));
        label_8->setText(QApplication::translate("Generic", "Linear Motor X:", 0));
        label_9->setText(QApplication::translate("Generic", "Angular Min Limits:", 0));
        label_10->setText(QApplication::translate("Generic", "Angular Max Limits:", 0));
        label_11->setText(QApplication::translate("Generic", "Angular Motor X:", 0));
        label_12->setText(QApplication::translate("Generic", "Linear Motor Y:", 0));
        label_13->setText(QApplication::translate("Generic", "Linear Motor Z:", 0));
        label_14->setText(QApplication::translate("Generic", "Angular Motor Y:", 0));
        label_15->setText(QApplication::translate("Generic", "Angular Motor Z:", 0));
        radius->setText(QApplication::translate("Generic", "Radius", 0));
        degree->setText(QApplication::translate("Generic", "Degree", 0));
    } // retranslateUi

};

namespace Ui {
    class Generic: public Ui_Generic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERIC_H
