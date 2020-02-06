// TITLE:   Optimization_Interface/include/controls/compute_thread.h
// AUTHORS: Daniel Sullivan
// LAB:     Autonomous Controls Lab (ACL)
// LICENSE: Copyright 2020, All Rights Reserved

// Thread for concurrently running Skyfly compute

#ifndef COMPUTE_THREAD_H_
#define COMPUTE_THREAD_H_

#include <QThread>

#include <cprs.h>
#include <algorithm.h>

#include "include/graphics/canvas.h"
#include "include/models/constraint_model.h"
#include "include/graphics/path_graphics_item.h"
#include "include/graphics/drone_graphics_item.h"
#include "include/graphics/waypoints_graphics_item.h"
#include "include/graphics/point_graphics_item.h"

namespace interface {

class ComputeThread : public QObject {
    Q_OBJECT

 public:
    explicit ComputeThread(ConstraintModel *model);
    ~ComputeThread();

 signals:
    void startCompute();
    void updateGraphics();
    // set color
    // set message

 private slots:
    void compute();

 private:
    ConstraintModel *model_;
    SkyeFly *fly_;

    void initializeFly();
};

}  // namespace interface

#endif  // COMPUTE_THREAD_H_
