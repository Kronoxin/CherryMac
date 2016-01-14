//
//  Varillas.h
//  Ejercicio1


#ifndef Varillas_h
#define Varillas_h

#include "Matriz.h"
#include <vector>
#include <iostream>
#include <stdexcept>

class Varillas
{
public:
    
    Varillas(std::vector<int> varillas, std::vector<int> costes, int nVarillas, int L)
    {
        
        numMinVarillas = std::vector<int> (L+1, infinidad);
        combinaciones = std::vector<int> (L+1, 0);
        precios = std::vector<int> (L+1, infinidad);
        numMinVarillas[0] = 0;
        combinaciones[0] = 0;
        precios[0] = 0;
        
        calcularNumMinVarillas(varillas, nVarillas, L, numMinVarillas);
        calcularCombinaciones(varillas, nVarillas, L, combinaciones);
        calcularPrecios(varillas, nVarillas, L, precios, costes);
        
        
    }
    
    bool esPosible(int longitud)
    {
        if (longitud > combinaciones.size()-1)
            throw std::invalid_argument("La longitud requerida no ha sido previamente calculada.");
        
        if(numMinVarillas[longitud] == infinidad)
            return false;
        else
            return true;
    }
    
    int numCombinaciones(int longitud)
    {
        if (longitud > combinaciones.size()-1)
            throw std::invalid_argument("La longitud requerida no ha sido previamente calculada.");
        else
            return combinaciones[longitud];
    }
    
    int numeroMinVarillas(int longitud)
    {
        if (longitud > numMinVarillas.size()-1)
            throw std::invalid_argument("La longitud requerida no ha sido previamente calculada.");
        else
            return numMinVarillas[longitud];
    }
    
    int costeMinimo(int longitud)
    {
        if (longitud > numMinVarillas.size()-1)
            throw std::invalid_argument("La longitud requerida no ha sido previamente calculada.");
        else
            return precios[longitud];
    }
    
    
private:
    const long long int infinidad = 1000001;
    
    std::vector<int> numMinVarillas;
    std::vector<int> combinaciones;
    std::vector<int> precios;
    
    void imprimeMatriz(Matriz<int> &m){
        for(int i = 0; i < m.numfils() ;i++){
            std::cout <<"[";
            for( int j = 0 ; j < m.numcols() ; j++){
                std::cout <<" " << m[i][j];
            }
            std::cout <<" ]\n";
        }
    }
    void imprimeVector(const std::vector<int> &v)
    {
        
        std::cout << "[";
        
        for(int i = 0; i < v.size(); i++)
            std::cout << " " << v[i];
        
        std::cout << "]\n";
        
    }
    
    //  varillas(i,j) = numero de varillas mínimo que de longitud l que suman una longitud j.
    //  varillas(0,0) = 0
    //  varillas(0,L) = inf;
    //  varillas(l,o)= 0;
    //
    //  varillas(i,j) = varillas(i-1,j) si l > j;
    //  varillas(i,j) = min(varillas(i-1,j) , varillas(i-1, j-l)) si l<=j
    //

    void calcularNumMinVarillas(std::vector<int> &v, int nVarillas, int L,std::vector<int> &solucion)
    {
        Matriz<int> m(nVarillas+1,L+1,0);
        
        for(int i = 1; i <= L;i++)
        {
            m[0][i]= infinidad;
            
        }
        
        for (int i = 1; i <= nVarillas; i++)
        {
            for (int j = 1; j <= L ; j++)
            {
                if(v[i] > j)
                {
                    m[i][j] = m[i-1][j];
                }
                else{
                    m[i][j]= std::min(m[i-1][j], m[i-1][j-v[i]]+1);
                }
                if (solucion[j] > m[i][j])
                    solucion[j] = m[i][j];
            }
        }
    }
    
    
    
    // combinaciones(i,j) = numero de formas de sumar la longitud j con varillas de l0....li.
    //
    //  combinaciones(0,0) = 0;
    //  combinaciones(0,j) = 0;
    //  combinaciones(i,0) = 0;
    //
    void calcularCombinaciones(std::vector<int> &v, int nVarillas, int L,std::vector<int> &solucion)
    {
        Matriz<int> m(nVarillas+1,L+1,0);
        
        for (int i = 1; i <= nVarillas; i++)
        {
            for (int j = 1; j <= L ; j++)
            {
                if(v[i] > j)
                    m[i][j] = m[i-1][j];
                else if (v[i]  == j)
                    m[i][j]= m[i-1][j]+1;
                else
                    m[i][j]= m[i-1][j] + m[i-1][j-v[i]];
                
                if (solucion[j] < m[i][j])
                    solucion[j] = m[i][j];
            }
        }
    }
    
    
    // combinaciones(i,j) = numero de formas de sumar la longitud j con varillas de l0....li.
    //
    //  combinaciones(0,0) = 0;
    //  combinaciones(0,j) = 0;
    //  combinaciones(i,0) = 0;
    //
    void calcularPrecios(std::vector<int> &v, int nVarillas, int L,std::vector<int> &solucion,std::vector<int> &costes)
    {
        Matriz<int> m(nVarillas+1,L+1,0);
        for(int i = 1; i <= L;i++)
        {
            m[0][i]= infinidad;
            
        }
        
        for (int i = 1; i <= nVarillas; i++)
        {
            for (int j = 1; j <= L ; j++)
            {
                if(v[i] > j)
                    m[i][j] = m[i-1][j];
                
                else if( v[i] == j)
                {
                    m[i][j]= std::min(costes[i],m[i-1][j]);
                }
                else
                {
                    m[i][j] = std::min(costes[i] + m[i-1][j-v[i]],m[i-1][j]);
                }
                
                
                
                if (solucion[j] > m[i][j])
                    solucion[j] = m[i][j];
            }
        }
    }
    


};


#endif /* Varillas_h */
