/********************************************************************************
** Form generated from reading UI file 'linearclearance.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINEARCLEARANCE_H
#define UI_LINEARCLEARANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "motorselector.h"
#include "rotationsetter.h"
#include "vec3setter.h"

QT_BEGIN_NAMESPACE

class Ui_LinearClearance
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    Vec3Setter *widgetPivotA;
    QLabel *label_3;
    Vec3Setter *widgetPivotB;
    QLabel *label_4;
    RotationSetter *widgetBasisA;
    QLabel *label_5;
    RotationSetter *widgetBasisB;
    QLabel *label_6;
    Vec3Setter *widgetMin;
    QLabel *label_9;
    Vec3Setter *widgetMax;
    QLabel *label_7;
    QDoubleSpinBox *spinBoxFriction;
    QLabel *label_8;
    MotorSelector *widgetMotor;
    QLabel *label_10;
    QDoubleSpinBox *spinBoxMotorTarget;

    void setupUi(QWidget *LinearClearance)
    {
        if (LinearClearance->objectName().isEmpty())
            LinearClearance->setObjectName(QStringLiteral("LinearClearance"));
        LinearClearance->resize(307, 198);
        formLayout = new QFormLayout(LinearClearance);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(LinearClearance);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        comboBox = new QComboBox(LinearClearance);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox);

        label_2 = new QLabel(LinearClearance);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        widgetPivotA = new Vec3Setter(LinearClearance);
        widgetPivotA->setObjectName(QStringLiteral("widgetPivotA"));

        formLayout->setWidget(1, QFormLayout::FieldRole, widgetPivotA);

        label_3 = new QLabel(LinearClearance);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        widgetPivotB = new Vec3Setter(LinearClearance);
        widgetPivotB->setObjectName(QStringLiteral("widgetPivotB"));

        formLayout->setWidget(2, QFormLayout::FieldRole, widgetPivotB);

        label_4 = new QLabel(LinearClearance);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        widgetBasisA = new RotationSetter(LinearClearance);
        widgetBasisA->setObjectName(QStringLiteral("widgetBasisA"));

        formLayout->setWidget(3, QFormLayout::FieldRole, widgetBasisA);

        label_5 = new QLabel(LinearClearance);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        widgetBasisB = new RotationSetter(LinearClearance);
        widgetBasisB->setObjectName(QStringLiteral("widgetBasisB"));

        formLayout->setWidget(4, QFormLayout::FieldRole, widgetBasisB);

        label_6 = new QLabel(LinearClearance);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        widgetMin = new Vec3Setter(LinearClearance);
        widgetMin->setObjectName(QStringLiteral("widgetMin"));

        formLayout->setWidget(5, QFormLayout::FieldRole, widgetMin);

        label_9 = new QLabel(LinearClearance);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_9);

        widgetMax = new Vec3Setter(LinearClearance);
        widgetMax->setObjectName(QStringLiteral("widgetMax"));

        formLayout->setWidget(6, QFormLayout::FieldRole, widgetMax);

        label_7 = new QLabel(LinearClearance);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_7);

        spinBoxFriction = new QDoubleSpinBox(LinearClearance);
        spinBoxFriction->setObjectName(QStringLiteral("spinBoxFriction"));
        spinBoxFriction->setDecimals(6);
        spinBoxFriction->setMaximum(9999);

        formLayout->setWidget(7, QFormLayout::FieldRole, spinBoxFriction);

        label_8 = new QLabel(LinearClearance);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_8);

        widgetMotor = new MotorSelector(LinearClearance);
        widgetMotor->setObjectName(QStringLiteral("widgetMotor"));

        formLayout->setWidget(8, QFormLayout::FieldRole, widgetMotor);

        label_10 = new QLabel(LinearClearance);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_10);

        spinBoxMotorTarget = new QDoubleSpinBox(LinearClearance);
        spinBoxMotorTarget->setObjectName(QStringLiteral("spinBoxMotorTarget"));
        spinBoxMotorTarget->setDecimals(6);
        spinBoxMotorTarget->setMinimum(-9999);
        spinBoxMotorTarget->setMaximum(9999);

        formLayout->setWidget(9, QFormLayout::FieldRole, spinBoxMotorTarget);


        retranslateUi(LinearClearance);

        QMetaObject::connectSlotsByName(LinearClearance);
    } // setupUi

    void retranslateUi(QWidget *LinearClearance)
    {
        LinearClearance->setWindowTitle(QApplication::translate("LinearClearance", "Form", 0));
        label->setText(QApplication::translate("LinearClearance", "Type:", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("LinearClearance", "Prismatic", 0)
         << QApplication::translate("LinearClearance", "Hinge", 0)
         << QApplication::translate("LinearClearance", "Ball Socket", 0)
        );
        label_2->setText(QApplication::translate("LinearClearance", "Pivot A:", 0));
        label_3->setText(QApplication::translate("LinearClearance", "Pivot B:", 0));
        label_4->setText(QApplication::translate("LinearClearance", "Basis A:", 0));
        label_5->setText(QApplication::translate("LinearClearance", "Basis B:", 0));
        label_6->setText(QApplication::translate("LinearClearance", "Min Limits:", 0));
        label_9->setText(QApplication::translate("LinearClearance", "Max Limits:", 0));
        label_7->setText(QApplication::translate("LinearClearance", "Max Friction:", 0));
        label_8->setText(QApplication::translate("LinearClearance", "Motor:", 0));
        label_10->setText(QApplication::translate("LinearClearance", "Motor Target:", 0));
    } // retranslateUi

};

namespace Ui {
    class LinearClearance: public Ui_LinearClearance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINEARCLEARANCE_H
