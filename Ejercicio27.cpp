//
//  Ejercicio27.cpp
//  Ejercicio1
//



#include <string>
#include <iostream>
#include <vector>
#include "Matriz.h"

void comprobarA(Matriz<bool> &A , Matriz<bool> &B, Matriz<bool> &C , int i , int j , int k)
{
    A[i][j] = false;
    
    while (!A[i][j] && k < j) {
        //si ocurre (A y C)
        if(A[i][k] && C[k+1][j])
        {
            A[i][j] = true;
            //llamada rara
        }
        // si ocurre (B y C)
        else if (B[i][k] && C[k+1][j])
        {
            A[i][j] = true;
        }
        // si ocurre (C y A)
        else if (C[i][k] && A[k+1][j])
        {
            A[i][j] = true;
        }
        else{
            k++;
        }
    }
    //Para B

}

void comprobarB(Matriz<bool> &A , Matriz<bool> &B, Matriz<bool> &C , int i , int j , int k)
{
    B[i][j] = false;
    
    while (!B[i][j] && k < j) {
        //si ocurre (A y A)
        if(A[i][k] && A[k+1][j])
        {
            B[i][j] = true;
            //llamada rara
        }
        // si ocurre (A y B)
        else if (A[i][k] && B[k+1][j])
        {
            B[i][j] = true;
        }
        // si ocurre (B y B)
        else if (B[i][k] && B[k+1][j])
        {
            B[i][j] = true;
        }
        else{
            k++;
        }
    }

}

void comprobarC(Matriz<bool> &A , Matriz<bool> &B, Matriz<bool> &C , int i , int j , int k)
{
    C[i][j] = false;
    
    while (!C[i][j] && k < j) {
        //si ocurre (B y A)
        if(B[i][k] && A[k+1][j])
        {
            C[i][j] = true;
            //llamada rara
        }
        // si ocurre (C y B)
        else if (C[i][k] && B[k+1][j])
        {
            C[i][j] = true;
        }
        // si ocurre (C y C)
        else if (C[i][k] && C[k+1][j])
        {
            C[i][j] = true;
        }
        else{
            k++;
        }
    }

}


bool colocarParentesis(std::vector<char> letras, int n)
{
    Matriz<bool> A(n+1,n+1,false);
    Matriz<bool> B(n+1,n+1,false);
    Matriz<bool> C(n+1,n+1,false);
    
    for (int i = 1; i <= n; i++) {
        A[i][i] = (letras[i] == 'a');
        B[i][i] = (letras[i] == 'b');
        C[i][i] = (letras[i] == 'c');
        
    }
    
    for (int d = 1; d<= n-1; d++) {
        for (int i = 1; i <= n-d; i++) {
            int j = i+d;
            int k = i;
            
            comprobarA(A, B, C, i, j, k);
            comprobarB(A, B, C, i, j, k);
            comprobarC(A, B, C, i, j, k);
            
            
        }
    }
    return A[1][n];
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
    
    
    std::vector<char> letras(linea.length()+1);
    
    for (int i = 1; i <= linea.length(); i++) {
        letras[i] = linea[i-1];
    }
    
    if ( colocarParentesis(letras,letras.size()-1)){
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
}