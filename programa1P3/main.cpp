
#include <iostream>
#include "libreria_1.h"

#include <fstream>
#include <sstream>

using namespace std;

int main()
{   
    
    char letras[ ]= "AbCd";
    //int longLetras = sizeof(letras)-1;
    int longLetras = sizeof(letras)-1;
    int cantBits = longLetras*8;
    //longLetras--;

    char *binarioletras;
    char *codifMetodo1;
    char *codifMetodo2;
    char *decodifMetdo1;
    char *decodifMetodo2;

    binarioletras = new char [cantBits];
    codifMetodo1 = new char [cantBits];
    codifMetodo2 = new char [cantBits];
    decodifMetdo1 = new char [cantBits];
    decodifMetodo2 = new char [cantBits];


    rellenar(binarioletras,longLetras);
    rellenar(codifMetodo1,longLetras);
    rellenar(codifMetodo2,longLetras);
    rellenar(decodifMetdo1,longLetras);
    rellenar(decodifMetodo2,longLetras);

    int semilla =4;
    int indexVectorBinario =0; //

    extraerCaracterYasignarBinario(letras,longLetras,binarioletras, indexVectorBinario);
    //void extraerCaracterYasignarBinario(char *cadenaOriginal, int lenOriginal, char *arrayParaBinario, int indexArrayBinario)

    metodo2Codif(binarioletras,cantBits, semilla,codifMetodo2);
    //void metodo2Codif(char *sinEncriptar, int &longSinEncriptar, int &base, char *encriptacionM2);

    metodo2Decodificar(codifMetodo2, cantBits, semilla,decodifMetodo2);
    //void metodo2Decodificar(char *codificadoM2, int &longCodificadoM2, int &partida, char *decodificaM2);

    conmutarM1(binarioletras,cantBits,semilla,codifMetodo1);
    //void conmutarM1(char *path0, int &longPath0, int &separador, char *pathOutPut)


    cout<<"--------------------------------------------------------"<<endl;
    cout<<"CadenaOriginal: "<<letras<<endl;
    cout<<"cadena original binario: "<<endl;
    cout<<binarioletras<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"cadena originar codificada Met 2: "<<endl;
    cout<<codifMetodo2<<endl;
    cout<<"cadena originar decodificada de Met 2: "<<endl;
    cout<<decodifMetodo2<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"cadena originar codificada Met 1: "<<endl;
    cout<<codifMetodo1<<endl;    
    
    /*
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
    */
    



    return 0;
}
/*
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
*/
