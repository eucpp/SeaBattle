#pragma once
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QSharedPointer>
#include <QTimer>

#include "cell.h"
namespace Ui {
class Field;
}

class Field : public QWidget
{
	Q_OBJECT
	
public:
	explicit Field(QWidget *parent = 0);
    void paintCell(int id, Textures texture);
	void showAttackStatus(AttackStatus status);
	void showResult(Players player);
    Cell* getCellView(int id);

	~Field();
private slots:
	void cellWasAttacked(int id);
	void getCoordinate(QPointF first, QPointF second);
	void deleteShipOnCell(int id);
	void deleteMessage();
signals:
	void playerAttackCell(int id);
	void shipOnCells(int firstId, int secondId);
	void deleteShip(int id);
private:
	Ui::Field *ui;
	QVector<Cell *> field;
	QGraphicsScene *mScene;
	QSharedPointer<QGraphicsItem> item;
	QSharedPointer<QGraphicsItem> item2;
	QTimer timer;
};

