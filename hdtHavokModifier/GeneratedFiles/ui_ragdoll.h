/********************************************************************************
** Form generated from reading UI file 'ragdoll.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RAGDOLL_H
#define UI_RAGDOLL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "motorselector.h"
#include "rotationsetter.h"
#include "vec3setter.h"

QT_BEGIN_NAMESPACE

class Ui_Ragdoll
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QFormLayout *formLayout;
    QLabel *label;
    Vec3Setter *widgetPivotA;
    QLabel *label_2;
    Vec3Setter *widgetPivotB;
    QLabel *label_3;
    RotationSetter *widgetBasisA;
    QLabel *label_4;
    RotationSetter *widgetBasisB;
    QWidget *tab_3;
    QFormLayout *formLayout_2;
    QLabel *label_5;
    QDoubleSpinBox *spinBoxCone;
    QLabel *label_10;
    QLabel *label_14;
    MotorSelector *widgetMotorCone;
    QDoubleSpinBox *spinBoxConeTau;
    QWidget *tab_2;
    QFormLayout *formLayout_3;
    QLabel *label_6;
    QDoubleSpinBox *spinBoxPlaneMin;
    QLabel *label_7;
    QDoubleSpinBox *spinBoxPlaneMax;
    QLabel *label_11;
    MotorSelector *widgetMotorPlane;
    QLabel *label_15;
    QDoubleSpinBox *spinBoxPlaneTau;
    QWidget *tab_4;
    QFormLayout *formLayout_4;
    QLabel *label_8;
    QDoubleSpinBox *spinBoxTwistMin;
    QLabel *label_9;
    QDoubleSpinBox *spinBoxTwistMax;
    QLabel *label_12;
    MotorSelector *widgetMotorTwist;
    QLabel *label_16;
    QDoubleSpinBox *spinBoxTwistTau;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioRadius;
    QRadioButton *radioDegree;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Ragdoll)
    {
        if (Ragdoll->objectName().isEmpty())
            Ragdoll->setObjectName(QStringLiteral("Ragdoll"));
        Ragdoll->resize(342, 162);
        verticalLayout = new QVBoxLayout(Ragdoll);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(Ragdoll);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setStyleSheet(QStringLiteral(""));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        formLayout = new QFormLayout(tab);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        widgetPivotA = new Vec3Setter(tab);
        widgetPivotA->setObjectName(QStringLiteral("widgetPivotA"));

        formLayout->setWidget(0, QFormLayout::FieldRole, widgetPivotA);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        widgetPivotB = new Vec3Setter(tab);
        widgetPivotB->setObjectName(QStringLiteral("widgetPivotB"));

        formLayout->setWidget(1, QFormLayout::FieldRole, widgetPivotB);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        widgetBasisA = new RotationSetter(tab);
        widgetBasisA->setObjectName(QStringLiteral("widgetBasisA"));

        formLayout->setWidget(2, QFormLayout::FieldRole, widgetBasisA);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        widgetBasisB = new RotationSetter(tab);
        widgetBasisB->setObjectName(QStringLiteral("widgetBasisB"));

        formLayout->setWidget(3, QFormLayout::FieldRole, widgetBasisB);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        formLayout_2 = new QFormLayout(tab_3);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_5);

        spinBoxCone = new QDoubleSpinBox(tab_3);
        spinBoxCone->setObjectName(QStringLiteral("spinBoxCone"));
        spinBoxCone->setDecimals(6);
        spinBoxCone->setMaximum(9999);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, spinBoxCone);

        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_10);

        label_14 = new QLabel(tab_3);
        label_14->setObjectName(QStringLiteral("label_14"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_14);

        widgetMotorCone = new MotorSelector(tab_3);
        widgetMotorCone->setObjectName(QStringLiteral("widgetMotorCone"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, widgetMotorCone);

        spinBoxConeTau = new QDoubleSpinBox(tab_3);
        spinBoxConeTau->setObjectName(QStringLiteral("spinBoxConeTau"));
        spinBoxConeTau->setDecimals(6);
        spinBoxConeTau->setMaximum(1);
        spinBoxConeTau->setSingleStep(0.01);
        spinBoxConeTau->setValue(0.8);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, spinBoxConeTau);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        formLayout_3 = new QFormLayout(tab_2);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_6);

        spinBoxPlaneMin = new QDoubleSpinBox(tab_2);
        spinBoxPlaneMin->setObjectName(QStringLiteral("spinBoxPlaneMin"));
        spinBoxPlaneMin->setDecimals(6);
        spinBoxPlaneMin->setMinimum(-9999);
        spinBoxPlaneMin->setMaximum(9999);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, spinBoxPlaneMin);

        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_7);

        spinBoxPlaneMax = new QDoubleSpinBox(tab_2);
        spinBoxPlaneMax->setObjectName(QStringLiteral("spinBoxPlaneMax"));
        spinBoxPlaneMax->setDecimals(6);
        spinBoxPlaneMax->setMinimum(-9999);
        spinBoxPlaneMax->setMaximum(9999);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, spinBoxPlaneMax);

        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_11);

        widgetMotorPlane = new MotorSelector(tab_2);
        widgetMotorPlane->setObjectName(QStringLiteral("widgetMotorPlane"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, widgetMotorPlane);

        label_15 = new QLabel(tab_2);
        label_15->setObjectName(QStringLiteral("label_15"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_15);

        spinBoxPlaneTau = new QDoubleSpinBox(tab_2);
        spinBoxPlaneTau->setObjectName(QStringLiteral("spinBoxPlaneTau"));
        spinBoxPlaneTau->setDecimals(6);
        spinBoxPlaneTau->setMaximum(1);
        spinBoxPlaneTau->setSingleStep(0.01);
        spinBoxPlaneTau->setValue(0.8);

        formLayout_3->setWidget(3, QFormLayout::FieldRole, spinBoxPlaneTau);

        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        formLayout_4 = new QFormLayout(tab_4);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        label_8 = new QLabel(tab_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_8);

        spinBoxTwistMin = new QDoubleSpinBox(tab_4);
        spinBoxTwistMin->setObjectName(QStringLiteral("spinBoxTwistMin"));
        spinBoxTwistMin->setDecimals(6);
        spinBoxTwistMin->setMinimum(-9999);
        spinBoxTwistMin->setMaximum(9999);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, spinBoxTwistMin);

        label_9 = new QLabel(tab_4);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_9);

        spinBoxTwistMax = new QDoubleSpinBox(tab_4);
        spinBoxTwistMax->setObjectName(QStringLiteral("spinBoxTwistMax"));
        spinBoxTwistMax->setDecimals(6);
        spinBoxTwistMax->setMinimum(-9999);
        spinBoxTwistMax->setMaximum(9999);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, spinBoxTwistMax);

        label_12 = new QLabel(tab_4);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_12);

        widgetMotorTwist = new MotorSelector(tab_4);
        widgetMotorTwist->setObjectName(QStringLiteral("widgetMotorTwist"));

        formLayout_4->setWidget(2, QFormLayout::FieldRole, widgetMotorTwist);

        label_16 = new QLabel(tab_4);
        label_16->setObjectName(QStringLiteral("label_16"));

        formLayout_4->setWidget(3, QFormLayout::LabelRole, label_16);

        spinBoxTwistTau = new QDoubleSpinBox(tab_4);
        spinBoxTwistTau->setObjectName(QStringLiteral("spinBoxTwistTau"));
        spinBoxTwistTau->setDecimals(6);
        spinBoxTwistTau->setMaximum(1);
        spinBoxTwistTau->setSingleStep(0.01);
        spinBoxTwistTau->setValue(0.8);

        formLayout_4->setWidget(3, QFormLayout::FieldRole, spinBoxTwistTau);

        tabWidget->addTab(tab_4, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radioRadius = new QRadioButton(Ragdoll);
        radioRadius->setObjectName(QStringLiteral("radioRadius"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(radioRadius->sizePolicy().hasHeightForWidth());
        radioRadius->setSizePolicy(sizePolicy1);
        radioRadius->setChecked(true);

        horizontalLayout->addWidget(radioRadius);

        radioDegree = new QRadioButton(Ragdoll);
        radioDegree->setObjectName(QStringLiteral("radioDegree"));
        sizePolicy1.setHeightForWidth(radioDegree->sizePolicy().hasHeightForWidth());
        radioDegree->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(radioDegree);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Ragdoll);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Ragdoll);
    } // setupUi

    void retranslateUi(QWidget *Ragdoll)
    {
        Ragdoll->setWindowTitle(QApplication::translate("Ragdoll", "Form", 0));
        label->setText(QApplication::translate("Ragdoll", "Pivot A:", 0));
        label_2->setText(QApplication::translate("Ragdoll", "Pivot B:", 0));
        label_3->setText(QApplication::translate("Ragdoll", "Basis A:", 0));
        label_4->setText(QApplication::translate("Ragdoll", "Basis B:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Ragdoll", "Joint", 0));
        label_5->setText(QApplication::translate("Ragdoll", "Cone Limit:", 0));
        label_10->setText(QApplication::translate("Ragdoll", "Cone Motor", 0));
        label_14->setText(QApplication::translate("Ragdoll", "Cone Tau:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Ragdoll", "Cone Limits", 0));
        label_6->setText(QApplication::translate("Ragdoll", "Min Plane Limit:", 0));
        label_7->setText(QApplication::translate("Ragdoll", "Max Plane Limit:", 0));
        label_11->setText(QApplication::translate("Ragdoll", "Plane Motor:", 0));
        label_15->setText(QApplication::translate("Ragdoll", "Plane Tau:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Ragdoll", "Plane Limits", 0));
        label_8->setText(QApplication::translate("Ragdoll", "Min Twist Limit:", 0));
        label_9->setText(QApplication::translate("Ragdoll", "Max Twist Limit:", 0));
        label_12->setText(QApplication::translate("Ragdoll", "Twist Motor:", 0));
        label_16->setText(QApplication::translate("Ragdoll", "Twist Tau:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Ragdoll", "Twist Limits", 0));
        radioRadius->setText(QApplication::translate("Ragdoll", "Radius", 0));
        radioDegree->setText(QApplication::translate("Ragdoll", "Degree", 0));
    } // retranslateUi

};

namespace Ui {
    class Ragdoll: public Ui_Ragdoll {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RAGDOLL_H
