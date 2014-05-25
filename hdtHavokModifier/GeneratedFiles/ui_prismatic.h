/********************************************************************************
** Form generated from reading UI file 'prismatic.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRISMATIC_H
#define UI_PRISMATIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "motorselector.h"
#include "rotationsetter.h"
#include "vec3setter.h"

QT_BEGIN_NAMESPACE

class Ui_Prismatic
{
public:
    QGridLayout *gridLayout;
    QLabel *label_8;
    QLabel *label;
    Vec3Setter *widgetPivotA;
    RotationSetter *widgetBasisA;
    RotationSetter *widgetBasisB;
    Vec3Setter *widgetPivotB;
    MotorSelector *widgetMotor;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_9;
    QLabel *label_2;
    QLabel *label_7;
    QLabel *label_6;
    QDoubleSpinBox *spinBoxMax;
    QDoubleSpinBox *spinBoxFriction;
    QDoubleSpinBox *spinBoxMin;
    QDoubleSpinBox *spinBoxMotorTarget;
    QCheckBox *checkBox;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Prismatic)
    {
        if (Prismatic->objectName().isEmpty())
            Prismatic->setObjectName(QStringLiteral("Prismatic"));
        Prismatic->resize(184, 300);
        gridLayout = new QGridLayout(Prismatic);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(Prismatic);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 8, 0, 1, 1);

        label = new QLabel(Prismatic);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 7, 0, 1, 1);

        widgetPivotA = new Vec3Setter(Prismatic);
        widgetPivotA->setObjectName(QStringLiteral("widgetPivotA"));

        gridLayout->addWidget(widgetPivotA, 0, 1, 1, 1);

        widgetBasisA = new RotationSetter(Prismatic);
        widgetBasisA->setObjectName(QStringLiteral("widgetBasisA"));

        gridLayout->addWidget(widgetBasisA, 2, 1, 1, 1);

        widgetBasisB = new RotationSetter(Prismatic);
        widgetBasisB->setObjectName(QStringLiteral("widgetBasisB"));

        gridLayout->addWidget(widgetBasisB, 3, 1, 1, 1);

        widgetPivotB = new Vec3Setter(Prismatic);
        widgetPivotB->setObjectName(QStringLiteral("widgetPivotB"));

        gridLayout->addWidget(widgetPivotB, 1, 1, 1, 1);

        widgetMotor = new MotorSelector(Prismatic);
        widgetMotor->setObjectName(QStringLiteral("widgetMotor"));

        gridLayout->addWidget(widgetMotor, 7, 1, 1, 1);

        label_4 = new QLabel(Prismatic);
        label_4->setObjectName(QStringLiteral("label_4"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_5 = new QLabel(Prismatic);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        label_3 = new QLabel(Prismatic);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_9 = new QLabel(Prismatic);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_9, 5, 0, 1, 1);

        label_2 = new QLabel(Prismatic);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_7 = new QLabel(Prismatic);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        label_6 = new QLabel(Prismatic);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        spinBoxMax = new QDoubleSpinBox(Prismatic);
        spinBoxMax->setObjectName(QStringLiteral("spinBoxMax"));
        spinBoxMax->setDecimals(6);

        gridLayout->addWidget(spinBoxMax, 5, 1, 1, 1);

        spinBoxFriction = new QDoubleSpinBox(Prismatic);
        spinBoxFriction->setObjectName(QStringLiteral("spinBoxFriction"));
        spinBoxFriction->setDecimals(6);
        spinBoxFriction->setMaximum(9999);

        gridLayout->addWidget(spinBoxFriction, 6, 1, 1, 1);

        spinBoxMin = new QDoubleSpinBox(Prismatic);
        spinBoxMin->setObjectName(QStringLiteral("spinBoxMin"));
        spinBoxMin->setDecimals(6);
        spinBoxMin->setMinimum(-9999);
        spinBoxMin->setMaximum(9999);

        gridLayout->addWidget(spinBoxMin, 4, 1, 1, 1);

        spinBoxMotorTarget = new QDoubleSpinBox(Prismatic);
        spinBoxMotorTarget->setObjectName(QStringLiteral("spinBoxMotorTarget"));
        spinBoxMotorTarget->setDecimals(6);
        spinBoxMotorTarget->setMinimum(-9999);
        spinBoxMotorTarget->setMaximum(9999);

        gridLayout->addWidget(spinBoxMotorTarget, 8, 1, 1, 1);

        checkBox = new QCheckBox(Prismatic);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 9, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 10, 0, 1, 1);

        QWidget::setTabOrder(spinBoxMin, spinBoxMax);
        QWidget::setTabOrder(spinBoxMax, spinBoxFriction);

        retranslateUi(Prismatic);

        QMetaObject::connectSlotsByName(Prismatic);
    } // setupUi

    void retranslateUi(QWidget *Prismatic)
    {
        Prismatic->setWindowTitle(QApplication::translate("Prismatic", "Form", 0));
        label_8->setText(QApplication::translate("Prismatic", "Motor Target:", 0));
        label->setText(QApplication::translate("Prismatic", "Motor:", 0));
        label_4->setText(QApplication::translate("Prismatic", "Basis A:", 0));
        label_5->setText(QApplication::translate("Prismatic", "Basis B:", 0));
        label_3->setText(QApplication::translate("Prismatic", "PivotB:", 0));
        label_9->setText(QApplication::translate("Prismatic", "Max Limits:", 0));
        label_2->setText(QApplication::translate("Prismatic", "PivotA:", 0));
        label_7->setText(QApplication::translate("Prismatic", "Max Friction:", 0));
        label_6->setText(QApplication::translate("Prismatic", "Min Limits:", 0));
        checkBox->setText(QApplication::translate("Prismatic", "Allow Rotation Around Axis", 0));
    } // retranslateUi

};

namespace Ui {
    class Prismatic: public Ui_Prismatic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRISMATIC_H
