/*
* Proyecto Warframe main
* Enrique Santos Fraire
* A01705746
* 12/06/2020
*
* Esta clase define el objeto de tipo Juego, contiene las clases
* heredadas Exterminio y Captura, que son los modos de juego.
* Utiliza las clase Escuadron como agregacion para extraer el
* arreglo de jugadors y utiliza la clase Enemigos como
* composición para generarlos en cada modo de juego.
*/

#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include "Escuadron.h" // biblioteca con los objetos a usar
#include "Enemigos.h" // biblioteca con los objetos a usar
#include <iostream> // biblioteca para imprimir
#include <inttypes.h>

using namespace std;

//Declaracion de clase Juego que es abstracta
class Juego{
// Declaración de variables protegidas de instancia
protected:
    string planeta;
    int nivelp;
    Escuadron players; // se define como objeto de otra clase
    Enemigos *enemy[1]; // se define como apuntador para usar polimorfismo, un arreglo de un solo elemento

//Declaración de los métodos públicos que va a tener el objeto
public:
    Juego(); //constructor por defualt
    Juego(string plnt, int nvl);
    virtual void cargar_nivel() = 0; //método abstracto será sobreescrito
};

Juego::Juego(){
    planeta="";
    nivelp=0;
}

Juego::Juego(string plnt, int nvl){
    planeta=plnt;
    nivelp=nvl;
};

//Declaro objeto Exterminio que hereda de Juego
class Exterminio : public Juego{
// Declaración de variables privadas de instancia
private:
    int n_objetivos;
    int bajas;
    int contador;

//Declaración de los métodos públicos que va a tener el objeto
public:
    Exterminio(string plnt, int nvl, int nobj):Juego(plnt, nvl){
        n_objetivos=nobj;
        bajas=0;
    }
    void cargar_nivel();
    void contador_bajas();
    void extraer_jugadores(Escuadron jugs);
    void crear_enemigos(int nvl);
};


/**
 * crear_enemigos imprime la información general del enemigo
 *
 * genera un objeto de tipo Enemigos y se guarda en la variable de
 * instancia de enemy[] para poder llamar al método generar_enemigo de la
 * clase Enemigos con los parametros que se definen en este método
 *
 * @param int nvl será el nivel de los enemigos, es heredado por Juego
 * @return
*/
void Exterminio::crear_enemigos(int nvl){
    enemy[0] = new Enemigos("Grineer","Bombardero",nvl); //new crea el objeto en tiempo de ejecución para usar polimorfismo
    enemy[0]->generar_enemigo();
}

/**
 * extraer_jugadores imprime el arreglo de jugadores
 *
 * es la agregación, toma como referencia el objeto escuadron utilizado
 * previamente y se lo asigna a una variable temporal que llamará al
 * método agregar_jugadores que contiene el arreglo de jugadores del
 * escuadron
 *
 * @param Escuadron jugs será el objeto Escuadron con el que se incialice en la clase Escuadron
 * @return
*/
void Exterminio::extraer_jugadores(Escuadron jugs){
    Escuadron players=jugs;
    players.agregar_jugadores();
}

/**
 * cargar_nivel imprime la información del nivel seleccionado
 *
 * utiliza los datos heredados y del constructor para imprimirlos
 * siendo estos el planeta seleccionado, su nivel y el número de
 * objetivos de la misión.
 *
 * @param
 * @return
*/
void Exterminio::cargar_nivel(){
    cout<<"Planeta: "<<planeta<<endl;
    cout<<"Nivel: "<<nivelp<<endl;
    cout<<"Enemigos por eliminar: "<<n_objetivos<<endl<<endl;
}

/**
 * contador_bajas imprime una cuenta regresiva a partir del numero de objetivos
 *
 * utiliza el numero de objetivos como valor maximo, se le asigna ese valor a
 * la variable temporal contador y con la variable i se crea un ciclo que
 * de 0 hasta el valor maximo a la vez que el contador va disminuyendo
 * representando los objetivos eliminados, que al llegar a 0 se anuncia la misión
 * cumplida mediante una impresión
 *
 * @param
 * @return
*/
void Exterminio::contador_bajas(){
    cout<<"----Bajas----"<<endl;
    for(int i=0;i<n_objetivos;i++){
        contador=n_objetivos-bajas;
        cout<<"Quedan "<<contador<<" enemigos"<<endl;
        bajas++;
    }
    cout<<"Mision Cumplida"<<endl<<endl;
}

//Declaro objeto Captura que hereda de Juego
class Captura : public Juego{
// Declaración de variables privadas de instancia
private:
    string seleccionar_objetivo;
    int temporizador;
    int i;

//Declaración de los métodos públicos que va a tener el objeto
public:
    Captura(string plnt, int nvl, string sobj):Juego(plnt, nvl){
        seleccionar_objetivo=sobj;
        temporizador=600;
        i=temporizador;
    }
    void cargar_nivel();
    void estado_objetivo();
    void extraer_jugadores(Escuadron jugs);
    void crear_enemigos(int nvl);
};

/**
 * extraer_jugadores imprime el arreglo de jugadores
 *
 * es la agregación, toma como referencia el objeto escuadron utilizado
 * previamente y se lo asigna a una variable temporal que llamará al
 * método agregar_jugadores que contiene el arreglo de jugadores del
 * escuadron
 *
 * @param Escuadron jugs será el objeto Escuadron con el que se incialice en la clase Escuadron
 * @return
*/
void Captura::extraer_jugadores(Escuadron jugs){
    Escuadron players=jugs;
    players.agregar_jugadores();
}

/**
 * crear_enemigos imprime la información general del enemigo
 *
 * genera un objeto de tipo Enemigos y se guarda en la variable de
 * instancia de enemy[] para poder llamar al método generar_enemigo de la
 * clase Enemigos con los parametros que se definen en este método
 *
 * @param int nvl será el nivel de los enemigos, es heredado por Juego
 * @return
*/
void Captura::crear_enemigos(int nvl){
    enemy[0] = new Enemigos("Corpus","Tripulante",nvl); //new crea el objeto en tiempo de ejecución para usar polimorfismo
    enemy[0]->generar_enemigo();
}

/**
 * cargar_nivel imprime la información del nivel seleccionado
 *
 * utiliza los datos heredados y del constructor para imprimirlos
 * siendo estos el planeta seleccionado, su nivel y el nombre del
 * objetivos a capturar de la misión.
 *
 * @param
 * @return
*/
void Captura::cargar_nivel(){
    cout<<"Planeta: "<<planeta<<endl;
    cout<<"Nivel: "<<nivelp<<endl;
    cout<<"Objetivo a capturar: "<<seleccionar_objetivo<<endl<<endl;
}

/**
 * estado_objetivo imprime una cuenta regresiva de un temporizador definido
 *
 * utiliza la variable i, que fue igualada al temporizador con valor de 600
 * segundos, el ciclo continua hasta llegar al 0, disminuyendo de 60 en 60
 * imprimiendo dicho valor, cuando llega a 60, un ciclo antes de que termine
 * la operación, aparece el mensaje misión cumplida, simulando que el objetivo
 * ha sido capturado con éxito
 *
 * @param
 * @return
*/
void Captura::estado_objetivo(){
    for (i;i>0;i=i-60){
        cout<<"Quedan "<<i<<" segundos"<<endl;
        if(i==60)
            cout<<"Mision Cumplida"<<endl<<endl;
    }
}
#endif // JUEGO_H_INCLUDED
