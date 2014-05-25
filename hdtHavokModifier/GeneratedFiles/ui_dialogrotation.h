/********************************************************************************
** Form generated from reading UI file 'dialogrotation.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGROTATION_H
#define UI_DIALOGROTATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "matrix33setter.h"
#include "vec3setter.h"
#include "vec4setter.h"

QT_BEGIN_NAMESPACE

class Ui_DialogRotation
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabEular;
    QGridLayout *gridLayout_4;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *radioEularRadius;
    QRadioButton *radioEularDegree;
    QSpacerItem *horizontalSpacer_5;
    QFrame *frame_4;
    QFormLayout *formLayout_3;
    QLabel *label_6;
    QDoubleSpinBox *spinBoxR;
    QLabel *label_7;
    QDoubleSpinBox *spinBoxP;
    QLabel *label_8;
    QDoubleSpinBox *spinBoxY;
    QWidget *tabAxisAngle;
    QVBoxLayout *verticalLayout_3;
    QFrame *gridFrame_3;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *radioAxisAngleRadius;
    QRadioButton *radioAxisAngleDegree;
    QSpacerItem *horizontalSpacer_6;
    QFrame *formFrame_3;
    QFormLayout *formLayout_4;
    QLabel *label_9;
    QLabel *label_10;
    QDoubleSpinBox *spinBoxAngle;
    Vec3Setter *widgetAxis;
    QWidget *tabMatrix;
    QGridLayout *gridLayout_5;
    Matrix33Setter *widgetMatrix;
    QWidget *tabQuaternion;
    QGridLayout *gridLayout_6;
    Vec4Setter *widgetQuaternion;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogRotation)
    {
        if (DialogRotation->objectName().isEmpty())
            DialogRotation->setObjectName(QStringLiteral("DialogRotation"));
        DialogRotation->resize(360, 182);
        DialogRotation->setStyleSheet(QLatin1String("QWidget{\n"
"	color: rgb(0,0,127);\n"
"	background:transparent;\n"
"}\n"
"\n"
"QDialog{\n"
"	background-image: url(:/backgrounds/yande.re 271499.jpg);\n"
"}\n"
"\n"
"QTabWidget{\n"
"	border: 1px solid white;\n"
"}\n"
"\n"
"QTabWidget::pane{\n"
"	border: 1px solid white;\n"
"	padding: 0 0 0 0px;\n"
"}\n"
"\n"
"QTabWidget#tabWidget::pane{\n"
"	background-color: rgba(255,255,255,127);\n"
"	border: 1px solid white;\n"
"	padding: 0 0 0 0px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 255, 255, 64), stop:1 rgba(255, 255, 255, 127));\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 255, 255, 64), stop:1 rgba(255, 255, 255, 255));\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 255, 255, 64), stop:1 rgba(255, 255, 255, 255));\n"
"}\n"
"\n"
"QGroupBox{\n"
"	border: 1px solid white;\n"
""
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
"	background-color: rgba(255, 255, 255, 127);\n"
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
"	border-left: 1px solid white;\n"
"	background-color: transparent;\n"
"}\n"
"\n"
"QSpinBox::up-button:hover,\n"
"QDoubleSpinBox::up-button:hover,\n"
"QSpinBox::down-"
                        "button:hover,\n"
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
"QToolButton{\n"
"	color: rgb(0,0,127);\n"
"	background-color: rgba(255, 255, 255, 127);\n"
"	border: 1px solid white;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QToolButton::menu-button{\n"
"	border-left: 1px solid white;\n"
"}\n"
"\n"
"QToolButton::menu-arrow{\n"
"	image: url(:/icons/arrowdown.png);\n"
"	width: 3;\n"
"}\n"
"\n"
"QPushButton:hover, QToolButton:hover{\n"
"	background-color: rgba(255, 255, 255, 192);\n"
"}\n"
"\n"
"QPushButton:pres"
                        "sed, QToolButton:pressed{\n"
"	background-color: rgba(255, 255, 255, 224);\n"
"}\n"
"\n"
"QComboBox{\n"
"	color: rgb(0,0,127);\n"
"	background-color: rgba(255, 255, 255, 127);\n"
"	border: 1px solid white;\n"
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
"QComboBox::down-arrow{\n"
"	image: url(:/icons/arrowdown.png);\n"
"	width: 7px;\n"
"}\n"
"\n"
"QComboBoxListView{\n"
"	background-color: white;\n"
"}\n"
"\n"
"QListWidget{\n"
"	border:1px solid white;\n"
"	border-radius:2px;\n"
"}\n"
"\n"
"QMenu{\n"
"	color: rgb(0,0,127);\n"
"	background-color:white;\n"
"	border: 1px solid wh"
                        "ite;\n"
"}"));
        verticalLayout = new QVBoxLayout(DialogRotation);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(DialogRotation);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabEular = new QWidget();
        tabEular->setObjectName(QStringLiteral("tabEular"));
        gridLayout_4 = new QGridLayout(tabEular);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        frame_3 = new QFrame(tabEular);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        radioEularRadius = new QRadioButton(frame_3);
        radioEularRadius->setObjectName(QStringLiteral("radioEularRadius"));
        radioEularRadius->setChecked(true);

        horizontalLayout_4->addWidget(radioEularRadius);

        radioEularDegree = new QRadioButton(frame_3);
        radioEularDegree->setObjectName(QStringLiteral("radioEularDegree"));

        horizontalLayout_4->addWidget(radioEularDegree);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        gridLayout_4->addWidget(frame_3, 0, 0, 1, 1);

        frame_4 = new QFrame(tabEular);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy1);
        formLayout_3 = new QFormLayout(frame_4);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(frame_4);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_6);

        spinBoxR = new QDoubleSpinBox(frame_4);
        spinBoxR->setObjectName(QStringLiteral("spinBoxR"));
        spinBoxR->setDecimals(8);
        spinBoxR->setMinimum(-360);
        spinBoxR->setMaximum(360);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, spinBoxR);

        label_7 = new QLabel(frame_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_7);

        spinBoxP = new QDoubleSpinBox(frame_4);
        spinBoxP->setObjectName(QStringLiteral("spinBoxP"));
        spinBoxP->setDecimals(8);
        spinBoxP->setMinimum(-360);
        spinBoxP->setMaximum(360);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, spinBoxP);

        label_8 = new QLabel(frame_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_8);

        spinBoxY = new QDoubleSpinBox(frame_4);
        spinBoxY->setObjectName(QStringLiteral("spinBoxY"));
        spinBoxY->setDecimals(8);
        spinBoxY->setMinimum(-360);
        spinBoxY->setMaximum(360);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, spinBoxY);


        gridLayout_4->addWidget(frame_4, 1, 0, 1, 1);

        tabWidget->addTab(tabEular, QString());
        tabAxisAngle = new QWidget();
        tabAxisAngle->setObjectName(QStringLiteral("tabAxisAngle"));
        verticalLayout_3 = new QVBoxLayout(tabAxisAngle);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridFrame_3 = new QFrame(tabAxisAngle);
        gridFrame_3->setObjectName(QStringLiteral("gridFrame_3"));
        horizontalLayout_5 = new QHBoxLayout(gridFrame_3);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        radioAxisAngleRadius = new QRadioButton(gridFrame_3);
        radioAxisAngleRadius->setObjectName(QStringLiteral("radioAxisAngleRadius"));
        radioAxisAngleRadius->setChecked(true);

        horizontalLayout_5->addWidget(radioAxisAngleRadius);

        radioAxisAngleDegree = new QRadioButton(gridFrame_3);
        radioAxisAngleDegree->setObjectName(QStringLiteral("radioAxisAngleDegree"));

        horizontalLayout_5->addWidget(radioAxisAngleDegree);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        verticalLayout_3->addWidget(gridFrame_3);

        formFrame_3 = new QFrame(tabAxisAngle);
        formFrame_3->setObjectName(QStringLiteral("formFrame_3"));
        sizePolicy1.setHeightForWidth(formFrame_3->sizePolicy().hasHeightForWidth());
        formFrame_3->setSizePolicy(sizePolicy1);
        formLayout_4 = new QFormLayout(formFrame_3);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(formFrame_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_9);

        label_10 = new QLabel(formFrame_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_10);

        spinBoxAngle = new QDoubleSpinBox(formFrame_3);
        spinBoxAngle->setObjectName(QStringLiteral("spinBoxAngle"));
        spinBoxAngle->setDecimals(8);
        spinBoxAngle->setMinimum(-180);
        spinBoxAngle->setMaximum(180);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, spinBoxAngle);

        widgetAxis = new Vec3Setter(formFrame_3);
        widgetAxis->setObjectName(QStringLiteral("widgetAxis"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, widgetAxis);


        verticalLayout_3->addWidget(formFrame_3);

        tabWidget->addTab(tabAxisAngle, QString());
        tabMatrix = new QWidget();
        tabMatrix->setObjectName(QStringLiteral("tabMatrix"));
        gridLayout_5 = new QGridLayout(tabMatrix);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        widgetMatrix = new Matrix33Setter(tabMatrix);
        widgetMatrix->setObjectName(QStringLiteral("widgetMatrix"));

        gridLayout_5->addWidget(widgetMatrix, 0, 0, 1, 2);

        tabWidget->addTab(tabMatrix, QString());
        tabQuaternion = new QWidget();
        tabQuaternion->setObjectName(QStringLiteral("tabQuaternion"));
        gridLayout_6 = new QGridLayout(tabQuaternion);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        widgetQuaternion = new Vec4Setter(tabQuaternion);
        widgetQuaternion->setObjectName(QStringLiteral("widgetQuaternion"));

        gridLayout_6->addWidget(widgetQuaternion, 0, 0, 1, 2);

        tabWidget->addTab(tabQuaternion, QString());

        verticalLayout->addWidget(tabWidget);

        buttonBox = new QDialogButtonBox(DialogRotation);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DialogRotation);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogRotation, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogRotation, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DialogRotation);
    } // setupUi

    void retranslateUi(QDialog *DialogRotation)
    {
        DialogRotation->setWindowTitle(QApplication::translate("DialogRotation", "Dialog", 0));
        radioEularRadius->setText(QApplication::translate("DialogRotation", "Radius", 0));
        radioEularDegree->setText(QApplication::translate("DialogRotation", "Degree", 0));
        label_6->setText(QApplication::translate("DialogRotation", "Roll(Z):", 0));
        label_7->setText(QApplication::translate("DialogRotation", "Pitch(Y):", 0));
        label_8->setText(QApplication::translate("DialogRotation", "Yaw(X):", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabEular), QApplication::translate("DialogRotation", "Eular", 0));
        tabWidget->setTabToolTip(tabWidget->indexOf(tabEular), QApplication::translate("DialogRotation", "Roll first, then pitch, finally yaw.", 0));
        radioAxisAngleRadius->setText(QApplication::translate("DialogRotation", "Radius", 0));
        radioAxisAngleDegree->setText(QApplication::translate("DialogRotation", "Degree", 0));
        label_9->setText(QApplication::translate("DialogRotation", "Axis:", 0));
        label_10->setText(QApplication::translate("DialogRotation", "Angle:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabAxisAngle), QApplication::translate("DialogRotation", "Axis-Angle", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabMatrix), QApplication::translate("DialogRotation", "Matrix", 0));
        tabWidget->setTabToolTip(tabWidget->indexOf(tabMatrix), QApplication::translate("DialogRotation", "<html><head/><body><p>Each column represent an axis after rotated in old space.</p><p>Column 1 : X axis.</p><p>Column 2 : Y axis.</p><p>Column 3 : Z axis.</p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabQuaternion), QApplication::translate("DialogRotation", "Quaternion", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogRotation: public Ui_DialogRotation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGROTATION_H
