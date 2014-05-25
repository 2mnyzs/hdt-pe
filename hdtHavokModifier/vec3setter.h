#ifndef VEC3SETTER_H
#define VEC3SETTER_H

#include <QWidget>
#include "havokhelper.h"

namespace Ui {
	class Vec3Setter;
}

class Vec3Setter : public QWidget
{
	Q_OBJECT
	
public:
	explicit Vec3Setter(QWidget *parent = 0);
	~Vec3Setter();
	
	void getVector(hkVector4& vec);
	void setVector(const hkVector4& vec);
	
	void setLowLimit(const hkVector4& vec);
	void setHighLimit(const hkVector4& vec);
	void setPrecision(int precision);
	
private:
	Ui::Vec3Setter *ui;
};

#endif // VEC3SETTER_H
