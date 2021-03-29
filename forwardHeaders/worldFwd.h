//
// Created by binasaurus on 04/03/2021.
//

#ifndef SECONDARMTEST_WORLDFWD_H
#define SECONDARMTEST_WORLDFWD_H

#include "memory"

namespace dart::simulation{
    class World;
    typedef std::shared_ptr<World> WorldPtr;
}

#endif //SECONDARMTEST_WORLDFWD_H
