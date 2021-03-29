//
// Created by binasaurus on 04/03/2021.
//

#ifndef SECONDARMTEST_GROUND_H
#define SECONDARMTEST_GROUND_H
#include "memory"
#include "../forwardHeaders/skeletonFwd.h"
#include "../forwardHeaders/renderInterfaceFwd.h"

class Ground {
public:
    Ground(dart::dynamics::SkeletonPtr skeleton);
    ~Ground();
    void render(dart::gui::RenderInterface* renderer);
    dart::dynamics::SkeletonPtr skeleton;
};


#endif //SECONDARMTEST_GROUND_H
