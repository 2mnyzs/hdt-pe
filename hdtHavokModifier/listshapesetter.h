#ifndef LISTSHAPESETTER_H
#define LISTSHAPESETTER_H

#include <QWidget>
#include <vector>
#include "shapesetterbase.h"

namespace Ui {
	class ListShapeSetter;
}

class ListShapeSetter : public ShapeSetterBase
{
	Q_OBJECT
	
public:
	explicit ListShapeSetter(QWidget *parent = 0);
	~ListShapeSetter();
	
	virtual const hkpShape* getShape();
	virtual bool parseShape(const hkpShape *);
	
private slots:
	void on_listWidget_doubleClicked(const QModelIndex &index);
	
	void on_buttonAdd_clicked();
	
	void on_buttonRemove_clicked();
	
private:
	Ui::ListShapeSetter *ui;
	hkArray<const hkpShape*> children;
};

#endif // LISTSHAPESETTER_H
