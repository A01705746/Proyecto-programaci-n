#ifndef TENNO_H_INCLUDED
#define TENNO_H_INCLUDED

#include <iostream>

using namespace std;

class Tenno{
private:
    string nombre;
    string correo;
    int platino;
    int creditos;
    int maestria;
    string amg_rec;

public:
    Tenno(){};
    Tenno(string nom, string cor, int pl, int cr, int ma);
    Tenno(string nom, string cor);
    string get_nombre(){return nombre;}
    int get_platino(){return platino;}
    int get_creditos(){return creditos;}
    int get_maestria(){return maestria;}
    void comprar_platino(int plat);
    void agrega_amigo(string usuario);
    void info_general();
};

Tenno::Tenno(string nom, string cor, int pl, int cr, int ma){
    nombre=nom;
    correo=cor;
    platino=pl;
    creditos=cr;
    maestria=ma;
};

Tenno::Tenno(string nom, string cor){
    nombre=nom;
    correo=cor;
    platino=0;
    creditos=0;
    maestria=1;
};

void Tenno::comprar_platino(int plat){
    platino=platino+plat;
    cout<<"Tu nueva cantidad de platino: "<<platino<<endl<<endl;
}

void Tenno::agrega_amigo(string usuario){
    amg_rec=usuario;
    cout<<"Has agregado a: "<<amg_rec<<endl<<endl;
}

void Tenno::info_general(){
    cout<<"Usuario: "<<get_nombre()<<endl;
    cout<<"Creditos: "<<get_creditos()<<endl;
    cout<<"Maestria: "<<get_maestria()<<endl;
    cout<<"Platino: "<<get_platino()<<endl<<endl;
}

#endif // TENNO_H_INCLUDED
