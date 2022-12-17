#include <vector>
#include <string>




/* 
*   L'arbre contient l'instruction à executer
*   On fait un parcour par largeur de l'arbre
*   Si l'instruction est une instruction simple (pas une boucle ou un if) on ajoute un
*   
*/
class Arbre{
private:
    std::vector<Arbre> fils;
public:
    Arbre(std::string _instruction);
    virtual void parcourir();
    virtual void ajouterFils(std::string _instruction);
};

class tantque : public Arbre {

};

class repete : public Arbre {

};

class if : public Arbre {

};

class Feuille  {
private:
    std::string _instruction; //peut être pas un string, contient l'instruction à executer
}