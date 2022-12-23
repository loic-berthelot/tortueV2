#include <vector>
#include <string>
#include <memory>
#include "driver.hh"
#include "contexte.hh"
#include "expressionBinaire.hh"
#include "expressionUnaire.hh"
#include "constante.hh"
#include "variable.hh"

    


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
extern std::map<std::string, InstPtr> fonctions;

class Instruction{
protected:
    std::vector<InstPtr> _fils;
public:
    Instruction() {}
    virtual void parcourir(Driver & driver) const=0;
    void ajouterFils(InstPtr f) { _fils.push_back(f); } 
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
    ExpressionPtr _nbiterations;
public:
    Repete(ExpressionPtr nbi) : _nbiterations(nbi) {}
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
    Bloc(InstPtr i1, InstPtr i2){ ajouterFils(i1); ajouterFils(i2); }
    void parcourir(Driver & driver) const override;
};

class Action  : public Instruction {
private:
    std::string _type;
    int _num;
    int _num2;
    std::string _str;
    ExpressionPtr _expptr;
public:
    Action(std::string const & t, int n) : _type(t), _num(n){}
    Action(std::string const & t, ExpressionPtr ep) : _type(t), _expptr(ep) {}
    Action(std::string const & t, std::string const & s) : _type(t), _str(s) {}
    Action(std::string const & t, int n, int n2) : _type(t), _num(n), _num2(n2) {}
    Action(std::string const & t, int n, int n2, ExpressionPtr expr) : _type(t), _num(n), _num2(n2), _expptr(expr) {}
    Action(std::string const & t, ExpressionPtr ep, int n) : _type(t), _num(n), _expptr(ep){}
    Action(std::string const & t, int n, int n2, std::string const & s): _type(t), _num(n), _num2(n2), _str(s) {}
    void parcourir(Driver & driver) const override;
};

class Fonction : public Instruction {
private:
    std::string _name;
    std::vector<ExpressionPtr> _parametres;
public:
    Fonction(std::string const & n, std::vector<ExpressionPtr> const & p) : _name(n), _parametres(p) {}
    void parcourir(Driver & driver) const override;
};