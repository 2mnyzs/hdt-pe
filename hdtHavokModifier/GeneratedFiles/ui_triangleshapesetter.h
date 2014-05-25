/********************************************************************************
** Form generated from reading UI file 'triangleshapesetter.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIANGLESHAPESETTER_H
#define UI_TRIANGLESHAPESETTER_H

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

class Ui_TriangleShapeSetter
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    Vec3Setter *widgetV1;
    QLabel *label_2;
    Vec3Setter *widgetV2;
    QLabel *label_3;
    Vec3Setter *widgetV3;
    QLabel *label_4;
    QDoubleSpinBox *spinBoxMargin;

    void setupUi(QWidget *TriangleShapeSetter)
    {
        if (TriangleShapeSetter->objectName().isEmpty())
            TriangleShapeSetter->setObjectName(QStringLiteral("TriangleShapeSetter"));
        TriangleShapeSetter->resize(370, 74);
        formLayout = new QFormLayout(TriangleShapeSetter);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(TriangleShapeSetter);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        widgetV1 = new Vec3Setter(TriangleShapeSetter);
        widgetV1->setObjectName(QStringLiteral("widgetV1"));

        formLayout->setWidget(0, QFormLayout::FieldRole, widgetV1);

        label_2 = new QLabel(TriangleShapeSetter);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        widgetV2 = new Vec3Setter(TriangleShapeSetter);
        widgetV2->setObjectName(QStringLiteral("widgetV2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, widgetV2);

        label_3 = new QLabel(TriangleShapeSetter);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        widgetV3 = new Vec3Setter(TriangleShapeSetter);
        widgetV3->setObjectName(QStringLiteral("widgetV3"));

        formLayout->setWidget(2, QFormLayout::FieldRole, widgetV3);

        label_4 = new QLabel(TriangleShapeSetter);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        spinBoxMargin = new QDoubleSpinBox(TriangleShapeSetter);
        spinBoxMargin->setObjectName(QStringLiteral("spinBoxMargin"));
        spinBoxMargin->setDecimals(6);

        formLayout->setWidget(3, QFormLayout::FieldRole, spinBoxMargin);


        retranslateUi(TriangleShapeSetter);

        QMetaObject::connectSlotsByName(TriangleShapeSetter);
    } // setupUi

    void retranslateUi(QWidget *TriangleShapeSetter)
    {
        TriangleShapeSetter->setWindowTitle(QApplication::translate("TriangleShapeSetter", "Form", 0));
        label->setText(QApplication::translate("TriangleShapeSetter", "Vertex1:", 0));
        label_2->setText(QApplication::translate("TriangleShapeSetter", "Vertex2:", 0));
        label_3->setText(QApplication::translate("TriangleShapeSetter", "Vertex3:", 0));
        label_4->setText(QApplication::translate("TriangleShapeSetter", "Margin:", 0));
    } // retranslateUi

};

namespace Ui {
    class TriangleShapeSetter: public Ui_TriangleShapeSetter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIANGLESHAPESETTER_H
