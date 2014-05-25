/********************************************************************************
** Form generated from reading UI file 'rackandpinion.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RACKANDPINION_H
#define UI_RACKANDPINION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "rotationsetter.h"
#include "vec3setter.h"

QT_BEGIN_NAMESPACE

class Ui_RackAndPinion
{
public:
    QGridLayout *gridLayout;
    Vec3Setter *widgetPivotA;
    RotationSetter *widgetBasisA;
    RotationSetter *widgetBasisB;
    Vec3Setter *widgetPivotB;
    QLabel *labelRadius;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label;
    QCheckBox *checkBoxScrew;
    QLabel *label_2;
    QDoubleSpinBox *spinBoxRadius;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *RackAndPinion)
    {
        if (RackAndPinion->objectName().isEmpty())
            RackAndPinion->setObjectName(QStringLiteral("RackAndPinion"));
        RackAndPinion->resize(400, 300);
        gridLayout = new QGridLayout(RackAndPinion);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widgetPivotA = new Vec3Setter(RackAndPinion);
        widgetPivotA->setObjectName(QStringLiteral("widgetPivotA"));

        gridLayout->addWidget(widgetPivotA, 0, 1, 1, 1);

        widgetBasisA = new RotationSetter(RackAndPinion);
        widgetBasisA->setObjectName(QStringLiteral("widgetBasisA"));

        gridLayout->addWidget(widgetBasisA, 2, 1, 1, 1);

        widgetBasisB = new RotationSetter(RackAndPinion);
        widgetBasisB->setObjectName(QStringLiteral("widgetBasisB"));

        gridLayout->addWidget(widgetBasisB, 3, 1, 1, 1);

        widgetPivotB = new Vec3Setter(RackAndPinion);
        widgetPivotB->setObjectName(QStringLiteral("widgetPivotB"));

        gridLayout->addWidget(widgetPivotB, 1, 1, 1, 1);

        labelRadius = new QLabel(RackAndPinion);
        labelRadius->setObjectName(QStringLiteral("labelRadius"));

        gridLayout->addWidget(labelRadius, 5, 0, 1, 1);

        label_3 = new QLabel(RackAndPinion);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(RackAndPinion);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label = new QLabel(RackAndPinion);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        checkBoxScrew = new QCheckBox(RackAndPinion);
        checkBoxScrew->setObjectName(QStringLiteral("checkBoxScrew"));

        gridLayout->addWidget(checkBoxScrew, 4, 0, 1, 2);

        label_2 = new QLabel(RackAndPinion);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        spinBoxRadius = new QDoubleSpinBox(RackAndPinion);
        spinBoxRadius->setObjectName(QStringLiteral("spinBoxRadius"));
        spinBoxRadius->setDecimals(4);
        spinBoxRadius->setMaximum(9999);

        gridLayout->addWidget(spinBoxRadius, 5, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 6, 0, 1, 1);


        retranslateUi(RackAndPinion);

        QMetaObject::connectSlotsByName(RackAndPinion);
    } // setupUi

    void retranslateUi(QWidget *RackAndPinion)
    {
        RackAndPinion->setWindowTitle(QApplication::translate("RackAndPinion", "Form", 0));
        labelRadius->setText(QApplication::translate("RackAndPinion", "Pinion Radius:", 0));
        label_3->setText(QApplication::translate("RackAndPinion", "Basis A:", 0));
        label_4->setText(QApplication::translate("RackAndPinion", "Basis B:", 0));
        label->setText(QApplication::translate("RackAndPinion", "Pivot A:", 0));
        checkBoxScrew->setText(QApplication::translate("RackAndPinion", "Is Screw", 0));
        label_2->setText(QApplication::translate("RackAndPinion", "Pivot B:", 0));
    } // retranslateUi

};

namespace Ui {
    class RackAndPinion: public Ui_RackAndPinion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RACKANDPINION_H
