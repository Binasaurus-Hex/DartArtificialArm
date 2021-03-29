//
// Created by binasaurus on 02/03/2021.
//

#ifndef SECONDARMTEST_WORLDUTILS_H
#define SECONDARMTEST_WORLDUTILS_H
#include "string"
#include "memory"
#include "../forwardHeaders/worldFwd.h"

class Ground;
class ArtificialArm;

namespace WorldUtils {
    ArtificialArm* loadFromFiles(std::string& skeletonFile, std::string& muscleFile, bool loadModels = true);
    Ground* loadFromFiles(std::string& skeletonFile);
    void addArmToWorld(ArtificialArm* arm, dart::simulation::WorldPtr world );
    void addGroundToWorld(Ground* ground, dart::simulation::WorldPtr world);
    void removeArmFromWorld(ArtificialArm* arm, dart::simulation::WorldPtr world);
};


#endif //SECONDARMTEST_WORLDUTILS_H
