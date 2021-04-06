//
// Created by binasaurus on 06/04/2021.
//

#include "ObservationSpace.h"
Eigen::VectorXd ObservationSpace::getShape() {
    Eigen::VectorXd shape(2);
    shape[0] = 2;
    shape[1] = 4;
    return shape;
}

Eigen::Matrix<float,2,4> ObservationSpace::getMean() {
    Eigen::Matrix<float,2,4> mean;

}

Eigen::Matrix<float,2,4> ObservationSpace::getStd() {

}