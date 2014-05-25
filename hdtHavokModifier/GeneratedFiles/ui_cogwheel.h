/********************************************************************************
** Form generated from reading UI file 'cogwheel.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COGWHEEL_H
#define UI_COGWHEEL_H

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

class Ui_CogWheel
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    Vec3Setter *widgetPivotA;
    QLabel *label_2;
    Vec3Setter *widgetPivotB;
    QLabel *label_3;
    Vec3Setter *widgetAxisA;
    QLabel *label_4;
    Vec3Setter *widgetAxisB;
    QLabel *label_5;
    QDoubleSpinBox *spinBoxRadiusA;
    QLabel *label_6;
    QDoubleSpinBox *spinBoxRadiusB;

    void setupUi(QWidget *CogWheel)
    {
        if (CogWheel->objectName().isEmpty())
            CogWheel->setObjectName(QStringLiteral("CogWheel"));
        CogWheel->resize(319, 118);
        formLayout = new QFormLayout(CogWheel);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(CogWheel);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        widgetPivotA = new Vec3Setter(CogWheel);
        widgetPivotA->setObjectName(QStringLiteral("widgetPivotA"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widgetPivotA->sizePolicy().hasHeightForWidth());
        widgetPivotA->setSizePolicy(sizePolicy1);

        formLayout->setWidget(0, QFormLayout::FieldRole, widgetPivotA);

        label_2 = new QLabel(CogWheel);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        widgetPivotB = new Vec3Setter(CogWheel);
        widgetPivotB->setObjectName(QStringLiteral("widgetPivotB"));
        sizePolicy1.setHeightForWidth(widgetPivotB->sizePolicy().hasHeightForWidth());
        widgetPivotB->setSizePolicy(sizePolicy1);

        formLayout->setWidget(1, QFormLayout::FieldRole, widgetPivotB);

        label_3 = new QLabel(CogWheel);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        widgetAxisA = new Vec3Setter(CogWheel);
        widgetAxisA->setObjectName(QStringLiteral("widgetAxisA"));
        sizePolicy1.setHeightForWidth(widgetAxisA->sizePolicy().hasHeightForWidth());
        widgetAxisA->setSizePolicy(sizePolicy1);

        formLayout->setWidget(2, QFormLayout::FieldRole, widgetAxisA);

        label_4 = new QLabel(CogWheel);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        widgetAxisB = new Vec3Setter(CogWheel);
        widgetAxisB->setObjectName(QStringLiteral("widgetAxisB"));
        sizePolicy1.setHeightForWidth(widgetAxisB->sizePolicy().hasHeightForWidth());
        widgetAxisB->setSizePolicy(sizePolicy1);

        formLayout->setWidget(3, QFormLayout::FieldRole, widgetAxisB);

        label_5 = new QLabel(CogWheel);
        label_5->setObjectName(QStringLiteral("label_5"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        spinBoxRadiusA = new QDoubleSpinBox(CogWheel);
        spinBoxRadiusA->setObjectName(QStringLiteral("spinBoxRadiusA"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(spinBoxRadiusA->sizePolicy().hasHeightForWidth());
        spinBoxRadiusA->setSizePolicy(sizePolicy3);
        spinBoxRadiusA->setDecimals(6);
        spinBoxRadiusA->setMaximum(9999);

        formLayout->setWidget(4, QFormLayout::FieldRole, spinBoxRadiusA);

        label_6 = new QLabel(CogWheel);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        spinBoxRadiusB = new QDoubleSpinBox(CogWheel);
        spinBoxRadiusB->setObjectName(QStringLiteral("spinBoxRadiusB"));
        spinBoxRadiusB->setDecimals(6);
        spinBoxRadiusB->setMaximum(9999);

        formLayout->setWidget(5, QFormLayout::FieldRole, spinBoxRadiusB);


        retranslateUi(CogWheel);

        QMetaObject::connectSlotsByName(CogWheel);
    } // setupUi

    void retranslateUi(QWidget *CogWheel)
    {
        CogWheel->setWindowTitle(QApplication::translate("CogWheel", "Form", 0));
        label->setText(QApplication::translate("CogWheel", "Pivot A(A space):", 0));
        label_2->setText(QApplication::translate("CogWheel", "Pivot B(B space):", 0));
        label_3->setText(QApplication::translate("CogWheel", "Axis A(A space):", 0));
        label_4->setText(QApplication::translate("CogWheel", "Axis B(B space):", 0));
        label_5->setText(QApplication::translate("CogWheel", "Radius A:", 0));
        label_6->setText(QApplication::translate("CogWheel", "Radius B:", 0));
    } // retranslateUi

};

namespace Ui {
    class CogWheel: public Ui_CogWheel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COGWHEEL_H
