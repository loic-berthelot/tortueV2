#include <vector>
#include <string>

class Noeud{
    //continent l'instruction à lancer
};


/* 
*   L'arbre contient l'instruction à executer
*   On fait un parcour par largeur de l'arbre
*   Si l'instruction est une instruction simple (pas une boucle ou un if) on ajoute un
*   
*/
class Arbre{
private:
    std::vector<Arbre> fils;
    std::string _instruction; //peut être pas un string, contient l'instruction à executer
public:
    Arbre(std::string _instruction);
    void parcourir();
    void ajouterFils(std::string _instruction);
};