#include "boost/python.hpp"

#include <string>
#include "artificialArm/ArtificialArm.h"
#include "WorldUtils.h"
#include "dart/dart.hpp"
#include "artificialArm/Muscles.h"
#include "artificialArm/Muscle.h"
#include "environments/PhysicalEnvironment.h"
#include "NumPyHelper.h"

float RandomFloat(float min, float max)
{
    // this  function assumes max > min, you may want
    // more robust error checking for a non-debug build
    assert(max > min);
    float random = ((float) rand()) / (float) RAND_MAX;

    // generate (in your case) a float between 0 and (4.5-.78)
    // then add .78, giving you a float between .78 and 4.5
    float range = max - min;
    return (random*range) + min;
}

void initRandom(Eigen::VectorXd& vector){
    for(size_t i = 0; i < vector.size(); i ++){
        float valueA = RandomFloat(0,1);
        float valueB = RandomFloat(0,1);
        vector[i] = (valueA * valueB);
    }
}

boost::python::tuple simulate(size_t iterations){
    using namespace dart::simulation;
    using namespace dart::dynamics;
    using namespace Eigen;
    using namespace boost::python;

    std::string skeletonFile = "../data/ArtificialArm.xml";
    std::string muscleFile = "../data/Muscles.xml";
    std::string groundFile = "../data/ground.xml";

    ArtificialArm* arm = WorldUtils::loadFromFiles(skeletonFile, muscleFile, true);
    Ground* ground = WorldUtils::loadFromFiles(groundFile);

    PhysicalEnvironment physicalEnvironment(arm,ground);
    const int numberOfMuscles = arm->muscles->numberOfMuscles();
    size_t degreesOfFreedom = arm->skeleton->getNumDofs();

    MatrixXd muscleActivations(iterations,numberOfMuscles);
    MatrixXd jointAccelerations(iterations,degreesOfFreedom);
    muscleActivations.setZero();
    jointAccelerations.setZero();

    for(size_t i = 0; i < iterations; i++){
        Eigen::VectorXd activations(numberOfMuscles);
        initRandom(activations);
        arm->muscles->setActivations(activations);
        muscleActivations.row(i) = activations.transpose();

        int envSteps = 1;
        for(int j = 0; j < envSteps; j ++){
            physicalEnvironment.step();
        }
        for(int w = 0; w < degreesOfFreedom; w++){
            auto acceleration = arm->skeleton->getDof(w)->getAcceleration();
            jointAccelerations(i,w) = acceleration;
        }
    }

    numpy::ndarray muscleArr = toNumPyArray(muscleActivations);
    numpy::ndarray jointAcc = toNumPyArray(jointAccelerations);
    return make_tuple(muscleArr,jointAcc);
}

using namespace boost::python;

BOOST_PYTHON_MODULE(simHelper)
{
    Py_Initialize();
    numpy::initialize();
    def("simulate",simulate);
}