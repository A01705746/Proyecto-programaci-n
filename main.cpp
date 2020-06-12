/*
* Proyecto Warframe main
* Enrique Santos Fraire
* A01705746
* 12/06/2020
*
* Proyecto para la clase TC1030 de Programación Orientado a Objetos.
* Programa inspirado en el videojuego en línea Warframe, donde el jugador
* podrá inciar sesión o crear una cuenta nueva, poder comprar la moneda del
* juego, agregar amigos, recibir un equipamiento y tener la opción de modificarlo
* por completo, crear un escuadrón para jugar solo o con amigos, y elegir uno de
* los dos modos de juego disponibles para jugar con su escuadrón.
*/

// bibliotecas del proyecto con sus objetos
#include "Jugador.h"
#include "Equipamiento.h"
#include "Escuadron.h"
#include "Enemigos.h"
#include "Juego.h"

// bibliotecas para impresión y manejo de datos
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    int op;
    int opc;
    string nom;
    string cor;

    Jugador Jug("","",0,0);
    cout<<"Bienvenido a Warframe"<<endl;
    cout<<"Entrar\n1.-Iniciar sesion\n2.-Crea una cuenta\n";
    cin>>op;
    cout<<endl;
    if (op==1){ //Menu de inicio de sesion
        cout<<"Nombre de usuario ";
        cin>>nom;
        cout<<"Correo electronico ";
        cin>>cor;
        cout<<endl;
        Jugador Jug(nom,cor,3420975,13);
        Jug.info_general();
    }
    else if (op==2){
        cout<<"Nombre de usuario ";
        cin>>nom;
        cout<<"Correo electronico ";
        cin>>cor;
        cout<<endl;
        Jugador Jug(nom,cor);
        Jug.info_general();
    }
    else{
        cout<<"Opcion invalida"<<endl;
    }

    Jug.mostrar_equipamiento("Excalibur","Braton","Kunai","Skana","Kubrow");
    Escuadron Squad(nom,"Solitario");

    bool salida=false;
    while(salida==false){ // Menu general
        cout<<endl;
        cout<<"----------MENU----------"<<endl;
        cout<<"Elige una opcion: "<<endl;
        cout<<"1.-Comprar Platino"<<endl;
        cout<<"2.-Agregar un amigo"<<endl;
        cout<<"3.-Cambiar equipamiento"<<endl;
        cout<<"4.-Configuracion de escuadron"<<endl;
        cout<<"5.-Jugar"<<endl;
        cout<<"6.-Salir"<<endl;
        cin>>opc;
        cout<<endl;

        switch (opc){
        case 1:
            {
                cout<<"Cantidad a comprar"<<endl;
                Jug.comprar_platino();
                cout<<"Gracias por tu compra"<<endl;
            }
            break;

        case 2:
            {
                string amigo;
                cout<<"Usuario a agregar:"<<endl;
                cin>>amigo;
                Jug.agrega_amigo(amigo);
            }
            break;

        case 3:
            {
                bool exit=false;
                while(exit==false){ // Menu de equipamiento
                    int equipo;
                    cout<<"----------EQUIPAMIENTO----------"<<endl;
                    cout<<"¿Que deseas cambiar?"<<endl;
                    cout<<"Elige una opcion"<<endl;
                    cout<<"1.-Warframe"<<endl;
                    cout<<"2.-Arma Primaria"<<endl;
                    cout<<"3.-Arma Secundaria"<<endl;
                    cout<<"4.-Arma Melee"<<endl;
                    cout<<"5.-Acompanante"<<endl;
                    cout<<"6.-Terminar de editar"<<endl;
                    cin>>equipo;
                    cout<<endl;

                    switch (equipo){
                    case 1:
                        {
                            string warframe;
                            cout<<"Selecciona el Warframe"<<endl;
                            cin>>warframe;
                            cout<<endl;
                            Jug.cambiar_warframe(warframe);
                            Jug.mostrar_equipamiento();
                        }
                        break;
                    case 2:
                        {
                            string ap;
                            cout<<"Selecciona el Arma Primaria"<<endl;
                            cin>>ap;
                            cout<<endl;
                            Jug.cambiar_arma_primaria(ap);
                            Jug.mostrar_equipamiento();
                        }
                        break;
                    case 3:
                        {
                            string as;
                            cout<<"Selecciona el Arma Secundaria"<<endl;
                            cin>>as;
                            cout<<endl;
                            Jug.cambiar_arma_secundaria(as);
                            Jug.mostrar_equipamiento();
                        }
                        break;
                    case 4:
                        {
                            string am;
                            cout<<"Selecciona el Arma Melee"<<endl;
                            cin>>am;
                            cout<<endl;
                            Jug.cambiar_arma_melee(am);
                            Jug.mostrar_equipamiento();
                        }
                        break;
                    case 5:
                        {
                            string ac;
                            cout<<"Selecciona el Acompanante"<<endl;
                            cin>>ac;
                            cout<<endl;
                            Jug.cambiar_acompanante(ac);
                            Jug.mostrar_equipamiento();
                        }
                        break;
                    case 6:
                        {
                            exit=true;
                        }
                        break;
                    default:
                        {
                            cout<<"Opcion invalida, intente de nuevo"<<endl;
                        }
                        break;
                    }
                }
                cout<<"Equipamiento listo"<<endl;
            }
            break;

        case 4:
            {
                Squad.agregar_jugadores(); // Menu de escuadron
                cout<<"Deseas cambiar los ajustes de escuadron?"<<endl;
                cout<<"1.-Cambiar a publico"<<endl;
                cout<<"2.-Mantener configuracion"<<endl;
                int opc2;
                cin>>opc2;
                switch(opc2){
                case 1:
                    {
                        Squad.cambiar_tipo_escuadron("Publico"); // Menu de configuracion de escuadron
                        bool exit2=false;
                        while(exit2==false){
                            int opc3;
                            cout<<"1.-Invitar jugadores"<<endl;
                            cout<<"2.-Expulsar jugadores"<<endl;
                            cout<<"3.-Confirmar"<<endl;
                            cin>>opc3;
                            switch(opc3){
                            case 1:
                                {
                                    string plyr;
                                    cout<<"Nombre del jugador"<<endl;
                                    cin>>plyr;
                                    Squad.invitar(plyr);
                                    Squad.agregar_jugadores();
                                }
                                break;
                            case 2:
                                {
                                    string plyr2;
                                    cout<<"Nombre del jugador"<<endl;
                                    cin>>plyr2;
                                    Squad.expulsar(plyr2);
                                    Squad.agregar_jugadores();
                                }
                                break;
                            case 3:
                                {
                                    exit2=true;
                                }
                                break;
                            default:
                                {
                                    cout<<"Opcion invalida, intente de nuevo"<<endl;
                                }
                                break;
                            }
                            cout<<"Escuadra confirmada"<<endl;
                        }
                    }
                    break;
                case 2:
                    {
                        Squad.agregar_jugadores();
                    }
                    break;
                default:
                    {
                        cout<<"Opcion invalida, intente de nuevo"<<endl;
                    }
                    break;
                }
            }
            break;

        case 5:
            {
                cout<<"----------MODOS DE JUEGO----------"<<endl; // Menu de modos de juego
                cout<<"1.-Exterminio"<<endl;
                cout<<"2.-Captura"<<endl;
                int opc3;
                cin>>opc3;
                string planeta;
                int nivel;
                switch(opc3){
                case 1:
                    {
                        cout<<"----------EXTERMINIO----------"<<endl;
                        cout<<"Elige un planeta: ";
                        cin>>planeta;
                        cout<<"Nivel de los enemigos: ";
                        cin>>nivel;
                        cout<<endl;
                        Juego *msn= new Exterminio(planeta,nivel,10);
                        dynamic_cast<Exterminio*>(msn)->extraer_jugadores(Squad);
                        msn->cargar_nivel();
                        dynamic_cast<Exterminio*>(msn)->crear_enemigos(nivel);
                        dynamic_cast<Exterminio*>(msn)->contador_bajas();
                        delete msn;
                    }
                    break;
                case 2:
                    {
                        cout<<"----------CAPTURA----------"<<endl;
                        cout<<"Elige un planeta: ";
                        cin>>planeta;
                        cout<<"Nivel de los enemigos: ";
                        cin>>nivel;
                        cout<<endl;
                        Juego *msn2= new Captura(planeta,nivel,"Almirante");
                        dynamic_cast<Captura*>(msn2)->extraer_jugadores(Squad);
                        msn2->cargar_nivel();
                        dynamic_cast<Captura*>(msn2)->crear_enemigos(nivel);
                        dynamic_cast<Captura*>(msn2)->estado_objetivo();
                        delete msn2;
                    }
                    break;
                default:
                    {
                        cout<<"Opcion invalida, intente de nuevo"<<endl;
                    }
                    break;
                }
            }
            break;

        case 6:
            {
                cout<<"Ha salido del juego"<<endl;
                salida=true;
            }
            break;


        default:
            {
                cout<<"Opcion invalida, intente de nuevo"<<endl;
            }
            break;
        }
    }
    return 0;
}
