/********************************************************************************
** Form generated from reading UI file 'motorspringdamper.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOTORSPRINGDAMPER_H
#define UI_MOTORSPRINGDAMPER_H

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

class Ui_MotorSpringDamper
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QDoubleSpinBox *spinBoxConstant;
    QDoubleSpinBox *spinBoxDamping;

    void setupUi(QWidget *MotorSpringDamper)
    {
        if (MotorSpringDamper->objectName().isEmpty())
            MotorSpringDamper->setObjectName(QStringLiteral("MotorSpringDamper"));
        MotorSpringDamper->resize(216, 58);
        MotorSpringDamper->setStyleSheet(QLatin1String("QSpinBox,QDoubleSpinBox {\n"
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
        verticalLayout = new QVBoxLayout(MotorSpringDamper);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(MotorSpringDamper);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(MotorSpringDamper);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        spinBoxConstant = new QDoubleSpinBox(MotorSpringDamper);
        spinBoxConstant->setObjectName(QStringLiteral("spinBoxConstant"));
        spinBoxConstant->setDecimals(6);
        spinBoxConstant->setMaximum(9999);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBoxConstant);

        spinBoxDamping = new QDoubleSpinBox(MotorSpringDamper);
        spinBoxDamping->setObjectName(QStringLiteral("spinBoxDamping"));
        spinBoxDamping->setDecimals(6);
        spinBoxDamping->setMaximum(9999);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBoxDamping);


        verticalLayout->addLayout(formLayout);


        retranslateUi(MotorSpringDamper);

        QMetaObject::connectSlotsByName(MotorSpringDamper);
    } // setupUi

    void retranslateUi(QWidget *MotorSpringDamper)
    {
        MotorSpringDamper->setWindowTitle(QApplication::translate("MotorSpringDamper", "Dialog", 0));
        label->setText(QApplication::translate("MotorSpringDamper", "Spring Constant:", 0));
        label_2->setText(QApplication::translate("MotorSpringDamper", "Spring Damping:", 0));
    } // retranslateUi

};

namespace Ui {
    class MotorSpringDamper: public Ui_MotorSpringDamper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOTORSPRINGDAMPER_H
