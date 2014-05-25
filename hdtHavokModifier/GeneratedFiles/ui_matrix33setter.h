/********************************************************************************
** Form generated from reading UI file 'matrix33setter.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATRIX33SETTER_H
#define UI_MATRIX33SETTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Matrix33Setter
{
public:
    QGridLayout *gridLayout;
    QDoubleSpinBox *doubleSpinBox_4;
    QDoubleSpinBox *doubleSpinBox_3;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_5;
    QDoubleSpinBox *doubleSpinBox_6;
    QDoubleSpinBox *doubleSpinBox_7;
    QDoubleSpinBox *doubleSpinBox_8;
    QDoubleSpinBox *doubleSpinBox_9;

    void setupUi(QWidget *Matrix33Setter)
    {
        if (Matrix33Setter->objectName().isEmpty())
            Matrix33Setter->setObjectName(QStringLiteral("Matrix33Setter"));
        Matrix33Setter->resize(222, 72);
        gridLayout = new QGridLayout(Matrix33Setter);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_4 = new QDoubleSpinBox(Matrix33Setter);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setDecimals(4);
        doubleSpinBox_4->setMinimum(-99);

        gridLayout->addWidget(doubleSpinBox_4, 1, 0, 1, 1);

        doubleSpinBox_3 = new QDoubleSpinBox(Matrix33Setter);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setDecimals(4);
        doubleSpinBox_3->setMinimum(-99);

        gridLayout->addWidget(doubleSpinBox_3, 0, 2, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(Matrix33Setter);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setDecimals(4);
        doubleSpinBox->setMinimum(-99);

        gridLayout->addWidget(doubleSpinBox, 0, 0, 1, 1);

        doubleSpinBox_2 = new QDoubleSpinBox(Matrix33Setter);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setDecimals(4);
        doubleSpinBox_2->setMinimum(-99);

        gridLayout->addWidget(doubleSpinBox_2, 0, 1, 1, 1);

        doubleSpinBox_5 = new QDoubleSpinBox(Matrix33Setter);
        doubleSpinBox_5->setObjectName(QStringLiteral("doubleSpinBox_5"));
        doubleSpinBox_5->setDecimals(4);
        doubleSpinBox_5->setMinimum(-99);

        gridLayout->addWidget(doubleSpinBox_5, 1, 1, 1, 1);

        doubleSpinBox_6 = new QDoubleSpinBox(Matrix33Setter);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));
        doubleSpinBox_6->setDecimals(4);
        doubleSpinBox_6->setMinimum(-99);

        gridLayout->addWidget(doubleSpinBox_6, 1, 2, 1, 1);

        doubleSpinBox_7 = new QDoubleSpinBox(Matrix33Setter);
        doubleSpinBox_7->setObjectName(QStringLiteral("doubleSpinBox_7"));
        doubleSpinBox_7->setDecimals(4);
        doubleSpinBox_7->setMinimum(-99);

        gridLayout->addWidget(doubleSpinBox_7, 2, 0, 1, 1);

        doubleSpinBox_8 = new QDoubleSpinBox(Matrix33Setter);
        doubleSpinBox_8->setObjectName(QStringLiteral("doubleSpinBox_8"));
        doubleSpinBox_8->setDecimals(4);
        doubleSpinBox_8->setMinimum(-99);

        gridLayout->addWidget(doubleSpinBox_8, 2, 1, 1, 1);

        doubleSpinBox_9 = new QDoubleSpinBox(Matrix33Setter);
        doubleSpinBox_9->setObjectName(QStringLiteral("doubleSpinBox_9"));
        doubleSpinBox_9->setDecimals(4);
        doubleSpinBox_9->setMinimum(-99);

        gridLayout->addWidget(doubleSpinBox_9, 2, 2, 1, 1);


        retranslateUi(Matrix33Setter);

        QMetaObject::connectSlotsByName(Matrix33Setter);
    } // setupUi

    void retranslateUi(QWidget *Matrix33Setter)
    {
        Matrix33Setter->setWindowTitle(QApplication::translate("Matrix33Setter", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class Matrix33Setter: public Ui_Matrix33Setter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATRIX33SETTER_H
