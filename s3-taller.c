#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) {

    char estudiante[4][30];
    char materia[2][30];
    char entrada[100];
    float notas[2][4][0];
    int opc1=0, val=0, nmateria=0, nestudiante=0;

    do{

    printf("\n\n");
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
     if (fgets(entrada, sizeof(entrada), stdin)) {
            char extra;
            if (sscanf(entrada, "%d %c", &opc1, &extra) == 1) {
                if (opc1 >= 1 && opc1 <= 8) {
                    break; // Opción válida
                } else {
                    printf("Opción fuera del rango. Ingrese un número entre 1 y 8.\n");
                }
            } else {
                printf("Entrada inválida. Ingrese solo un número entero.\n");
            }
        }
    
     
    switch (opc1)
    {
    case 1:
    while (getchar() != '\n'); // Limpia el salto de línea pendiente

    printf("Ingrese las 3 materias: \n");

    for(int i = 0; i <= 2; i++)
    {
        printf("Materia #%i:\n", i+1);
        fgets(materia[i], 30, stdin);
    }

    val += 1;
    break;

    case 2:
        while (getchar() != '\n');
        printf("Ingrese 5 estudiantes: \n");

        for(int j=0; j <= 4; j++)
        {
            fflush(stdin);
            printf("Estudiante #%i: ", j+1);
            fgets(estudiante[j], 30, stdin);
        
        }
        val+=1;

        break;
    case 3:
        while (getchar() != '\n');
        if(val==2){
          while (1) {  
        printf("Seleccione una materia a calificar.\n");
        printf("#\t\tMateria\n");
        for(int i = 0; i < 3; i++)
            {
                printf("%d\t\t%s",i,materia[i]);
            }
        printf(">>.\n");
        if (fgets(entrada, sizeof(entrada), stdin)) {
            // Validar si es entero y no hay caracteres sobrantes
            char extra;
            if (sscanf(entrada, "%d %c", &nmateria, &extra) == 1) {
                if (nmateria >= 0) {
                    // Entrada válida
                    break;
                } else {
                    printf("No se permiten números negativos.\n");
                }
            } else {
                printf("Entrada inválida. Ingrese solo números enteros positivos.\n");
            }
        }
          }
        

    break;
        }else{
            printf("***Ingrese primero las materias y los estudiantes.***");
            break;
        }
    
    default:
        break;
    }



    }while(opc1!=8);

   return 0;
} 
