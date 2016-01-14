//
//  Ejercicio26.cpp
//  Ejercicio1
//
//

#include <stdio.h>

bool resuelveCaso()
{
    int nProyectos,iniInter,finInter;
    
    std::cin >> iniInter >> finInter >> nProyectos ;
    
    if(nProyectos == 0 && iniInter == 0 && finInter == 0)
        return false;
    
    PriorityQueue<Proyectos,menorProyecto> listaProyectos(nProyectos);
    
    
    
    for(int i = 0; i < nProyectos ; i++)
    {
        
        int inicio, fin;
        
        std::cin >> inicio >> fin;
        
        Proyectos p;
        p.inicio = inicio;
        p.fin = fin;
        
        listaProyectos.push(p);
        
    }
    
    int resultado = resuelve(listaProyectos,iniInter,finInter);
    if(resultado == 0){
        std::cout << "Imposible" << std::endl;
    }
    else{
        std::cout << resultado << std::endl;
    }
    
    
    return true;
    
}


int main()
{
    while(resuelveCaso());
    return 0;
}