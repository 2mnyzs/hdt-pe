/********************************************************************************
** Form generated from reading UI file 'boxshapesetter.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOXSHAPESETTER_H
#define UI_BOXSHAPESETTER_H

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

class Ui_BoxShapeSetter
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    Vec3Setter *widgetHalfExtents;
    QLabel *label_2;
    QDoubleSpinBox *spinBoxRadius;

    void setupUi(QWidget *BoxShapeSetter)
    {
        if (BoxShapeSetter->objectName().isEmpty())
            BoxShapeSetter->setObjectName(QStringLiteral("BoxShapeSetter"));
        BoxShapeSetter->resize(237, 38);
        formLayout = new QFormLayout(BoxShapeSetter);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(BoxShapeSetter);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        widgetHalfExtents = new Vec3Setter(BoxShapeSetter);
        widgetHalfExtents->setObjectName(QStringLiteral("widgetHalfExtents"));

        formLayout->setWidget(0, QFormLayout::FieldRole, widgetHalfExtents);

        label_2 = new QLabel(BoxShapeSetter);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        spinBoxRadius = new QDoubleSpinBox(BoxShapeSetter);
        spinBoxRadius->setObjectName(QStringLiteral("spinBoxRadius"));
        spinBoxRadius->setDecimals(6);
        spinBoxRadius->setMaximum(1e+09);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBoxRadius);


        retranslateUi(BoxShapeSetter);

        QMetaObject::connectSlotsByName(BoxShapeSetter);
    } // setupUi

    void retranslateUi(QWidget *BoxShapeSetter)
    {
        BoxShapeSetter->setWindowTitle(QApplication::translate("BoxShapeSetter", "Form", 0));
        label->setText(QApplication::translate("BoxShapeSetter", "Half Extents:", 0));
        label_2->setText(QApplication::translate("BoxShapeSetter", "Margin:", 0));
#ifndef QT_NO_TOOLTIP
        spinBoxRadius->setToolTip(QApplication::translate("BoxShapeSetter", "Seem like the margin. Suggestion : 0.", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class BoxShapeSetter: public Ui_BoxShapeSetter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOXSHAPESETTER_H
