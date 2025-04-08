#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) {

    char estudiante[4][30];
    char materia[2][30];
    float notas[2][4];

    do{

     int opc1;

     printf("Programa de Gestion de notas\n");
     printf("1. Ingresar Materia.\n");
     printf("2. Ingresar Estudiantes.\n");
     printf("3. Ingresar Notas.\n");
     printf("4. Promedio por estudiantes.\n");
     printf("5. Promedio por asignatura.\n");
     printf("6. Notas Maxima y Minima.\n");
     printf("7. Aprobados y Reprobados\n");
     printf("8. Salir...\n");
    printf(">> ");
     scanf(" %d",&opc1);
    switch (opc1)
    {
    case 1:
        printf("Ingrese las 3 materias: \n");
        
        for(int i=0; i <= 2 ; i++)
        {
            fflush(stdin);
            printf("Materia #%i:\n", i+1);
            fgets(materia[i], 30, stdin);
        }

        break;
    case 2:
        printf("Ingrese los 5 estudiantes\n");

        for(int j=0; j <= 4; j++)
        {
            fflush(stdin);
            printf("Estudiante #%i: ", j+1);
            fgets(estudiante[j], 30, stdin);
        
        }

        break;
    case 3:
        
    printf("#\t\tMateria\n");
    for(int i = 0; i < cont; i++)
            {
                printf("%d\t\t%s\t\t%s\t\t%d\t\t%.2f\n",i,id[i],nombre[i],stock[i],precio[i]);
            }

    break;
    default:
        break;
    }





    return 0;
}
