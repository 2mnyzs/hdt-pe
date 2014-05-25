/********************************************************************************
** Form generated from reading UI file 'chainpowered.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAINPOWERED_H
#define UI_CHAINPOWERED_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "motorselector.h"
#include "rotationsetter.h"
#include "vec3setter.h"

QT_BEGIN_NAMESPACE

class Ui_ChainPowered
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    Vec3Setter *pivotA;
    QLabel *label_2;
    Vec3Setter *pivotB;
    QLabel *label_8;
    RotationSetter *basisA;
    QLabel *label_9;
    RotationSetter *basisB;
    QCheckBox *switchBodies;
    QLabel *label_5;
    MotorSelector *motorX;
    QLabel *label_6;
    MotorSelector *motorY;
    QLabel *label_7;
    MotorSelector *motorZ;

    void setupUi(QWidget *ChainPowered)
    {
        if (ChainPowered->objectName().isEmpty())
            ChainPowered->setObjectName(QStringLiteral("ChainPowered"));
        ChainPowered->resize(155, 142);
        formLayout = new QFormLayout(ChainPowered);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(ChainPowered);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        pivotA = new Vec3Setter(ChainPowered);
        pivotA->setObjectName(QStringLiteral("pivotA"));

        formLayout->setWidget(0, QFormLayout::FieldRole, pivotA);

        label_2 = new QLabel(ChainPowered);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        pivotB = new Vec3Setter(ChainPowered);
        pivotB->setObjectName(QStringLiteral("pivotB"));

        formLayout->setWidget(1, QFormLayout::FieldRole, pivotB);

        label_8 = new QLabel(ChainPowered);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_8);

        basisA = new RotationSetter(ChainPowered);
        basisA->setObjectName(QStringLiteral("basisA"));

        formLayout->setWidget(2, QFormLayout::FieldRole, basisA);

        label_9 = new QLabel(ChainPowered);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_9);

        basisB = new RotationSetter(ChainPowered);
        basisB->setObjectName(QStringLiteral("basisB"));

        formLayout->setWidget(3, QFormLayout::FieldRole, basisB);

        switchBodies = new QCheckBox(ChainPowered);
        switchBodies->setObjectName(QStringLiteral("switchBodies"));

        formLayout->setWidget(4, QFormLayout::FieldRole, switchBodies);

        label_5 = new QLabel(ChainPowered);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        motorX = new MotorSelector(ChainPowered);
        motorX->setObjectName(QStringLiteral("motorX"));

        formLayout->setWidget(5, QFormLayout::FieldRole, motorX);

        label_6 = new QLabel(ChainPowered);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_6);

        motorY = new MotorSelector(ChainPowered);
        motorY->setObjectName(QStringLiteral("motorY"));

        formLayout->setWidget(6, QFormLayout::FieldRole, motorY);

        label_7 = new QLabel(ChainPowered);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_7);

        motorZ = new MotorSelector(ChainPowered);
        motorZ->setObjectName(QStringLiteral("motorZ"));

        formLayout->setWidget(7, QFormLayout::FieldRole, motorZ);


        retranslateUi(ChainPowered);

        QMetaObject::connectSlotsByName(ChainPowered);
    } // setupUi

    void retranslateUi(QWidget *ChainPowered)
    {
        ChainPowered->setWindowTitle(QApplication::translate("ChainPowered", "Form", 0));
        label->setText(QApplication::translate("ChainPowered", "Pivot A:", 0));
        label_2->setText(QApplication::translate("ChainPowered", "Pivot B:", 0));
        label_8->setText(QApplication::translate("ChainPowered", "Basis A:", 0));
        label_9->setText(QApplication::translate("ChainPowered", "Basis B:", 0));
        switchBodies->setText(QApplication::translate("ChainPowered", "Switch Bodies", 0));
        label_5->setText(QApplication::translate("ChainPowered", "Motor X:", 0));
        label_6->setText(QApplication::translate("ChainPowered", "Motor Y:", 0));
        label_7->setText(QApplication::translate("ChainPowered", "Motor Z:", 0));
    } // retranslateUi

};

namespace Ui {
    class ChainPowered: public Ui_ChainPowered {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAINPOWERED_H
