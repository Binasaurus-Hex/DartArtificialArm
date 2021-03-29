//
// Created by binasaurus on 02/03/2021.
//

#ifndef SECONDARMTEST_MUSCLES_H
#define SECONDARMTEST_MUSCLES_H
#include "memory"
#include "list"
#include "Eigen/Dense"

namespace MASS{
    class Muscle;
}
namespace dart::gui{
    class RenderInterface;
}

class Muscles {
public:
    Muscles();
    ~Muscles();
    void addMuscle(MASS::Muscle* muscle);
    void update();
    void applyForces();
    void setActivations(const Eigen::VectorXd muscleActivations);
    void render(dart::gui::RenderInterface* renderer);
    int numberOfMuscles();
private:
    std::list<MASS::Muscle*>* muscles;
};

#endif //SECONDARMTEST_MUSCLES_H
