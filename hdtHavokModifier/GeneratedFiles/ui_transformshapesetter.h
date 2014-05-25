/********************************************************************************
** Form generated from reading UI file 'transformshapesetter.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFORMSHAPESETTER_H
#define UI_TRANSFORMSHAPESETTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "rotationsetter.h"
#include "shapeselector.h"
#include "vec3setter.h"

QT_BEGIN_NAMESPACE

class Ui_TransformShapeSetter
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    Vec3Setter *widgetTranslation;
    QLabel *label_2;
    QLabel *label_3;
    Vec3Setter *widgetScaling;
    QLabel *label_4;
    RotationSetter *widgetRotation;
    ShapeSelector *widgetShape;

    void setupUi(QWidget *TransformShapeSetter)
    {
        if (TransformShapeSetter->objectName().isEmpty())
            TransformShapeSetter->setObjectName(QStringLiteral("TransformShapeSetter"));
        TransformShapeSetter->resize(387, 66);
        formLayout = new QFormLayout(TransformShapeSetter);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(TransformShapeSetter);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        widgetTranslation = new Vec3Setter(TransformShapeSetter);
        widgetTranslation->setObjectName(QStringLiteral("widgetTranslation"));

        formLayout->setWidget(0, QFormLayout::FieldRole, widgetTranslation);

        label_2 = new QLabel(TransformShapeSetter);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(TransformShapeSetter);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        widgetScaling = new Vec3Setter(TransformShapeSetter);
        widgetScaling->setObjectName(QStringLiteral("widgetScaling"));

        formLayout->setWidget(2, QFormLayout::FieldRole, widgetScaling);

        label_4 = new QLabel(TransformShapeSetter);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        widgetRotation = new RotationSetter(TransformShapeSetter);
        widgetRotation->setObjectName(QStringLiteral("widgetRotation"));

        formLayout->setWidget(1, QFormLayout::FieldRole, widgetRotation);

        widgetShape = new ShapeSelector(TransformShapeSetter);
        widgetShape->setObjectName(QStringLiteral("widgetShape"));

        formLayout->setWidget(3, QFormLayout::FieldRole, widgetShape);


        retranslateUi(TransformShapeSetter);

        QMetaObject::connectSlotsByName(TransformShapeSetter);
    } // setupUi

    void retranslateUi(QWidget *TransformShapeSetter)
    {
        TransformShapeSetter->setWindowTitle(QApplication::translate("TransformShapeSetter", "Form", 0));
        label->setText(QApplication::translate("TransformShapeSetter", "Translation:", 0));
        label_2->setText(QApplication::translate("TransformShapeSetter", "Rotation:", 0));
        label_3->setText(QApplication::translate("TransformShapeSetter", "Scaling:", 0));
        label_4->setText(QApplication::translate("TransformShapeSetter", "Child Shape:", 0));
    } // retranslateUi

};

namespace Ui {
    class TransformShapeSetter: public Ui_TransformShapeSetter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFORMSHAPESETTER_H
