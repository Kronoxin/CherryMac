//  TAIS08 , Rubén Gómez y Daniel Lago
//
//  Ejercicio6 - ¿Es un monticulo?
//
/*  Resumen de solucion:
    Recorremos todos los nodos y nos vamos quedando con la altura de cada rama.
    Al volver al padre comparamos las alturas del hijo izquierdo y el derecho y confirmamos que la diferencia sea menor o igual a 1
    Tambien comprobamos que el padre sea mayor que sus hijos y que si el hijo izquierdo existe el hijo derecho tambien debe existir.
    
    O(numero de nodos del arbol).
 */
/*
#include <algorithm>
#include <iostream>

#include "BinTree.h"


// lee un árbol binario de la entrada estándar
BinTree<int> leerArbol() {
    
    int raiz;
    std::cin >> raiz;
    
    if (raiz == -1) { // es un árbol vacío
        return {};
    } else {    // leer recursivamente los hijos
        
        auto iz = leerArbol();
        auto dr = leerArbol();
        return {iz, raiz, dr};
    }
}

bool esHoja(BinTree<int> const& arbol){
    // Un arbol es hoja si no es vacio y no tiene hijo derecho ni izquierdo
    return !arbol.empty() && arbol.left().empty() && arbol.right().empty();
}


void esMonticuloAux(BinTree<int> const &arbol,bool &esCompleto,bool &esSemi, bool &esMin, unsigned int &profundidad)
{
    
    // Si es vacio o es hoja, es completo
    if (arbol.empty())
    {
        esCompleto = true;
        esSemi = true;
        esMin = true;
        profundidad = 0;
    }
    else
    {
        bool esCompletoIzquierda, esCompletoDerecha, esSemiIzquierda, esSemiDerecha, esMinIzquierda, esMinDerecha;
        unsigned int pIzquierda, pDerecha;
        
        esMonticuloAux(arbol.left(),esCompletoIzquierda,esSemiIzquierda,esMinIzquierda,pIzquierda);
        esMonticuloAux(arbol.right(),esCompletoDerecha,esSemiDerecha,esMinDerecha,pDerecha);
        
        if (esHoja(arbol))
            esMin = true;
        
        else if (!arbol.left().empty())
        {
            esMin = arbol.left().root() >= arbol.root();
            
            if (!arbol.right().empty())
                esMin = esMin && (arbol.right().root() >= arbol.root());
        }
        else
            esMin = arbol.right().root() >= arbol.root();
        
        
        
        esMin = esMin && esMinIzquierda && esMinDerecha;

            if (esCompletoIzquierda && esCompletoDerecha)
            {
                if (pIzquierda == pDerecha)
                {
                    esCompleto = true;
                    esSemi = true;
                    profundidad = pIzquierda +1;
                }
                else if(pIzquierda == pDerecha +1)
                {
                    esCompleto = false;
                    esSemi = true;
                    profundidad = pIzquierda +1;
                    
                }
                else{
                    esCompleto = false;
                    esSemi = false;
                    profundidad = std::max(pIzquierda,pDerecha)+1;
                }
            }
            else if (esCompletoIzquierda && esSemiDerecha && pIzquierda == pDerecha)
            {
                esCompleto = false;
                esSemi = true;
                profundidad = pIzquierda +1;
            }
            else if (esSemiIzquierda && esCompletoDerecha && pIzquierda == pDerecha+1)
            {
                esCompleto = false;
                esSemi = true;
                profundidad = pIzquierda +1;
            }
            
            else
            {
                esCompleto = false;
                esSemi = false;
                profundidad = std::max(pIzquierda,pDerecha)+1;
            }
        
    }
}

bool esMonticulo (BinTree<int> const &arbol)
{
    bool esCompleto = true;
    bool esSemi = true;
    bool esMin= true;;
    unsigned int profundidad = 0;
    esMonticuloAux(arbol, esCompleto,esSemi, esMin, profundidad);
    
    return esSemi && esMin;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
    auto arbol = leerArbol();
    
    if(esMonticulo(arbol)){
        std::cout << "SI\n" ;
    }else{
        std::cout << "NO\n";
    }
}



int main() {
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    return 0;
}
 */
