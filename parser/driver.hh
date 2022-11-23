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

    void    changerPositionTortue(int n, int x, int y);
    
    void avancerTortue(int n, int x);
    
    void sauter(int n);

    float    obtenirOrientationTortue(int n);
 
    void tourner(int n, int s);
};

#endif


class Tortue{
    Tortue(int x, int y): _x(x), _y(y){}
    
private:
    int _x;
    int _y;
}