/********************************************************************************
** Form generated from reading UI file 'deformablefixed.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEFORMABLEFIXED_H
#define UI_DEFORMABLEFIXED_H

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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "rotationsetter.h"
#include "vec3setter.h"

QT_BEGIN_NAMESPACE

class Ui_DeformableFixed
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabWidgetPage1;
    QFormLayout *formLayout_2;
    QLabel *label;
    RotationSetter *widgetBasisA;
    QLabel *label_4;
    QLabel *label_2;
    Vec3Setter *widgetPivotA;
    RotationSetter *widgetBasisB;
    QLabel *label_3;
    Vec3Setter *widgetPivotB;
    QWidget *tabWidgetPage2;
    QFormLayout *formLayout_3;
    QLabel *label_5;
    Vec3Setter *widgetLinOffset;
    QLabel *label_6;
    QDoubleSpinBox *spinBoxLinLimit;
    QLabel *label_7;
    Vec3Setter *widgetLinYield;
    QLabel *label_8;
    Vec3Setter *widgetLinUltimate;
    QWidget *tabWidgetPage3;
    QFormLayout *formLayout;
    QLabel *label_9;
    Vec3Setter *widgetAngYield;
    QLabel *label_12;
    Vec3Setter *widgetAngUltimate;
    QLabel *label_10;
    RotationSetter *widgetAngOffset;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout;
    QDoubleSpinBox *spinBoxAngLimit;
    QRadioButton *radioRadius;
    QRadioButton *radioDegree;

    void setupUi(QWidget *DeformableFixed)
    {
        if (DeformableFixed->objectName().isEmpty())
            DeformableFixed->setObjectName(QStringLiteral("DeformableFixed"));
        DeformableFixed->resize(400, 120);
        verticalLayout = new QVBoxLayout(DeformableFixed);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(DeformableFixed);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setStyleSheet(QStringLiteral(""));
        tabWidgetPage1 = new QWidget();
        tabWidgetPage1->setObjectName(QStringLiteral("tabWidgetPage1"));
        formLayout_2 = new QFormLayout(tabWidgetPage1);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(tabWidgetPage1);
        label->setObjectName(QStringLiteral("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        widgetBasisA = new RotationSetter(tabWidgetPage1);
        widgetBasisA->setObjectName(QStringLiteral("widgetBasisA"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, widgetBasisA);

        label_4 = new QLabel(tabWidgetPage1);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_4);

        label_2 = new QLabel(tabWidgetPage1);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);

        widgetPivotA = new Vec3Setter(tabWidgetPage1);
        widgetPivotA->setObjectName(QStringLiteral("widgetPivotA"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, widgetPivotA);

        widgetBasisB = new RotationSetter(tabWidgetPage1);
        widgetBasisB->setObjectName(QStringLiteral("widgetBasisB"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, widgetBasisB);

        label_3 = new QLabel(tabWidgetPage1);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_3);

        widgetPivotB = new Vec3Setter(tabWidgetPage1);
        widgetPivotB->setObjectName(QStringLiteral("widgetPivotB"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, widgetPivotB);

        tabWidget->addTab(tabWidgetPage1, QString());
        tabWidgetPage2 = new QWidget();
        tabWidgetPage2->setObjectName(QStringLiteral("tabWidgetPage2"));
        formLayout_3 = new QFormLayout(tabWidgetPage2);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label_5 = new QLabel(tabWidgetPage2);
        label_5->setObjectName(QStringLiteral("label_5"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_5);

        widgetLinOffset = new Vec3Setter(tabWidgetPage2);
        widgetLinOffset->setObjectName(QStringLiteral("widgetLinOffset"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, widgetLinOffset);

        label_6 = new QLabel(tabWidgetPage2);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_6);

        spinBoxLinLimit = new QDoubleSpinBox(tabWidgetPage2);
        spinBoxLinLimit->setObjectName(QStringLiteral("spinBoxLinLimit"));
        spinBoxLinLimit->setDecimals(4);
        spinBoxLinLimit->setMaximum(9999);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, spinBoxLinLimit);

        label_7 = new QLabel(tabWidgetPage2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setWordWrap(false);

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_7);

        widgetLinYield = new Vec3Setter(tabWidgetPage2);
        widgetLinYield->setObjectName(QStringLiteral("widgetLinYield"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, widgetLinYield);

        label_8 = new QLabel(tabWidgetPage2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setWordWrap(false);

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_8);

        widgetLinUltimate = new Vec3Setter(tabWidgetPage2);
        widgetLinUltimate->setObjectName(QStringLiteral("widgetLinUltimate"));

        formLayout_3->setWidget(3, QFormLayout::FieldRole, widgetLinUltimate);

        tabWidget->addTab(tabWidgetPage2, QString());
        tabWidgetPage3 = new QWidget();
        tabWidgetPage3->setObjectName(QStringLiteral("tabWidgetPage3"));
        formLayout = new QFormLayout(tabWidgetPage3);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_9 = new QLabel(tabWidgetPage3);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_9);

        widgetAngYield = new Vec3Setter(tabWidgetPage3);
        widgetAngYield->setObjectName(QStringLiteral("widgetAngYield"));

        formLayout->setWidget(2, QFormLayout::FieldRole, widgetAngYield);

        label_12 = new QLabel(tabWidgetPage3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setWordWrap(false);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_12);

        widgetAngUltimate = new Vec3Setter(tabWidgetPage3);
        widgetAngUltimate->setObjectName(QStringLiteral("widgetAngUltimate"));

        formLayout->setWidget(3, QFormLayout::FieldRole, widgetAngUltimate);

        label_10 = new QLabel(tabWidgetPage3);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_10);

        widgetAngOffset = new RotationSetter(tabWidgetPage3);
        widgetAngOffset->setObjectName(QStringLiteral("widgetAngOffset"));

        formLayout->setWidget(0, QFormLayout::FieldRole, widgetAngOffset);

        label_11 = new QLabel(tabWidgetPage3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setWordWrap(false);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_11);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        spinBoxAngLimit = new QDoubleSpinBox(tabWidgetPage3);
        spinBoxAngLimit->setObjectName(QStringLiteral("spinBoxAngLimit"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBoxAngLimit->sizePolicy().hasHeightForWidth());
        spinBoxAngLimit->setSizePolicy(sizePolicy1);
        spinBoxAngLimit->setDecimals(4);
        spinBoxAngLimit->setMaximum(9999);

        horizontalLayout->addWidget(spinBoxAngLimit);

        radioRadius = new QRadioButton(tabWidgetPage3);
        radioRadius->setObjectName(QStringLiteral("radioRadius"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(radioRadius->sizePolicy().hasHeightForWidth());
        radioRadius->setSizePolicy(sizePolicy2);
        radioRadius->setChecked(true);

        horizontalLayout->addWidget(radioRadius);

        radioDegree = new QRadioButton(tabWidgetPage3);
        radioDegree->setObjectName(QStringLiteral("radioDegree"));
        sizePolicy2.setHeightForWidth(radioDegree->sizePolicy().hasHeightForWidth());
        radioDegree->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(radioDegree);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout);

        tabWidget->addTab(tabWidgetPage3, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(DeformableFixed);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DeformableFixed);
    } // setupUi

    void retranslateUi(QWidget *DeformableFixed)
    {
        DeformableFixed->setWindowTitle(QApplication::translate("DeformableFixed", "Form", 0));
        label->setText(QApplication::translate("DeformableFixed", "Pivot A:", 0));
        label_4->setText(QApplication::translate("DeformableFixed", "Basis B:", 0));
        label_2->setText(QApplication::translate("DeformableFixed", "Pivot B:", 0));
        label_3->setText(QApplication::translate("DeformableFixed", "Basis A:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabWidgetPage1), QApplication::translate("DeformableFixed", "Joint", 0));
        label_5->setText(QApplication::translate("DeformableFixed", "Linear Offset:", 0));
        label_6->setText(QApplication::translate("DeformableFixed", "Linear Limit:", 0));
        label_7->setText(QApplication::translate("DeformableFixed", "Linear Yield Strength:", 0));
        label_8->setText(QApplication::translate("DeformableFixed", "Linear Ultimate Strength:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabWidgetPage2), QApplication::translate("DeformableFixed", "Linear Limits", 0));
        label_9->setText(QApplication::translate("DeformableFixed", "Angular Offset:", 0));
        label_12->setText(QApplication::translate("DeformableFixed", "Angular Ultimate Strength:", 0));
        label_10->setText(QApplication::translate("DeformableFixed", "Angular Limit:", 0));
        label_11->setText(QApplication::translate("DeformableFixed", "Angular Yeild Strength:", 0));
        radioRadius->setText(QApplication::translate("DeformableFixed", "Radius", 0));
        radioDegree->setText(QApplication::translate("DeformableFixed", "Degree", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabWidgetPage3), QApplication::translate("DeformableFixed", "Angular Limits", 0));
    } // retranslateUi

};

namespace Ui {
    class DeformableFixed: public Ui_DeformableFixed {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEFORMABLEFIXED_H
