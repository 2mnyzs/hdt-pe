/********************************************************************************
** Form generated from reading UI file 'limitedhinge.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIMITEDHINGE_H
#define UI_LIMITEDHINGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
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

class Ui_LimitedHinge
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
    QLabel *label_7;
    QLabel *label_6;
    QDoubleSpinBox *spinBoxMin;
    QLabel *label_5;
    QDoubleSpinBox *spinBoxMax;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioRadius;
    QRadioButton *radioDegree;
    QSpacerItem *horizontalSpacer;
    MotorSelector *widgetMotor;
    QLabel *label_8;
    QDoubleSpinBox *spinBoxTau;

    void setupUi(QWidget *LimitedHinge)
    {
        if (LimitedHinge->objectName().isEmpty())
            LimitedHinge->setObjectName(QStringLiteral("LimitedHinge"));
        LimitedHinge->resize(400, 249);
        formLayout = new QFormLayout(LimitedHinge);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(LimitedHinge);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        widgetPivotA = new Vec3Setter(LimitedHinge);
        widgetPivotA->setObjectName(QStringLiteral("widgetPivotA"));

        formLayout->setWidget(0, QFormLayout::FieldRole, widgetPivotA);

        label_2 = new QLabel(LimitedHinge);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        widgetPivotB = new Vec3Setter(LimitedHinge);
        widgetPivotB->setObjectName(QStringLiteral("widgetPivotB"));

        formLayout->setWidget(1, QFormLayout::FieldRole, widgetPivotB);

        label_3 = new QLabel(LimitedHinge);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        widgetBasisA = new RotationSetter(LimitedHinge);
        widgetBasisA->setObjectName(QStringLiteral("widgetBasisA"));

        formLayout->setWidget(2, QFormLayout::FieldRole, widgetBasisA);

        label_4 = new QLabel(LimitedHinge);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        widgetBasisB = new RotationSetter(LimitedHinge);
        widgetBasisB->setObjectName(QStringLiteral("widgetBasisB"));

        formLayout->setWidget(3, QFormLayout::FieldRole, widgetBasisB);

        label_7 = new QLabel(LimitedHinge);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_7);

        label_6 = new QLabel(LimitedHinge);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_6);

        spinBoxMin = new QDoubleSpinBox(LimitedHinge);
        spinBoxMin->setObjectName(QStringLiteral("spinBoxMin"));
        spinBoxMin->setDecimals(6);
        spinBoxMin->setMinimum(-9999);
        spinBoxMin->setMaximum(9999);

        formLayout->setWidget(4, QFormLayout::FieldRole, spinBoxMin);

        label_5 = new QLabel(LimitedHinge);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        spinBoxMax = new QDoubleSpinBox(LimitedHinge);
        spinBoxMax->setObjectName(QStringLiteral("spinBoxMax"));
        spinBoxMax->setDecimals(6);
        spinBoxMax->setMinimum(-9999);
        spinBoxMax->setMaximum(9999);

        formLayout->setWidget(5, QFormLayout::FieldRole, spinBoxMax);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radioRadius = new QRadioButton(LimitedHinge);
        radioRadius->setObjectName(QStringLiteral("radioRadius"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(radioRadius->sizePolicy().hasHeightForWidth());
        radioRadius->setSizePolicy(sizePolicy);
        radioRadius->setChecked(true);

        horizontalLayout->addWidget(radioRadius);

        radioDegree = new QRadioButton(LimitedHinge);
        radioDegree->setObjectName(QStringLiteral("radioDegree"));
        sizePolicy.setHeightForWidth(radioDegree->sizePolicy().hasHeightForWidth());
        radioDegree->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(radioDegree);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        formLayout->setLayout(6, QFormLayout::FieldRole, horizontalLayout);

        widgetMotor = new MotorSelector(LimitedHinge);
        widgetMotor->setObjectName(QStringLiteral("widgetMotor"));

        formLayout->setWidget(7, QFormLayout::FieldRole, widgetMotor);

        label_8 = new QLabel(LimitedHinge);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_8);

        spinBoxTau = new QDoubleSpinBox(LimitedHinge);
        spinBoxTau->setObjectName(QStringLiteral("spinBoxTau"));
        spinBoxTau->setDecimals(6);
        spinBoxTau->setMaximum(1);
        spinBoxTau->setSingleStep(0.01);
        spinBoxTau->setValue(1);

        formLayout->setWidget(8, QFormLayout::FieldRole, spinBoxTau);


        retranslateUi(LimitedHinge);

        QMetaObject::connectSlotsByName(LimitedHinge);
    } // setupUi

    void retranslateUi(QWidget *LimitedHinge)
    {
        LimitedHinge->setWindowTitle(QApplication::translate("LimitedHinge", "Form", 0));
        label->setText(QApplication::translate("LimitedHinge", "Pivot A:", 0));
        label_2->setText(QApplication::translate("LimitedHinge", "Pivot B:", 0));
        label_3->setText(QApplication::translate("LimitedHinge", "Basis A:", 0));
        label_4->setText(QApplication::translate("LimitedHinge", "Basis B:", 0));
        label_7->setText(QApplication::translate("LimitedHinge", "Motor:", 0));
        label_6->setText(QApplication::translate("LimitedHinge", "Min Limit:", 0));
        label_5->setText(QApplication::translate("LimitedHinge", "Max Limit:", 0));
        radioRadius->setText(QApplication::translate("LimitedHinge", "Radius", 0));
        radioDegree->setText(QApplication::translate("LimitedHinge", "Degree", 0));
        label_8->setText(QApplication::translate("LimitedHinge", "Tau:", 0));
    } // retranslateUi

};

namespace Ui {
    class LimitedHinge: public Ui_LimitedHinge {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIMITEDHINGE_H
