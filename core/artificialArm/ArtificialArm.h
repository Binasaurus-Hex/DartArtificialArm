//
// Created by binasaurus on 27/02/2021.
//

#ifndef SECONDARMTEST_ARTIFICIALARM_H
#define SECONDARMTEST_ARTIFICIALARM_H
#include "memory"
#include "Eigen/Dense"

namespace dart::dynamics{
    class Skeleton;
    typedef std::shared_ptr<Skeleton> SkeletonPtr;
}
namespace dart::simulation{
    class World;
    typedef std::shared_ptr<World> WorldPtr;
}

class Muscles;

using namespace dart::simulation;

#include "list"

class ArtificialArm {
public:
    ArtificialArm();
    ~ArtificialArm();
    Eigen::VectorXd getPositions();
    Eigen::VectorXd getVelocities();
    Eigen::VectorXd getJointLowerLimits();
    Eigen::VectorXd getJointUpperLimits();
    Eigen::Vector3d getEndEffectorPosition();
    void setJointAccelerations(Eigen::VectorXd accelerations);
    void setJointPositions(Eigen::VectorXd positions);
    int getNumDofs();

    Muscles* muscles;
    dart::dynamics::SkeletonPtr skeleton;
};


#endif //SECONDARMTEST_ARTIFICIALARM_H
