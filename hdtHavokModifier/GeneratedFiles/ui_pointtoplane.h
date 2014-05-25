/********************************************************************************
** Form generated from reading UI file 'pointtoplane.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POINTTOPLANE_H
#define UI_POINTTOPLANE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "vec3setter.h"

QT_BEGIN_NAMESPACE

class Ui_PointToPlane
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    Vec3Setter *widgetPivotA;
    Vec3Setter *widgetPivotB;
    Vec3Setter *widgetNormalB;

    void setupUi(QWidget *PointToPlane)
    {
        if (PointToPlane->objectName().isEmpty())
            PointToPlane->setObjectName(QStringLiteral("PointToPlane"));
        PointToPlane->resize(400, 48);
        formLayout = new QFormLayout(PointToPlane);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(PointToPlane);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(PointToPlane);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(PointToPlane);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        widgetPivotA = new Vec3Setter(PointToPlane);
        widgetPivotA->setObjectName(QStringLiteral("widgetPivotA"));

        formLayout->setWidget(0, QFormLayout::FieldRole, widgetPivotA);

        widgetPivotB = new Vec3Setter(PointToPlane);
        widgetPivotB->setObjectName(QStringLiteral("widgetPivotB"));

        formLayout->setWidget(1, QFormLayout::FieldRole, widgetPivotB);

        widgetNormalB = new Vec3Setter(PointToPlane);
        widgetNormalB->setObjectName(QStringLiteral("widgetNormalB"));

        formLayout->setWidget(2, QFormLayout::FieldRole, widgetNormalB);


        retranslateUi(PointToPlane);

        QMetaObject::connectSlotsByName(PointToPlane);
    } // setupUi

    void retranslateUi(QWidget *PointToPlane)
    {
        PointToPlane->setWindowTitle(QApplication::translate("PointToPlane", "Form", 0));
        label->setText(QApplication::translate("PointToPlane", "Pivot A:", 0));
        label_2->setText(QApplication::translate("PointToPlane", "Pivot B:", 0));
        label_3->setText(QApplication::translate("PointToPlane", "Normal B:", 0));
    } // retranslateUi

};

namespace Ui {
    class PointToPlane: public Ui_PointToPlane {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POINTTOPLANE_H
