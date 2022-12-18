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
    // on prépare les indices de début et de fin de boucle afin de savoir quelles tortues sélectionner
    unsigned int imin, imax;
    if (n == -1) { // si n vaut -1, on sélectionne toutes les tortues
        imin = 0;
        imax = getJardin()->nbTortues()-1; // La fonction nbTortues() a été ajoutée à JardinRendering
    } else {
        imin = n;
        imax = n;
    }
    for (unsigned int i = imin; i <= imax; i++) {
        int x, y;

        int oldx = getJardin()->position(i).x();
        int oldy = getJardin()->position(i).y();    
        int orientation = getJardin()->orientation(i)/90; //la tortue commence par regarder en haut

        switch (orientation) // on cherche à obtenir une direction de mouvement à partir de l'orientation de la tortue
        {
            case(0) : 
                x =0; y = -1; break;
            case(1) : 
            default :
                x =1; y = 0; break;
            case(2) : 
                x =0; y = 1; break;
            case(3) : 
                x =-1; y = 0; break;
        }
        getJardin()->changePosition(i,oldx+steps*x, oldy+steps*y);
    }
}

void Driver::sauter(int n){
    unsigned int imin, imax;
    if (n == -1) { // si n vaut -1, on sélectionne toutes les tortues
        imin = 0;
        imax = getJardin()->nbTortues()-1; // La fonction nbTortues() a été ajoutée à JardinRendering
    } else {
        imin = n;
        imax = n;
    }
    for (unsigned int i = imin; i <= imax; i++) {
        int a = getJardin()->position(i).x();
        int b = getJardin()->position(i).y();        
        getJardin()->changePosition(i,a+2,b);   
    }
}

float    Driver::obtenirOrientationTortue(int n) { //implémenter le fait de tourner plusieurs fois
    return getJardin()->orientation(n);
}

void   Driver::tourner(int n, int s) {
    unsigned int imin, imax;
    if (n == -1) { // si n vaut -1, on sélectionne toutes les tortues
        imin = 0;
        imax = getJardin()->nbTortues()-1; // La fonction nbTortues() a été ajoutée à JardinRendering
    } else {
        imin = n;
        imax = n;
    }
    for (unsigned int i = imin; i <= imax; i++) getJardin()->changeOrientation(i, getJardin()->orientation(i)+90*s);
}

