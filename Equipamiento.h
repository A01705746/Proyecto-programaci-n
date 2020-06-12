/*
* Proyecto Warframe main
* Enrique Santos Fraire
* A01705746
* 12/06/2020
*
* Esta clase define el objeto de tipo Equipamiento, donde se
* guardan e imprimen las variables de cada elemento del equipamiento
* del jugador, esta clase es utilizada por la clase Jugador ya que es
* una composición y no puede existir sin que se cree algo en la clase
* Jugador
*/

#ifndef EQUIPAMIENTO_H_INCLUDED
#define EQUIPAMIENTO_H_INCLUDED

#include <iostream> // biblioteca para imprimir

using namespace std;

// Declaración de la clase Equipamiento
class Equipamiento{
// Declaración de variables públicas de instancia
public:
    string warframe;
    string arma_primaria;
    string arma_secundaria;
    string arma_melee;
    string acompanante;

//Declaración de los métodos públicos que va a tener el objeto
public:
    Equipamiento(){}; // constructor por default
    Equipamiento(string warf, string prim, string sec, string melee, string acomp);
    void equip_actual();
    string get_warframe(){return warframe;}
    string get_arma_primaria(){return arma_primaria;}
    string get_arma_secundaria(){return arma_secundaria;}
    string get_arma_melee(){return arma_melee;}
    string get_acompanante(){return acompanante;}
};

Equipamiento::Equipamiento(string warf, string prim, string sec, string melee, string acomp){
    warframe=warf;
    arma_primaria=prim;
    arma_secundaria=sec;
    arma_melee=melee;
    acompanante=acomp;
};


/**
 * equip_actual imprime el valor actual de cada variable
 * como información desplegable para el jugador
 *
 * utiliza las variables por medio de getters de la
 * clase Equipamiento
 *
 * @param
 * @return
 */
void Equipamiento::equip_actual(){
    cout<<"----Equipamiento Actual----"<<endl;
    cout<<"Warframe: "<<get_warframe()<<endl;
    cout<<"Arma Primaria: "<<get_arma_primaria()<<endl;
    cout<<"Arma Secundaria: "<<get_arma_secundaria()<<endl;
    cout<<"Arma Melee: "<<get_arma_melee()<<endl;
    cout<<"Acompanante: "<<get_acompanante()<<endl<<endl;
}

#endif // EQUIPAMIENTO_H_INCLUDED
