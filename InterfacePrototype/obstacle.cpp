#include "obstacle.h"

#include <QDebug>
#include <QGraphicsView>

Obstacle::Obstacle(QGraphicsItem *parent, qreal rad)
    : QGraphicsItem(parent)
{
    this->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemSendsScenePositionChanges);
    this->radius = rad;
    this->resizeHandle = new ResizeHandle(this);
    this->setSelected(true);
}

QRectF Obstacle::boundingRect() const
{
    return QRectF(-this->radius, -this->radius, this->radius * 2, this->radius * 2);
}

void Obstacle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QBrush brush(Qt::gray);
    QPen pen(Qt::black);

    if(this->isSelected()) {
        this->resizeHandle->setPos(-this->radius, 0);
        this->resizeHandle->show();
        pen.setWidth(3);
    } else {
        this->resizeHandle->hide();
        pen.setWidth(1);
    }

    painter->setBrush(brush);
    painter->setPen(pen);

    painter->drawEllipse(-this->radius+1, -this->radius+1, this->radius*2-2, this->radius*2-2);
}

QVariant Obstacle::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemPositionChange && scene()) {
        // value is the new position.
        QPointF newPos = value.toPointF();
        QRectF itemRect = this->boundingRect();
        itemRect.moveTopLeft(newPos);
        QRectF rect = scene()->sceneRect();

        if (!rect.contains(itemRect)) {
            this->scene()->setSceneRect((this->scene()->sceneRect()).united(this->scene()->itemsBoundingRect()));
            this->scene()->update();
            this->scene()->views().first()->setSceneRect(this->scene()->sceneRect());
        }
    }
    return QGraphicsItem::itemChange(change, value);
}