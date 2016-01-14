//
//  ArbolBipartito.h
//  Ejercicio1
//
//  Created by Rubén Gómez on 18/11/15.
//  Copyright © 2015 Rubén Gómez. All rights reserved.
//

#ifndef ArbolBipartito_h
#define ArbolBipartito_h

#include "Grafo.h"
#include <vector>
#include "HashMap.h"

class ArbolBipartito
{
    
private:
    bool _esBipartito;
    
public:
    
    ArbolBipartito(const Grafo &g)
    {
        _esBipartito = dfs(g);
        
    }
    
    bool grafoBipartito()
    {
        return _esBipartito;
    }
    
private:
    
    void dfsAux(Grafo const& G, int v,std::vector<bool> &marked,bool soyRojo,std::vector<bool> &color,bool &soyBipartito, HashMap<int,int> &nodos)
    {
        if (soyBipartito)
        {
            marked[v] = true;
            color[v] = soyRojo;
            nodos.erase(v);
           
            for (auto w : G.adj(v))
            {
                if(!marked[w])
                    dfsAux(G,w,marked,!soyRojo,color,soyBipartito,nodos);
                else if(color[w] == soyRojo)
                    soyBipartito = false;
                
            }
        }
    }
    
    bool dfs(Grafo const& G)
    {
        bool correcto = true;
        HashMap<int, int> nodos;
        
        for (int i = 0; i < G.V(); i++)
        {
            nodos.insert(i,i);
        }
        
        while(!nodos.empty())
        {
            std::vector<bool> marked(G.V());
            std::vector<bool> color(G.V());
            bool soyBipartito = true;
            int nodo = (nodos.begin()).key();
            dfsAux(G,nodo,marked,true,color,soyBipartito,nodos);
            correcto &= soyBipartito;
            
        }
        
        return correcto;
        
    }
    
};


#endif /* ArbolBipartito_h */
