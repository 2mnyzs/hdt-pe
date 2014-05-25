/********************************************************************************
** Form generated from reading UI file 'rotational.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROTATIONAL_H
#define UI_ROTATIONAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "rotationsetter.h"

QT_BEGIN_NAMESPACE

class Ui_Rotational
{
public:
    QFormLayout *formLayout;
    QLabel *label_3;
    RotationSetter *widgetBasisA;
    QLabel *label_4;
    RotationSetter *widgetBasisB;

    void setupUi(QWidget *Rotational)
    {
        if (Rotational->objectName().isEmpty())
            Rotational->setObjectName(QStringLiteral("Rotational"));
        Rotational->resize(400, 300);
        formLayout = new QFormLayout(Rotational);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(Rotational);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        widgetBasisA = new RotationSetter(Rotational);
        widgetBasisA->setObjectName(QStringLiteral("widgetBasisA"));

        formLayout->setWidget(0, QFormLayout::FieldRole, widgetBasisA);

        label_4 = new QLabel(Rotational);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        widgetBasisB = new RotationSetter(Rotational);
        widgetBasisB->setObjectName(QStringLiteral("widgetBasisB"));

        formLayout->setWidget(1, QFormLayout::FieldRole, widgetBasisB);


        retranslateUi(Rotational);

        QMetaObject::connectSlotsByName(Rotational);
    } // setupUi

    void retranslateUi(QWidget *Rotational)
    {
        Rotational->setWindowTitle(QApplication::translate("Rotational", "Form", 0));
        label_3->setText(QApplication::translate("Rotational", "Basis A:", 0));
        label_4->setText(QApplication::translate("Rotational", "Basis B:", 0));
    } // retranslateUi

};

namespace Ui {
    class Rotational: public Ui_Rotational {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROTATIONAL_H
