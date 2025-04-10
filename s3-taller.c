#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) {

    char estudiante[5][30];  
    char materia[3][30];     
    char entrada[100];
    float notas[3][5] = {0}; 
    int opc1 = 0, val = 0, nmateria = 0, maxestudiantes = 0, nestudiante = 0, vali;

    while (opc1 != 8) {
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
            if (sscanf(entrada, "%d %c", &opc1, &extra) != 1) {
                printf("Entrada inválida. Ingrese solo un número entero.\n");
                continue;
            }

            switch (opc1)
            {
            case 1:
                printf("Ingrese las 3 materias:\n");
                for (int i = 0; i < 3; i++) {
                    printf("Materia #%d: ", i + 1);
                    fgets(materia[i], 30, stdin);
                    materia[i][strcspn(materia[i], "\n")] = 0; // quitar salto de línea
                    printf("¡Materias ingresadas con Exito!");
                }
                val += 1;
                break;

            case 2:
                do {
                    printf("¿Cuántos estudiantes desea ingresar? (máximo 5): ");
                    if (fgets(entrada, sizeof(entrada), stdin)) {
                        if (sscanf(entrada, "%d", &maxestudiantes) != 1 || maxestudiantes < 1 || maxestudiantes > 5) {
                            printf("Debe ingresar un número entero válido entre 1 y 5.\n");
                        } else {
                            break;
                        }
                    }
                } while (1);

                for (int j = 0; j < maxestudiantes; j++) {
                    printf("Estudiante #%d: ", j + 1);
                    fgets(estudiante[j], 30, stdin);
                    estudiante[j][strcspn(estudiante[j], "\n")] = 0;
                    printf("¡Estudiantes ingresados con Exito!");
                }
                val += 1;
                break;

            case 3:
                if (val == 2) {
                    // Selección de materia
                    printf("Seleccione una materia:\n");
                    for (int i = 0; i < 3; i++) {
                        printf("%d\t\t%s\n", i, materia[i]);
                    }

                    do {
                        printf(">> ");
                        fgets(entrada, sizeof(entrada), stdin);
                        if (sscanf(entrada, "%d", &nmateria) != 1 || nmateria < 0 || nmateria > 2) {
                            printf("Entrada inválida. Seleccione un número válido de materia.\n");
                        } else break;
                    } while (1);

                    // Selección de estudiante
                    printf("Seleccione un estudiante:\n");
                    for (int i = 0; i < maxestudiantes; i++) {
                        printf("%d\t\t%s\n", i, estudiante[i]);
                    }

                    do {
                        printf(">> ");
                        fgets(entrada, sizeof(entrada), stdin);
                        if (sscanf(entrada, "%d", &nestudiante) != 1 || nestudiante < 0 || nestudiante >= maxestudiantes) {
                            printf("Entrada inválida. Seleccione un número válido de estudiante.\n");
                        } else break;
                    } while (1);

                    // Ingreso de nota
                    float nota;
                    do {
                        printf("Ingrese la nota (0 - 10): ");
                        fgets(entrada, sizeof(entrada), stdin);
                        if (sscanf(entrada, "%f", &nota) != 1 || nota < 0 || nota > 10) {
                            printf("Nota inválida. Debe estar entre 0 y 10.\n");
                        } else {
                            notas[nmateria][nestudiante] = nota;
                            printf("¡Nota ingresada con Exito!");
                            break;
                        }
                    } while (1);
                } else {
                    printf("Debe ingresar primero las materias y los estudiantes.\n");
                }
                break;

            case 4: // Promedio por estudiante
                if (val == 2) {
                    for (int e = 0; e < maxestudiantes; e++) {
                        float suma = 0;
                        for (int m = 0; m < 3; m++) {
                            suma += notas[m][e];
                        }
                        float promedio = suma / 3.0;
                        printf("Estudiante: %s | Promedio: %.2f\n", estudiante[e], promedio);
                    }
                } else {
                    printf("Debe ingresar primero las materias y los estudiantes.\n");
                }
                break;

            case 5: // Promedio por materia
                if (val == 2) {
                    for (int m = 0; m < 3; m++) {
                        float suma = 0;
                        for (int e = 0; e < maxestudiantes; e++) {
                            suma += notas[m][e];
                        }
                        float promedio = suma / maxestudiantes;
                        printf("Materia: %s | Promedio: %.2f\n", materia[m], promedio);
                    }
                } else {
                    printf("Debe ingresar primero las materias y los estudiantes.\n");
                }
                break;

            case 6:
                printf("Funcionalidad no implementada aún.\n");
                break;

            case 7:
                printf("Funcionalidad no implementada aún.\n");
                break;

            case 8:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opción inválida. Ingrese un número entre 1 y 8.\n");
                break;
            }
        }
    }

    return 0;
}
