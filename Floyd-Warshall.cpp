#include <bits/stdc++.h>

using namespace std;

int matrix[1000][1000];

int main()
{
    ifstream fin("royfloyd.in");
    int rows;
    fin >> rows;

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < rows; j++)
            fin >> matrix[i][j];

    for(int k = 0; k < rows; k++)
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < rows; j++)
                if(matrix[i][j] > matrix[i][k] + matrix[k][j]
                 && matrix[i][k] && matrix[k][j] && i != j)
                    matrix[i][j] = matrix[i][k] + matrix[j][k];

    ofstream fout("royfloyd.out");
    for(int i = 0; i < rows; i++){
        for(int j = 0 ; j < rows; j++){
            fout << matrix[i][j] << " ";
        }
        fout << "\n";
    }

    return 0;
}