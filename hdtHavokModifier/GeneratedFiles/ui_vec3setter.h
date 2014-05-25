/********************************************************************************
** Form generated from reading UI file 'vec3setter.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VEC3SETTER_H
#define UI_VEC3SETTER_H

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

class Ui_Vec3Setter
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *labelX;
    QDoubleSpinBox *spinBoxX;
    QLabel *labelY;
    QDoubleSpinBox *spinBoxY;
    QLabel *labelZ;
    QDoubleSpinBox *spinBoxZ;

    void setupUi(QWidget *Vec3Setter)
    {
        if (Vec3Setter->objectName().isEmpty())
            Vec3Setter->setObjectName(QStringLiteral("Vec3Setter"));
        Vec3Setter->resize(312, 20);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Vec3Setter->sizePolicy().hasHeightForWidth());
        Vec3Setter->setSizePolicy(sizePolicy);
        Vec3Setter->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(Vec3Setter);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        labelX = new QLabel(Vec3Setter);
        labelX->setObjectName(QStringLiteral("labelX"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelX->sizePolicy().hasHeightForWidth());
        labelX->setSizePolicy(sizePolicy1);
        labelX->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(labelX);

        spinBoxX = new QDoubleSpinBox(Vec3Setter);
        spinBoxX->setObjectName(QStringLiteral("spinBoxX"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(spinBoxX->sizePolicy().hasHeightForWidth());
        spinBoxX->setSizePolicy(sizePolicy2);
        spinBoxX->setDecimals(6);
        spinBoxX->setMinimum(-9999);
        spinBoxX->setMaximum(9999);
        spinBoxX->setValue(0);

        horizontalLayout->addWidget(spinBoxX);

        labelY = new QLabel(Vec3Setter);
        labelY->setObjectName(QStringLiteral("labelY"));

        horizontalLayout->addWidget(labelY);

        spinBoxY = new QDoubleSpinBox(Vec3Setter);
        spinBoxY->setObjectName(QStringLiteral("spinBoxY"));
        sizePolicy2.setHeightForWidth(spinBoxY->sizePolicy().hasHeightForWidth());
        spinBoxY->setSizePolicy(sizePolicy2);
        spinBoxY->setDecimals(6);
        spinBoxY->setMinimum(-9999);
        spinBoxY->setMaximum(9999);

        horizontalLayout->addWidget(spinBoxY);

        labelZ = new QLabel(Vec3Setter);
        labelZ->setObjectName(QStringLiteral("labelZ"));

        horizontalLayout->addWidget(labelZ);

        spinBoxZ = new QDoubleSpinBox(Vec3Setter);
        spinBoxZ->setObjectName(QStringLiteral("spinBoxZ"));
        sizePolicy2.setHeightForWidth(spinBoxZ->sizePolicy().hasHeightForWidth());
        spinBoxZ->setSizePolicy(sizePolicy2);
        spinBoxZ->setDecimals(6);
        spinBoxZ->setMinimum(-9999);
        spinBoxZ->setMaximum(9999);

        horizontalLayout->addWidget(spinBoxZ);


        retranslateUi(Vec3Setter);

        QMetaObject::connectSlotsByName(Vec3Setter);
    } // setupUi

    void retranslateUi(QWidget *Vec3Setter)
    {
        Vec3Setter->setWindowTitle(QApplication::translate("Vec3Setter", "Form", 0));
        labelX->setText(QApplication::translate("Vec3Setter", "X", 0));
        labelY->setText(QApplication::translate("Vec3Setter", "Y", 0));
        labelZ->setText(QApplication::translate("Vec3Setter", "Z", 0));
    } // retranslateUi

};

namespace Ui {
    class Vec3Setter: public Ui_Vec3Setter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VEC3SETTER_H
