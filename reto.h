/****************************************************************/
/*        Programacion para mecatronicos                        */
/* Nombre:     Enders Jose Fuma Santana                         */
/* Matricula:  2026-0304                                        */
/* Seccion:    Sabados                                          */
/* Practica:   Segundo Parcial C3 2026 Sabado                   */
/* Fecha:      05/11/2026                                       */
/****************************************************************/

#ifndef RETO_H
#define RETO_H

#define MAX_UNIDADES 20
#define MAX_MUESTRAS 8
#define MAX_NOMBRE   16
#define MIN_ID       1
#define MAX_ID       9999
#define MAX_VALOR    100

typedef struct {
    int tipo;
    int p;
} Config;

typedef struct {
    int id;
    char nombre[MAX_NOMBRE];
    Config config;
    int score;
    int estado;
} Registro;

int  calcular(const int v[], int m, int tipo, int p, int *estado);
int  total_rec(const Registro r[], int n);
void ordenar(Registro r[], int n, int por_id); /* 0: score desc, id asc; 1: id asc */
int  buscar(const Registro r[], int n, int q); /* r ordenado por id; indice o -1 */

#endif
