#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include <iostream>

using namespace std;

class Juego{
private:
    int jugadores;
    string planeta;
    int nivelp;

public:
    Juego(int plyr, string plnt, int nvl);
    void cargar_nivel();
    void meter_jugadores(string plyrs);
};

Juego::Juego(int plyr, string plnt, int nvl){
    jugadores=plyr;
    planeta=plnt;
    nivelp=nvl;
};

void Juego::cargar_nivel(){
    cout<<"Planeta "<<planeta<<endl;
    cout<<"Nivel "<<nivelp<<endl;
    cout<<"Tamaño de escuadra "<<jugadores<<endl<<endl;
}

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
    void contador_bajas();
};

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
    void estado_objetivo();
};

void Captura::estado_objetivo(){
    for (i;i>0;i=i-60){
        cout<<"Quedan "<<i<<" segundos"<<endl;
        if(i==60)
            cout<<"Mision Cumplida"<<endl<<endl;
    }
}
#endif // JUEGO_H_INCLUDED
