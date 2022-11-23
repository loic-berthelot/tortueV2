#include "driver.hh"
#include "jardinHandler.hh"
#include <iostream>

Driver::Driver(JardinHandler * J) {
    monJardin = J;
}

Driver::~Driver() {
	delete monJardin;
}

const Contexte& Driver::getContexte() const {
    return variables;
}

double Driver::getVariable(const std::string & name) const {
    return variables.get(name);
}

void Driver::setVariable(const std::string & name, double value) {
    variables[name] = value;
}

JardinRendering * Driver::getJardin() {
    return monJardin->getJardinRendering();
}

void Driver::changerPositionTortue(int n,int x, int y) {
    
    getJardin()->changePosition(n,x,y);
}

void Driver::avancerTortue(int n, int steps){
    int a = getJardin()->position(n).x();
    int b = getJardin()->position(n).y();
    
    int o = getJardin()->orientation(n)/90; //la tortue commence par regarder en haut

    int x, y;
    switch (o)
    {
        case(0) : x =0; y = -1; break;
        case(1) : x =1; y = 0; break;
        case(2) : x =0; y = 1; break;
        case(3) : x =-1; y = 0; break;
    }
    getJardin()->changePosition(n,a+steps*x, b+steps*y);
    std::cout << "ok";
}

void Driver::sauter(int n){
    int a = getJardin()->position(0).x();
    int b = getJardin()->position(0).y();
    
    getJardin()->changePosition(n,a+2,b);
}

float    Driver::obtenirOrientationTortue(int n) { //implémenter le fait de tourner plusieurs fois
    return getJardin()->orientation(n);
}

void   Driver::tourner(int n, int s) {
   getJardin()->changeOrientation(n, getJardin()->orientation(n)+90*s);
}

