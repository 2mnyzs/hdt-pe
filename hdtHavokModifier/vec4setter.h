#ifndef VEC4SETTER_H
#define VEC4SETTER_H

#include <QWidget>
#include "havokhelper.h"

namespace Ui {
	class Vec4Setter;
}

class Vec4Setter : public QWidget
{
	Q_OBJECT
	
public:
	explicit Vec4Setter(QWidget *parent = 0);
	~Vec4Setter();
	
	void getVector(hkVector4& vec);
	void setVector(const hkVector4& vec);
	
	void setLowLimit(const hkVector4& vec);
	void setHighLimit(const hkVector4& vec);
	void setPrecision(int precision);
	
private:
	Ui::Vec4Setter *ui;
};

#endif // VEC4SETTER_H
