#ifndef EQUIPAMIENTO_H_INCLUDED
#define EQUIPAMIENTO_H_INCLUDED

#include <iostream>

using namespace std;

class Equipamiento{
private:
    string warframe;
    string arma_primaria;
    string arma_secundaria;
    string arma_melee;
    string acompanante;

public:
    Equipamiento(string warf, string prim, string sec, string melee, string acomp);
    void equip_actual();
    string get_warframe(){return warframe;}
    string get_arma_primaria(){return arma_primaria;}
    string get_arma_secundaria(){return arma_secundaria;}
    string get_arma_melee(){return arma_melee;}
    string get_acompanante(){return acompanante;}
    void cambiar_warframe(string wa);
    void cambiar_arma_primaria(string ap);
    void cambiar_arma_secundaria(string as);
    void cambiar_arma_melee(string am);
    void cambiar_acompanante(string ac);
};

Equipamiento::Equipamiento(string warf, string prim, string sec, string melee, string acomp){
    warframe=warf;
    arma_primaria=prim;
    arma_secundaria=sec;
    arma_melee=melee;
    acompanante=acomp;
};

void Equipamiento::equip_actual(){
    cout<<"----Equipamiento Actual----"<<endl;
    cout<<"Warframe: "<<get_warframe()<<endl;
    cout<<"Arma Primaria: "<<get_arma_primaria()<<endl;
    cout<<"Arma Secundaria: "<<get_arma_secundaria()<<endl;
    cout<<"Arma Melee: "<<get_arma_melee()<<endl;
    cout<<"Acompanante: "<<get_acompanante()<<endl<<endl;
}

void Equipamiento::cambiar_warframe(string wa){
warframe=wa;
}

void Equipamiento::cambiar_arma_primaria(string ap){
arma_primaria=ap;
}

void Equipamiento::cambiar_arma_secundaria(string as){
arma_secundaria=as;
}

void Equipamiento::cambiar_arma_melee(string am){
arma_melee=am;
}

void Equipamiento::cambiar_acompanante(string ac){
acompanante=ac;
}

#endif // EQUIPAMIENTO_H_INCLUDED
