/********************************************************************************
** Form generated from reading UI file 'dialogrigidbody.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGRIGIDBODY_H
#define UI_DIALOGRIGIDBODY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include "collisionfiltersetter.h"
#include "masspropertysetter.h"
#include "shapeselector.h"

QT_BEGIN_NAMESPACE

class Ui_DialogRigidBody
{
public:
    QGridLayout *gridLayout;
    QDoubleSpinBox *spinBoxGravityFactor;
    QDoubleSpinBox *spinBoxRestitution;
    QLabel *label_2;
    QLineEdit *lineEditName;
    QLabel *label;
    QComboBox *comboMotionType;
    QDoubleSpinBox *spinBoxLinearDamping;
    QDialogButtonBox *buttonBox;
    QLabel *label_5;
    QLabel *label_4;
    QDoubleSpinBox *spinBoxAngularDamping;
    QLabel *label_8;
    QGroupBox *groupMassProperties;
    QGridLayout *gridLayout_3;
    MassPropertySetter *widgetMassProperties;
    QSpacerItem *verticalSpacer;
    QLabel *label_7;
    QLabel *label_9;
    QDoubleSpinBox *spinBoxFriction;
    QDoubleSpinBox *spinBoxTimeFactor;
    QLabel *label_6;
    QLabel *label_3;
    QGroupBox *collisionFilterGroup;
    QGridLayout *gridLayout_2;
    CollisionFilterSetter *collisionFilterSetter;
    ShapeSelector *widgetShape;

    void setupUi(QDialog *DialogRigidBody)
    {
        if (DialogRigidBody->objectName().isEmpty())
            DialogRigidBody->setObjectName(QStringLiteral("DialogRigidBody"));
        DialogRigidBody->resize(425, 600);
        DialogRigidBody->setStyleSheet(QLatin1String("QWidget{\n"
"	background: transparent;\n"
"}\n"
"\n"
"QLabel{\n"
"	color: white;\n"
"}\n"
"\n"
"QGroupBox{\n"
"	color: white;\n"
"	border: 1px solid white;\n"
"	margin-top: 12px;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"	background-color: rgba(255, 255, 255, 160);\n"
"	border-color:white;\n"
"	color: rgb(0,0,127);\n"
"}\n"
"\n"
"QLineEdit{\n"
"	color: rgb(0,0,127);\n"
"	background-color: rgba(255, 255, 255, 128);\n"
"	border: 1px solid white;\n"
"	border-radius: 2px;\n"
"}\n"
"\n"
"QLineEdit::hover{\n"
"	background-color: rgba(255, 255, 255, 192);\n"
"}\n"
"\n"
"QSpinBox,QDoubleSpinBox {\n"
"	color: rgb(0,0,127);\n"
"	background-color: rgba(255, 255, 255, 127);\n"
"	border: 1px solid white;\n"
"	border-radius: 2px;\n"
"}\n"
"\n"
"QSpinBox:hover,QDoubleSpinBox:hover {\n"
"	background-color: rgba(255, 255, 255, 192);\n"
"}\n"
"\n"
"QSpinBox::up-button,QDoubleSpinBox::up-button,\n"
"QSpinBox::down-button,QDoubleSpinBox::down-button {\n"
"	bord"
                        "er-left: 1px solid white;\n"
"	background-color: transparent;\n"
"}\n"
"\n"
"QSpinBox::up-button:hover,\n"
"QDoubleSpinBox::up-button:hover,\n"
"QSpinBox::down-button:hover,\n"
"QDoubleSpinBox::down-button:hover\n"
"{\n"
"	border-left: 1px solid white;\n"
"	background-color: rgba(255, 255, 255, 127);\n"
"}\n"
"\n"
"QSpinBox::up-arrow,QDoubleSpinBox::up-arrow{\n"
"	image: url(:/icons/arrowup.png);\n"
"	width: 5px;\n"
"}\n"
"\n"
"QSpinBox::down-arrow,QDoubleSpinBox::down-arrow{\n"
"	image: url(:/icons/arrowdown.png);\n"
"	width: 5px;\n"
"}\n"
"\n"
"QPushButton{\n"
"	color: rgb(0,0,127);\n"
"	background-color: rgba(255, 255, 255, 127);\n"
"	border: 1px solid white;\n"
"	border-radius: 5px;\n"
"	padding: 4 20 4 20px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgba(255, 255, 255, 192);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: rgba(255, 255, 255, 224);\n"
"}\n"
"\n"
"QComboBox{\n"
"	color: rgb(0,0,127);\n"
"	background-color: rgba(255, 255, 255, 127);\n"
"	border: 1px solid white;\n"
""
                        "	border-radius: 2px;\n"
"}\n"
"\n"
"QComboBox:hover{\n"
"	background-color: rgba(255, 255, 255, 192);\n"
"}\n"
"\n"
"QComboBox:on{\n"
"	background-color: rgba(255, 255, 255, 192);\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"	border-left:1px solid white;\n"
"}\n"
"\n"
"QComboBox::drop-down::hover{\n"
"	border-left:1px solid white;\n"
"	background-color: rgba(255, 255, 255, 127);\n"
"}\n"
"\n"
"QComboBox::down-arrow{\n"
"	image: url(:/icons/arrowdown.png);\n"
"	width: 7px;\n"
"}\n"
"\n"
"QComboBoxListView{\n"
"	background-color: white;\n"
"}\n"
"\n"
"QDialog{\n"
"	background-image: url(:/backgrounds/yande 271324.jpg);\n"
"}"));
        gridLayout = new QGridLayout(DialogRigidBody);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        spinBoxGravityFactor = new QDoubleSpinBox(DialogRigidBody);
        spinBoxGravityFactor->setObjectName(QStringLiteral("spinBoxGravityFactor"));
        spinBoxGravityFactor->setDecimals(6);
        spinBoxGravityFactor->setMaximum(100);
        spinBoxGravityFactor->setSingleStep(0.01);

        gridLayout->addWidget(spinBoxGravityFactor, 11, 1, 1, 1);

        spinBoxRestitution = new QDoubleSpinBox(DialogRigidBody);
        spinBoxRestitution->setObjectName(QStringLiteral("spinBoxRestitution"));
        spinBoxRestitution->setDecimals(6);
        spinBoxRestitution->setMaximum(1);
        spinBoxRestitution->setSingleStep(0.01);

        gridLayout->addWidget(spinBoxRestitution, 3, 1, 1, 1);

        label_2 = new QLabel(DialogRigidBody);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEditName = new QLineEdit(DialogRigidBody);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEditName->sizePolicy().hasHeightForWidth());
        lineEditName->setSizePolicy(sizePolicy);

        gridLayout->addWidget(lineEditName, 0, 1, 1, 1);

        label = new QLabel(DialogRigidBody);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboMotionType = new QComboBox(DialogRigidBody);
        comboMotionType->setObjectName(QStringLiteral("comboMotionType"));

        gridLayout->addWidget(comboMotionType, 1, 1, 1, 1);

        spinBoxLinearDamping = new QDoubleSpinBox(DialogRigidBody);
        spinBoxLinearDamping->setObjectName(QStringLiteral("spinBoxLinearDamping"));
        spinBoxLinearDamping->setDecimals(6);
        spinBoxLinearDamping->setMaximum(1);
        spinBoxLinearDamping->setSingleStep(0.01);

        gridLayout->addWidget(spinBoxLinearDamping, 4, 1, 1, 1);

        buttonBox = new QDialogButtonBox(DialogRigidBody);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 14, 0, 1, 2);

        label_5 = new QLabel(DialogRigidBody);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        label_4 = new QLabel(DialogRigidBody);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        spinBoxAngularDamping = new QDoubleSpinBox(DialogRigidBody);
        spinBoxAngularDamping->setObjectName(QStringLiteral("spinBoxAngularDamping"));
        spinBoxAngularDamping->setDecimals(6);
        spinBoxAngularDamping->setMaximum(1);
        spinBoxAngularDamping->setSingleStep(0.01);

        gridLayout->addWidget(spinBoxAngularDamping, 5, 1, 1, 1);

        label_8 = new QLabel(DialogRigidBody);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 12, 0, 1, 1);

        groupMassProperties = new QGroupBox(DialogRigidBody);
        groupMassProperties->setObjectName(QStringLiteral("groupMassProperties"));
        gridLayout_3 = new QGridLayout(groupMassProperties);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        widgetMassProperties = new MassPropertySetter(groupMassProperties);
        widgetMassProperties->setObjectName(QStringLiteral("widgetMassProperties"));

        gridLayout_3->addWidget(widgetMassProperties, 0, 0, 1, 1);


        gridLayout->addWidget(groupMassProperties, 6, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 13, 0, 1, 1);

        label_7 = new QLabel(DialogRigidBody);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 11, 0, 1, 1);

        label_9 = new QLabel(DialogRigidBody);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 9, 0, 1, 1);

        spinBoxFriction = new QDoubleSpinBox(DialogRigidBody);
        spinBoxFriction->setObjectName(QStringLiteral("spinBoxFriction"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBoxFriction->sizePolicy().hasHeightForWidth());
        spinBoxFriction->setSizePolicy(sizePolicy1);
        spinBoxFriction->setDecimals(6);
        spinBoxFriction->setMaximum(1);
        spinBoxFriction->setSingleStep(0.01);

        gridLayout->addWidget(spinBoxFriction, 2, 1, 1, 1);

        spinBoxTimeFactor = new QDoubleSpinBox(DialogRigidBody);
        spinBoxTimeFactor->setObjectName(QStringLiteral("spinBoxTimeFactor"));
        spinBoxTimeFactor->setDecimals(6);
        spinBoxTimeFactor->setMaximum(100);
        spinBoxTimeFactor->setSingleStep(0.01);

        gridLayout->addWidget(spinBoxTimeFactor, 12, 1, 1, 1);

        label_6 = new QLabel(DialogRigidBody);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        label_3 = new QLabel(DialogRigidBody);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        collisionFilterGroup = new QGroupBox(DialogRigidBody);
        collisionFilterGroup->setObjectName(QStringLiteral("collisionFilterGroup"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(collisionFilterGroup->sizePolicy().hasHeightForWidth());
        collisionFilterGroup->setSizePolicy(sizePolicy2);
        gridLayout_2 = new QGridLayout(collisionFilterGroup);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        collisionFilterSetter = new CollisionFilterSetter(collisionFilterGroup);
        collisionFilterSetter->setObjectName(QStringLiteral("collisionFilterSetter"));

        gridLayout_2->addWidget(collisionFilterSetter, 1, 0, 1, 1);


        gridLayout->addWidget(collisionFilterGroup, 10, 0, 1, 2);

        widgetShape = new ShapeSelector(DialogRigidBody);
        widgetShape->setObjectName(QStringLiteral("widgetShape"));

        gridLayout->addWidget(widgetShape, 9, 1, 1, 1);


        retranslateUi(DialogRigidBody);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogRigidBody, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogRigidBody, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogRigidBody);
    } // setupUi

    void retranslateUi(QDialog *DialogRigidBody)
    {
        DialogRigidBody->setWindowTitle(QApplication::translate("DialogRigidBody", "Dialog", 0));
        label_2->setText(QApplication::translate("DialogRigidBody", "MotionType", 0));
        label->setText(QApplication::translate("DialogRigidBody", "Name", 0));
        label_5->setText(QApplication::translate("DialogRigidBody", "Angular Damping", 0));
        label_4->setText(QApplication::translate("DialogRigidBody", "Linear Damping", 0));
        label_8->setText(QApplication::translate("DialogRigidBody", "Time Factor", 0));
        groupMassProperties->setTitle(QApplication::translate("DialogRigidBody", "MassProperties", 0));
        label_7->setText(QApplication::translate("DialogRigidBody", "Gravity Factor", 0));
        label_9->setText(QApplication::translate("DialogRigidBody", "Shape:", 0));
        label_6->setText(QApplication::translate("DialogRigidBody", "Restitution", 0));
        label_3->setText(QApplication::translate("DialogRigidBody", "Friction", 0));
        collisionFilterGroup->setTitle(QApplication::translate("DialogRigidBody", "Collision Filter", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogRigidBody: public Ui_DialogRigidBody {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGRIGIDBODY_H
