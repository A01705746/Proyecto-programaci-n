#ifndef ENEMIGOS_H_INCLUDED
#define ENEMIGOS_H_INCLUDED

#include <iostream>

using namespace std;

class Enemigos{
private:
    string clase;
    string denominacion;
    int nivel;
    int vida;
    int dano;

public:
    Enemigos(string cla, string den, int nvl);
    void aumentar_nivel(int lvl);
    void aumentar_vida(int hp);
    void aumentar_dano(int dmg);
    void generar_enemigo();
};

Enemigos::Enemigos(string cla, string den, int nvl){
    clase=cla;
    denominacion=den;
    nivel=nvl;
    vida=1000;
    dano=500;
};

void Enemigos::generar_enemigo(){
    cout<<"----Enemigo----"<<endl;
    cout<<"Clase: "<<clase<<endl;
    cout<<"Denominacion: "<<denominacion<<endl;
    cout<<"Nivel: "<<nivel<<endl;
    cout<<"Vida: "<<vida<<endl;
    cout<<"Daño: "<<dano<<endl<<endl;
}

void Enemigos::aumentar_nivel(int lvl){
    vida=vida*((lvl-nivel)*.1);
    dano=dano*((lvl-nivel)*.1);
    nivel=lvl;
}

#endif // ENEMIGOS_H_INCLUDED
