/********************************************************************************
** Form generated from reading UI file 'translatedshapesetter.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSLATEDSHAPESETTER_H
#define UI_TRANSLATEDSHAPESETTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "shapeselector.h"
#include "vec3setter.h"

QT_BEGIN_NAMESPACE

class Ui_TranslatedShapeSetter
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    Vec3Setter *widgetTranslation;
    ShapeSelector *widgetShape;

    void setupUi(QWidget *TranslatedShapeSetter)
    {
        if (TranslatedShapeSetter->objectName().isEmpty())
            TranslatedShapeSetter->setObjectName(QStringLiteral("TranslatedShapeSetter"));
        TranslatedShapeSetter->resize(271, 30);
        formLayout = new QFormLayout(TranslatedShapeSetter);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(TranslatedShapeSetter);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(TranslatedShapeSetter);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        widgetTranslation = new Vec3Setter(TranslatedShapeSetter);
        widgetTranslation->setObjectName(QStringLiteral("widgetTranslation"));

        formLayout->setWidget(1, QFormLayout::FieldRole, widgetTranslation);

        widgetShape = new ShapeSelector(TranslatedShapeSetter);
        widgetShape->setObjectName(QStringLiteral("widgetShape"));

        formLayout->setWidget(0, QFormLayout::FieldRole, widgetShape);


        retranslateUi(TranslatedShapeSetter);

        QMetaObject::connectSlotsByName(TranslatedShapeSetter);
    } // setupUi

    void retranslateUi(QWidget *TranslatedShapeSetter)
    {
        TranslatedShapeSetter->setWindowTitle(QApplication::translate("TranslatedShapeSetter", "Form", 0));
        label->setText(QApplication::translate("TranslatedShapeSetter", "Child Shape:", 0));
        label_2->setText(QApplication::translate("TranslatedShapeSetter", "Translation:", 0));
    } // retranslateUi

};

namespace Ui {
    class TranslatedShapeSetter: public Ui_TranslatedShapeSetter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSLATEDSHAPESETTER_H
