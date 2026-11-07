#!/bin/sh
##################################################################
#         Programacion para mecatronicos                         #
#  Nombre:     Enders Jose Fuma Santana                          #
#  Matricula:  2026-0304                                         #
#  Seccion:    Sabados                                           #
#  Practica:   Segundo Parcial C3 2026 Sabado                    #
#  Fecha:      05/11/2026                                        #
##################################################################

# Compara cada pruebas/*.in contra su .out
for f in pruebas/*.in; do
  b="${f%.in}"
  ./reto < "$f" | tr -d '\r' | diff -q - "$b.out" >/dev/null && echo "OK    $b" || echo "FALLO $b"
done
