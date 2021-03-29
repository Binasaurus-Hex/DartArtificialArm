//
// Created by binasaurus on 02/03/2021.
//

#include "dart/simulation/World.hpp"
#include "dart/dynamics/dynamics.hpp"
#include "PhysicalEnvironment.h"
#include "../artificialArm/ArtificialArm.h"
#include "../WorldUtils.h"
#include "../artificialArm/Muscles.h"
#include "dart/constraint/constraint.hpp"
#include "dart/collision/bullet/bullet.hpp"
#include "../Ground.h"

PhysicalEnvironment::PhysicalEnvironment(ArtificialArm* a, Ground* g) : arm(a), ground(g) {
    float mSimulationHz = 900;
    world = dart::simulation::World::create();
    WorldUtils::addArmToWorld(arm,world);
    WorldUtils::addGroundToWorld(ground,world);
    world->setGravity(Eigen::Vector3d(0,-9.8,0.0));
    world->setTimeStep(1.0/mSimulationHz);
    world->getConstraintSolver()->setCollisionDetector(dart::collision::BulletCollisionDetector::create());
}

void PhysicalEnvironment::step() {
    arm->muscles->update();
    world->step();
}

void PhysicalEnvironment::render(dart::gui::RenderInterface *renderer) {
    ground->render(renderer);
    arm->muscles->render(renderer);
}