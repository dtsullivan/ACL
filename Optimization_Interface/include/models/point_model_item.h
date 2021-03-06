// TITLE:   Optimization_Interface/include/models/point_model_item.h
// AUTHORS: Daniel Sullivan, Miki Szmuk
// LAB:     Autonomous Controls Lab (ACL)
// LICENSE: Copyright 2018, All Rights Reserved

// Data model for point

#ifndef POINT_MODEL_ITEM_H_
#define POINT_MODEL_ITEM_H_

#include <QPointF>
#include <QMutex>

#include "include/models/data_model.h"

namespace optgui {

class PointModelItem : public DataModel {
 public:
    explicit PointModelItem(QPointF const &pos) : mutex_() {
        pos_ = pos;
        port_ = 0;
    }

    ~PointModelItem() {
        // acquire lock to destroy it
        QMutexLocker locker(&this->mutex_);
    }

    QPointF getPos() {
        QMutexLocker locker(&this->mutex_);
        // get copy of pos in xyz pixels
        return this->pos_;
    }

    void setPos(QPointF pos) {
        QMutexLocker locker(&this->mutex_);
        this->pos_.setX(pos.x());
        this->pos_.setY(pos.y());
    }

 private:
    // mutex lock for getters/setters
    QMutex mutex_;
    // pos in xyz pixels
    QPointF pos_;
};

}  // namespace optgui

#endif  // POINT_MODEL_ITEM_H_
