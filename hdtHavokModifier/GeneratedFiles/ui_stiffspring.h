/********************************************************************************
** Form generated from reading UI file 'stiffspring.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STIFFSPRING_H
#define UI_STIFFSPRING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "vec3setter.h"

QT_BEGIN_NAMESPACE

class Ui_StiffSpring
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    Vec3Setter *widgetPivotA;
    QLabel *label_2;
    Vec3Setter *widgetPivotB;
    QLabel *label_3;
    QLabel *label_4;
    QDoubleSpinBox *spinBoxMin;
    QDoubleSpinBox *spinBoxMax;

    void setupUi(QWidget *StiffSpring)
    {
        if (StiffSpring->objectName().isEmpty())
            StiffSpring->setObjectName(QStringLiteral("StiffSpring"));
        StiffSpring->resize(400, 82);
        formLayout = new QFormLayout(StiffSpring);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(StiffSpring);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        widgetPivotA = new Vec3Setter(StiffSpring);
        widgetPivotA->setObjectName(QStringLiteral("widgetPivotA"));

        formLayout->setWidget(0, QFormLayout::FieldRole, widgetPivotA);

        label_2 = new QLabel(StiffSpring);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        widgetPivotB = new Vec3Setter(StiffSpring);
        widgetPivotB->setObjectName(QStringLiteral("widgetPivotB"));

        formLayout->setWidget(1, QFormLayout::FieldRole, widgetPivotB);

        label_3 = new QLabel(StiffSpring);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(StiffSpring);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        spinBoxMin = new QDoubleSpinBox(StiffSpring);
        spinBoxMin->setObjectName(QStringLiteral("spinBoxMin"));
        spinBoxMin->setDecimals(4);
        spinBoxMin->setMaximum(9999);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBoxMin);

        spinBoxMax = new QDoubleSpinBox(StiffSpring);
        spinBoxMax->setObjectName(QStringLiteral("spinBoxMax"));
        spinBoxMax->setDecimals(4);
        spinBoxMax->setMaximum(9999);

        formLayout->setWidget(3, QFormLayout::FieldRole, spinBoxMax);


        retranslateUi(StiffSpring);

        QMetaObject::connectSlotsByName(StiffSpring);
    } // setupUi

    void retranslateUi(QWidget *StiffSpring)
    {
        StiffSpring->setWindowTitle(QApplication::translate("StiffSpring", "Form", 0));
        label->setText(QApplication::translate("StiffSpring", "Pivot A:", 0));
        label_2->setText(QApplication::translate("StiffSpring", "Pivot B:", 0));
        label_3->setText(QApplication::translate("StiffSpring", "Min Length:", 0));
        label_4->setText(QApplication::translate("StiffSpring", "Max Length:", 0));
    } // retranslateUi

};

namespace Ui {
    class StiffSpring: public Ui_StiffSpring {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STIFFSPRING_H
