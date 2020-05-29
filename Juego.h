#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include <iostream>
#include <inttypes.h>

using namespace std;

class Juego{
protected:
    int jugadores;
    string planeta;
    int nivelp;

public:
    Juego();
    Juego(int plyr, string plnt, int nvl);
    virtual void cargar_nivel(){cout<< "Ha cargado el nivel \n";}
    void meter_jugadores(string plyrs);
};

Juego::Juego(){
    jugadores=0;
    planeta[0]=0;
    nivelp=0;
}

Juego::Juego(int plyr, string plnt, int nvl){
    jugadores=plyr;
    planeta=plnt;
    nivelp=nvl;
};

class Exterminio : public Juego{
private:
    int n_objetivos;
    int bajas;
    int contador;
public:
    Exterminio(int plyr, string plnt, int nvl, int nobj):Juego(plyr, plnt, nvl){
        n_objetivos=nobj;
        bajas=0;
    }
    void cargar_nivel();
    void contador_bajas();
};

void Exterminio::cargar_nivel(){
    cout<<"Planeta "<<planeta<<endl;
    cout<<"Nivel "<<nivelp<<endl;
    cout<<"Tamano de escuadra "<<jugadores<<endl;
    cout<<"Enemigos por eliminar: "<<n_objetivos<<endl<<endl;
}

void Exterminio::contador_bajas(){
    cout<<"----Bajas----"<<endl;
    for(int i=0;i<n_objetivos;i++){
        contador=n_objetivos-bajas;
        cout<<"Quedan "<<contador<<" enemigos"<<endl;
        bajas++;
    }
    cout<<"Mision Cumplida"<<endl<<endl;
}

class Captura : public Juego{
private:
    string seleccionar_objetivo;
    int temporizador;
    int i;
public:
    Captura(int plyr, string plnt, int nvl, string sobj):Juego(plyr, plnt, nvl){
        seleccionar_objetivo=sobj;
        temporizador=600;
        i=temporizador;
    }
    void cargar_nivel();
    void estado_objetivo();
};

void Captura::cargar_nivel(){
    cout<<"Planeta "<<planeta<<endl;
    cout<<"Nivel "<<nivelp<<endl;
    cout<<"Tamano de escuadra "<<jugadores<<endl;
    cout<<"Objetivo a capturar: "<<seleccionar_objetivo<<endl<<endl;
}

void Captura::estado_objetivo(){
    for (i;i>0;i=i-60){
        cout<<"Quedan "<<i<<" segundos"<<endl;
        if(i==60)
            cout<<"Mision Cumplida"<<endl<<endl;
    }
}
#endif // JUEGO_H_INCLUDED
