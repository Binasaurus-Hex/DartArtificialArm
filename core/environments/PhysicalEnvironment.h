//
// Created by binasaurus on 02/03/2021.
//

#ifndef SECONDARMTEST_PHYSICALENVIRONMENT_H
#define SECONDARMTEST_PHYSICALENVIRONMENT_H
#include "../../forwardHeaders/worldFwd.h"
#include "../../forwardHeaders/renderInterfaceFwd.h"

class ArtificialArm;
class Ground;

class PhysicalEnvironment {
public:
    PhysicalEnvironment(ArtificialArm* a, Ground* g);
    void step();
    void render(dart::gui::RenderInterface* renderer );
    ArtificialArm* arm;
    Ground* ground;
    dart::simulation::WorldPtr world;
};

#endif //SECONDARMTEST_PHYSICALENVIRONMENT_H
