/********************************************************************************
** Form generated from reading UI file 'hingelimits.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HINGELIMITS_H
#define UI_HINGELIMITS_H

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
#include "rotationsetter.h"

QT_BEGIN_NAMESPACE

class Ui_HingeLimits
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    RotationSetter *widgetBasisA;
    RotationSetter *widgetBasisB;
    QLabel *label_3;
    QLabel *label_4;
    QDoubleSpinBox *spinBoxMin;
    QDoubleSpinBox *spinBoxMax;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioRadius;
    QRadioButton *radioDegree;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *HingeLimits)
    {
        if (HingeLimits->objectName().isEmpty())
            HingeLimits->setObjectName(QStringLiteral("HingeLimits"));
        HingeLimits->resize(314, 200);
        formLayout = new QFormLayout(HingeLimits);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(HingeLimits);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(HingeLimits);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        widgetBasisA = new RotationSetter(HingeLimits);
        widgetBasisA->setObjectName(QStringLiteral("widgetBasisA"));

        formLayout->setWidget(0, QFormLayout::FieldRole, widgetBasisA);

        widgetBasisB = new RotationSetter(HingeLimits);
        widgetBasisB->setObjectName(QStringLiteral("widgetBasisB"));

        formLayout->setWidget(1, QFormLayout::FieldRole, widgetBasisB);

        label_3 = new QLabel(HingeLimits);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(HingeLimits);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        spinBoxMin = new QDoubleSpinBox(HingeLimits);
        spinBoxMin->setObjectName(QStringLiteral("spinBoxMin"));
        spinBoxMin->setDecimals(4);
        spinBoxMin->setMinimum(-9999);
        spinBoxMin->setMaximum(9999);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBoxMin);

        spinBoxMax = new QDoubleSpinBox(HingeLimits);
        spinBoxMax->setObjectName(QStringLiteral("spinBoxMax"));
        spinBoxMax->setDecimals(4);
        spinBoxMax->setMinimum(-9999);
        spinBoxMax->setMaximum(9999);

        formLayout->setWidget(3, QFormLayout::FieldRole, spinBoxMax);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radioRadius = new QRadioButton(HingeLimits);
        radioRadius->setObjectName(QStringLiteral("radioRadius"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(radioRadius->sizePolicy().hasHeightForWidth());
        radioRadius->setSizePolicy(sizePolicy);
        radioRadius->setChecked(true);

        horizontalLayout->addWidget(radioRadius);

        radioDegree = new QRadioButton(HingeLimits);
        radioDegree->setObjectName(QStringLiteral("radioDegree"));
        sizePolicy.setHeightForWidth(radioDegree->sizePolicy().hasHeightForWidth());
        radioDegree->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(radioDegree);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        formLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout);


        retranslateUi(HingeLimits);

        QMetaObject::connectSlotsByName(HingeLimits);
    } // setupUi

    void retranslateUi(QWidget *HingeLimits)
    {
        HingeLimits->setWindowTitle(QApplication::translate("HingeLimits", "Form", 0));
        label->setText(QApplication::translate("HingeLimits", "Basis A:", 0));
        label_2->setText(QApplication::translate("HingeLimits", "Basis B:", 0));
        label_3->setText(QApplication::translate("HingeLimits", "Min Limit:", 0));
        label_4->setText(QApplication::translate("HingeLimits", "Max Limit:", 0));
        radioRadius->setText(QApplication::translate("HingeLimits", "Radius", 0));
        radioDegree->setText(QApplication::translate("HingeLimits", "Degree", 0));
    } // retranslateUi

};

namespace Ui {
    class HingeLimits: public Ui_HingeLimits {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HINGELIMITS_H
