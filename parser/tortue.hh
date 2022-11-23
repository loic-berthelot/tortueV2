//changer le cmake
enum class Direction{
    DROITE, GAUCHE, HAUT, BAS
};

class Tortue{
public:
    Tortue(int x, int y): _x(x), _y(y), _dir(Direction:DROITE){};
    bool avancer();
    void tourner();
    bool sauter();
private:
    unsigned int _x;
    unsigned int _y;
    Direction _dir;
}
