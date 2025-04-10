#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Códigos ANSI para colores
#define ROJO "\x1b[31m"
#define VERDE "\x1b[32m"
#define AMARILLO "\x1b[33m"
#define AZUL "\x1b[34m"
#define RESET "\x1b[0m"

int main() {
    char estudiante[5][30];
    char materia[3][30];
    char entrada[100];
    float notas[3][5] = {0};
    int opc1 = 0, val = 0, val2=0, materias_ingresadas = 0;
    int maxestudiantes = 0, nmateria = 0, nestudiante = 0, vali;

    while (opc1 != 8) {
        printf("\n%s==============================%s\n", AZUL, RESET);
        printf("%s  Programa de Gestion de Notas  %s\n", VERDE, RESET);
        printf("%s==============================%s\n", AZUL, RESET);
        printf("%s1.%s Ingresar Materia\n", AMARILLO, RESET);
        printf("%s2.%s Ingresar Estudiantes\n", AMARILLO, RESET);
        printf("%s3.%s Ingresar Notas\n", AMARILLO, RESET);
        printf("%s4.%s Promedio por Estudiantes\n", AMARILLO, RESET);
        printf("%s5.%s Promedio por Asignatura\n", AMARILLO, RESET);
        printf("%s6.%s Notas Maxima y Minima\n", AMARILLO, RESET);
        printf("%s7.%s Aprobados y Reprobados\n", AMARILLO, RESET);
        printf("%s8.%s Salir\n", ROJO, RESET);
        printf("%s>> %s", VERDE, RESET);

        if (fgets(entrada, sizeof(entrada), stdin)) {
            char extra;
            if (sscanf(entrada, "%d %c", &opc1, &extra) != 1) {
                printf(ROJO "Entrada invalida. Ingrese solo un numero entero.\n" RESET);
                continue;
            }

            switch (opc1) {
            case 1:
                
                printf("Ingrese las 3 materias:\n");
                for (int i = 0; i < 3; i++) {
                    printf("Materia #%d: ", i + 1);
                    fgets(materia[i], 30, stdin);
                    materia[i][strcspn(materia[i], "\n")] = 0;
                }
                materias_ingresadas = 1;
                val++;
                printf(VERDE "¡Materias ingresadas con exito!\n" RESET);
                break;

            case 2:
                do {
                    printf("¿Cuantos estudiantes desea ingresar? (máximo 5): ");
                    fgets(entrada, sizeof(entrada), stdin);
                    if (sscanf(entrada, "%d", &maxestudiantes) != 1 || maxestudiantes < 1 || maxestudiantes > 5) {
                        printf(ROJO "Debe ingresar un numero valido entre 1 y 5.\n" RESET);
                    } else break;
                } while (1);

                for (int j = 0; j < maxestudiantes; j++) {
                    printf("Estudiante #%d: ", j + 1);
                    fgets(estudiante[j], 30, stdin);
                    estudiante[j][strcspn(estudiante[j], "\n")] = 0;
                }
                val2++;
                printf(VERDE "¡Estudiantes ingresados con exito!\n" RESET);
                break;

            case 3:
                if (val > 0 && val2>0) {
                    printf("Seleccione una materia:\n");
                    for (int i = 0; i < 3; i++) {
                        printf("%d\t\t%s\n", i, materia[i]);
                    }

                    do {
                        printf(">> ");
                        fgets(entrada, sizeof(entrada), stdin);
                        if (sscanf(entrada, "%d", &nmateria) != 1 || nmateria < 0 || nmateria > 2) {
                            printf(ROJO "Seleccione un numero valido de materia.\n" RESET);
                        } else break;
                    } while (1);

                    printf("Seleccione un estudiante:\n");
                    for (int i = 0; i < maxestudiantes; i++) {
                        printf("%d\t\t%s\n", i, estudiante[i]);
                    }

                    do {
                        printf(">> ");
                        fgets(entrada, sizeof(entrada), stdin);
                        if (sscanf(entrada, "%d", &nestudiante) != 1 || nestudiante < 0 || nestudiante >= maxestudiantes) {
                            printf(ROJO "Numero de estudiante invalido.\n" RESET);
                        } else break;
                    } while (1);

                    float nota;
                    do {
                        printf("Ingrese la nota (0 - 10): ");
                        fgets(entrada, sizeof(entrada), stdin);
                        if (sscanf(entrada, "%f", &nota) != 1 || nota < 0 || nota > 10) {
                            printf(ROJO "Nota invalida. Debe estar entre 0 y 10.\n" RESET);
                        } else {
                            notas[nmateria][nestudiante] = nota;
                            printf(VERDE "¡Nota ingresada con exito!\n" RESET);
                            break;
                        }
                    } while (1);
                } else {
                    printf(ROJO "Debe ingresar primero las materias y los estudiantes.\n" RESET);
                }
                break;

            case 4:
                if (val > 0 && val2>0) {
                    for (int e = 0; e < maxestudiantes; e++) {
                        float suma = 0;
                        for (int m = 0; m < 3; m++) {
                            suma += notas[m][e];
                        }
                        float promedio = suma / 3.0;
                        printf("Estudiante: %s | Promedio: %.2f\n", estudiante[e], promedio);
                    }
                } else {
                    printf(ROJO "Debe ingresar primero las materias y los estudiantes.\n" RESET);
                }
                break;

            case 5:
                if (val > 0 && val2>0) {
                    for (int m = 0; m < 3; m++) {
                        float suma = 0;
                        for (int e = 0; e < maxestudiantes; e++) {
                            suma += notas[m][e];
                        }
                        float promedio = suma / maxestudiantes;
                        printf("Materia: %s | Promedio: %.2f\n", materia[m], promedio);
                    }
                } else {
                    printf(ROJO "Debe ingresar primero las materias y los estudiantes.\n" RESET);
                }
                break;

            case 6:
                if (val > 0 && val2>0) {
                    for (int m = 0; m < 3; m++) {
                        float max = notas[m][0];
                        float min = notas[m][0];
                        for (int e = 1; e < maxestudiantes; e++) {
                            if (notas[m][e] > max) max = notas[m][e];
                            if (notas[m][e] < min) min = notas[m][e];
                        }
                        printf("Materia: %s | Máxima: %.2f | Mínima: %.2f\n", materia[m], max, min);
                    }
                } else {
                    printf(ROJO "Debe ingresar primero las materias y los estudiantes.\n" RESET);
                }
                break;

            case 7:
                if (val > 0 && val2>0) {
                    for (int m = 0; m < 3; m++) {
                        int aprobados = 0, reprobados = 0;
                        for (int e = 0; e < maxestudiantes; e++) {
                            if (notas[m][e] >= 6.0) {
                                aprobados++;
                            } else {
                                reprobados++;
                            }
                        }
                        printf("Materia: %s | Aprobados: %d | Reprobados: %d\n", materia[m], aprobados, reprobados);
                    }
                } else {
                    printf(ROJO "Debe ingresar primero las materias y los estudiantes.\n" RESET);
                }
                break;

            case 8:
                printf(ROJO "Saliendo del programa...\n" RESET);
                break;

            default:
                printf(ROJO "Opcion invalida. Ingrese un numero entre 1 y 8.\n" RESET);
                
                break;
            }
        }
    }

    return 0;
}