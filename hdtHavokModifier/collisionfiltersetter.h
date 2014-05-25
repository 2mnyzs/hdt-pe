#ifndef COLLISIONFILTERSETTER_H
#define COLLISIONFILTERSETTER_H

#include <QWidget>
#include <QCheckBox>

namespace Ui {
	class CollisionFilterSetter;
}

class CollisionFilterSetter : public QWidget
{
	Q_OBJECT
	
public:
	explicit CollisionFilterSetter(QWidget *parent = 0);
	~CollisionFilterSetter();
	
	void setFilterInfo(int mask);
	int getFilterInfo();
	
private:
	Ui::CollisionFilterSetter *ui;
	QCheckBox* boxes[24];
};

#endif // COLLISIONFILTERSETTER_H
