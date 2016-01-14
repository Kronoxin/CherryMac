//
//  Ejercicio7.cpp
//  Ejercicio1
//
//  Created by Rubén Gómez on 23/10/15.
//  Copyright © 2015 Rubén Gómez. All rights reserved.
//
/*
#include <stdio.h>
#include "PriorityQueue.h"

PriorityQueue<long> cargarCola(unsigned const long &n)
{
    PriorityQueue<long> cola;
    unsigned int elemento;
    
    for (unsigned int i = 0; i<n; i++)
    {
        std::cin >> elemento;
        cola.push(elemento);
    }
    
    return cola;
}


int main()
{
    unsigned long n;
    std::cin >> n;
    
    long a=0;
    long b=0;
    long suma = 0;
    long resultado = 0;
    
    PriorityQueue<long> cola = cargarCola(n);

    
    while(!cola.empty()){
        cola.pop(a);
        
        if(!cola.empty()){
            cola.pop(b);
            suma = a + b;
            cola.push(suma);
            resultado +=suma;
            
        }
    }
    
    std::cout << resultado << std::endl;

}*/