/********************************************************************************
** Form generated from reading UI file 'wheel.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WHEEL_H
#define UI_WHEEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "rotationsetter.h"
#include "vec3setter.h"

QT_BEGIN_NAMESPACE

class Ui_Wheel
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
    QLabel *label_8;
    QDoubleSpinBox *spinBoxMin;
    QLabel *label_7;
    QDoubleSpinBox *spinBoxMax;
    QLabel *label_9;
    QDoubleSpinBox *spinBoxStrength;
    QLabel *label_10;
    QDoubleSpinBox *spinBoxDamping;
    QLabel *label_6;
    RotationSetter *widgetSteeringBasisB;

    void setupUi(QWidget *Wheel)
    {
        if (Wheel->objectName().isEmpty())
            Wheel->setObjectName(QStringLiteral("Wheel"));
        Wheel->resize(400, 300);
        formLayout = new QFormLayout(Wheel);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(Wheel);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        widgetPivotA = new Vec3Setter(Wheel);
        widgetPivotA->setObjectName(QStringLiteral("widgetPivotA"));

        formLayout->setWidget(0, QFormLayout::FieldRole, widgetPivotA);

        label_2 = new QLabel(Wheel);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        widgetPivotB = new Vec3Setter(Wheel);
        widgetPivotB->setObjectName(QStringLiteral("widgetPivotB"));

        formLayout->setWidget(1, QFormLayout::FieldRole, widgetPivotB);

        label_3 = new QLabel(Wheel);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        widgetBasisA = new RotationSetter(Wheel);
        widgetBasisA->setObjectName(QStringLiteral("widgetBasisA"));

        formLayout->setWidget(2, QFormLayout::FieldRole, widgetBasisA);

        label_4 = new QLabel(Wheel);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        widgetBasisB = new RotationSetter(Wheel);
        widgetBasisB->setObjectName(QStringLiteral("widgetBasisB"));

        formLayout->setWidget(3, QFormLayout::FieldRole, widgetBasisB);

        label_8 = new QLabel(Wheel);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_8);

        spinBoxMin = new QDoubleSpinBox(Wheel);
        spinBoxMin->setObjectName(QStringLiteral("spinBoxMin"));
        spinBoxMin->setDecimals(4);
        spinBoxMin->setMinimum(-9999);
        spinBoxMin->setMaximum(9999);

        formLayout->setWidget(4, QFormLayout::FieldRole, spinBoxMin);

        label_7 = new QLabel(Wheel);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_7);

        spinBoxMax = new QDoubleSpinBox(Wheel);
        spinBoxMax->setObjectName(QStringLiteral("spinBoxMax"));
        spinBoxMax->setDecimals(4);
        spinBoxMax->setMinimum(-9999);
        spinBoxMax->setMaximum(9999);

        formLayout->setWidget(5, QFormLayout::FieldRole, spinBoxMax);

        label_9 = new QLabel(Wheel);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_9);

        spinBoxStrength = new QDoubleSpinBox(Wheel);
        spinBoxStrength->setObjectName(QStringLiteral("spinBoxStrength"));
        spinBoxStrength->setDecimals(6);
        spinBoxStrength->setMaximum(1);
        spinBoxStrength->setSingleStep(0.01);

        formLayout->setWidget(6, QFormLayout::FieldRole, spinBoxStrength);

        label_10 = new QLabel(Wheel);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_10);

        spinBoxDamping = new QDoubleSpinBox(Wheel);
        spinBoxDamping->setObjectName(QStringLiteral("spinBoxDamping"));
        spinBoxDamping->setDecimals(6);
        spinBoxDamping->setMaximum(1);
        spinBoxDamping->setSingleStep(0.01);

        formLayout->setWidget(7, QFormLayout::FieldRole, spinBoxDamping);

        label_6 = new QLabel(Wheel);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_6);

        widgetSteeringBasisB = new RotationSetter(Wheel);
        widgetSteeringBasisB->setObjectName(QStringLiteral("widgetSteeringBasisB"));

        formLayout->setWidget(8, QFormLayout::FieldRole, widgetSteeringBasisB);


        retranslateUi(Wheel);

        QMetaObject::connectSlotsByName(Wheel);
    } // setupUi

    void retranslateUi(QWidget *Wheel)
    {
        Wheel->setWindowTitle(QApplication::translate("Wheel", "Form", 0));
        label->setText(QApplication::translate("Wheel", "Pivot A:", 0));
        label_2->setText(QApplication::translate("Wheel", "Pivot B:", 0));
        label_3->setText(QApplication::translate("Wheel", "Basis A:", 0));
        label_4->setText(QApplication::translate("Wheel", "Suspension Basis B:", 0));
        label_8->setText(QApplication::translate("Wheel", "Min Suspension Limit:", 0));
        label_7->setText(QApplication::translate("Wheel", "Max Suspension Limit:", 0));
        label_9->setText(QApplication::translate("Wheel", "Suspension Strength:", 0));
        label_10->setText(QApplication::translate("Wheel", "Suspension Damping:", 0));
        label_6->setText(QApplication::translate("Wheel", "Steering Basis B:", 0));
    } // retranslateUi

};

namespace Ui {
    class Wheel: public Ui_Wheel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WHEEL_H
