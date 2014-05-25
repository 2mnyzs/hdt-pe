/********************************************************************************
** Form generated from reading UI file 'vec4setter.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VEC4SETTER_H
#define UI_VEC4SETTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Vec4Setter
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *labelX;
    QDoubleSpinBox *spinBoxX;
    QLabel *labelY;
    QDoubleSpinBox *spinBoxY;
    QLabel *labelZ;
    QDoubleSpinBox *spinBoxZ;
    QLabel *labelW;
    QDoubleSpinBox *spinBoxW;

    void setupUi(QWidget *Vec4Setter)
    {
        if (Vec4Setter->objectName().isEmpty())
            Vec4Setter->setObjectName(QStringLiteral("Vec4Setter"));
        Vec4Setter->resize(418, 20);
        Vec4Setter->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(Vec4Setter);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        labelX = new QLabel(Vec4Setter);
        labelX->setObjectName(QStringLiteral("labelX"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelX->sizePolicy().hasHeightForWidth());
        labelX->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(labelX);

        spinBoxX = new QDoubleSpinBox(Vec4Setter);
        spinBoxX->setObjectName(QStringLiteral("spinBoxX"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBoxX->sizePolicy().hasHeightForWidth());
        spinBoxX->setSizePolicy(sizePolicy1);
        spinBoxX->setDecimals(4);
        spinBoxX->setMinimum(-9999);
        spinBoxX->setMaximum(9999);

        horizontalLayout->addWidget(spinBoxX);

        labelY = new QLabel(Vec4Setter);
        labelY->setObjectName(QStringLiteral("labelY"));

        horizontalLayout->addWidget(labelY);

        spinBoxY = new QDoubleSpinBox(Vec4Setter);
        spinBoxY->setObjectName(QStringLiteral("spinBoxY"));
        sizePolicy1.setHeightForWidth(spinBoxY->sizePolicy().hasHeightForWidth());
        spinBoxY->setSizePolicy(sizePolicy1);
        spinBoxY->setDecimals(4);
        spinBoxY->setMinimum(-9999);
        spinBoxY->setMaximum(9999);

        horizontalLayout->addWidget(spinBoxY);

        labelZ = new QLabel(Vec4Setter);
        labelZ->setObjectName(QStringLiteral("labelZ"));

        horizontalLayout->addWidget(labelZ);

        spinBoxZ = new QDoubleSpinBox(Vec4Setter);
        spinBoxZ->setObjectName(QStringLiteral("spinBoxZ"));
        sizePolicy1.setHeightForWidth(spinBoxZ->sizePolicy().hasHeightForWidth());
        spinBoxZ->setSizePolicy(sizePolicy1);
        spinBoxZ->setDecimals(4);
        spinBoxZ->setMinimum(-9999);
        spinBoxZ->setValue(0);

        horizontalLayout->addWidget(spinBoxZ);

        labelW = new QLabel(Vec4Setter);
        labelW->setObjectName(QStringLiteral("labelW"));

        horizontalLayout->addWidget(labelW);

        spinBoxW = new QDoubleSpinBox(Vec4Setter);
        spinBoxW->setObjectName(QStringLiteral("spinBoxW"));
        sizePolicy1.setHeightForWidth(spinBoxW->sizePolicy().hasHeightForWidth());
        spinBoxW->setSizePolicy(sizePolicy1);
        spinBoxW->setDecimals(4);
        spinBoxW->setMinimum(-9999);
        spinBoxW->setMaximum(9999);

        horizontalLayout->addWidget(spinBoxW);


        retranslateUi(Vec4Setter);

        QMetaObject::connectSlotsByName(Vec4Setter);
    } // setupUi

    void retranslateUi(QWidget *Vec4Setter)
    {
        Vec4Setter->setWindowTitle(QApplication::translate("Vec4Setter", "Form", 0));
        labelX->setText(QApplication::translate("Vec4Setter", "X", 0));
        labelY->setText(QApplication::translate("Vec4Setter", "Y", 0));
        labelZ->setText(QApplication::translate("Vec4Setter", "Z", 0));
        labelW->setText(QApplication::translate("Vec4Setter", "W", 0));
    } // retranslateUi

};

namespace Ui {
    class Vec4Setter: public Ui_Vec4Setter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VEC4SETTER_H
