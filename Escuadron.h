#ifndef ESCUADRON_H_INCLUDED
#define ESCUADRON_H_INCLUDED

#include <iostream>

using namespace std;

class Escuadron{
private:
    string lider;
    int tamano;
    string tipo;
    string tipo2;
    string tenno[3];
    string elim;

public:
    Escuadron(string lid, string ti);
    void cambiar_tipo_escuadron(string type);
    void invitar(string jg);
    void expulsar(string jg);
    void agregar_jugadores();
};

Escuadron::Escuadron(string lid, string ti){
    tipo=ti;
    lider=lid;
    tenno[0]=lider;
    tamano=1;
};

void Escuadron::cambiar_tipo_escuadron(string type){
    tipo2=type;
    cout<<"El escuadron cambio de "<<tipo<<" a "<<tipo2<<endl<<endl;
    tipo=tipo2;
}

void Escuadron::agregar_jugadores(){
    cout<<"Miembros del escuadron: ";
    for (int i=0; i<tamano; i++)
        cout<<tenno[i]<<" ";
    cout<<endl<<endl;
}

void Escuadron::invitar(string jg){
    tenno[tamano]=jg;
    tamano++;
    cout<<"Has invitado a "<<jg<<endl<<endl;
}

void Escuadron::expulsar(string jg){
    elim=jg;
    for (int i=0; i<tamano; i++)
        if(tenno[i]==elim)
            tenno[i]="";
    cout<<"Has expulsado a "<<jg<<endl<<endl;
}

#endif // ESCUADRON_H_INCLUDED
