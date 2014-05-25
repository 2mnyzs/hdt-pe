/********************************************************************************
** Form generated from reading UI file 'rotationsetter.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROTATIONSETTER_H
#define UI_ROTATIONSETTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RotationSetter
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;

    void setupUi(QWidget *RotationSetter)
    {
        if (RotationSetter->objectName().isEmpty())
            RotationSetter->setObjectName(QStringLiteral("RotationSetter"));
        RotationSetter->resize(93, 23);
        gridLayout = new QGridLayout(RotationSetter);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(RotationSetter);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);


        retranslateUi(RotationSetter);

        QMetaObject::connectSlotsByName(RotationSetter);
    } // setupUi

    void retranslateUi(QWidget *RotationSetter)
    {
        RotationSetter->setWindowTitle(QApplication::translate("RotationSetter", "Form", 0));
        pushButton->setText(QApplication::translate("RotationSetter", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class RotationSetter: public Ui_RotationSetter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROTATIONSETTER_H
