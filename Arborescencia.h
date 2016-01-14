//
//  Arborescencia.h
//  Ejercicio1
//
//  Created by Rubén Gómez on 11/11/15.
//  Copyright © 2015 Rubén Gómez. All rights reserved.
//

#ifndef Arborescencia_h
#define Arborescencia_h


#include "GrafoDirigido.h"
#include <vector>

class Arborescencia{
    
private:
    bool _esLibre;
    bool _esCiclico;
    bool _esConexo;
    
    bool _esArborescencia;
    int _raiz;
    
public:
    
    Arborescencia(const GrafoDirigido &g){
        _raiz = -1;
        buscaRaiz(g,_raiz);
        
        _esArborescencia = false;
        _esCiclico = false;
        
        if(_raiz >= 0)
        {
            dfs(g,_raiz,_esCiclico);
            _esArborescencia = !_esCiclico;
        }
        
    }
    
    bool grafoArborescente(){
        return _esArborescencia;
    }
    
    int raiz()
    {
        return _raiz;
    }
    
private:
    
    void dfsAux(GrafoDirigido const& G, size_t v,std::vector<bool> &marked,size_t &count,size_t p, bool &hayCiclo)
    {
        if (!hayCiclo)
        {
            ++count;
            marked[v] = true;
            
            for (auto w : G.adj(v))
            {
                if (w != p)
                {
                    if(!marked[w])
                        dfsAux(G,w,marked,count,v,hayCiclo);
                    else
                        hayCiclo = true;
                }
            }
        }
    }
    
    size_t dfs(GrafoDirigido const& G, size_t v, bool & esCiclico)
    {
        std::vector<bool> marked(G.V());
        size_t count = 0;
        dfsAux(G,v,marked,count,v,esCiclico);
        
        return count;
        
    }
    
    void buscaRaizAux(const GrafoDirigido &g,size_t v, int &raiz, std::vector<bool> & marked)
    {
        marked[v] = true;
        if ((g.adj(v).size() == 0))
            raiz = v;
        else
        {
            for (auto w : g.adj(v))
            {
                if(!marked[w])
                    buscaRaizAux(g,w,raiz,marked);
                
            }
        }
    }
    
    void buscaRaiz(const GrafoDirigido &g, int &raiz)
    {
        std::vector<bool> marked(g.V());
        buscaRaizAux(g.reverse(),0,raiz,marked);
    }
    
    
    
};
#endif /* Arborescencia_h */
