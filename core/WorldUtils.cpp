//
// Created by binasaurus on 02/03/2021.
//

#include "WorldUtils.h"
#include "artificialArm/ArtificialArm.h"
#include "DARTHelper.h"
#include "artificialArm/Muscles.h"
#include "Ground.h"

ArtificialArm* WorldUtils::loadFromFiles(std::string &skeletonFile, std::string &muscleFile, bool loadModels) {
    using namespace dart::dynamics;
    SkeletonPtr skeleton = MASS::BuildFromFile(skeletonFile, loadModels);
    Muscles* muscles = MASS::BuildMusclesFromFile(muscleFile, skeleton);
    ArtificialArm* artificialArm = new ArtificialArm();
    artificialArm->skeleton = skeleton;
    artificialArm->muscles = muscles;
    return artificialArm;
}

Ground * WorldUtils::loadFromFiles(std::string &skeletonFile) {
    using namespace dart::dynamics;
    SkeletonPtr skeleton = MASS::BuildFromFile(skeletonFile);
    Ground* ground = new Ground(skeleton);
    return ground;
}

void WorldUtils::addArmToWorld(ArtificialArm *arm, dart::simulation::WorldPtr world) {
    world->addSkeleton(arm->skeleton);
}

void WorldUtils::addGroundToWorld(Ground* ground, dart::simulation::WorldPtr world){
    world->addSkeleton(ground->skeleton);
}
