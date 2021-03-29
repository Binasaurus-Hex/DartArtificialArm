//
// Created by binasaurus on 27/02/2021.
//

#include "ArtificialArm.h"
#include "../DARTHelper.h"
#include "Muscles.h"

ArtificialArm::ArtificialArm(){

}

Eigen::VectorXd* ArtificialArm::getPositions() {
    Eigen::VectorXd* positionTensor = new Eigen::VectorXd(3,2);
    return positionTensor;
}

Eigen::VectorXd* ArtificialArm::getVelocities() {

}

ArtificialArm::~ArtificialArm() {
    delete muscles;
}


