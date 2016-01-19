//
//  Ejercicio29.cpp
//  Ejercicio1
//


#include <string>
#include <iostream>
#include "Matriz.h"
/*
void imprime(const Matriz<int> &a,int nPoblados){
    
    for (int i = 0 ; i< nPoblados ; i++)
    {
        for (int j = i; j < nPoblados; j++)
        {
            if( i != j)
            {
                std::cout << a[i][j];
                if( j != nPoblados -1)
                    std::cout << " ";
                else
                    std::cout << "\n";
            }
        }
    }
    
}

void canoas(const Matriz<int> &costes, int nPoblados, Matriz<int> &solucion )
{
    for (int d = 1; d <= nPoblados-1 ; d++)
    {
        for (int i = 0; i <= nPoblados-d; i++)
        {
            int j = i+d;
            for (int  k = i; k <= j-1; k++)
            {
                solucion[i][j] = std::min(solucion[i][j] , solucion[i][k] + solucion[k][j]);
            }
        }
    }
}

bool resuelveCaso()
{
    int nPoblados;
     
    std::cin >> nPoblados;
     
 
 
    if(!std::cin)               // si no tenemos entrada, terminamos
        return false;
 
     Matriz<int> costes(nPoblados,nPoblados,0);
     
     for (int i = 0 ; i< nPoblados ; i++)
     {
         for (int j = i; j < nPoblados; j++)
         {
             
             if( i == j)
             {
                 costes[i][j] = 0;
             }
             else{
                 int c;
                 std::cin >> c;
                 costes[i][j] = c;
             }

             
         }
     }
     
     Matriz<int> solucion = costes;
     canoas(costes, nPoblados,solucion);
     imprime(solucion,nPoblados);
 
 
 
 return true;
 
 }
 
 
 int main()
 {
 while(resuelveCaso());
 return 0;
 }
*/