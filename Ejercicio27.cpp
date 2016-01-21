//
//  Ejercicio27.cpp
//  Ejercicio1
//

/*

#include <string>
#include <iostream>
#include <vector>
#include "Matriz.h"

void comprobarA(Matriz<bool> &A , Matriz<bool> &B, Matriz<bool> &C , int i , int j , int k)
{
    A[i][j] = false;
    
    while (!A[i][j] && k < j) {

        //Si ocurre         A y C               B y C                      C y A
        A[i][j] = (A[i][k] && C[k+1][j]) || (B[i][k] && C[k+1][j]) || (C[i][k] && A[k+1][j]);
        
        if(!A[i][j])
            k++;
    }

}

void comprobarB(Matriz<bool> &A , Matriz<bool> &B, Matriz<bool> &C , int i , int j , int k)
{
    B[i][j] = false;
    
    while (!B[i][j] && k < j) {

        //Si ocurre         A y A               A y B                       B y B
        B[i][j] = (A[i][k] && A[k+1][j]) || (A[i][k] && B[k+1][j]) || (B[i][k] && B[k+1][j]);
        
        if(!B[i][j])
            k++;
    }
}

void comprobarC(Matriz<bool> &A , Matriz<bool> &B, Matriz<bool> &C , int i , int j , int k)
{
    C[i][j] = false;
    
    while (!C[i][j] && k < j)
    {
        
        //Si ocurre     B y A                 C y B                   C y C
        C[i][j] = (B[i][k] && A[k+1][j]) || (C[i][k] && B[k+1][j]) || (C[i][k] && C[k+1][j]) ;
        
        if(!C[i][j])
            k++;
    }
}


bool colocarParentesis(std::vector<char> letras, int n)
{
    Matriz<bool> A(n,n,false);
    Matriz<bool> B(n,n,false);
    Matriz<bool> C(n,n,false);
    
    for (int i = 0; i < n; i++)
    {
        A[i][i] = (letras[i] == 'a');
        B[i][i] = (letras[i] == 'b');
        C[i][i] = (letras[i] == 'c');
        
    }
    
    for (int d = 1; d< n; d++)
    {
        for (int i = 0; i < n-d; i++)
        {
            int j = i+d;
            int k = i;
            
            comprobarA(A, B, C, i, j, k);
            comprobarB(A, B, C, i, j, k);
            comprobarC(A, B, C, i, j, k);
            
            
        }
    }
    return A[0][n-1];
}

bool resuelveCaso()
{
    
    
    //  Obtener A
    //
    //  A(i,j)  = A(i,k) y C(k+1,j)      (A y C)    i<=k<j
    //  A(i,j)  = B(i,k) y C(k+1,j)      (B y C)
    //  A(i,j)  = C(i,k) y A(k+1,j)      (C y A)
    //
    //
    //  Obtener B
    //
    //  B(i,j)  = A(i,k) y A(k+1,j)      (A y A)    i<=k<j
    //  B(i,j)  = A(i,k) y B(k+1,j)      (A y B)
    //  B(i,j)  = B(i,k) y B(k+1,j)      (B y B)
    //
    //
    //  Obtener C
    //
    //  C(i,j)  = B(i,k) y A(k+1,j)      (B y A)    i<=k<j
    //  C(i,j)  = C(i,k) y B(k+1,j)      (C y B)
    //  C(i,j)  = C(i,k) y C(k+1,j)      (C y C)
    //
    
    std::string linea;
    
    std::getline(std::cin,linea);     //leemos linea a linea
    
    
    if(!std::cin)               // si no tenemos entrada, terminamos
        return false;
    
    
    std::vector<char> letras(linea.length());
    
    for (int i = 0; i < linea.length(); i++) {
        letras[i] = linea[i];
    }
    
    if ( colocarParentesis(letras,letras.size())){
        std::cout << "SI\n";
    }
    else{
        std::cout << "NO\n";
    }
    

    
    return true;
    
}


int main()
{
    while(resuelveCaso());
    return 0;
}*/