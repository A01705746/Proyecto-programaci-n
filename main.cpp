#include "Tenno.h"
#include "Equipamiento.h"
#include "Escuadron.h"
#include "Enemigos.h"
#include "Juego.h"

#include <iostream>

using namespace std;

int main(){
    Tenno UTech58("UndecidedTech58","correo@hotmail.com",356,3420975,13);
    UTech58.info_general();
    UTech58.agrega_amigo("SUPERMURLOC28");
    UTech58.comprar_platino(200);

    Equipamiento Jugador("Excalibur","Braton","Kunai","Skana","Kubrow");
    Jugador.equip_actual();
    Jugador.cambiar_warframe("Saryn");
    Jugador.cambiar_arma_primaria("Lenz");
    Jugador.cambiar_arma_secundaria("Pandero");
    Jugador.cambiar_arma_melee("Skiajati");
    Jugador.cambiar_acompanante("Dethcube");
    Jugador.equip_actual();

    Escuadron Squad("UndecidedTech58","Solo");
    Squad.cambiar_tipo_escuadron("Publico");
    Squad.cambiar_tipo_escuadron("Privado");
    Squad.agregar_jugadores();
    Squad.invitar("Davos31");
    Squad.agregar_jugadores();
    Squad.invitar("SUPERMURLOC28");
    Squad.agregar_jugadores();
    Squad.expulsar("Davos31");
    Squad.agregar_jugadores();

    Enemigos Enemy("Grineer","Bombardero",30);
    Enemy.generar_enemigo();
    Enemy.aumentar_nivel(50);
    Enemy.generar_enemigo();

    Exterminio msn(2,"Venus",50,10);
    msn.cargar_nivel();
    msn.contador_bajas();

    Captura msn2(2,"Marte",50,"Almirante");
    msn2.cargar_nivel();
    msn2.estado_objetivo();
}
