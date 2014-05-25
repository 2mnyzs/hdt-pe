/********************************************************************************
** Form generated from reading UI file 'dialogconstraint.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCONSTRAINT_H
#define UI_DIALOGCONSTRAINT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogConstraint
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QTabWidget *tabWidget;
    QWidget *tabNormal;
    QGridLayout *gridLayout_2;
    QFrame *frameNormal;
    QGridLayout *gridLayout_4;
    QFrame *frameType;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QComboBox *comboType;
    QFrame *frameBodies;
    QHBoxLayout *layoutBodies;
    QLabel *label;
    QComboBox *comboBodyA;
    QLabel *label_2;
    QComboBox *comboBodyB;
    QGroupBox *groupBoxData;
    QGridLayout *layoutData;
    QWidget *tabChain;
    QGridLayout *gridLayout_3;
    QFrame *frameChain;
    QGridLayout *gridLayout_5;
    QFrame *frameData;
    QVBoxLayout *verticalLayout;
    QComboBox *comboChainType;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label_5;
    QLabel *label_6;
    QDoubleSpinBox *chainTau;
    QDoubleSpinBox *chainDamping;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_6;
    QGridLayout *layoutChainData;
    QListWidget *listWidget;
    QLabel *label_3;
    QFrame *horizontalFrame;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboChainBody;
    QToolButton *buttonAdd;
    QToolButton *buttonRemove;
    QToolButton *buttonUp;
    QToolButton *toolButton;

    void setupUi(QDialog *DialogConstraint)
    {
        if (DialogConstraint->objectName().isEmpty())
            DialogConstraint->setObjectName(QStringLiteral("DialogConstraint"));
        DialogConstraint->resize(700, 490);
        DialogConstraint->setStyleSheet(QLatin1String("QWidget{\n"
"	background:transparent;\n"
"}\n"
"\n"
"QLabel{\n"
"	color: rgb(0,0,127);\n"
"}\n"
"\n"
"QDialog{\n"
"	background-image: url(:/backgrounds/yande.re 268248.jpg);\n"
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
"QFrame#frameNormal, QFrame#frameChain{\n"
"	background-color:rgba(255,255,255,127);\n"
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
"	margin-top: 12px;\n"
""
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
"QSpinBox::down-button:hover,\n"
"QDoub"
                        "leSpinBox::down-button:hover\n"
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
"QPushButton:pressed, QToolButton:presse"
                        "d{\n"
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
"	background-color: rgba(255, 255, 255, 192);\n"
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
"	border: 1px solid white;\n"
"}"));
        gridLayout = new QGridLayout(DialogConstraint);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buttonBox = new QDialogButtonBox(DialogConstraint);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);

        tabWidget = new QTabWidget(DialogConstraint);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabNormal = new QWidget();
        tabNormal->setObjectName(QStringLiteral("tabNormal"));
        gridLayout_2 = new QGridLayout(tabNormal);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        frameNormal = new QFrame(tabNormal);
        frameNormal->setObjectName(QStringLiteral("frameNormal"));
        frameNormal->setFrameShape(QFrame::StyledPanel);
        frameNormal->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frameNormal);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 9, 0, 0);
        frameType = new QFrame(frameNormal);
        frameType->setObjectName(QStringLiteral("frameType"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frameType->sizePolicy().hasHeightForWidth());
        frameType->setSizePolicy(sizePolicy);
        frameType->setFrameShape(QFrame::StyledPanel);
        frameType->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frameType);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(frameType);
        label_4->setObjectName(QStringLiteral("label_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_4);

        comboType = new QComboBox(frameType);
        comboType->setObjectName(QStringLiteral("comboType"));
        sizePolicy.setHeightForWidth(comboType->sizePolicy().hasHeightForWidth());
        comboType->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(comboType);


        gridLayout_4->addWidget(frameType, 0, 0, 1, 1);

        frameBodies = new QFrame(frameNormal);
        frameBodies->setObjectName(QStringLiteral("frameBodies"));
        sizePolicy.setHeightForWidth(frameBodies->sizePolicy().hasHeightForWidth());
        frameBodies->setSizePolicy(sizePolicy);
        frameBodies->setFrameShape(QFrame::StyledPanel);
        frameBodies->setFrameShadow(QFrame::Raised);
        layoutBodies = new QHBoxLayout(frameBodies);
        layoutBodies->setObjectName(QStringLiteral("layoutBodies"));
        layoutBodies->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(frameBodies);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        layoutBodies->addWidget(label);

        comboBodyA = new QComboBox(frameBodies);
        comboBodyA->setObjectName(QStringLiteral("comboBodyA"));
        sizePolicy.setHeightForWidth(comboBodyA->sizePolicy().hasHeightForWidth());
        comboBodyA->setSizePolicy(sizePolicy);

        layoutBodies->addWidget(comboBodyA);

        label_2 = new QLabel(frameBodies);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        layoutBodies->addWidget(label_2);

        comboBodyB = new QComboBox(frameBodies);
        comboBodyB->setObjectName(QStringLiteral("comboBodyB"));
        sizePolicy.setHeightForWidth(comboBodyB->sizePolicy().hasHeightForWidth());
        comboBodyB->setSizePolicy(sizePolicy);

        layoutBodies->addWidget(comboBodyB);


        gridLayout_4->addWidget(frameBodies, 1, 0, 1, 1);

        groupBoxData = new QGroupBox(frameNormal);
        groupBoxData->setObjectName(QStringLiteral("groupBoxData"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBoxData->sizePolicy().hasHeightForWidth());
        groupBoxData->setSizePolicy(sizePolicy2);
        groupBoxData->setStyleSheet(QStringLiteral(""));
        layoutData = new QGridLayout(groupBoxData);
        layoutData->setObjectName(QStringLiteral("layoutData"));

        gridLayout_4->addWidget(groupBoxData, 2, 0, 1, 1);


        gridLayout_2->addWidget(frameNormal, 0, 0, 1, 1);

        tabWidget->addTab(tabNormal, QString());
        tabChain = new QWidget();
        tabChain->setObjectName(QStringLiteral("tabChain"));
        gridLayout_3 = new QGridLayout(tabChain);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        frameChain = new QFrame(tabChain);
        frameChain->setObjectName(QStringLiteral("frameChain"));
        frameChain->setFrameShape(QFrame::StyledPanel);
        frameChain->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frameChain);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, -1, 0, 0);
        frameData = new QFrame(frameChain);
        frameData->setObjectName(QStringLiteral("frameData"));
        sizePolicy2.setHeightForWidth(frameData->sizePolicy().hasHeightForWidth());
        frameData->setSizePolicy(sizePolicy2);
        frameData->setFrameShape(QFrame::StyledPanel);
        frameData->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frameData);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        comboChainType = new QComboBox(frameData);
        comboChainType->setObjectName(QStringLiteral("comboChainType"));

        verticalLayout->addWidget(comboChainType);

        groupBox = new QGroupBox(frameData);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_6);

        chainTau = new QDoubleSpinBox(groupBox);
        chainTau->setObjectName(QStringLiteral("chainTau"));
        chainTau->setDecimals(6);
        chainTau->setMaximum(1);
        chainTau->setSingleStep(0.01);
        chainTau->setValue(0.8);

        formLayout->setWidget(0, QFormLayout::FieldRole, chainTau);

        chainDamping = new QDoubleSpinBox(groupBox);
        chainDamping->setObjectName(QStringLiteral("chainDamping"));
        chainDamping->setDecimals(6);
        chainDamping->setMaximum(1);
        chainDamping->setSingleStep(0.01);
        chainDamping->setValue(0.8);

        formLayout->setWidget(1, QFormLayout::FieldRole, chainDamping);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(frameData);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_6 = new QGridLayout(groupBox_2);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        layoutChainData = new QGridLayout();
        layoutChainData->setObjectName(QStringLiteral("layoutChainData"));

        gridLayout_6->addLayout(layoutChainData, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_2);


        gridLayout_5->addWidget(frameData, 0, 1, 3, 1);

        listWidget = new QListWidget(frameChain);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy3);
        listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout_5->addWidget(listWidget, 1, 0, 1, 1);

        label_3 = new QLabel(frameChain);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy4);

        gridLayout_5->addWidget(label_3, 0, 0, 1, 1);

        horizontalFrame = new QFrame(frameChain);
        horizontalFrame->setObjectName(QStringLiteral("horizontalFrame"));
        sizePolicy4.setHeightForWidth(horizontalFrame->sizePolicy().hasHeightForWidth());
        horizontalFrame->setSizePolicy(sizePolicy4);
        horizontalLayout_2 = new QHBoxLayout(horizontalFrame);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        comboChainBody = new QComboBox(horizontalFrame);
        comboChainBody->setObjectName(QStringLiteral("comboChainBody"));

        horizontalLayout_2->addWidget(comboChainBody);

        buttonAdd = new QToolButton(horizontalFrame);
        buttonAdd->setObjectName(QStringLiteral("buttonAdd"));
        sizePolicy1.setHeightForWidth(buttonAdd->sizePolicy().hasHeightForWidth());
        buttonAdd->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(buttonAdd);

        buttonRemove = new QToolButton(horizontalFrame);
        buttonRemove->setObjectName(QStringLiteral("buttonRemove"));
        sizePolicy1.setHeightForWidth(buttonRemove->sizePolicy().hasHeightForWidth());
        buttonRemove->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(buttonRemove);

        buttonUp = new QToolButton(horizontalFrame);
        buttonUp->setObjectName(QStringLiteral("buttonUp"));
        buttonUp->setArrowType(Qt::UpArrow);

        horizontalLayout_2->addWidget(buttonUp);

        toolButton = new QToolButton(horizontalFrame);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setArrowType(Qt::DownArrow);

        horizontalLayout_2->addWidget(toolButton);


        gridLayout_5->addWidget(horizontalFrame, 2, 0, 1, 1);


        gridLayout_3->addWidget(frameChain, 0, 0, 1, 1);

        tabWidget->addTab(tabChain, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(DialogConstraint);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogConstraint, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogConstraint, SLOT(reject()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(DialogConstraint);
    } // setupUi

    void retranslateUi(QDialog *DialogConstraint)
    {
        DialogConstraint->setWindowTitle(QApplication::translate("DialogConstraint", "Dialog", 0));
        label_4->setText(QApplication::translate("DialogConstraint", "Type:", 0));
        label->setText(QApplication::translate("DialogConstraint", "Body A:", 0));
        label_2->setText(QApplication::translate("DialogConstraint", "Body B:", 0));
        groupBoxData->setTitle(QApplication::translate("DialogConstraint", "Constraints Settings:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabNormal), QApplication::translate("DialogConstraint", "Normal", 0));
        groupBox->setTitle(QApplication::translate("DialogConstraint", "Common Setting:", 0));
        label_5->setText(QApplication::translate("DialogConstraint", "Tau:", 0));
        label_6->setText(QApplication::translate("DialogConstraint", "Damping:", 0));
        groupBox_2->setTitle(QApplication::translate("DialogConstraint", "Node Setting:", 0));
        label_3->setText(QApplication::translate("DialogConstraint", "Rigidbodies:", 0));
        buttonAdd->setText(QApplication::translate("DialogConstraint", "+", 0));
        buttonRemove->setText(QApplication::translate("DialogConstraint", "-", 0));
        buttonUp->setText(QApplication::translate("DialogConstraint", "...", 0));
        toolButton->setText(QApplication::translate("DialogConstraint", "...", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabChain), QApplication::translate("DialogConstraint", "Chain", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogConstraint: public Ui_DialogConstraint {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCONSTRAINT_H
