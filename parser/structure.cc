#include "structure.hh"
#include <iostream>

std::map<std::string, InstPtr> fonctions;
std::vector<int> parametres;
int getParametre(int i) { return parametres[i-1]; }

bool Verification::calculer(Driver & driver) const{
    if(_type == 1){
        return driver.verif_mur(_id, _direction);
    }
    else if(_type == 0){
        return !driver.verif_mur(_id, _direction);
    }
    return false;
}

void Si::parcourir(Driver & driver) const {
    if(_condition->calculer(driver)) 
        _fils[0]->parcourir(driver);
    else if (_fils.size() > 1)
        _fils[1]->parcourir(driver);
}

void TantQue::parcourir(Driver & driver) const {
    while(_condition->calculer(driver)) 
        _fils[0]->parcourir(driver);
}

void Repete::parcourir(Driver & driver) const {
    unsigned int imax = (unsigned int)_nbiterations->calculer(driver.getContexte());
    for(unsigned int i = 0; i < imax; i++) 
    _fils[0]->parcourir(driver);
}

void Bloc::parcourir(Driver & driver) const {
    for(auto inst : _fils) 
        inst->parcourir(driver);
}

void Action::parcourir(Driver & driver) const {
    if (_type == "avance") 
        driver.avancerTortue(_num, (int)_expptr->calculer(driver.getContexte()));
    else if (_type == "saute") 
        driver.sauter(_num);
    else if (_type == "tourne") 
        driver.tourner(_num, (int)_expptr->calculer(driver.getContexte()));
    else if(_type == "couleur")
        driver.modifier_couleur(_num, _num2, _str);
    else if(_type == "tortues")
        driver.ajouter_tortues((int)_expptr->calculer(driver.getContexte()));
    else if(_type == "jardin")
        driver.chargerJardin(_str);
}

void Fonction::parcourir(Driver & driver) const {
    for (unsigned int i = 0; i < _parametres.size(); i++) driver.setVariable(std::to_string(i+1), _parametres[i]); 
    fonctions[_name]->parcourir(driver);
}
