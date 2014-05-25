/********************************************************************************
** Form generated from reading UI file 'ragdolllimit.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RAGDOLLLIMIT_H
#define UI_RAGDOLLLIMIT_H

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
#include "rotationsetter.h"

QT_BEGIN_NAMESPACE

class Ui_RagdollLimit
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QFormLayout *formLayout;
    QLabel *label_3;
    RotationSetter *widgetBasisA;
    QLabel *label_4;
    RotationSetter *widgetBasisB;
    QWidget *tab_3;
    QFormLayout *formLayout_2;
    QLabel *label_5;
    QDoubleSpinBox *spinBoxCone;
    QLabel *label;
    QDoubleSpinBox *spinBoxConeTau;
    QWidget *tab_4;
    QFormLayout *formLayout_3;
    QLabel *label_6;
    QDoubleSpinBox *spinBoxPlaneMin;
    QLabel *label_7;
    QDoubleSpinBox *spinBoxPlaneMax;
    QLabel *label_2;
    QDoubleSpinBox *spinBoxPlaneTau;
    QWidget *tab_5;
    QFormLayout *formLayout_4;
    QLabel *label_8;
    QDoubleSpinBox *spinBoxTwistMin;
    QLabel *label_9;
    QDoubleSpinBox *spinBoxTwistMax;
    QLabel *label_10;
    QDoubleSpinBox *spinBoxTwistTau;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioRadius;
    QRadioButton *radioDegree;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *RagdollLimit)
    {
        if (RagdollLimit->objectName().isEmpty())
            RagdollLimit->setObjectName(QStringLiteral("RagdollLimit"));
        RagdollLimit->resize(352, 144);
        verticalLayout = new QVBoxLayout(RagdollLimit);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(RagdollLimit);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        formLayout = new QFormLayout(tab);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        widgetBasisA = new RotationSetter(tab);
        widgetBasisA->setObjectName(QStringLiteral("widgetBasisA"));

        formLayout->setWidget(0, QFormLayout::FieldRole, widgetBasisA);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        widgetBasisB = new RotationSetter(tab);
        widgetBasisB->setObjectName(QStringLiteral("widgetBasisB"));

        formLayout->setWidget(1, QFormLayout::FieldRole, widgetBasisB);

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

        label = new QLabel(tab_3);
        label->setObjectName(QStringLiteral("label"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label);

        spinBoxConeTau = new QDoubleSpinBox(tab_3);
        spinBoxConeTau->setObjectName(QStringLiteral("spinBoxConeTau"));
        spinBoxConeTau->setDecimals(6);
        spinBoxConeTau->setMaximum(1);
        spinBoxConeTau->setSingleStep(0.01);
        spinBoxConeTau->setValue(1);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, spinBoxConeTau);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        formLayout_3 = new QFormLayout(tab_4);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label_6 = new QLabel(tab_4);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_6);

        spinBoxPlaneMin = new QDoubleSpinBox(tab_4);
        spinBoxPlaneMin->setObjectName(QStringLiteral("spinBoxPlaneMin"));
        spinBoxPlaneMin->setDecimals(6);
        spinBoxPlaneMin->setMinimum(-9999);
        spinBoxPlaneMin->setMaximum(9999);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, spinBoxPlaneMin);

        label_7 = new QLabel(tab_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_7);

        spinBoxPlaneMax = new QDoubleSpinBox(tab_4);
        spinBoxPlaneMax->setObjectName(QStringLiteral("spinBoxPlaneMax"));
        spinBoxPlaneMax->setDecimals(6);
        spinBoxPlaneMax->setMinimum(-9999);
        spinBoxPlaneMax->setMaximum(9999);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, spinBoxPlaneMax);

        label_2 = new QLabel(tab_4);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_2);

        spinBoxPlaneTau = new QDoubleSpinBox(tab_4);
        spinBoxPlaneTau->setObjectName(QStringLiteral("spinBoxPlaneTau"));
        spinBoxPlaneTau->setDecimals(6);
        spinBoxPlaneTau->setMaximum(1);
        spinBoxPlaneTau->setSingleStep(0.01);
        spinBoxPlaneTau->setValue(1);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, spinBoxPlaneTau);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        formLayout_4 = new QFormLayout(tab_5);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        label_8 = new QLabel(tab_5);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_8);

        spinBoxTwistMin = new QDoubleSpinBox(tab_5);
        spinBoxTwistMin->setObjectName(QStringLiteral("spinBoxTwistMin"));
        spinBoxTwistMin->setDecimals(6);
        spinBoxTwistMin->setMinimum(-9999);
        spinBoxTwistMin->setMaximum(9999);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, spinBoxTwistMin);

        label_9 = new QLabel(tab_5);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_9);

        spinBoxTwistMax = new QDoubleSpinBox(tab_5);
        spinBoxTwistMax->setObjectName(QStringLiteral("spinBoxTwistMax"));
        spinBoxTwistMax->setDecimals(6);
        spinBoxTwistMax->setMinimum(-9999);
        spinBoxTwistMax->setMaximum(9999);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, spinBoxTwistMax);

        label_10 = new QLabel(tab_5);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_10);

        spinBoxTwistTau = new QDoubleSpinBox(tab_5);
        spinBoxTwistTau->setObjectName(QStringLiteral("spinBoxTwistTau"));
        spinBoxTwistTau->setDecimals(6);
        spinBoxTwistTau->setMaximum(1);
        spinBoxTwistTau->setSingleStep(0.01);
        spinBoxTwistTau->setValue(1);

        formLayout_4->setWidget(2, QFormLayout::FieldRole, spinBoxTwistTau);

        tabWidget->addTab(tab_5, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radioRadius = new QRadioButton(RagdollLimit);
        radioRadius->setObjectName(QStringLiteral("radioRadius"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(radioRadius->sizePolicy().hasHeightForWidth());
        radioRadius->setSizePolicy(sizePolicy1);
        radioRadius->setChecked(true);

        horizontalLayout->addWidget(radioRadius);

        radioDegree = new QRadioButton(RagdollLimit);
        radioDegree->setObjectName(QStringLiteral("radioDegree"));
        sizePolicy1.setHeightForWidth(radioDegree->sizePolicy().hasHeightForWidth());
        radioDegree->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(radioDegree);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(RagdollLimit);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RagdollLimit);
    } // setupUi

    void retranslateUi(QWidget *RagdollLimit)
    {
        RagdollLimit->setWindowTitle(QApplication::translate("RagdollLimit", "Form", 0));
        label_3->setText(QApplication::translate("RagdollLimit", "Basis A:", 0));
        label_4->setText(QApplication::translate("RagdollLimit", "Basis B:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("RagdollLimit", "Joint", 0));
        label_5->setText(QApplication::translate("RagdollLimit", "Cone Limit:", 0));
        label->setText(QApplication::translate("RagdollLimit", "Conet Tau:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("RagdollLimit", "Cone Limits", 0));
        label_6->setText(QApplication::translate("RagdollLimit", "Min Plane Limit:", 0));
        label_7->setText(QApplication::translate("RagdollLimit", "Max Plane Limit:", 0));
        label_2->setText(QApplication::translate("RagdollLimit", "Plane Tau:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("RagdollLimit", "Plane Limits", 0));
        label_8->setText(QApplication::translate("RagdollLimit", "Min Twist Limit:", 0));
        label_9->setText(QApplication::translate("RagdollLimit", "Max Twist Limit:", 0));
        label_10->setText(QApplication::translate("RagdollLimit", "Twist Tau:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("RagdollLimit", "Twist Limits", 0));
        radioRadius->setText(QApplication::translate("RagdollLimit", "Radius", 0));
        radioDegree->setText(QApplication::translate("RagdollLimit", "Degree", 0));
    } // retranslateUi

};

namespace Ui {
    class RagdollLimit: public Ui_RagdollLimit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RAGDOLLLIMIT_H
