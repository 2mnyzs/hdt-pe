#include "deformablefixed.h"
#include "ui_deformablefixed.h"

DeformableFixed::DeformableFixed(QWidget *parent) :
	ConstraintBase(parent),
	ui(new Ui::DeformableFixed)
{
	ui->setupUi(this);
}

DeformableFixed::~DeformableFixed()
{
	delete ui;
}

hkpConstraintData* DeformableFixed::getConstraint()
{
	hkTransform pivotA, pivotB;
	ui->widgetPivotA->getVector(pivotA.getTranslation());
	ui->widgetPivotB->getVector(pivotB.getTranslation());
	ui->widgetBasisA->getRotation(pivotA.getRotation());
	ui->widgetBasisB->getRotation(pivotB.getRotation());
	auto data = new hkpDeformableFixedConstraintData;
	data->setInBodySpace(pivotA, pivotB);
	
	hkSymmetricMatrix3 yield, ultimate;
	hkVector4 vec;
	hkQuaternion rotOffset;
	
	data->setLinearLimit(ui->spinBoxLinLimit->value());
	ui->widgetLinOffset->getVector(vec);
	data->setLinearOffset(vec);
	ui->widgetLinYield->getVector(vec);
	yield.setDiagonal(vec);
	ui->widgetLinUltimate->getVector(vec);
	ultimate.setDiagonal(vec);
	data->setLinearStrength(yield, ultimate);
			
	data->setAngularLimit(ui->spinBoxAngLimit->value() * (ui->radioDegree->isChecked() ? HK_REAL_DEG_TO_RAD : 1));
	ui->widgetAngOffset->getRotation(rotOffset);
	data->setAngularOffset(rotOffset);
	ui->widgetAngYield->getVector(vec);
	yield.setDiagonal(vec);
	ui->widgetAngUltimate->getVector(vec);
	ultimate.setDiagonal(vec);
	data->setAngularStrength(yield, ultimate);
	
	return data;
}

int DeformableFixed::parseConstraint(const hkpConstraintData *p)
{
	auto data = dynamic_cast<const hkpDeformableFixedConstraintData*>(p);
	if(!data) return false;
	ui->widgetPivotA->setVector(data->m_atoms.m_transforms.m_transformA.getTranslation());
	ui->widgetPivotB->setVector(data->m_atoms.m_transforms.m_transformB.getTranslation());
	ui->widgetBasisA->setRotation(data->m_atoms.m_transforms.m_transformA.getRotation());
	ui->widgetBasisB->setRotation(data->m_atoms.m_transforms.m_transformB.getRotation());
	
	hkVector4 yield, ultimate;
	ui->widgetLinOffset->setVector(data->m_atoms.m_lin.getOffset());
	ui->spinBoxLinLimit->setValue(data->m_atoms.m_lin.getMaxDistance());
	yield = data->m_atoms.m_lin.getYieldStrengthDiag();
	ultimate = data->m_atoms.m_lin.getUltimateStrengthDiag();
	ui->widgetLinYield->setVector(yield);
	ui->widgetLinUltimate->setVector(ultimate);
	
	float k = ui->radioDegree->isChecked() ? HK_REAL_RAD_TO_DEG : HK_REAL_DEG_TO_RAD;
	ui->widgetAngOffset->setRotation(data->m_atoms.m_ang.getOffset());
	ui->spinBoxAngLimit->setValue( hkMath::acos(data->m_atoms.m_ang.getCosMaxAngle())*k );
	yield = data->m_atoms.m_lin.getYieldStrengthDiag();
	ultimate = data->m_atoms.m_lin.getUltimateStrengthDiag();
	ui->widgetLinYield->setVector(yield);
	ui->widgetLinUltimate->setVector(ultimate);
	
	return true;
}

void DeformableFixed::on_radioDegree_toggled(bool checked)
{
	hkSymmetricMatrix3 matr;
	float k = checked ? HK_REAL_RAD_TO_DEG : HK_REAL_DEG_TO_RAD;
	ui->spinBoxAngLimit->setValue(ui->spinBoxAngLimit->value()*k);
}


