/********************************************************************************
** Form generated from reading UI file 'motorposition.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOTORPOSITION_H
#define UI_MOTORPOSITION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MotorPosition
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QDoubleSpinBox *spinBoxTau;
    QDoubleSpinBox *spinBoxDamping;
    QDoubleSpinBox *spinBoxPV;
    QDoubleSpinBox *spinBoxCV;

    void setupUi(QWidget *MotorPosition)
    {
        if (MotorPosition->objectName().isEmpty())
            MotorPosition->setObjectName(QStringLiteral("MotorPosition"));
        MotorPosition->resize(306, 102);
        MotorPosition->setStyleSheet(QLatin1String("QSpinBox,QDoubleSpinBox {\n"
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
        verticalLayout = new QVBoxLayout(MotorPosition);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(MotorPosition);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(MotorPosition);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(MotorPosition);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(MotorPosition);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        spinBoxTau = new QDoubleSpinBox(MotorPosition);
        spinBoxTau->setObjectName(QStringLiteral("spinBoxTau"));
        spinBoxTau->setDecimals(6);
        spinBoxTau->setMaximum(1);
        spinBoxTau->setSingleStep(0.01);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBoxTau);

        spinBoxDamping = new QDoubleSpinBox(MotorPosition);
        spinBoxDamping->setObjectName(QStringLiteral("spinBoxDamping"));
        spinBoxDamping->setDecimals(6);
        spinBoxDamping->setMaximum(1);
        spinBoxDamping->setSingleStep(0.01);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBoxDamping);

        spinBoxPV = new QDoubleSpinBox(MotorPosition);
        spinBoxPV->setObjectName(QStringLiteral("spinBoxPV"));
        spinBoxPV->setDecimals(6);
        spinBoxPV->setMaximum(9999);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBoxPV);

        spinBoxCV = new QDoubleSpinBox(MotorPosition);
        spinBoxCV->setObjectName(QStringLiteral("spinBoxCV"));
        spinBoxCV->setDecimals(6);
        spinBoxCV->setMaximum(9999);

        formLayout->setWidget(3, QFormLayout::FieldRole, spinBoxCV);


        verticalLayout->addLayout(formLayout);


        retranslateUi(MotorPosition);

        QMetaObject::connectSlotsByName(MotorPosition);
    } // setupUi

    void retranslateUi(QWidget *MotorPosition)
    {
        MotorPosition->setWindowTitle(QApplication::translate("MotorPosition", "Dialog", 0));
        label->setText(QApplication::translate("MotorPosition", "Tau:", 0));
        label_2->setText(QApplication::translate("MotorPosition", "Damping:", 0));
        label_3->setText(QApplication::translate("MotorPosition", "Proportional Recovery Velocity:", 0));
        label_4->setText(QApplication::translate("MotorPosition", "Constant Recovery Velocity:", 0));
    } // retranslateUi

};

namespace Ui {
    class MotorPosition: public Ui_MotorPosition {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOTORPOSITION_H
