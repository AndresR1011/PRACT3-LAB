#include <iostream>

void rellenar(char *arreglo, int tam){
    /*Recibe un arreglo de tipo char y un entero(tam) que va siendo el tamaño del arreglo
      Devuelve el arreglo incializado con el valor de '0'
    */
    for (int m=0; m<tam;m++){
        *(arreglo+m)= '0';
    }
}


//Para Procesos de Extraer Carcateres y pasarlos a Binario: ********************
int potenciasDe2Binario(int &exponente){
    /* Esta función recibe un entero positivo (exponente)
    retorna el valor de 2^exponente
    */

    //#define base2 2;
    const int base2 =2; //valor base
    int auxPotencia =1;
    for (int i=1; i<= exponente;i++){
        auxPotencia = (auxPotencia*base2);//se va multiplicado por si mismo como acumulador
    }
    return auxPotencia;
}

void conversionCharToBinary (char caracterAscii, char *punteroAcumulador, int &indexArrayBinario){
    /*Recibe un entero carcaterASCII [0-255], un apuntador tipo char, y un entero >=0 (&indexArrayBinario)
    Retorna a "pointerAcumuladorChar" como valor binario de "carcaterASCII"

   Recibe un caracter ASCII, que luego lo pasara a BINARIO en BLOQUE de 8-BITS, al macenandolos en el arreglo "punteroAcumulador"
   y su respecivo indice(indexArraybinario) que controla la poscion a rellenar

    */


    for(int j=7;j>=0; j--){ //cliclo para llenar byte el caracter //inverso para rellenar de Izquierda a Derecha

        if (caracterAscii >= potenciasDe2Binario(j)){   //valida SI el valor ASCII Del caracter es >= que 2^j
            *(punteroAcumulador+ indexArrayBinario)='1';    //rellenar arreglo con 1
            caracterAscii = caracterAscii-potenciasDe2Binario(j);      //actualiza el nuevo numero(carcaterASCII) a comparar
        }
        else{
            *(punteroAcumulador + indexArrayBinario) = '0'; //al ser carcaterASCII menor, rellena el arreglo con un 0
        }

        indexArrayBinario =indexArrayBinario+1; //incrementar valor, para el siguiente paso
    }
}

void extraerCaracterYasignarBinario(char *cadenaOriginal, int lenOriginal, char *arrayParaBinario, int indexArrayBinario){
    /*Recibe una cadena de CARCATERES "cadenaOriginal" con su respectivo tamaño entero "lenOriginal"
     *además recibe otro arreglo de tipo char "arrayParaBinario" en donde se alvergará los CARCATERES de FORMA BINARIA
     *con su respectivo Indice "indiceArrayBinario" el cual ubicaradicho valor en el lugar correspondiente del arreglo
     *arrayParabinario

    */
    for (int i = 0; i < lenOriginal; i++){
        int numASCII = *(cadenaOriginal+i); //EXtraer CARACTER
        conversionCharToBinary(numASCII,arrayParaBinario, indexArrayBinario);   //PARASARLO PARASER CONVERTIDO EN BINARIO
    }


}


//------------Metodo 2 de  CODIFICACION:   ********************
void metodo2Codif(char *sinEncriptar, int &longSinEncriptar, int &base, char *encriptacionM2){
    /*Recibe un arreglo de cadena de carcateres(sinEncriptar) y su respectivo tamaño  entero(longSinCodificar)
     *recibe al igua otro entero(base) para segmentar a "sinEncriptar"  y posteriormente aplicar codificación
     *los datos codificados son alvergados en el arreglo "encriptacionM2"
    */

    int xInicial=0, xFinal= xInicial+base; //cotas

    int celdaFinal = *(sinEncriptar+(xFinal-1)) ; //Auxiliar para alvergar el ultimo valor

    for (int x=0; x<longSinEncriptar; x++){ //Ciclo para la extraccion de la INFO y asignacion la INFO Codificada
        if (x>0 && x%base==0){ //Proceso para resetear valores
            xInicial =x; //Nueva Cota Inicial

            if (xInicial+base >longSinEncriptar){ //Proceso para asignar Cota Final
                xFinal = longSinEncriptar;
            }
            else{
                xFinal = xInicial+base;
            }

            celdaFinal = *(sinEncriptar+(xFinal-1)); //Nuevo valor Final Resguardado
        }

        if (x>xInicial && x<xFinal){ //Limite para efecuar proceso despues de CotaInicial
            *(encriptacionM2+(x)) = *(sinEncriptar+(x-1));
        }
        else{
            *(encriptacionM2+(xInicial)) = celdaFinal; //asiganción de ultimo dato a la Primera POSICION
        }
    }

}

void metodo2Decodificar(char *codificadoM2, int &longCodificadoM2, int &partida, char *decodificaM2){
    /*Recibe a un arreglo "codifucadoM2"(Binario) y su respectivo tamano entero "longCodificadoM2"
     * recibe del mismo modo otro entero "partida" la cual segementará a "codifucadoM2" para realizar la DECODIFICACION.
     * Los DATOS decodificados se alvergaran en el arreglo "decodificadoM2"
    */
    int inicio =0, fin = inicio+partida; //Asignar segmentos para la respectiva DECODIFICACION
    int celdaInicial = *(codificadoM2+inicio); //auxiliar para alvergar el PRIMER dato DEL ARERGLO FRAGMENTADO

    for (int p =0; p<longCodificadoM2;p++){ //Ciclo para la extraccion de la INFO Codificada y asignacion la INFO Decodificada
        if (p == fin ){ //Resetar valores (asignar nuevos valores)
            inicio = p; //Cota inicial
            if (inicio+partida > longCodificadoM2){ //para Cota Final
                fin = longCodificadoM2;
            }
            else{
                fin = inicio+partida;
            }
            celdaInicial = *(codificadoM2+inicio); //Nuevo valor auxiliar

        }

        if(p == fin-1){ //Poceso de DECODIFICACION
            *(decodificaM2+p)= celdaInicial; //asignación del valor auxiliar

        }
        else{
            *(decodificaM2+p)= *(codificadoM2+(p+1));
        }
    }
}


//------------Metodo 1 CODIFICACION:   ********************
void conmutarM1(char *path0, int &longPath0, int &separador, char *pathOutPut) {
    /*
    se recibe un char*(path0) con su respectivo tamaño(longPath0), ademas
    se recibe un un int (separador-semilla) que fraccciona  a "path0" en secciones de "separador" para luego aplicar codificacion
    y guardarla en el char*(pathOutPut) encriptada.
    */


    int cotaInferior =0, cotaSuperior=cotaInferior+separador; //para enfatizar el primer bloque(Primer paso nada mas)
    int auxiliarCeroInterno = 1; //Controlan EL INTERCAMBIO
    int auxiliarUnoInterno = 1;  //Controlan EL INTERCAMBIO

    int cantCeros_Unos=2; // 2 si 1=0; 0 si 0>1; 1 su 1>0 CONTROLADOR DE QUIEN ES MAYOR:::2 son iguales, 1 es si uno es mayor que Cero, y 0 si cero es mayor que uno
    int ceros=0, unos=0; //Auxliares para el conteo

    for (int index=0; index<longPath0; index++){ //Ciclo para realizar Proceso De Encriptación

        if (index>0 && index%separador==0){ //RESETEAR VALORES DE CONTROL
            //SELECCION DE LA FORMA DE ENCPRIPTAR LOS VALORES:
            if (unos>ceros){ //MAYOR CANTIDAD DE UNOS
                cantCeros_Unos = 1;
            }
            else if (unos<ceros){//MAYOR CANTIDAD DE CEROS
                cantCeros_Unos=0;
            }
            else{               //CANTIDAES IGUALES
                cantCeros_Unos =2;
            }
            unos=0; //cantidad de unos
            ceros =0;  //cantidad de ceros
            auxiliarUnoInterno=1; //auxilares para controlar cambio en cuando 0>1
            auxiliarCeroInterno=1;//auxilares para controlar cambio en cuando 1>0

            cotaInferior=index; //NUevas Cotas
            if (cotaInferior+separador>longPath0){
                cotaSuperior = longPath0;       //Se asigna un nuevo cotado superior.
            }
            else{
                cotaSuperior=cotaInferior+separador; //Se asigna un nuevo cotado superior.
            }
        }


        if (cantCeros_Unos ==2){ //PROCESO para EL "PRIMER PASO" y para cuando "LA CANTIDA DE CEROS == CANTIDAD DE UNOS" *************
            if(cotaInferior<cotaSuperior && cantCeros_Unos==2 ){ //primer paso o CEROS ==UNOSS  ->INTERCAMBIAR Todos los VALORES
                if ( *(path0+index)=='1' ){
                    *(pathOutPut+index)= '0';
                    unos++; //Contador de unos
                }
                else{
                    *(pathOutPut+index)= '1';
                    ceros++;  //Contador de ceros
                }
            }
        }


        else if ( cantCeros_Unos==1){ //PROCESO para cuando "LA CANTIDAD de UNOS >   CANTIDAD de CEROS" *************

            if (auxiliarUnoInterno%3==0){ //MULTIPLO DE TRES INTERCAMBIA VALOR (3 porque alterna cada 3 pasos)
                if ( *(path0+index)=='1' ){
                    *(pathOutPut+index)= '0';
                    unos++ ;     //CONTEO DE UNOS
                }
                else{
                    *(pathOutPut+index)= '1';
                    ceros++;  //CONTEO DE CEROS
                }
            }
            else{ //SI NO ES MULTIPLO DE 3
                *(pathOutPut+index) = *(path0+index); // NO ALTERA EL VALOR
                if ( *(path0+index) == '1'){
                    unos++; //CONTEO DE UNOS
                }
                else{
                    ceros++; //CONTEO DE CEROS
                }
            }
            auxiliarUnoInterno++; //CONTROLADOR PARA INTERCAMBIAR VALORES
        }


        else { //PROCESO para cuando "LA CANTIDAD de CEROS > CANTIDAD de UNOS" *************

            if ( auxiliarCeroInterno%2==0   ){ // 2 por que alterna cada 2 pasos

                if ( *(path0+index)=='1' ){
                    *(pathOutPut+index)= '0';
                    unos++ ;     //CONTEO DE UNOS
                }
                else{
                    *(pathOutPut+index)= '1';
                    ceros++;  //CONTEO DE CEROS
                }
            }
            else{ //SI NO ES MULTIPLO DE 2 -NO ALTERNA
                *(pathOutPut+index) = *(path0+index); // NO ALTERA EL VALOR
                if ( *(path0+index) =='1' ){
                    unos++;
                }
                else{
                    ceros++;
                }
            }
            auxiliarCeroInterno++;  //CONTROLADOR PARA INTERCAMBIAR VALORES
        }

    }
}
