/*
* Proyecto Warframe main
* Enrique Santos Fraire
* A01705746
* 12/06/2020
*
* Esta clase define el objeto de tipo Escuadron, donde se obtienen
* los datos del grupo de jugadores que van a jugar, se guardan sus
* nombres en un arreglo del jugador y se imprime, se cambia el tipo
* de escuadron, y se agregan o expulsan jugadores, esta clase utiliza
* la clase Jugador ya que extrae el nombre de usuario del jugador para
* agregarlo al arreglo, es una agregación, Jugador puede existir sin
* que se cree algo en esta clase
*/

#ifndef ESCUADRON_H_INCLUDED
#define ESCUADRON_H_INCLUDED

#include "Jugador.h" // biblioteca con los objetos a usar
#include <iostream> // biblioteca para imprimir

using namespace std;

// Declaración de la clase Escuadron
class Escuadron{
// Declaración de variables privadas de instancia
private:
    string lider;
    int tamano;
    string tipo;
    string tipo2;
    string tenno[4];
    string elim;

//Declaración de los métodos públicos que va a tener el objeto
public:
    Escuadron(){}; // constructor por default
    Escuadron(string lid,string ti);
    void cambiar_tipo_escuadron(string type);
    void invitar(string jg);
    void expulsar(string jg);
    void agregar_jugadores();
};

Escuadron::Escuadron(string lid,string ti){
    tipo=ti;
    lider=lid;
    tenno[0]=lider;
    tamano=1;
};

/**
 * cambiar_tipo_escuadron te permite cambiar la configuracion del escuadron
 *
 * utiliza dos variables, donde tipo2 se usa como una temporal para mandar
 * el mensaje que se ha cambiado el escuadrón de tipo A a B
 *
 * @param string type deber ser: solitario o publico
 * @return
*/
void Escuadron::cambiar_tipo_escuadron(string type){
    tipo2=type;
    cout<<"El escuadron cambio de "<<tipo<<" a "<<tipo2<<endl<<endl;
    tipo=tipo2;
}

/**
 * agregar jugadores imprime el tipo de escuadrón y sus integrantes del arreglo de jugadores
 *
 * utiliza la variable tipo para obtener el tipo de escuadrón, el arreglo tenno[], que es
 * donde se guardan los nombres de los jugadores, y la variable i que recorre todo el arreglo
 * e imrpime todos sus elementos
 *
 * @param
 * @return
*/
void Escuadron::agregar_jugadores(){
    cout<<"Tipo: "<<tipo<<endl;
    cout<<"Miembros del escuadron: ";
    for (int i=0; i<tamano; i++)
        cout<<tenno[i]<<" ";
    cout<<endl<<endl;
}

/**
 * invitar agrega una persona al arreglo de jugadores
 *
 * utiliza la variable tamano para saber el numero maximo de elementos,
 * se usa como indice esa misma variable para agregar el nombre a la
 * posición del arreglo, se incrmenta en 1 tamano y se imprime a quien
 * se ha invitado recientemente
 *
 * @param string jg será el nombre de la persona que se desea agregar
 * @return
*/
void Escuadron::invitar(string jg){
    tenno[tamano]=jg;
    tamano++;
    cout<<"Has invitado a "<<jg<<endl<<endl;
}

/**
 * invitar elimina una persona del arreglo de jugadores
 *
 * utiliza la variable elim como una variable temporal que guarda el
 * nombre del jugador a buscar, la variable tamano para saber el numero
 * maximo de elementos y usarlo como condición del for,se recorre todo
 * el arreglo tenno[] y si coincide el nombre introducido con alguno de
 * los elementos este se elimina, seguidamente aparece un mensaje de
 * confirmación
 *
 * @param string jg será el nombre de la persona que se desea expulsar
 * @return
*/
void Escuadron::expulsar(string jg){
    elim=jg;
    for (int i=0; i<tamano; i++)
        if(tenno[i]==elim)
            tenno[i]="";
    cout<<"Has expulsado a "<<jg<<endl<<endl;
}

#endif // ESCUADRON_H_INCLUDED
