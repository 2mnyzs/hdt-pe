/********************************************************************************
** Form generated from reading UI file 'chainstiffspring.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAINSTIFFSPRING_H
#define UI_CHAINSTIFFSPRING_H

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

class Ui_ChainStiffSpring
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    Vec3Setter *pivotA;
    QLabel *label_2;
    Vec3Setter *pivotB;
    QLabel *label_5;
    QDoubleSpinBox *length;

    void setupUi(QWidget *ChainStiffSpring)
    {
        if (ChainStiffSpring->objectName().isEmpty())
            ChainStiffSpring->setObjectName(QStringLiteral("ChainStiffSpring"));
        ChainStiffSpring->resize(148, 56);
        formLayout = new QFormLayout(ChainStiffSpring);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(ChainStiffSpring);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        pivotA = new Vec3Setter(ChainStiffSpring);
        pivotA->setObjectName(QStringLiteral("pivotA"));

        formLayout->setWidget(0, QFormLayout::FieldRole, pivotA);

        label_2 = new QLabel(ChainStiffSpring);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        pivotB = new Vec3Setter(ChainStiffSpring);
        pivotB->setObjectName(QStringLiteral("pivotB"));

        formLayout->setWidget(1, QFormLayout::FieldRole, pivotB);

        label_5 = new QLabel(ChainStiffSpring);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        length = new QDoubleSpinBox(ChainStiffSpring);
        length->setObjectName(QStringLiteral("length"));
        length->setDecimals(6);
        length->setMaximum(9999);

        formLayout->setWidget(2, QFormLayout::FieldRole, length);


        retranslateUi(ChainStiffSpring);

        QMetaObject::connectSlotsByName(ChainStiffSpring);
    } // setupUi

    void retranslateUi(QWidget *ChainStiffSpring)
    {
        ChainStiffSpring->setWindowTitle(QApplication::translate("ChainStiffSpring", "Form", 0));
        label->setText(QApplication::translate("ChainStiffSpring", "Pivot A:", 0));
        label_2->setText(QApplication::translate("ChainStiffSpring", "Pivot B:", 0));
        label_5->setText(QApplication::translate("ChainStiffSpring", "Length:", 0));
    } // retranslateUi

};

namespace Ui {
    class ChainStiffSpring: public Ui_ChainStiffSpring {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAINSTIFFSPRING_H
