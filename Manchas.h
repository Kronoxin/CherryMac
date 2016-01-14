//
//  Manchas.h
//  Ejercicio1
//
//  Created by Rubén Gómez on 22/11/15.
//  Copyright © 2015 Rubén Gómez. All rights reserved.
//

#ifndef Manchas_h
#define Manchas_h

#include "Grafo.h"
#include "Matriz.h"

#include <vector>

class Manchas
{
    
private:
    
    //unsigned int _nComponentesConexas;
    unsigned int _mayorNumeroManchas;
    //std::vector<unsigned int> _numeroManchasPorComponente;
    
    
public:
    
    Manchas(const Matriz<bool> &m, const unsigned int &f, const unsigned int &c)
    {
        //_nComponentesConexas = 0;
        _mayorNumeroManchas = 0;
        
        //_numeroManchasPorComponente = std::vector<unsigned int> (f*c);
        
        Grafo g = generaGrafoDeMapa(m,f,c);
        cuentaManchas(g,m,c);
    }
    
    unsigned int mayorNumeroManchas()
    {
        return _mayorNumeroManchas;
    }
    
private:
    
    Grafo generaGrafoDeMapa(const Matriz<bool> &m, unsigned int f, unsigned int c)
    {
        Grafo g = Grafo(f*c);
        
        for(int i = 0; i < f; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if (m[i][j]) // Si la casilla actual es negra.
                {
                    // Comprobamos que la casilla derecha existe y es negra y la agregamos al grafo.
                    if (j+1 < c) // Si no nos pasamos.
                        if (m[i][j+1]) // Si la de la derecha es negra.
                            g.ponArista((i*c)+j,(i*c)+j+1);
                    
                    // Comprobamos que la casilla de abajo existe y es negra y la agregamos al grafo.
                    if (i+1 < f) // Si no nos pasamos.
                        if (m[i+1][j]) // Si la de abajp es negra.
                            g.ponArista((i*c)+j,((i+1)*c)+j);
                    
                }
            }
        }
        return g;
    }
    void dfsAux(Grafo const& G, size_t v,std::vector<bool> &marked,size_t &count)
    {
        
        ++count;
        marked[v] = true;
        
        for (auto w : G.adj(v))
        {
            if(!marked[w])
                dfsAux(G,w,marked,count);
            
        }
    }
    
    
    
    void cuentaManchas(Grafo const& G,const Matriz<bool> &m,int c)
    {
        std::vector<bool> marked(G.V());
        
        for (unsigned int i = 0; i < G.V(); i++)
        {
            if (!marked[i] && m[i/c][i%c])
            {
                size_t count = 0;
                dfsAux(G,i,marked,count);
                //_numeroManchasPorComponente.at(_nComponentesConexas) = count;
                
                if (count > _mayorNumeroManchas)
                    _mayorNumeroManchas = count;
                /*if (count > 0)
                    _nComponentesConexas++;
                */
            }
        }
    }
};



#endif /* Manchas_h */
