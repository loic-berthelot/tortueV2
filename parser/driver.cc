#include "driver.hh"
#include "jardinHandler.hh"
#include <iostream>
#include <sstream>

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

bool Driver::verif_mur(int n, int pos){
    if(n==-1){
        int imax = getJardin()->nbTortues()-1;
        for(int i=0;i<=imax;i++){
            if(mur_pos(i, pos))
                return true;
        }
        return false;
    }
    return mur_pos(n, pos);
}

bool Driver::mur_pos(int n, int pos) {
        switch (pos)
    {
    case -1:
        return getJardin()->estMur(getJardin()->position(n).x()-1, getJardin()->position(n).y());
        break;
    case 0:
        return getJardin()->estMur(getJardin()->position(n).x(), getJardin()->position(n).y()+1);
        break;
    case 1:
        return getJardin()->estMur(getJardin()->position(n).x()+1, getJardin()->position(n).y());
        break;
    case 2:
        return getJardin()->estMur(getJardin()->position(n).x(), getJardin()->position(n).y()-1);
        break;
    }
    return false;
}

int convert_hexa(char n){
    int result;
    std::istringstream(std::string(1, n)) >> std::hex >> result;
    return result;
}

void Driver::modifier_couleur(int n, int mode, std::string couleur){
    if(couleur.size()!=7){
        return;
    } //offset of 1 because of the "#"
    int red(convert_hexa(couleur.at(1))*16 + convert_hexa(couleur.at(2)));
    int green(convert_hexa(couleur.at(3))*16 + convert_hexa(couleur.at(4)));
    int blue(convert_hexa(couleur.at(5))*16 + convert_hexa(couleur.at(6)));

    int imin(n);
    int imax(n);
    if (n == -1) { // si n vaut -1, on sélectionne toutes les tortues
        imin = 0;
        imax = getJardin()->nbTortues()-1; // La fonction nbTortues() a été ajoutée à JardinRendering
    }

    for (unsigned int i = imin; i <= imax; i++) {
        if(!mode){ //mode = 0 correspond à la carapace
            getJardin()->changeCouleurCarapace(i, red, green, blue);
        }
        else{
            getJardin()->changeCouleurMotif(i, red, green, blue);
        }
    }
}

void Driver::ajouter_tortues(int n){
    for(int i=0;i<n;i++){
        getJardin()->ajouterTortue();
    }
}

void Driver::chargerJardin(std::string nom){
    getJardin()->nettoyerJardin();
    getJardin()->construction(nom.c_str());
}