#pragma once
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QSharedPointer>
#include <QTimer>
#include <QList>
#include "InterfaceField.h"

#include "cell.h"
namespace Ui {
class Field;
}

class Field : public InterfaceField
{
	Q_OBJECT
public:
	explicit Field();
	void showAttackStatus(AttackStatus status);
	void showResult(Players player);
	Cell* getCellView(int id);
	void addImage(int id, ImageID iD);
	void removeImageFromCell(int id);

	~Field();

public slots:
	void setEnabledItself(bool switcher);
	void repaint(int id, Textures texture);

private slots:
	void getCoordinate(QPointF first, QPointF second);
	void deleteShipOnCell(int id);
	void deleteMessage();

signals:
	void attack(int id);
	void placeShip(int firstId, int secondId);
	void deleteShip(int id);
	void setFirstArrows(int id);
	void setNextArrow(int id);

private:
	void paintCell(int id, Textures texture);
	Ui::Field *ui;
	QVector<Cell *> field;
	QGraphicsScene *mScene;
	QSharedPointer<QGraphicsItem> itemForMessage;
	QSharedPointer<QGraphicsItem> itemForEndMessage;
	QTimer timer;

	int positionOFItem(int id);
	QSharedPointer<QGraphicsItem> picturesUnderCell[100];
};

