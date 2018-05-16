#include <stdio.h>
#include <stdlib.h>
#include "eliminar.h"
#include "dispersion.h"

#define LOG(string)                                                                     \
  do{                                                                                   \
    if(debug == 1){                                                                     \
      printf("\n\n\t\t[%s:%d:%s] # %s\n\n",__FILE__,__LINE__,__FUNCTION__,string);      \
    }                                                                                   \
  }while(0)

#define FICHERO_DAT  "alumnos.dat"
#define FICHERO_HASH "alumnos.hash"

#define DNI1 "7389298"
#define DNI2 "7219752"
#define DNI3 "123456789"

void probarBusquedas(char*rutaHash);
void probarEliminaciones(char*rutaHash);


int debug = 0;
int imprimirFichero = 0;

int main(){
  int i;

  printf("\n\n************************ GENERAR HASH ********************************\n");
  printf("\n\tEntrada: %s\n\tSalida: %s",FICHERO_DAT,FICHERO_HASH);
  LOG("Generacion fichero HASH");
  i=creaHash(FICHERO_DAT,FICHERO_HASH);
  LOG("Generacion fichero HASH done");
  printf("\n\tRegistros desbordados: %d\n",i);
  if(imprimirFichero == 1){
    printf("\n\nImpresion de fichero Hash:\n");
    leeHash(FICHERO_HASH);
  }

  printf("\n\n************************ BUSQUEDAS DE PRUEBA *************************\n");
  probarBusquedas(FICHERO_HASH);

  printf("\n\n************************ PROBAR ELIMINACIONES ************************\n");
  probarEliminaciones(FICHERO_HASH);

  printf("\n\n************************ BUSQUEDAS DE COMPROBACION *******************\n");
  probarBusquedas(FICHERO_HASH);

  if(imprimirFichero == 1){
    printf("\n\n************************ IMPRESION DE COMPROBACION *******************\n");
    leeHash(FICHERO_HASH);
  }


  printf("\n\n");

  return 0;
}


void probarBusquedas(char*rutaHash){
  FILE *f;
  tipoAlumno reg;
  int i;

  LOG("Abriendo fichero HASH");
  f=fopen(FICHERO_HASH,"rb");
  LOG("Fichero HASH abierto");

  LOG("Comenzando busqueda 1");
  printf("\n\n\tBuscando %s -- EN BLOQUE ORIGINAL",DNI1);
  i = buscaReg(f,&reg,DNI1);
  if(i > 0){
  	printf("\n\tRegistro encontrado en el CUBO %d",i);
  	printf("\n\t\t %s %s %s %s %s\n",reg.dni,reg.nombre,reg.ape1,reg.ape2,reg.provincia);
  }else{
  	printf("\n\tRegistro con DNI: %s no encontrado; codigo de retorno %d",DNI1,i);
  }

  LOG("Comenzando busqueda 2");
  printf("\n\n\tBuscando %s -- EN DESBORDE",DNI2);
  i = buscaReg(f,&reg,DNI2);
  if(i > 0){
  	printf("\n\tRegistro encontrado en el CUBO %d",i);
  	printf("\n\t\t %s %s %s %s %s\n",reg.dni,reg.nombre,reg.ape1,reg.ape2,reg.provincia);
  }else{
  	printf("\n\tRegistro con DNI: %s no encontrado; codigo de retorno %d",DNI2,i);
  }

  LOG("Comenzando busqueda 3");
  printf("\n\n\tBuscando %s -- NO ESTA",DNI3);
  i = buscaReg(f,&reg,DNI3);
  if(i > 0){
  	printf("\n\tRegistro encontrado en el CUBO %d",i);
  	printf("\n\t\t %s %s %s %s %s\n",reg.dni,reg.nombre,reg.ape1,reg.ape2,reg.provincia);
  }else{
  	printf("\n\tRegistro con DNI: %s no encontrado; codigo de retorno %d",DNI3,i);
  }

  LOG("Cerrando fichero HASH");
  fclose(f);
  LOG("Fichero HASH cerrado");
}

void probarEliminaciones(char*rutaHash){

}