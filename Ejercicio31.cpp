//
//  Ejercicio31.cpp
//  Ejercicio1
//


#include <string>
#include <iostream>
#include <vector>
#include "Matriz.h"
#include <unordered_map>

//Solución con Matriz
void monedas_minimas(Matriz<int> &M , std::vector<int> &monedas, int precio){
    
    for (int i = 1; i < monedas.size(); i++)
    {
        for (int j = 1; j <= precio ; j++)
        {
            if(monedas[i] < j)
                M[i][j]= std::min(M[i-1][j], M[i-1][j-monedas[i]]+1);
            else if ( monedas[i] == j)
                M[i][j] = 1;
            else
                M[i][j] = M[i-1][j];
        }
    }
}


std::unordered_map<int, int> contruyendoSolucion(int precio, Matriz<int> &M, std::vector<int> monedas,int nMonedas, std::vector<int> &cantidadDeMonedas,std::vector<int> & valorMonedas)
{
    std::unordered_map<int, int> cantidad(nMonedas);
    for(int i = nMonedas-1; i >= 0; i--)
        cantidad[valorMonedas[i]] = 0;
    
    int j = precio;
    
    int i = monedas.size()-1;
    
    while (M[i][j] > 0) {
        if( M[i-1][j-monedas[i]] == M[i][j]-1){
            cantidad[monedas[i]]++;
            j = j - monedas[i];
        }
        i = i-1;
    }
    return cantidad;

}

//Solución con vector
/*
void monedas_minimas(std::vector<int> &monedas, int precio, std::vector<int> &solucion){
    
    for (int i = 1; i <= monedas.size(); i++)
    {
        for (int j = precio; j >= 1 ; j--)
        {
            if(monedas[i] < j)
               solucion[j]= std::min(solucion[j], solucion[j-monedas[i]]+1);
            else if ( monedas[i] == j)
                solucion[j] = 1;
        }
    }
}*/

bool resuelveCaso()
{
    
    //  monedas(i,j) = Numero minimo de monedas de tipo hasta i, con las que se puede pagar j.
    //
    //  monedas(i,0) = 0
    //  monedas(0,j) = inf.
    //
    //  monedas(i,j) =  monedas(i-1,j)      xi > j.
    //  monedas(i,j) =  1                   xi = j.
    //  monedas(i,j) =  min{ monedas(i-1), monedas(i-1,j-xi)+1 }
    //
    const int infinidad= 1000001;
    int nMonedas;
    int cantidadDeMonedas = 0;
    
    std::cin >> nMonedas;
    
    
    
    if(!std::cin)               // si no tenemos entrada, terminamos
        return false;
    
    std::vector<int> linea1(nMonedas,0);
    std::vector<int> linea2(nMonedas,0);
    
    
    for (int i = 0; i<nMonedas; i++) {
        int num;
        std::cin >> num;
        linea1[i] = num;
    }
    
    for (int i = 0; i<nMonedas; i++) {
        int num;
        std::cin >> num;
        linea2[i] = num;
        cantidadDeMonedas += num;
    }
    
    int precio;
    int indice = 1;
    std::cin >> precio;
    std::vector<int> monedas(cantidadDeMonedas+1,0);
    
    for (int i = 0 ; i< nMonedas; i++) {
        for (int j = 0; j < linea2[i]; j++) {
            monedas[indice] = linea1[i];
            indice++;
        }
    }
    
    Matriz<int> M(cantidadDeMonedas+1,precio+1,infinidad);
    for (int i = 0; i <= cantidadDeMonedas; i++) {
        M[i][0] = 0;
    }
    
    //std::vector<int> solucion(precio+1,infinidad);
    //solucion[0] = 0;
    
    std::unordered_map<int, int> cantidad(nMonedas);
    
    //monedas_minimas(monedas, precio,solucion);
    monedas_minimas(M, monedas, precio);
    
    
    if (M[cantidadDeMonedas][precio] == infinidad)
        std::cout << "NO\n";
    else
    {
        cantidad = contruyendoSolucion(precio,M,monedas,nMonedas,linea2,linea1);
        
        std::unordered_map<int, int>::iterator it = cantidad.begin();

        std::cout << "SI";
        
        while (it != cantidad.end())
        {
            std::cout << " " << (*it).second;
            it++;
        }
        std::cout << std::endl;
    }
    
    
    return true;
    
}


int main()
{
    while(resuelveCaso());
    return 0;
}
