// TITLE:   Optimization_Interface/include/controls/compute_thread.h
// AUTHORS: Daniel Sullivan
// LAB:     Autonomous Controls Lab (ACL)
// LICENSE: Copyright 2020, All Rights Reserved

// Thread for concurrently running Skyfly compute

#ifndef COMPUTE_THREAD_H_
#define COMPUTE_THREAD_H_

#include <QThread>

#include "cprs.h"
#include "algorithm.h"

#include "include/models/constraint_model.h"
#include "include/globals.h"

namespace optgui {

class ComputeThread : public QThread {
    Q_OBJECT

 public:
    explicit ComputeThread(ConstraintModel *model);
    ~ComputeThread();

protected:
    void run() override;

 signals:
    void updateGraphics();
    void setPathColor(bool isRed);
    void setMessage(QString message);

 public slots:
    void stopCompute();

 private:
    ConstraintModel *model_;
    SkyeFly *fly_;
    bool run_loop_;
};

}  // namespace optgui

#endif  // COMPUTE_THREAD_H_