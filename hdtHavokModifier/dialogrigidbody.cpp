#include "dialogrigidbody.h"
#include "ui_dialogrigidbody.h"

DialogRigidBody::DialogRigidBody(hkpRigidBody* rb, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DialogRigidBody)
{
	ui->setupUi(this);
	setWindowTitle("RigidBody");
	setWindowFlags(windowFlags()|Qt::MSWindowsFixedSizeDialogHint);
	
	if(rb)
	{
		rigidbody = rb;
		rigidbody->addReference();
	}
	else
	{
		hkpRigidBodyCinfo cinfo;
		cinfo.m_shape = new hkpSphereShape(1);
		rb = rigidbody = new hkpRigidBody(cinfo);
		rb->setName("New Rigidbody");
		cinfo.m_shape->removeReference();
	}
	
	ui->lineEditName->setText(tr(rb->getName()));
	ui->spinBoxFriction->setValue(rb->getFriction());
	ui->spinBoxRestitution->setValue(rb->getRestitution());
	ui->spinBoxLinearDamping->setValue(rb->getLinearDamping());
	ui->spinBoxAngularDamping->setValue(rb->getAngularDamping());
	ui->spinBoxTimeFactor->setValue(rb->getTimeFactor());
	ui->spinBoxGravityFactor->setValue(rb->getGravityFactor());
	
	ui->collisionFilterSetter->setFilterInfo(rb->getCollisionFilterInfo());
	
	hkMassProperties pi;
	pi.m_mass = rb->getMass();
	pi.m_centerOfMass = rb->getCenterOfMassLocal();
	rb->getInertiaLocal(pi.m_inertiaTensor);
	ui->widgetMassProperties->setMassProperties(pi);
	
	ui->widgetShape->setShape(rb->getCollidable()->getShape());
	
	auto motionTypeClass = hkpMotionClass.getDeclaredEnumByName("MotionType");
	for(int i=1; i<motionTypeClass->getNumItems()-1; ++i)
	{
		auto name = motionTypeClass->getItem(i).getName();
		auto value = motionTypeClass->getItem(i).getValue();
		ui->comboMotionType->addItem(tr(name), QVariant(value));
		if(value == rb->getMotionType())
		{
			ui->comboMotionType->setCurrentIndex(i);
			ui->comboMotionType->setCurrentText(tr(name));
		}
	}
}

DialogRigidBody::~DialogRigidBody()
{
	if(rigidbody) rigidbody->removeReference();
	delete ui;
}

void DialogRigidBody::accept()
{
	hkpRigidBodyCinfo cinfo;
	
	cinfo.m_friction = ui->spinBoxFriction->value();
	cinfo.m_restitution = ui->spinBoxRestitution->value();
	cinfo.m_linearDamping = ui->spinBoxLinearDamping->value();
	cinfo.m_angularDamping = ui->spinBoxAngularDamping->value();
	cinfo.m_gravityFactor = ui->spinBoxGravityFactor->value();
	cinfo.m_timeFactor = ui->spinBoxTimeFactor->value();
	cinfo.m_motionType = (hkpMotion::MotionType)ui->comboMotionType->itemData(ui->comboMotionType->currentIndex()).toInt();
	if(cinfo.m_motionType == hkpMotion::MOTION_FIXED)
		cinfo.m_motionType = hkpMotion::MOTION_KEYFRAMED;
	cinfo.m_collisionFilterInfo = ui->collisionFilterSetter->getFilterInfo();
	cinfo.m_shape = ui->widgetShape->getShape();
	
	hkMassProperties pi;
	ui->widgetMassProperties->getMassProperties(pi);
	if(cinfo.m_motionType != hkpMotion::MOTION_KEYFRAMED)
	{
		if(!pi.m_mass) pi.m_mass = 1;
		if(!pi.m_inertiaTensor.getDeterminant()) pi.m_inertiaTensor.setIdentity();
	}
	cinfo.setMassProperties(pi);
	cinfo.m_linearVelocity = rigidbody->getLinearVelocity();
	cinfo.m_angularVelocity = rigidbody->getAngularVelocity();
	cinfo.m_position = rigidbody->getPosition();
	cinfo.m_rotation = rigidbody->getRotation();

	if(!rigidbody || rigidbody->isFixedOrKeyframed() != (cinfo.m_motionType == hkpMotion::MOTION_KEYFRAMED))
	{
		if(rigidbody)rigidbody->removeReference();
		rigidbody = new hkpRigidBody(cinfo);
	}
	else
	{
		rigidbody->setFriction(cinfo.m_friction);
		rigidbody->setRestitution(cinfo.m_restitution);
		rigidbody->setLinearDamping(cinfo.m_linearDamping);
		rigidbody->setAngularDamping(cinfo.m_angularDamping);
		rigidbody->setGravityFactor(cinfo.m_gravityFactor);
		rigidbody->setTimeFactor(cinfo.m_timeFactor);
		if(!rigidbody->isFixedOrKeyframed())
		{
			rigidbody->setMotionType(cinfo.m_motionType);
			rigidbody->setMass(cinfo.m_mass);
			rigidbody->setCenterOfMassLocal(cinfo.m_centerOfMass);
			rigidbody->setInertiaLocal(cinfo.m_inertiaTensor);
		}
		rigidbody->setCollisionFilterInfo(cinfo.m_collisionFilterInfo);
		rigidbody->setShape(cinfo.m_shape);
	}

	rigidbody->setName(ui->lineEditName->text().toStdString().c_str());
	QDialog::accept();
}

void DialogRigidBody::on_widgetMassProperties_buttonAutoFill(float mass)
{
	if(mass)
	{
		hkMassProperties pi;
		pi.m_mass = mass;
		calcMassProperties(pi, ui->widgetShape->getShape());
		ui->widgetMassProperties->setMassProperties(pi);
	}
}
