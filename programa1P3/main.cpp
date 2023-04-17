
#include <iostream>
#include "libreria_1.h"

#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    ifstream inputt; //Solo lectura de informacion
    ofstream outputt; //guardado de  informacion  R-W
    //cout << "Hello World!" << endl;

    int tamano;
    int indexBinario=0;
    cout<<"Ingrese Tamano de la frase: ";
    cin>>tamano;
    char original[tamano];
    char codificada[tamano];
    char decodificada[tamano];

    rellenar(original,tamano);
    rellenar(codificada,tamano);
    rellenar(decodificada,tamano);

    cin.ignore();
    cout<<"ingrese frase: ";
    cin.getline(original,tamano);

    char elecion= menu();



    return 0;
}

//Proceso MENU:
char menu( ){

    char opcion;
    do{
        cout<<"METODOS: "<<endl;
        cout<<"1. Metodo codificacion UNO"<<endl;
        cout<<"2. Metodo codificacion DOS"<<endl;
        cout<<"3. Metodo de Decodificacion para M1"<<endl;
        cout<<"4. Metodo de Decodificacion para M2"<<endl;
        cout<<"0. Para Salir"<<endl;
        cout<<"Eligie metodo de codificacion o decodificacion: ";
        cin>>opcion;
    } while(opcion !='0' && opcion!='1' && opcion!='2' && opcion!='3' && opcion!='4');

    return opcion;

}

void evaluarOpcion(int opc,char *orig, char *codif, char *decodif, int indexBinary ){
    if (opc== '1'){
        conmutarM1(orig,);
    }

}
