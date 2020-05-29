// TITLE:   Optimization_Interface/include/models/plane_model_item.h
// AUTHORS: Daniel Sullivan, Miki Szmuk
// LAB:     Autonomous Controls Lab (ACL)
// LICENSE: Copyright 2018, All Rights Reserved

// Data model for plane constraint

#ifndef PLANE_MODEL_ITEM_H_
#define PLANE_MODEL_ITEM_H_

#include <QPointF>
#include <QMutex>

#include "include/models/data_model.h"

namespace optgui {

class PlaneModelItem : public DataModel {
 public:
    explicit PlaneModelItem(QPointF p1, QPointF p2) :
        mutex_(), direction_(false) { p1_ = p1; p2_ = p2; port_ = 0;}
    ~PlaneModelItem() {
        QMutexLocker locker(&this->mutex_);
    }

    QPointF getP1() {
        QMutexLocker locker(&this->mutex_);
        return this->p1_;
    }

    void setP1(QPointF pos) {
        QMutexLocker locker(&this->mutex_);
        this->p1_.setX(pos.x());
        this->p1_.setY(pos.y());
    }

    QPointF getP2() {
        QMutexLocker locker(&this->mutex_);
        return this->p2_;
    }

    void setP2(QPointF pos) {
        QMutexLocker locker(&this->mutex_);
        this->p2_.setX(pos.x());
        this->p2_.setY(pos.y());
    }

    bool getDirection() {
        QMutexLocker locker(&this->mutex_);
        return this->direction_;
    }

    void flipDirection() {
        QMutexLocker locker(&this->mutex_);
        this->direction_ = !this->direction_;
    }

 private:
    QMutex mutex_;
    QPointF p1_;
    QPointF p2_;
    bool direction_;
};

}  // namespace optgui

#endif  // PLANE_MODEL_ITEM_H_
