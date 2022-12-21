#include "structure.hh"
#include <iostream>

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
    for(unsigned int i = 0; i < _nbiterations; i++) 
        _fils[0]->parcourir(driver);
}

void Bloc::parcourir(Driver & driver) const {
    for(auto inst : _fils) 
        inst->parcourir(driver);
}

void Action::parcourir(Driver & driver) const {
    if (_type == "avance") driver.avancerTortue(_p1,_p2);
    else if (_type == "saute") driver.sauter(_p1);
    else if (_type == "tourne") driver.tourner(_p1,_p2);
}
