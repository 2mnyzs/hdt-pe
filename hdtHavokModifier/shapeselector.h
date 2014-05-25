#ifndef SHAPESELECTOR_H
#define SHAPESELECTOR_H

#include <QWidget>
#include "havokhelper.h"

namespace Ui {
	class ShapeSelector;
}

class ShapeSelector : public QWidget
{
	Q_OBJECT
	
public:
	explicit ShapeSelector(QWidget *parent = 0);
	~ShapeSelector();
	
	void setShape(const hkpShape*);
	const hkpShape* getShape();
		
private slots:
	void on_pushButton_clicked();
	
private:
	const hkpShape* shape;
	Ui::ShapeSelector *ui;
};

#endif // SHAPESELECTOR_H
