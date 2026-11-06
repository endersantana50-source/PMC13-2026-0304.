<!--
Programacion para mecatronicos
Nombre:     Enders Jose Fuma Santana
Matricula:  2026-0304
Seccion:    Sabados
Practica:   Segundo Parcial C3 2026 Sabado
Fecha:      05/11/2026
-->

# Plan y análisis

## Interpretación
Cada unidad se procesa de forma independiente. Una muestra es defectuosa si x < p.
Las muestras defectuosas consecutivas forman rachas máximas. Una racha califica si
su longitud >= tipo + 2. score = suma de las longitudes de las rachas que califican;
estado = 1 si existe alguna, si no 0.

## Pseudocódigo de calcular(v, m, tipo, p, *estado)
```
score <- 0; racha <- 0; minimo <- tipo + 2; *estado <- 0
PARA i DESDE 0 HASTA m:            // i = m cierra la racha final
    SI i < m Y v[i] < p ENTONCES
        racha <- racha + 1
    SINO
        SI racha >= minimo ENTONCES
            score <- score + racha; *estado <- 1
        racha <- 0
RETORNAR score
```

## Programa principal
1. Leer n, m, q y los n registros; validar dominios, id únicos, nombre, entrada incompleta. Si falla: imprimir ERROR y terminar.
2. Calcular score y estado por unidad (variables locales, sin arrastre).
3. Imprimir una línea por unidad en el orden original.
4. TOTAL con total_rec (caso base n = 0).
5. ORDER: copia ordenada por inserción (score desc, id asc).
6. FIND: copia ordenada por id + búsqueda binaria; -1 si q no existe.

## Decisiones
- Todo en memoria estática, sin malloc.
- Se ordenan copias para preservar el orden original de salida.
- Validación completa antes de imprimir cualquier resultado.
