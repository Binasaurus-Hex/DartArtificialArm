#include "dart/dart.hpp"
#include "dart/gui/gui.hpp"
#include "../EnvWindow.h"
#include "../core/environments/PhysicalEnvironment.h"
#include "../core/artificialArm/ArtificialArm.h"
#include "../core/Ground.h"
#include "../core/WorldUtils.h"
#include "../core/artificialArm/Muscles.h"

using namespace dart::dynamics;
using namespace dart::simulation;
using namespace dart::gui::glut;

int main(int argc, char* argv[]){
    std::string skeletonFile = "../data/ArtificialArm.xml";
    std::string muscleFile = "../data/Muscles.xml";
    std::string groundFile = "../data/ground.xml";

    ArtificialArm* arm = WorldUtils::loadFromFiles(skeletonFile, muscleFile, true);
    Ground* ground = WorldUtils::loadFromFiles(groundFile);

    PhysicalEnvironment* physicalEnvironment = new PhysicalEnvironment(arm,ground);

    Eigen::VectorXd* activations = new Eigen::VectorXd(5);
    activations->setZero();
    std::cout << "args = " << argc << std::endl;
    if(argc == 6){
        std::cout << "setting values" << std::endl;
        for(int i = 1; i < argc; i ++){
            (*activations)(i-1) = std::atof(argv[i]);
        }
    }

    std::cout << "activations : " << *activations << std::endl;

    EnvWindow* envWindow = new EnvWindow(physicalEnvironment);
    if(argc == 6)
    envWindow->activations = activations;

    glutInit(&argc, argv);
    envWindow->initWindow(1920, 1080, "playground");
    glutMainLoop();
}