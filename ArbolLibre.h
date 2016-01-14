//
//  ArbolLibre.h
//  Ejercicio1
//
//  Created by Rubén Gómez on 4/11/15.
//  Copyright © 2015 Rubén Gómez. All rights reserved.
//

#ifndef ArbolLibre_h
#define ArbolLibre_h

#include <hash_map>
#include "Grafo.h"
#include "Grafo.cpp"

class ArbolLibre{
    
private:
    bool _esLibre;
    bool _esCiclico;
    bool _esConexo;
    
public:
    
    ArbolLibre(const Grafo &g){
        _esCiclico = grafoCiclico(g);
        _esConexo = grafoConexo(g);
        _esLibre = !_esCiclico && _esConexo;
        
    }
    
    bool grafoLibre(){
        return _esLibre;
    }
    
private:
    void grafoCiclico(const Grafo &g,int v, int p, bool &hayCiclo, HashMap<int,bool> &visitados)
    {
        
        if (!hayCiclo)
        {
            for (auto w : g.adj(v))
            {
                if (w != padre)
                {
                    hayCiclo = visitados.contains(w);
                    if (!hayCiclo)
                    {
                        grafoCiclico(g,w,v,hayCiclo);
                    }
                }
            }
        }
        
        
    }
    
};


#endif /* ArbolLibre_h */

