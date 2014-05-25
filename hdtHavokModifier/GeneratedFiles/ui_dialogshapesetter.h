/********************************************************************************
** Form generated from reading UI file 'dialogshapesetter.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSHAPESETTER_H
#define UI_DIALOGSHAPESETTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DialogShapeSetter
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox;
    QGridLayout *layoutShape;

    void setupUi(QDialog *DialogShapeSetter)
    {
        if (DialogShapeSetter->objectName().isEmpty())
            DialogShapeSetter->setObjectName(QStringLiteral("DialogShapeSetter"));
        DialogShapeSetter->resize(450, 319);
        DialogShapeSetter->setStyleSheet(QLatin1String("QWidget{\n"
"	background: transparent;\n"
"}\n"
"\n"
"QDialog{\n"
"	background-image: url(:/backgrounds/yande.re 134377.jpg);\n"
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
"QSpinBox::up-button,QDoub"
                        "leSpinBox::up-button,\n"
"QSpinBox::down-button,QDoubleSpinBox::down-button {\n"
"	border-left: 1px solid white;\n"
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
"	color: rgb(0,0,1"
                        "27);\n"
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
"QListWidget{\n"
"	background-color: rgba(255, 255, 255, 127);\n"
"	border: 1px solid white;\n"
"	border-radius: 2px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView{\n"
"	background-color: white;\n"
"}\n"
"\n"
"QMenu{\n"
"	color: rgb(0,0,127);\n"
"	background-color: rgba(255, 255, 255, 127);\n"
"	border: 1px solid white;\n"
"	border-radius: 2px;\n"
"	selection-background-color: rgba(255, 255, 255, 192);\n"
"}"));
        gridLayout = new QGridLayout(DialogShapeSetter);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buttonBox = new QDialogButtonBox(DialogShapeSetter);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);

        comboBox = new QComboBox(DialogShapeSetter);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 0, 0, 1, 1);

        layoutShape = new QGridLayout();
        layoutShape->setObjectName(QStringLiteral("layoutShape"));

        gridLayout->addLayout(layoutShape, 1, 0, 1, 1);


        retranslateUi(DialogShapeSetter);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogShapeSetter, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogShapeSetter, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogShapeSetter);
    } // setupUi

    void retranslateUi(QDialog *DialogShapeSetter)
    {
        DialogShapeSetter->setWindowTitle(QApplication::translate("DialogShapeSetter", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogShapeSetter: public Ui_DialogShapeSetter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSHAPESETTER_H
