/*
* Proyecto Warframe main
* Enrique Santos Fraire
* A01705746
* 12/06/2020
*
* Esta clase define el objeto de tipo Enemigos, donde se generan
* los enemigos y se imprime su información correspondiente, así como
* la conversión de valores de vida y daño en base al nivel, esta clase
* es utilizada por la clase Juego ya que es una composición y no puede
* existir sin que se cree algo en la clase Juego
*/

#ifndef ENEMIGOS_H_INCLUDED
#define ENEMIGOS_H_INCLUDED

#include <iostream> // biblioteca para imprimir

using namespace std;

// Declaración de la clase Enemigos
class Enemigos{
// Declaración de variables privadas de instancia
private:
    string clase;
    string denominacion;
    int nivel;
    int vida;
    int dano;

//Declaración de los métodos públicos que va a tener el objeto
public:
    Enemigos(){}; // constructor por default
    Enemigos(string cla, string den, int nvl);
    void generar_enemigo();
};

Enemigos::Enemigos(string cla, string den, int nvl){
    clase=cla;
    denominacion=den;
    nivel=nvl;
    vida=1000*(nvl*.1); // se modifica la vida en base al nivel
    dano=500*(nvl*.1); // se modifica el daño en base al nivel
};

/**
 * generar_enemigo imprime el valor actual de cada variable
 * del enemigo como texto para el jugador
 *
 * @param
 * @return
 */
void Enemigos::generar_enemigo(){
    cout<<"----INFORMACION DE ENEMIGOS----"<<endl;
    cout<<"Clase: "<<clase<<endl;
    cout<<"Denominacion: "<<denominacion<<endl;
    cout<<"Nivel: "<<nivel<<endl;
    cout<<"Vida: "<<vida<<endl;
    cout<<"Daño: "<<dano<<endl<<endl;
}

#endif // ENEMIGOS_H_INCLUDED
