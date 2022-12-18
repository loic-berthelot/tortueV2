#include "structure.hh"

bool Verification::calculer() const{
    return true;
}

void Si::parcourir(Driver & driver) const {
    if(_condition) _fils[0]->parcourir(driver);
    else _fils[1]->parcourir(driver);
}

void TantQue::parcourir(Driver & driver) const {
    while(_condition->calculer()) _fils[0]->parcourir(driver);
}

void Repete::parcourir(Driver & driver) const {
    for(unsigned int i = 0; i < _nbiterations; i++) _fils[0]->parcourir(driver);
}

void Bloc::parcourir(Driver & driver) const {
    for(auto inst : _fils) inst->parcourir(driver);
}

void Action::parcourir(Driver & driver) const {
    if (_type == "avance") driver.avancerTortue(_p1,_p2);
    else if (_type == "saute") driver.sauter(_p1);
    else if (_type == "tourne") driver.tourner(_p1,_p2);
}
