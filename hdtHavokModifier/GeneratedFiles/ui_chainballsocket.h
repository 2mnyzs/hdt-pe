/********************************************************************************
** Form generated from reading UI file 'chainballsocket.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAINBALLSOCKET_H
#define UI_CHAINBALLSOCKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "vec3setter.h"

QT_BEGIN_NAMESPACE

class Ui_ChainBallSocket
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    Vec3Setter *pivotA;
    QLabel *label_2;
    Vec3Setter *pivotB;

    void setupUi(QWidget *ChainBallSocket)
    {
        if (ChainBallSocket->objectName().isEmpty())
            ChainBallSocket->setObjectName(QStringLiteral("ChainBallSocket"));
        ChainBallSocket->resize(237, 30);
        formLayout = new QFormLayout(ChainBallSocket);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(ChainBallSocket);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        pivotA = new Vec3Setter(ChainBallSocket);
        pivotA->setObjectName(QStringLiteral("pivotA"));

        formLayout->setWidget(0, QFormLayout::FieldRole, pivotA);

        label_2 = new QLabel(ChainBallSocket);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        pivotB = new Vec3Setter(ChainBallSocket);
        pivotB->setObjectName(QStringLiteral("pivotB"));

        formLayout->setWidget(1, QFormLayout::FieldRole, pivotB);


        retranslateUi(ChainBallSocket);

        QMetaObject::connectSlotsByName(ChainBallSocket);
    } // setupUi

    void retranslateUi(QWidget *ChainBallSocket)
    {
        ChainBallSocket->setWindowTitle(QApplication::translate("ChainBallSocket", "Form", 0));
        label->setText(QApplication::translate("ChainBallSocket", "Pivot A:", 0));
        label_2->setText(QApplication::translate("ChainBallSocket", "Pivot B:", 0));
    } // retranslateUi

};

namespace Ui {
    class ChainBallSocket: public Ui_ChainBallSocket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAINBALLSOCKET_H
