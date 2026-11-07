/****************************************************************/
/*        Programacion para mecatronicos                        */
/* Nombre:     Enders Jose Fuma Santana                         */
/* Matricula:  2026-0304                                        */
/* Seccion:    Sabados                                          */
/* Practica:   Segundo Parcial C3 2026 Sabado                   */
/* Fecha:      05/11/2026                                       */
/****************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "reto.h"

static int nombre_valido(const char *s)
{
    size_t i, len = strlen(s);
    if (len < 1 || len > MAX_NOMBRE - 1) return 0;
    for (i = 0; i < len; i++)
        if (!isalnum((unsigned char)s[i]) && s[i] != '_') return 0;
    return 1;
}

static int leer_entrada(int muestras[][MAX_MUESTRAS], Registro regs[],
                        int *n, int *m, int *q)
{
    int i, j, k;
    char buf[64];

    if (scanf("%d %d %d", n, m, q) != 3) return 0;
    if (*n < 1 || *n > MAX_UNIDADES) return 0;
    if (*m < 1 || *m > MAX_MUESTRAS) return 0;
    if (*q < MIN_ID || *q > MAX_ID) return 0;

    for (i = 0; i < *n; i++) {
        if (scanf("%d %63s %d %d", &regs[i].id, buf,
                  &regs[i].config.tipo, &regs[i].config.p) != 4) return 0;
        if (regs[i].id < MIN_ID || regs[i].id > MAX_ID) return 0;
        for (k = 0; k < i; k++)
            if (regs[k].id == regs[i].id) return 0;
        if (!nombre_valido(buf)) return 0;
        strcpy(regs[i].nombre, buf);
        if (regs[i].config.tipo != 0 && regs[i].config.tipo != 1) return 0;
        if (regs[i].config.p < 0 || regs[i].config.p > MAX_VALOR) return 0;
        for (j = 0; j < *m; j++) {
            if (scanf("%d", &muestras[i][j]) != 1) return 0;
            if (muestras[i][j] < 0 || muestras[i][j] > MAX_VALOR) return 0;
        }
    }
    return 1;
}

int calcular(const int v[], int m, int tipo, int p, int *estado)
{
    int score = 0, racha = 0, minimo = tipo + 2, i;
    *estado = 0;
    for (i = 0; i <= m; i++) {
        if (i < m && v[i] < p) {
            racha++;
        } else {
            if (racha >= minimo) { score += racha; *estado = 1; }
            racha = 0;
        }
    }
    return score;
}

int main(void)
{
    int muestras[MAX_UNIDADES][MAX_MUESTRAS];
    Registro regs[MAX_UNIDADES];
    int n, m, q, i;

    if (!leer_entrada(muestras, regs, &n, &m, &q)) {
        printf("ERROR\n");
        return 0;
    }

    for (i = 0; i < n; i++)
        regs[i].score = calcular(muestras[i], m, regs[i].config.tipo,
                                 regs[i].config.p, &regs[i].estado);

    for (i = 0; i < n; i++)
        printf("%d %d %d\n", regs[i].id, regs[i].score, regs[i].estado);
    return 0;
}
