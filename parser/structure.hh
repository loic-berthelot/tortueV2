#include <vector>
#include <string>
#include <memory>



/* 
*   L'arbre contient l'instruction à executer
*   On fait un parcour par largeur de l'arbre
*   Si l'instruction est une instruction simple (pas une boucle ou un if) on ajoute un
*   
*/
class Arbre{
private:
    std::vector<std::shared_ptr<Arbre>> fils;
public:
    Arbre();
    virtual void parcourir();
    virtual void ajouterFils(std::string _instruction);
    virtual void ajouterFils();
};

class Tantque : public Arbre {

};

class Repete : public Arbre {

};

class Ifelse : public Arbre {
    
};

class Feuille  {
private:
    std::string _instruction; //peut être pas un string, contient l'instruction à executer
};