/*Autor: Ricardo Jafet Granados Chable, Realizado: 18/04/2022
    Tarea 6 parcial 2 en C: Menu de opciones.
	*/
	
#include<stdio.h>
#include<stdlib.h>

#define MAX 10
struct alumno {
char nombre[30];
float promedio;
int faltas;
};

int menu();
void agregar(struct alumno x[]);
void imprimir(struct alumno x[], int tipo);
void promedio(struct alumno x[]);
void Per(struct alumno x[]);

int main(){
int op;
struct alumno grupo[MAX];
do{
op=menu();
switch(op){
case 0: printf("Adios..\n");
break;
case 1: agregar(grupo);
break;
case 2: imprimir(grupo,0);
break;
case 3: imprimir(grupo,1);
break;
case 4: imprimir(grupo, 2);
break;
case 5:
break;
case 6:
break;
}
}while(op!=0);
return 0;
}

int menu(){
int opcion;
printf("-------- MENU PRINCIPAL ---------\n");
printf("0. Salir \n");
printf("1. Agregar alumnos \n");
printf("2. Imprimir \n");
printf("3. Alumnos Aprobados \n");
printf("4. Alumnos Reprobados \n");
printf("5. Promedio del grupo \n");
printf("6. Porcentaje de alumnos Aprobados: \n");
printf("--------------------------------------\n");
opcion=leerd("Selecciona una opcion: ",0,6);
return opcion;
}
void agregar(struct alumno x[]){
int pregunta;
while(n<MAX){
leers("Nombre: ", x[n].nombre,30);
x[n].promedio=leerf("Promedio: ",0,10);
x[n].faltas=leerd("Faltas: ",0,32);
n++; //hay que validar
pregunta=leerd("¿Agregar otro alumno? (1-Si, 0-No): ", 0, 1);
if (pregunta==0) {
break;
}
}
if(n==MAX){
printf("Arreglo lleno!!!\n");
system("PAUSE");
}
}

void imprimir(struct alumno x[], int tipo){
char mensaje[20];
switch(tipo){
case 0: strcpy(mensaje, "TOTALES ");
break;
case 1: strcpy(mensaje, "APROBADOS");
break;
case 2: strcpy(mensaje, "REPROBADOS");
break;
}
printf("----------------- ALUMNOS %s ----------------------------\n", mensaje);
printf("NO.ALUMNO\tNOMBRE \t\t\tFALTAS \t\tPROM\n");
printf("----------------------------\n");
for (int i=0;i<n;i++){
switch(tipo){
case 0: printf("%2d \t\t%-30s\t%2d\t\t%4.1f\n",i+1,x[i].nombre,x[i].faltas,x[i].promedio);
break;
case 1: if(x[i].promedio>=7){
printf("%2d \t\t%-30s\t%2d\t\t%4.1f\n",i+1,x[i].nombre,x[i].faltas,x[i].promedio);
}
break;
case 2: if(x[i].promedio<7){
printf("%2d\t\t%-30s\t%2d\t\t%d\n",i+1,x[i].nombre,x[i].faltas, 5);
}
break;
}
}
printf("----------------------------\n");
system("PAUSE");
}
void promedio(struct alumno x[]){
float suma=0, prom;
for(int i =0;i<MAX;i++){
if(x[i].promedio>=7){
suma=suma+x[i].promedio;
} else if (x[i].promedio<7){
suma=suma+(float)5.0;
}
}
prom=suma/n;
printf("PROMEDIO DEL GRUPO\n");
printf("------------------------\n");
printf("El promedio es %.01f\n: ", prom);
printf("------------------------\n");
system("PAUSE");
}
