// TITLE:   Optimization_Interface/include/models/constraint_model.h
// AUTHORS: Daniel Sullivan, Miki Szmuk
// LAB:     Autonomous Controls Lab (ACL)
// LICENSE: Copyright 2018, All Rights Reserved

// Model holding data for all constraints and item info

#ifndef CONSTRAINT_MODEL_H_
#define CONSTRAINT_MODEL_H_

#include <cprs.h>
#include <algorithm.h>

#include <QSet>
#include <QVector>
#include <QPointF>
#include <QMutex>

#include "include/globals.h"
#include "include/models/point_model_item.h"
#include "include/models/ellipse_model_item.h"
#include "include/models/polygon_model_item.h"
#include "include/models/plane_model_item.h"
#include "include/models/path_model_item.h"
#include "include/models/drone_model_item.h"

namespace interface {

class ConstraintModel {
 public:
    explicit ConstraintModel();

    ~ConstraintModel();

    void addPoint(PointModelItem *item);
    void removePoint(PointModelItem *item);

    void addEllipse(EllipseModelItem *item);
    void removeEllipse(EllipseModelItem *item);

    void addPolygon(PolygonModelItem *item);
    void removePolygon(PolygonModelItem *item);

    void addPlane(PlaneModelItem *item);
    void removePlane(PlaneModelItem *item);

    void addWaypoint(QPointF *item);
    void removeWaypoint(QPointF *item);

    void setPathPoints(QVector<QPointF *> *points);

    void loadFinalPos(double*);
    void loadInitialPos(double*);

    uint32_t loadEllipseConstraint(double* R, double* c_e, double* c_n);
    uint32_t loadPosConstraints(double* A, double* b);

    bool isEllipseOverlap(QPointF *pos);

 private:
    void initialize();

    QMutex model_lock_;

    float finaltime_;
    uint32_t horizon_length_;
    autogen::packet::traj3dof drone_traj3dof_data_;

    QSet<EllipseModelItem *> *ellipses_;
    QSet<PolygonModelItem *> *polygons_;
    QSet<PlaneModelItem *> *planes_;
    PathModelItem *waypoints_;
    PathModelItem *path_;
    DroneModelItem *drone_;
    PointModelItem *final_pos_;

    void loadPlaneConstraint(double *A, double *b, uint32_t index,
                                 QPointF p, QPointF q);

};

}  // namespace interface

#endif  // CONSTRAINT_MODEL_H_
