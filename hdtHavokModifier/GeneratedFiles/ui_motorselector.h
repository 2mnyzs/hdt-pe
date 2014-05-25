/********************************************************************************
** Form generated from reading UI file 'motorselector.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOTORSELECTOR_H
#define UI_MOTORSELECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MotorSelector
{
public:
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QToolButton *toolButton;

    void setupUi(QWidget *MotorSelector)
    {
        if (MotorSelector->objectName().isEmpty())
            MotorSelector->setObjectName(QStringLiteral("MotorSelector"));
        MotorSelector->resize(249, 20);
        horizontalLayout = new QHBoxLayout(MotorSelector);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(MotorSelector);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);

        toolButton = new QToolButton(MotorSelector);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setPopupMode(QToolButton::InstantPopup);

        horizontalLayout->addWidget(toolButton);


        retranslateUi(MotorSelector);

        QMetaObject::connectSlotsByName(MotorSelector);
    } // setupUi

    void retranslateUi(QWidget *MotorSelector)
    {
        MotorSelector->setWindowTitle(QApplication::translate("MotorSelector", "Form", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MotorSelector", "No Motor", 0)
         << QApplication::translate("MotorSelector", "hkpPositionConstraintMotor", 0)
         << QApplication::translate("MotorSelector", "hkpSpringDamperConstraintMotor", 0)
         << QApplication::translate("MotorSelector", "hkpVelocityConstraintMotor", 0)
        );
        toolButton->setText(QApplication::translate("MotorSelector", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class MotorSelector: public Ui_MotorSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOTORSELECTOR_H
