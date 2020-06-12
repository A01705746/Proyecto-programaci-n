/*
* Proyecto Warframe main
* Enrique Santos Fraire
* A01705746
* 12/06/2020
*
* Esta clase define el objeto de tipo Jugador, donde se obtienen
* los datos del jugador, puede comprar la moneda del juego, agregar
* amigos, desplegar su información de general y modificar cada parte
* de su equipamiento, esta clase utiliza a la clase equipamiento para
* tomar y modificar sus variables.
*/

#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include "Equipamiento.h" // biblioteca con los objetos a usar
#include <iostream> // biblioteca para imprimir

using namespace std;

// Declaración de la clase Jugador
class Jugador{
// Declaración de variables privadas de instancia
private:
    string nombre;
    string correo;
    int platino;
    int creditos;
    int maestria;
    int pnuevo;
    string amg_rec;
    Equipamiento *equip[1]; // se define como apuntador para usar polimorfismo, un arreglo de un solo elemento

//Declaración de los métodos públicos que va a tener el objeto
public:
    Jugador(){}; // constructor por default
    Jugador(string nom, string cor, int cr, int ma);
    Jugador(string nom, string cor);
    string get_nombre(){return nombre;}
    int get_platino(){return platino;}
    int get_creditos(){return creditos;}
    int get_maestria(){return maestria;}
    void comprar_platino();
    void agrega_amigo(string usuario);
    void info_general();
    void mostrar_equipamiento(string warf, string prim, string sec, string melee, string acomp);
    void mostrar_equipamiento();
    void cambiar_warframe(string wa);
    void cambiar_arma_primaria(string ap);
    void cambiar_arma_secundaria(string as);
    void cambiar_arma_melee(string am);
    void cambiar_acompanante(string ac);
};

Jugador::Jugador(string nom, string cor, int cr, int ma){
    nombre=nom;
    correo=cor;
    platino=0;
    creditos=cr;
    maestria=ma;
};

Jugador::Jugador(string nom, string cor){
    nombre=nom;
    correo=cor;
    platino=0;
    creditos=0;
    maestria=1;
};

/**
 * agrega_amigo te permite agregar personas a tus
 * amigos y te imprime cuál ha sido la persona
 * que has agregado recientemente
 *
 * @param string usuario debe ser: cualquier nombre de usuario que quieras agregar
 * @return
*/
void Jugador::agrega_amigo(string usuario){
    amg_rec=usuario;
    cout<<"Has agregado a: "<<amg_rec<<endl<<endl;
}

/**
 * comprar_platino te agrega una determinada cantidad de
 * la moneda del juego platino
 *
 * Utiliza la variable pnuevo como variable de entrada para
 * pedir la cantidad a comprar, este valor se le suma al valor
 * anterior de platino y se imprime tu nueva cantidad actual de
 * platino con un mensaje
 *
 * @param
 * @return
*/
void Jugador::comprar_platino(){
    cin>>pnuevo;
    platino=platino+pnuevo;
    cout<<"Tu nueva cantidad de platino es: "<<platino<<endl<<endl;
}

/**
 * info_general imprime los datos generales del jugador
 *
 * utiliza el nombre de usuario que se pidió al principio
 * y agrega los valores parametrizados previamente dependiendo
 * si es una cuenta nueva o existente
 *
 * @param
 * @return
*/
void Jugador::info_general(){
    cout<<"Usuario: "<<get_nombre()<<endl;
    cout<<"Creditos: "<<get_creditos()<<endl;
    cout<<"Maestria: "<<get_maestria()<<endl;
    cout<<"Platino: "<<get_platino()<<endl<<endl;
}

/**
 * mostrar_equipamiento imprime el equipamiento actual del jugador
 *
 * genera un objeto de tipo equipamiento y se guarda en la variable de
 * instancia de equip[] para poder llamar al método equip_actual de la
 * clase Equipamiento con los parametros que se definen en este método
 *
 * @param string warframe, arma primaria, arma secundaria, arma melee, acompañante
 * @return
*/
void Jugador::mostrar_equipamiento(string warf, string prim, string sec, string melee, string acomp){
    //new crea el objeto en tiempo de ejecución para usar polimorfismo
    equip[0]=new Equipamiento(warf, prim, sec, melee, acomp);
    equip[0]->equip_actual();
}

/**
 * mostrar_equipamiento imprime el equipamiento actual del jugador
 *
 * este método se utiliza una vez se inicializa el anterior método del mismo
 * nombre, es una sobrecarga, en este caso no se necesit inicializar ni pedir
 * parametros, solo imprime el método equip_actual de Equipamiento con la
 * variable de instancia equip[]
 *
 * @param
 * @return
*/
void Jugador::mostrar_equipamiento(){
    equip[0]->equip_actual();
}

/**
 * cambiar_warframe le asigna un nuevo valor a la variable warframe
 * del objeto equipamiento
 *
 * utiliza la variable de instancia equip[] para asignarle el parámetro
 * dado a una variable de otra clase distinta
 *
 * @param string del nuevo warframe
 * @return
*/
void Jugador::cambiar_warframe(string wa){
    equip[0]->warframe=wa;
}

/**
 * cambiar_arma_primaria le asigna un nuevo valor a la variable
 * arma_primaria del objeto equipamiento
 *
 * utiliza la variable de instancia equip[] para asignarle el parámetro
 * dado a una variable de otra clase distinta
 *
 * @param string de la nueva arma primaria
 * @return
*/
void Jugador::cambiar_arma_primaria(string ap){
    equip[0]->arma_primaria=ap;
}

/**
 * cambiar_arma_secundaria le asigna un nuevo valor a la variable
 * arma_secundaria del objeto equipamiento
 *
 * utiliza la variable de instancia equip[] para asignarle el parámetro
 * dado a una variable de otra clase distinta
 *
 * @param string de la nueva arma secundaria
 * @return
*/
void Jugador::cambiar_arma_secundaria(string as){
    equip[0]->arma_secundaria=as;
}

/**
 * cambiar_arma_melee le asigna un nuevo valor a la variable
 * arma_melee del objeto equipamiento
 *
 * utiliza la variable de instancia equip[] para asignarle el parámetro
 * dado a una variable de otra clase distinta
 *
 * @param string de la nueva arma melee
 * @return
*/
void Jugador::cambiar_arma_melee(string am){
    equip[0]->arma_melee=am;
}

/**
 * cambiar_acompanante le asigna un nuevo valor a la variable
 * acompanante del objeto equipamiento
 *
 * utiliza la variable de instancia equip[] para asignarle el parámetro
 * dado a una variable de otra clase distinta
 *
 * @param string del nuevo acompañante
 * @return
*/
void Jugador::cambiar_acompanante(string ac){
    equip[0]->acompanante=ac;
}

#endif // JUGADOR_H_INCLUDED
