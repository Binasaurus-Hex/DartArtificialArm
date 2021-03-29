//
// Created by binasaurus on 02/03/2021.
//

#include <GL/freeglut_std.h>
#include "Muscles.h"
#include "Muscle.h"
#include "dart/gui/RenderInterface.hpp"

Muscles::Muscles() {
    muscles = new std::list<MASS::Muscle*>();
}

void Muscles::addMuscle(MASS::Muscle *muscle) {
    muscles->push_back(muscle);
}

void Muscles::update() {
    for(MASS::Muscle* muscle: *muscles){
        muscle->Update();
        muscle->ApplyForceToBody();
    }
}

int Muscles::numberOfMuscles() {
    return muscles->size();
}

void Muscles::setActivations(const Eigen::VectorXd muscleActivations) {
    int i = 0;
    for(MASS::Muscle* muscle: *muscles){
        muscle->activation = muscleActivations[i];
        i++;
    }
}

void Muscles::render(dart::gui::RenderInterface* renderer) {
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);

    for(MASS::Muscle* muscle : *muscles)
    {
        auto aps = muscle->GetAnchors();
        double a = muscle->activation;
        Eigen::Vector4d color(0.4+(2.0*a),0.4,0.4,1.0);//0.7*(1.0-3.0*a));
        renderer->setPenColor(color);
        for(int i=0;i<aps.size();i++)
        {
            Eigen::Vector3d p = aps[i]->GetPoint();
            renderer->pushMatrix();
            renderer->translate(p);
            renderer->drawSphere(0.005*sqrt(muscle->f0/1000.0));
            renderer->popMatrix();
        }

        for(int i=0;i<aps.size()-1;i++)
        {
            Eigen::Vector3d p = aps[i]->GetPoint();
            Eigen::Vector3d p1 = aps[i+1]->GetPoint();

            Eigen::Vector3d u(0,0,1);
            Eigen::Vector3d v = p-p1;
            Eigen::Vector3d mid = 0.5*(p+p1);
            double len = v.norm();
            v /= len;
            Eigen::Isometry3d T;
            T.setIdentity();
            Eigen::Vector3d axis = u.cross(v);
            axis.normalize();
            double angle = acos(u.dot(v));
            Eigen::Matrix3d w_bracket = Eigen::Matrix3d::Zero();
            w_bracket(0, 1) = -axis(2);
            w_bracket(1, 0) =  axis(2);
            w_bracket(0, 2) =  axis(1);
            w_bracket(2, 0) = -axis(1);
            w_bracket(1, 2) = -axis(0);
            w_bracket(2, 1) =  axis(0);


            Eigen::Matrix3d R = Eigen::Matrix3d::Identity()+(sin(angle))*w_bracket+(1.0-cos(angle))*w_bracket*w_bracket;
            T.linear() = R;
            T.translation() = mid;
            renderer->pushMatrix();
            renderer->transform(T);
            renderer->drawCylinder(0.005*sqrt(muscle->f0/1000.0),len);
            renderer->popMatrix();
        }

    }
    glEnable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
}

Muscles::~Muscles(){
    delete muscles;
}
