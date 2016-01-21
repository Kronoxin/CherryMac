//
//  Laberinto.cpp
//  Ejercicio1
//
//  Created by Daniel Lago Aguado on 21/1/16.
//

#include <stdio.h>
#include "Matriz.h"

struct coordenada
{
    int x;
    int y;
};

coordenada siguientePosicion(coordenada posicionActual, int direccion)
{
    coordenada siguientePosicion;
    switch(direccion)
    {
        case 0:
            siguientePosicion.x = posicionActual.x;
            siguientePosicion.y = posicionActual.y+1;
            break;
        case 1:
            siguientePosicion.x = posicionActual.x+1;
            siguientePosicion.y = posicionActual.y;
            break;
        case 2:
            siguientePosicion.x = posicionActual.x;
            siguientePosicion.y = posicionActual.y-1;
            break;
        case 3:
            siguientePosicion.x = posicionActual.x-1;
            siguientePosicion.y = posicionActual.y;
            break;
    }
    return siguientePosicion;
    
}

bool esValida(coordenada posicionActual,int N)
{
    return posicionActual.x < N && posicionActual.x >= 0 && posicionActual.y < N && posicionActual.y >= 0;
}

void laberinto(Matriz<bool> L, int N, coordenada posActual,coordenada posDestino,std::vector<int>solucion, std::vector<int> &mejorSolucion,int costeActual, int &mejorCoste, int k, Matriz<bool> &marcaje)
{
    for (int i = 0; i < 4; i++)
    {
        solucion[k] = i;
        posActual = siguientePosicion(posActual,i);
        costeActual++;
        
        // Es valida, si no esta marcada, si es transitable y no nos salimos del tablero.
        if (esValida(posActual,N) && !marcaje[posActual.x][posActual.y] && !L[posActual.x][posActual.y])
        {
            // Es solucion si estamos en la ultima posicion.
            if (posActual.x == posDestino.x && posActual.y == posDestino.y)
            {
                // Es mejor solucion si mejoramos el coste.
                if (costeActual < mejorCoste)
                {
                    mejorCoste = costeActual;
                    mejorSolucion = solucion;
                }
            }
            else
            {
                marcaje[posActual.x][posActual.y] = true;
                laberinto(L,N,posActual,posDestino,solucion,mejorSolucion,costeActual,mejorCoste,k+1,marcaje);
                marcaje[posActual.x][posActual.y] = false;
            }
        }
    }
}