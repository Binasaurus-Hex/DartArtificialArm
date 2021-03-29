//
// Created by binasaurus on 04/03/2021.
//

#include "Ground.h"
#include "dart/dynamics/dynamics.hpp"
#include "../EnvWindow.h"

Ground::Ground(dart::dynamics::SkeletonPtr skeleton) {
    this->skeleton = skeleton;
}

void Ground::render(dart::gui::RenderInterface *renderer) {
    float y = skeleton->getBodyNode(0)->getTransform().translation()[1] + dynamic_cast<const dart::dynamics::BoxShape*>(skeleton->getBodyNode(0)->getShapeNodesWith<dart::dynamics::VisualAspect>()[0]->getShape().get())->getSize()[1]*0.5;
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glDisable(GL_LIGHTING);
    double width = 0.005;
    int count = 0;
    glBegin(GL_QUADS);
    for(double x = -100.0;x<100.01;x+=1.0)
    {
        for(double z = -100.0;z<100.01;z+=1.0)
        {
            if(count%2==0)
                glColor3f(216.0/255.0,211.0/255.0,204.0/255.0);
            else
                glColor3f(216.0/255.0-0.1,211.0/255.0-0.1,204.0/255.0-0.1);
            count++;
            glVertex3f(x,y,z);
            glVertex3f(x+1.0,y,z);
            glVertex3f(x+1.0,y,z+1.0);
            glVertex3f(x,y,z+1.0);
        }
    }
    glEnd();
    glEnable(GL_LIGHTING);
}

Ground::~Ground() {

}
