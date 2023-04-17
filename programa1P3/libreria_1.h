
#ifndef LIBRERIA_1_H
#define LIBRERIA_1_H

char menu();

void rellenar(char *arreglo, int tam);

//Proceso para PASAR CADENA DE CARCATERES a representacion BINARIA: ********************************
int potenciasDe2Binario(int &exponente);
void conversionCharToBinary (char caracterAscii, char *punteroAcumulador, int &indexArrayBinario);
void extraerCaracterYasignarBinario(char *cadenaOriginal, int lenOriginal, char *arrayParaBinario, int indexArrayBinario);

//Metodo 2 de ENCRIPTACION:
void metodo2Codif(char *sinEncriptar, int &longSinEncriptar, int &base, char *encriptacionM2);
void metodo2Decodificar(char *codificadoM2, int &longCodificadoM2, int &partida, char *decodificaM2);

//Metodo 1 de ENCRIPTACION:
void conmutarM1(char *path0, int &longPath0, int &separador, char *pathOutPut);

#endif // LIBRERIA_1_H
