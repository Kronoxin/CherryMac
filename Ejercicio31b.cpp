//
//  Ejercicio31.cpp
//  Ejercicio1
//

/*
#include <string>
#include <iostream>
#include <vector>


//Solución con vector

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
 }

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
    
    std::vector<int> solucion(precio+1,infinidad);
    solucion[0] = 0;
    
    
    monedas_minimas(monedas, precio,solucion);
    
    
    
    if(solucion[precio]==infinidad){
        std::cout<<"NO"<<std::endl;
    }
    else{
        std::cout <<"SI "<< solucion[precio] << std::endl;
    }
    
    
    return true;
    
}


int main()
{
    while(resuelveCaso());
    return 0;
}*/
