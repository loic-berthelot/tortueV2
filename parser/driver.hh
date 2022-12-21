#ifndef DRIVER_H
#define DRIVER_H

#include <map>
#include <string>
#include <QPoint>
#include <QColor>
#include <QSize>
#include "contexte.hh"

class JardinHandler;
class JardinRendering;

class Driver {
private:      
    JardinHandler * monJardin;
    Contexte variables;       

public:
    Driver(JardinHandler * J);
    ~Driver();
    const   Contexte& getContexte() const;
    double  getVariable(const std::string& name) const;
    void    setVariable(const std::string& name, double value);
    JardinRendering* getJardin();

    void changerPositionTortue(int n, int x, int y);
    
    void avancerTortue(int n, int x);
    
    void sauter(int n);

    float obtenirOrientationTortue(int n);
 
    void tourner(int n, int s);
    
    bool verif_mur(int n, int pos);
    bool mur_pos(int n, int pos);

    void modifier_couleur(int n, int mode, std::string couleur);
};

#endif