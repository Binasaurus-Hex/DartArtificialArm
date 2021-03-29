//
// Created by binasaurus on 01/03/2021.
//

#include "EnvWindow.h"
#include "core/environments/PhysicalEnvironment.h"
#include "core/WorldUtils.h"
#include "core/artificialArm/ArtificialArm.h"
#include "core/Ground.h"
#include "core/artificialArm/Muscles.h"

EnvWindow::EnvWindow(PhysicalEnvironment *e) {
    environment = e;
    setWorld(e->world);
    activations == nullptr;
}

void EnvWindow::draw() {
    SimWindow::draw();
    environment->render(mRI);
}

void EnvWindow::timeStepping() {
    if(activations != nullptr){
        environment->arm->muscles->setActivations(*activations);
    }
    environment->step();
}

float activation = 0;
float floatClamp(float value){
    if(value < 0)return 0;
    if(value > 1)return 0;
    return value;
}

void EnvWindow::keyboard(unsigned char _key, int _x, int _y) {
    if(_key == 'r'){
        std::string skeletonFile = "../data/ArtificialArm.xml";
        std::string muscleFile = "../data/Muscles.xml";
        std::string groundFile = "../data/ground.xml";
        ArtificialArm* arm = WorldUtils::loadFromFiles(skeletonFile,muscleFile);
        Ground* ground = WorldUtils::loadFromFiles(groundFile);

        mWorld->removeAllSkeletons();

        WorldUtils::addGroundToWorld(ground,environment->world);
        WorldUtils::addArmToWorld(arm,environment->world);
        environment->arm = arm;
        environment->ground = ground;
    }
    Eigen::VectorXd activations(9,1);
    activations.setZero();
    int number = _key - '0';
    if(number > 0 && number < 9){
        activations[number - 1] = activation;
    }
    if(_key == 'j'){
        activation = floatClamp(activation + 0.01);
    }
    if(_key == 'k'){
        activation = floatClamp(activation - 0.01);
    }
    environment->arm->muscles->setActivations(activations);
    dart::gui::glut::SimWindow::keyboard(_key,_x,_y);
}





