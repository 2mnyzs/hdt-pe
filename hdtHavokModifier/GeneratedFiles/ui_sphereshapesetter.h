/********************************************************************************
** Form generated from reading UI file 'sphereshapesetter.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPHERESHAPESETTER_H
#define UI_SPHERESHAPESETTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SphereShapeSetter
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;

    void setupUi(QWidget *SphereShapeSetter)
    {
        if (SphereShapeSetter->objectName().isEmpty())
            SphereShapeSetter->setObjectName(QStringLiteral("SphereShapeSetter"));
        SphereShapeSetter->resize(172, 20);
        formLayout = new QFormLayout(SphereShapeSetter);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(SphereShapeSetter);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        doubleSpinBox = new QDoubleSpinBox(SphereShapeSetter);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setDecimals(6);
        doubleSpinBox->setMaximum(9999);
        doubleSpinBox->setSingleStep(1);

        formLayout->setWidget(0, QFormLayout::FieldRole, doubleSpinBox);


        retranslateUi(SphereShapeSetter);

        QMetaObject::connectSlotsByName(SphereShapeSetter);
    } // setupUi

    void retranslateUi(QWidget *SphereShapeSetter)
    {
        SphereShapeSetter->setWindowTitle(QApplication::translate("SphereShapeSetter", "Form", 0));
        label->setText(QApplication::translate("SphereShapeSetter", "Radius:", 0));
    } // retranslateUi

};

namespace Ui {
    class SphereShapeSetter: public Ui_SphereShapeSetter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPHERESHAPESETTER_H
