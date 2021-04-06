//
// Created by binasaurus on 06/04/2021.
//

#ifndef ARTIFICIALARM_OBSERVATIONSPACE_H
#define ARTIFICIALARM_OBSERVATIONSPACE_H
#include "Eigen/Eigen"

class ObservationSpace {
public:
    Eigen::VectorXd getShape();
    Eigen::Matrix<float,2,4> getMean();
    Eigen::Matrix<float,2,4> getStd();
};


#endif //ARTIFICIALARM_OBSERVATIONSPACE_H
