#include "dialogshapesetter.h"
#include "ui_dialogshapesetter.h"

DialogShapeSetter::DialogShapeSetter(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DialogShapeSetter),
	box(this),
	capsule(this),
	cylinder(this),
	list(this),
	sphere(this),
	transformed(this),
	translated(this),
	triangle(this)
{
	ui->setupUi(this);
	setWindowFlags(windowFlags()|Qt::MSWindowsFixedSizeDialogHint);
	setWindowTitle("Shape");
	
	setters[0] = &box;
	setters[1] = &capsule;
	setters[2] = &cylinder;
	setters[3] = &list;
	setters[4] = &sphere;
	setters[5] = &transformed;
	setters[6] = &translated;
	setters[7] = &triangle;
	
	ui->comboBox->addItem("hkpBoxShape");
	ui->comboBox->addItem("hkpCapsuleShape");
	ui->comboBox->addItem("hkpCylinderShape");
	ui->comboBox->addItem("hkpListShape");
	ui->comboBox->addItem("hkpSphereShape");
	ui->comboBox->addItem("hkpConvexTransformShape");
	ui->comboBox->addItem("hkpConvexTranslateShape");
	ui->comboBox->addItem("hkpTriangleShape");
	
	for(auto i : setters) i->setVisible(0);
	for(auto i : setters) ui->layoutShape->addWidget(i, 0, 0);
	
	ui->comboBox->setCurrentIndex(4);
	ui->comboBox->setCurrentText(ui->comboBox->itemText(4));
	
	shape = 0;
}

DialogShapeSetter::~DialogShapeSetter()
{
	delete ui;
}

bool DialogShapeSetter::setShape(const hkpShape *shape)
{
	bool ret = 0;
	for(int i=0; i<8; ++i)
	{
		auto flag = setters[i]->parseShape(shape);
		ret |= flag;
		if(flag)
		{
			ui->comboBox->setCurrentIndex(i);
			ui->comboBox->setCurrentText(ui->comboBox->itemText(i));
			on_comboBox_currentIndexChanged(i);
		}
	}
	return ret;
}

void DialogShapeSetter::accept()
{
	shape = setters[ui->comboBox->currentIndex()]->getShape();
	if(shape) QDialog::accept();
}

void DialogShapeSetter::on_comboBox_currentIndexChanged(int index)
{
	for(auto i : setters) i->setVisible(0);
	setters[index]->setVisible(1);
}
