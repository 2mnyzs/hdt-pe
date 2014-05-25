/********************************************************************************
** Form generated from reading UI file 'malleable.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MALLEABLE_H
#define UI_MALLEABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Malleable
{
public:
    QGridLayout *gridLayout;
    QDoubleSpinBox *spinBoxStrength;
    QLabel *label;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QGridLayout *layoutChild;
    QLabel *label_2;
    QComboBox *comboBoxChild;

    void setupUi(QWidget *Malleable)
    {
        if (Malleable->objectName().isEmpty())
            Malleable->setObjectName(QStringLiteral("Malleable"));
        Malleable->resize(576, 391);
        gridLayout = new QGridLayout(Malleable);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        spinBoxStrength = new QDoubleSpinBox(Malleable);
        spinBoxStrength->setObjectName(QStringLiteral("spinBoxStrength"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinBoxStrength->sizePolicy().hasHeightForWidth());
        spinBoxStrength->setSizePolicy(sizePolicy);
        spinBoxStrength->setDecimals(6);
        spinBoxStrength->setMaximum(1);
        spinBoxStrength->setSingleStep(0.01);

        gridLayout->addWidget(spinBoxStrength, 0, 1, 1, 1);

        label = new QLabel(Malleable);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        groupBox = new QGroupBox(Malleable);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        layoutChild = new QGridLayout();
        layoutChild->setObjectName(QStringLiteral("layoutChild"));

        gridLayout_3->addLayout(layoutChild, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 2, 0, 1, 4);

        label_2 = new QLabel(Malleable);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        comboBoxChild = new QComboBox(Malleable);
        comboBoxChild->setObjectName(QStringLiteral("comboBoxChild"));
        sizePolicy.setHeightForWidth(comboBoxChild->sizePolicy().hasHeightForWidth());
        comboBoxChild->setSizePolicy(sizePolicy);

        gridLayout->addWidget(comboBoxChild, 1, 1, 1, 1);


        retranslateUi(Malleable);

        QMetaObject::connectSlotsByName(Malleable);
    } // setupUi

    void retranslateUi(QWidget *Malleable)
    {
        Malleable->setWindowTitle(QApplication::translate("Malleable", "Form", 0));
        label->setText(QApplication::translate("Malleable", "Strength:", 0));
        groupBox->setTitle(QString());
        label_2->setText(QApplication::translate("Malleable", "Child Constraint Type:", 0));
    } // retranslateUi

};

namespace Ui {
    class Malleable: public Ui_Malleable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MALLEABLE_H
