//
//  Ejercicio27.cpp
//  Ejercicio1
//



#include <string>
#include <iostream>
#include <vector>
#include "Matriz.h"

void nFormasA(Matriz<int> &A , Matriz<int> &B, Matriz<int> &C , int i , int j , int k, int d)
{
    while (k <= i+d-1) {
        A[i][j] += (A[i][k] * C[k+1][j]) + (B[i][k] * C[k+1][j]) + (C[i][k] * A[k+1][j]);
        k++;
    }
}

void nFormasB(Matriz<int> &A , Matriz<int> &B, Matriz<int> &C , int i , int j , int k, int d)
{
    while (k <= i+d-1) {
        B[i][j] += (A[i][k] * A[k+1][j]) + (A[i][k] * B[k+1][j]) + (B[i][k] * B[k+1][j]);
        k++;
    }
}

void nFormasC(Matriz<int> &A , Matriz<int> &B, Matriz<int> &C , int i , int j , int k, int d)
{
    while (k <= i+d-1) {
        C[i][j] += (B[i][k] * A[k+1][j]) + (C[i][k] * B[k+1][j]) + (C[i][k] * C[k+1][j]);
        k++;
    }
}

int nFormas(std::vector<char> letras, int n)
{
    Matriz<int> A(n,n,0);
    Matriz<int> B(n,n,0);
    Matriz<int> C(n,n,0);
    
    for (int i = 0; i < n; i++)
    {
        if(letras[i] == 'a')
            A[i][i] = 1;
        if(letras[i] == 'b')
            B[i][i] = 1;
        if(letras[i] == 'c')
            C[i][i] = 1;
        
    }
    
    for (int d = 1; d< n; d++)
    {
        for (int i = 0; i < n-d; i++)
        {
            int j = i+d;
            int k=i;
          //  A[i][j]=0; B[i][j]=0; C[i][j]=0;
            
           // for (int k = i; k <= i+d-1; k++) {
                
           /* while (k <= i+d-1) {
                
            
                A[i][j] += (A[i][k] * C[k+1][j]) + (B[i][k] * C[k+1][j]) + (C[i][k] * A[k+1][j]);
                B[i][j] += (A[i][k] * A[k+1][j]) + (A[i][k] * B[k+1][j]) + (B[i][k] * B[k+1][j]);
                C[i][j] += (B[i][k] * A[k+1][j]) + (C[i][k] * B[k+1][j]) + (C[i][k] * C[k+1][j]);
                
                k++;
            }*/
            nFormasA(A, B, C, i, j, k, d);
            nFormasB(A, B, C, i, j, k, d);
            nFormasC(A, B, C, i, j, k, d);
            
        }
    }
    return A[0][n-1];
}



bool resuelveCaso()
{
    
    
    //  nFormas A
    //
    //  nFormasA(i,j) = 1                           si i=j ; xi=a .
    //  nFormasA(i,j) = 0                           si i=j ; xi=b o xi=c.
    //
    //  nFormasA(i,j)  +=  [nFormasA(i,k) * nFormasC(k+1,j) +
    //                    + nFormasB(i,k) * nFormasC(k+1,j) +
    //                    + nFormasC(i,k) * nFormasA(k+1,j)]
    //
    //
    //  nFormas B
    //
    //  nFormasA(i,j) = 1                           si i=j ; xi=b .
    //  nFormasA(i,j) = 0                           si i=j ; xi=a o xi=c.
    //
    //  nFormasA(i,j)  +=  [nFormasA(i,k) * nFormasA(k+1,j) +
    //                    + nFormasA(i,k) * nFormasB(k+1,j) +
    //                    + nFormasB(i,k) * nFormasB(k+1,j)]
    //
    //
    //  nFormas C
    //
    //  nFormasA(i,j) = 1                           si i=j ; xi=c .
    //  nFormasA(i,j) = 0                           si i=j ; xi=a o xi=b.
    //
    //  nFormasA(i,j)  +=  [nFormasB(i,k) * nFormasA(k+1,j) +
    //                    + nFormasC(i,k) * nFormasB(k+1,j) +
    //                    + nFormasC(i,k) * nFormasC(k+1,j)]
    //
    //
    
    
    std::string linea;
    
    std::getline(std::cin,linea);     //leemos linea a linea
    
    
    if(!std::cin)               // si no tenemos entrada, terminamos
        return false;
    
    
    std::vector<char> letras(linea.length());
    
    for (int i = 0; i < linea.length(); i++) {
        letras[i] = linea[i];
    }
    
    
    std::cout << nFormas(letras, letras.size()) << std::endl;
    
    
    
    return true;
    
}


int main()
{
    while(resuelveCaso());
    return 0;
}