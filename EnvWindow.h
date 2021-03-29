//
// Created by binasaurus on 01/03/2021.
//

#ifndef SECONDARMTEST_ENVWINDOW_H
#define SECONDARMTEST_ENVWINDOW_H
#include "dart/gui/glut/SimWindow.hpp"

class PhysicalEnvironment;

class EnvWindow : public dart::gui::glut::SimWindow {
public:
    EnvWindow(PhysicalEnvironment* e);
    void draw() override;
    void timeStepping() override;
    void keyboard(unsigned char _key, int _x, int _y) override;
    Eigen::VectorXd* activations;

private:
    PhysicalEnvironment* environment;
};


#endif //SECONDARMTEST_ENVWINDOW_H
