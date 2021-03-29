//
// Created by binasaurus on 04/03/2021.
//

#ifndef SECONDARMTEST_SKELETONFWD_H
#define SECONDARMTEST_SKELETONFWD_H

#include "memory"

namespace dart::dynamics{
    class Skeleton;
    typedef std::shared_ptr<Skeleton> SkeletonPtr;
};

#endif //SECONDARMTEST_SKELETONFWD_H

