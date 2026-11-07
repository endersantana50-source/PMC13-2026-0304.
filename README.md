/**************************************************/
/*        Programacion para mecatronicos          */
/* Nombre:     Enders Jose Fuma Santana           */
/* Matricula:  2026-0304                          */
/* Seccion:    Sabados                            */
/* Practica:   Segundo Parcial C3 2026 Sabado     */
/* Fecha:      05/11/2026                         */
/**************************************************/

# PMC13-2026-0304

- Matrícula: 2026-0304
- Correo institucional: 

## Modelo y decisiones
Ver `plan.md`. Resumen: rachas máximas de muestras con x < p; califican si longitud >= tipo+2;
score suma esas longitudes; estado 1 si hay alguna. Validación total antes de imprimir.

## Compilación y ejecución
```
gcc -std=c11 -Wall -Wextra -Wpedantic main.c -o reto

./reto < pruebas/publico1.in            (Windows: reto.exe < pruebas\publico1.in)

python3 evaluar.py publicas.json ./reto (Windows: py evaluar.py publicas.json reto.exe)
```

## Resultados
Pendiente: se documentan al terminar las pruebas.

## Fuentes consultadas
-  contenidos de los capítulos 1 al 4 del libro de texto Diseño de algoritmos y su codificación en lenguaje C.
- Documentación de la biblioteca estándar de C.
- Documento asignado a mi matrícula , el código fue revisado y ejecutado por mí.

## Historial de commits
| Commit | Hash | Avance |
|---|---|---|
| 1 | COMPLETAR | Estructura inicial, plan y reto.h |
| 2 | COMPLETAR | Lectura, validación y calcular |
| 3 | COMPLETAR | Ordenar, buscar, total_rec y pruebas |
| 4 | (final, se entrega aparte) | Correcciones y documentación |
