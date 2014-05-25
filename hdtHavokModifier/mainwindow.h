#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "havokhelper.h"
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
	
public slots:
	void onButtonLoad();
	void onButtonSave();
	void onModifyRigidBody(int, int);
	void onModifyConstraint(int, int);
		
private slots:
	void on_buttonAddBody_clicked();
		
	void on_buttonRemoveBody_clicked();
	
	void on_buttonAddConstraint_clicked();
	
	void on_buttonRemoveConstraint_clicked();
	
private:
    Ui::MainWindow *ui;
	std::vector<hkpRigidBody*> rigidbodies;
	std::vector<hkpConstraintInstance*> constraints;
		
	void fillTableRigidBodies();
	void fillTableConstraints();
	void updateRigidBody(int idx);
	void updateConstraint(int idx);
};

#endif // MAINWINDOW_H
