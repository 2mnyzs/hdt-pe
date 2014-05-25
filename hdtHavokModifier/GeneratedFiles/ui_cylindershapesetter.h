/********************************************************************************
** Form generated from reading UI file 'cylindershapesetter.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CYLINDERSHAPESETTER_H
#define UI_CYLINDERSHAPESETTER_H

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

class Ui_CylinderShapeSetter
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    Vec3Setter *widgetVertex1;
    QLabel *label_2;
    Vec3Setter *widgetVertex2;
    QLabel *label_3;
    QDoubleSpinBox *spinBoxRadius;
    QLabel *label_4;
    QDoubleSpinBox *spinBoxMargin;

    void setupUi(QWidget *CylinderShapeSetter)
    {
        if (CylinderShapeSetter->objectName().isEmpty())
            CylinderShapeSetter->setObjectName(QStringLiteral("CylinderShapeSetter"));
        CylinderShapeSetter->resize(225, 82);
        formLayout = new QFormLayout(CylinderShapeSetter);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(CylinderShapeSetter);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        widgetVertex1 = new Vec3Setter(CylinderShapeSetter);
        widgetVertex1->setObjectName(QStringLiteral("widgetVertex1"));

        formLayout->setWidget(0, QFormLayout::FieldRole, widgetVertex1);

        label_2 = new QLabel(CylinderShapeSetter);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        widgetVertex2 = new Vec3Setter(CylinderShapeSetter);
        widgetVertex2->setObjectName(QStringLiteral("widgetVertex2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, widgetVertex2);

        label_3 = new QLabel(CylinderShapeSetter);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        spinBoxRadius = new QDoubleSpinBox(CylinderShapeSetter);
        spinBoxRadius->setObjectName(QStringLiteral("spinBoxRadius"));
        spinBoxRadius->setDecimals(6);
        spinBoxRadius->setMaximum(1e+09);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBoxRadius);

        label_4 = new QLabel(CylinderShapeSetter);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        spinBoxMargin = new QDoubleSpinBox(CylinderShapeSetter);
        spinBoxMargin->setObjectName(QStringLiteral("spinBoxMargin"));
        spinBoxMargin->setDecimals(6);
        spinBoxMargin->setMaximum(9999);

        formLayout->setWidget(3, QFormLayout::FieldRole, spinBoxMargin);


        retranslateUi(CylinderShapeSetter);

        QMetaObject::connectSlotsByName(CylinderShapeSetter);
    } // setupUi

    void retranslateUi(QWidget *CylinderShapeSetter)
    {
        CylinderShapeSetter->setWindowTitle(QApplication::translate("CylinderShapeSetter", "Form", 0));
        label->setText(QApplication::translate("CylinderShapeSetter", "Vertex1:", 0));
        label_2->setText(QApplication::translate("CylinderShapeSetter", "Vertex2", 0));
        label_3->setText(QApplication::translate("CylinderShapeSetter", "Radius:", 0));
        label_4->setText(QApplication::translate("CylinderShapeSetter", "Margin", 0));
    } // retranslateUi

};

namespace Ui {
    class CylinderShapeSetter: public Ui_CylinderShapeSetter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CYLINDERSHAPESETTER_H
