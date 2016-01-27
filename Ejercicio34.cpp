//
//  Ejercicio34.cpp
//  Las Vacas Pensantes
//



#include <string>
#include <iostream>
#include <vector>
/*

//Solución con vector

bool es_par(int n){
    
    if(n%2 == 0)
        return true;
    else
        return false;
}

int maximizar_comida(std::vector<int> &cubos, int nCubos){
    int sumaPares = 0;
    int sumaImpares = 0;
    
    //PARES SEGUN LAS POSICIONES DEL VECTOR, elemento 0 impar, elemento 1 par.
    for (int i = 0; i< nCubos; i++) {
        if(es_par(i)){
            sumaImpares += cubos[i];
        }
        else{
            sumaPares += cubos[i];
        }
    }
    
    int extremoIzq = 0;
    int extremoDrch = nCubos-1;
    int acumulado = 0;
    
    while (extremoIzq < extremoDrch) {
        if(sumaImpares >= sumaPares){
            
            //como por impar
            if(es_par(extremoIzq)){
                
                acumulado += cubos[extremoIzq];
                sumaImpares -= cubos[extremoIzq];
                extremoIzq++;
            }
            else{
                acumulado += cubos[extremoDrch];
                sumaImpares -= cubos[extremoDrch];
                extremoDrch--;
                
            }
            
        }
        else{
            //como por par
            if(es_par(extremoIzq)){
                
                acumulado += cubos[extremoDrch];
                sumaPares -= cubos[extremoDrch];
                extremoDrch--;
            }
            else{
                acumulado += cubos[extremoIzq];
                sumaPares -= cubos[extremoIzq];
                extremoIzq++;
            }
        }
        //come la otra vaca
        
        if(cubos[extremoIzq] >= cubos[extremoDrch]){
            //come el más grande, en este caso, por la izquierda
            
            if(es_par(extremoIzq)){
                sumaImpares -= cubos[extremoIzq];
            }
            else{
                sumaPares -= cubos[extremoIzq];
            }
        }
        else{
            //come por la derecha
            
            if(es_par(extremoDrch)){
                sumaImpares -= cubos[extremoDrch];
            }
            else{
                sumaPares -= cubos[extremoDrch];
            }
            extremoDrch--;
        }
    }
    
    return acumulado;
}

bool resuelveCaso()
{
    
    
    const int infinidad= 1000001;
    int nCubos;
    
    std::cin >> nCubos;
    
    if(nCubos == 0)               // si no tenemos entrada, terminamos
        return false;
    
    
    std::vector<int> cubos(nCubos,0);
    
    for (int i = 0; i<nCubos; i++) {
        int num;
        std::cin >> num;
        cubos[i] = num;
    }
    
    std::cout << maximizar_comida(cubos,nCubos) << std::endl;
    
    return true;
    
}


int main()
{
    while(resuelveCaso());
    return 0;
}
*/