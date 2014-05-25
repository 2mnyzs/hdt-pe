/********************************************************************************
** Form generated from reading UI file 'motorvelocity.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOTORVELOCITY_H
#define UI_MOTORVELOCITY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MotorVelocity
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QDoubleSpinBox *spinBoxTau;
    QDoubleSpinBox *spinBoxTarget;
    QCheckBox *checkBox;

    void setupUi(QWidget *MotorVelocity)
    {
        if (MotorVelocity->objectName().isEmpty())
            MotorVelocity->setObjectName(QStringLiteral("MotorVelocity"));
        MotorVelocity->resize(299, 80);
        MotorVelocity->setStyleSheet(QLatin1String("QSpinBox,QDoubleSpinBox {\n"
"	color: rgb(0,0,127);\n"
"	border: 1px solid rgb(0,0,127);\n"
"	border-radius: 2px;\n"
"}\n"
"\n"
"QSpinBox:hover,QDoubleSpinBox:hover {\n"
"	background-color: rgba(0, 0, 0, 16);\n"
"}\n"
"\n"
"QSpinBox::up-button,QDoubleSpinBox::up-button,\n"
"QSpinBox::down-button,QDoubleSpinBox::down-button {\n"
"	border-left: 1px solid rgb(0,0,127);\n"
"	background-color: transparent;\n"
"}\n"
"\n"
"QSpinBox::up-button:hover,\n"
"QDoubleSpinBox::up-button:hover,\n"
"QSpinBox::down-button:hover,\n"
"QDoubleSpinBox::down-button:hover\n"
"{\n"
"	border-left: 1px solid rgb(0,0,127);\n"
"	background-color: rgba(0, 0, 0, 32);\n"
"}\n"
"\n"
"QSpinBox::up-arrow,QDoubleSpinBox::up-arrow{\n"
"	image: url(:/icons/arrowup.png);\n"
"	width: 5px;\n"
"}\n"
"\n"
"QSpinBox::down-arrow,QDoubleSpinBox::down-arrow{\n"
"	image: url(:/icons/arrowdown.png);\n"
"	width: 5px;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(MotorVelocity);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(MotorVelocity);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(MotorVelocity);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        spinBoxTau = new QDoubleSpinBox(MotorVelocity);
        spinBoxTau->setObjectName(QStringLiteral("spinBoxTau"));
        spinBoxTau->setDecimals(6);
        spinBoxTau->setMaximum(1);
        spinBoxTau->setSingleStep(0.01);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBoxTau);

        spinBoxTarget = new QDoubleSpinBox(MotorVelocity);
        spinBoxTarget->setObjectName(QStringLiteral("spinBoxTarget"));
        spinBoxTarget->setDecimals(6);
        spinBoxTarget->setMaximum(9999);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBoxTarget);


        verticalLayout->addLayout(formLayout);

        checkBox = new QCheckBox(MotorVelocity);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout->addWidget(checkBox);


        retranslateUi(MotorVelocity);

        QMetaObject::connectSlotsByName(MotorVelocity);
    } // setupUi

    void retranslateUi(QWidget *MotorVelocity)
    {
        MotorVelocity->setWindowTitle(QApplication::translate("MotorVelocity", "Dialog", 0));
        label->setText(QApplication::translate("MotorVelocity", "Tau:", 0));
        label_2->setText(QApplication::translate("MotorVelocity", "Target Velocity:", 0));
        checkBox->setText(QApplication::translate("MotorVelocity", "Use Velocity Target From Constraint Targets", 0));
    } // retranslateUi

};

namespace Ui {
    class MotorVelocity: public Ui_MotorVelocity {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOTORVELOCITY_H
