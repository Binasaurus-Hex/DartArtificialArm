//
// Created by binasaurus on 27/02/2021.
//

#include "ArtificialArm.h"
#include "../DARTHelper.h"
#include "Muscles.h"

ArtificialArm::ArtificialArm(){}

Eigen::VectorXd ArtificialArm::getPositions() {
    return skeleton->getPositions();
}

Eigen::VectorXd ArtificialArm::getVelocities() {
    return skeleton->getVelocities();
}

Eigen::VectorXd ArtificialArm::getJointLowerLimits() {
    return skeleton->getPositionLowerLimits();
}

Eigen::VectorXd ArtificialArm::getJointUpperLimits() {
    return skeleton->getPositionUpperLimits();
}

void ArtificialArm::setJointAccelerations(Eigen::VectorXd accelerations) {
    skeleton->setAccelerations(accelerations);
}

void ArtificialArm::setJointPositions(Eigen::VectorXd positions) {
    skeleton->setPositions(positions);
}

Eigen::Vector3d ArtificialArm::getEndEffectorPosition() {
    return skeleton->getBodyNode(skeleton->getNumBodyNodes() -2)->getCOM();
}

ArtificialArm::~ArtificialArm() {
    delete muscles;
}

int ArtificialArm::getNumDofs(){
    return skeleton->getNumDofs();
}




