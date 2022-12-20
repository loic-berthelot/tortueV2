#include <vector>
#include <string>
#include <memory>
#include "driver.hh"


/* 
*   L'arbre contient l'instruction à executer
*   On fait un parcour par largeur de l'arbre
*   Si l'instruction est une instruction simple (pas une boucle ou un if) on ajoute un
*   
*/

class Verification {
private:
    int _type;
    int _direction;
    int _id;
public:
    Verification(int t, int d, int id) : _type(t), _direction(d), _id(id) {}
    bool calculer(Driver & driver) const;
};

class Instruction;

using InstPtr = std::shared_ptr<Instruction>;
using VerifPtr = std::shared_ptr<Verification>;

class Instruction{//J'ai changé le nom de "Arbre", que je trouvais trop générique (c'est un peu comme appeler un entier 'nombre' nan ?) bah c'est l'objectif en même temps autant appelé un chat un chat
protected:
    std::vector<InstPtr> _fils;
    std::shared_ptr<Instruction> _parent; //pourquoi on a le parent ???
public:
    Instruction() : _parent(nullptr){}
    virtual void parcourir(Driver & driver) const=0;
    void ajouterFils(InstPtr f) { _fils.push_back(f); } //en gros à utiliser pour les structures de contrôles
    void ajouterBloc() {_fils.push_back(Bloc())};       // à utiliser après la fin de chaque structue
    void ajouterAction(InstPtr f) {_fils.back().ajouterFils(f);} //et à utiliser pour les actions directes
    std::shared_ptr<Instruction> fils(unsigned int i) { return _fils[i]; }
};


class TantQue : public Instruction {
private:
    VerifPtr _condition;
public:
    TantQue(VerifPtr cond) : _condition(cond) {}
    void parcourir(Driver & driver) const override;
};

class Repete : public Instruction {
private:
    unsigned int _nbiterations;
public:
    Repete(unsigned int nbi) : _nbiterations(nbi) {}
    void parcourir(Driver & driver) const override;
};

class Si : public Instruction {
private:
    VerifPtr _condition;
    int _id;
public:
    Si(VerifPtr cond) : _condition(cond){}
    void parcourir(Driver & driver) const override;
};

class Bloc : public Instruction {
public:
    void parcourir(Driver & driver) const override;
};

class Action  : public Instruction {
private:
    std::string _type; //l'instruction à executer
    int _p1;//le premier paramètre de l'instruction
    int _p2;
public:
    Action(std::string const & t, int p1, int p2) : _type(t), _p1(p1), _p2(p2) {}
    void parcourir(Driver & driver) const override;
};