/********************************************************************************
** Form generated from reading UI file 'masspropertysetter.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MASSPROPERTYSETTER_H
#define UI_MASSPROPERTYSETTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "matrix33setter.h"
#include "vec3setter.h"

QT_BEGIN_NAMESPACE

class Ui_MassPropertySetter
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLabel *label;
    QDoubleSpinBox *spinBoxMass;
    QLabel *label_3;
    Vec3Setter *widgetCOM;
    Matrix33Setter *widgetInertia;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonSimplify;
    QPushButton *buttonAutoFill;

    void setupUi(QWidget *MassPropertySetter)
    {
        if (MassPropertySetter->objectName().isEmpty())
            MassPropertySetter->setObjectName(QStringLiteral("MassPropertySetter"));
        MassPropertySetter->resize(295, 157);
        verticalLayout = new QVBoxLayout(MassPropertySetter);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(MassPropertySetter);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        label = new QLabel(MassPropertySetter);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        spinBoxMass = new QDoubleSpinBox(MassPropertySetter);
        spinBoxMass->setObjectName(QStringLiteral("spinBoxMass"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinBoxMass->sizePolicy().hasHeightForWidth());
        spinBoxMass->setSizePolicy(sizePolicy);
        spinBoxMass->setDecimals(6);

        gridLayout_2->addWidget(spinBoxMass, 0, 1, 1, 1);

        label_3 = new QLabel(MassPropertySetter);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        widgetCOM = new Vec3Setter(MassPropertySetter);
        widgetCOM->setObjectName(QStringLiteral("widgetCOM"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widgetCOM->sizePolicy().hasHeightForWidth());
        widgetCOM->setSizePolicy(sizePolicy1);
        widgetCOM->setMinimumSize(QSize(0, 20));

        gridLayout_2->addWidget(widgetCOM, 1, 1, 1, 1);

        widgetInertia = new Matrix33Setter(MassPropertySetter);
        widgetInertia->setObjectName(QStringLiteral("widgetInertia"));
        sizePolicy1.setHeightForWidth(widgetInertia->sizePolicy().hasHeightForWidth());
        widgetInertia->setSizePolicy(sizePolicy1);
        widgetInertia->setMinimumSize(QSize(0, 72));

        gridLayout_2->addWidget(widgetInertia, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonSimplify = new QPushButton(MassPropertySetter);
        buttonSimplify->setObjectName(QStringLiteral("buttonSimplify"));

        horizontalLayout->addWidget(buttonSimplify);

        buttonAutoFill = new QPushButton(MassPropertySetter);
        buttonAutoFill->setObjectName(QStringLiteral("buttonAutoFill"));

        horizontalLayout->addWidget(buttonAutoFill);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(MassPropertySetter);
        QObject::connect(buttonSimplify, SIGNAL(clicked()), MassPropertySetter, SLOT(onButtonSimplify()));
        QObject::connect(buttonAutoFill, SIGNAL(clicked()), MassPropertySetter, SLOT(onButtonAutoFill()));

        QMetaObject::connectSlotsByName(MassPropertySetter);
    } // setupUi

    void retranslateUi(QWidget *MassPropertySetter)
    {
        MassPropertySetter->setWindowTitle(QApplication::translate("MassPropertySetter", "Form", 0));
        label_2->setText(QApplication::translate("MassPropertySetter", "Inertia Tensor:", 0));
        label->setText(QApplication::translate("MassPropertySetter", "Center of Mass:", 0));
        label_3->setText(QApplication::translate("MassPropertySetter", "Mass(kg):", 0));
#ifndef QT_NO_TOOLTIP
        buttonSimplify->setToolTip(QApplication::translate("MassPropertySetter", "Computes a \"best\" approximation of a full inertia tensor as an oriented particle inertia tensor, which is constant along the diagonal, and zero on the off-diagonals, i.e., = I * k for some k. The matrix passed in is set to this approximation.", 0));
#endif // QT_NO_TOOLTIP
        buttonSimplify->setText(QApplication::translate("MassPropertySetter", "Simplify", 0));
        buttonAutoFill->setText(QApplication::translate("MassPropertySetter", "Auto Fill", 0));
    } // retranslateUi

};

namespace Ui {
    class MassPropertySetter: public Ui_MassPropertySetter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MASSPROPERTYSETTER_H
