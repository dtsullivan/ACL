// TITLE:   Optimization_Interface/include/graphics/polygon_graphics_item.h
// AUTHORS: Daniel Sullivan, Miki Szmuk
// LAB:     Autonomous Controls Lab (ACL)
// LICENSE: Copyright 2018, All Rights Reserved

// Graphical representation of polygon constraint

#ifndef POLYGON_GRAPHICS_ITEM_H_
#define POLYGON_GRAPHICS_ITEM_H_

#include <QGraphicsItem>
#include <QPainter>

#include "include/models/polygon_model_item.h"
#include "include/graphics/polygon_resize_handle.h"

namespace optgui {

qreal const POLYGON_BORDER = 15;

class PolygonGraphicsItem : public QGraphicsItem {
 public:
    explicit PolygonGraphicsItem(PolygonModelItem *model,
                                 QGraphicsItem *parent = nullptr);
    ~PolygonGraphicsItem();

    // data model
    PolygonModelItem *model_;

    // rough area of graphic
    QRectF boundingRect() const override;
    // draw graphic
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0) override;
    // unique graphic type
    int type() const override;

    // flip direction of constraint
    void flipDirection();

 protected:
    // shape to draw
    QPainterPath shape() const override;
    // update model when graphic is changed
    QVariant itemChange(GraphicsItemChange change,
                        const QVariant &value) override;

 private:
    QPen pen_;
    QBrush brush_;

    // resize handles
    QVector<PolygonResizeHandle *> resize_handles_;

    // scale zoom level
    qreal getScalingFactor() const;
};

}  // namespace optgui

#endif  // POLYGON_GRAPHICS_ITEM_H_
