/********************************************************************************
** Form generated from reading UI file 'capsuleshapesetter.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAPSULESHAPESETTER_H
#define UI_CAPSULESHAPESETTER_H

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

class Ui_CapsuleShapeSetter
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    Vec3Setter *widgetVertex1;
    Vec3Setter *widgetVertex2;
    QDoubleSpinBox *spinBoxRadius;

    void setupUi(QWidget *CapsuleShapeSetter)
    {
        if (CapsuleShapeSetter->objectName().isEmpty())
            CapsuleShapeSetter->setObjectName(QStringLiteral("CapsuleShapeSetter"));
        CapsuleShapeSetter->resize(196, 56);
        formLayout = new QFormLayout(CapsuleShapeSetter);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(CapsuleShapeSetter);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(CapsuleShapeSetter);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(CapsuleShapeSetter);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        widgetVertex1 = new Vec3Setter(CapsuleShapeSetter);
        widgetVertex1->setObjectName(QStringLiteral("widgetVertex1"));

        formLayout->setWidget(0, QFormLayout::FieldRole, widgetVertex1);

        widgetVertex2 = new Vec3Setter(CapsuleShapeSetter);
        widgetVertex2->setObjectName(QStringLiteral("widgetVertex2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, widgetVertex2);

        spinBoxRadius = new QDoubleSpinBox(CapsuleShapeSetter);
        spinBoxRadius->setObjectName(QStringLiteral("spinBoxRadius"));
        spinBoxRadius->setDecimals(6);
        spinBoxRadius->setMaximum(1e+09);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBoxRadius);


        retranslateUi(CapsuleShapeSetter);

        QMetaObject::connectSlotsByName(CapsuleShapeSetter);
    } // setupUi

    void retranslateUi(QWidget *CapsuleShapeSetter)
    {
        CapsuleShapeSetter->setWindowTitle(QApplication::translate("CapsuleShapeSetter", "Form", 0));
        label->setText(QApplication::translate("CapsuleShapeSetter", "Vertex1:", 0));
        label_2->setText(QApplication::translate("CapsuleShapeSetter", "Vertex2", 0));
        label_3->setText(QApplication::translate("CapsuleShapeSetter", "Radius:", 0));
    } // retranslateUi

};

namespace Ui {
    class CapsuleShapeSetter: public Ui_CapsuleShapeSetter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAPSULESHAPESETTER_H
