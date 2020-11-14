#include <iostream>
#include <stdlib.h>
#include <vector>

using std::vector;
using namespace std;

void MatrixInit(vector< vector<int> > &matrix, int n)
{ 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = i+j;
        }
    }
}

void printMat(vector< vector<int> > &matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void MatrixSum(vector< vector<int> > &matrixA, vector< vector<int> > &matrixB, vector< vector<int> > &matrixC)
{
    for (int i = 0; i < (int)matrixA.size(); i++)
    {
        for (int j = 0; j< (int)matrixA[i].size(); j++)
        {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void MatrixSub(vector< vector<int> > &matrixA, vector< vector<int> > &matrixB, vector< vector<int> > &matrixC)
{
    for (int i = 0; i < (int)matrixA.size(); i++)
    {
        for (int j = 0; j< (int)matrixA[i].size(); j++)
        {
            matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

void MatrixMul(vector< vector<int> > &matrixA, vector< vector<int> > &matrixB, vector< vector<int> > &matrixC)
{
    for (int i = 0; i < (int)matrixA.size(); i++)
    {
        for (int j = 0; j< (int)matrixA[i].size(); j++)
        {
            for (int k = 0; k < (int)matrixA[i].size(); k++)
            {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    } 
}

void Submatrix(vector< vector<int> > &matrixOrigin, vector< vector<int> > &matrix11, vector< vector<int> > &matrix12,
               vector< vector<int> > &matrix21, vector< vector<int> > &matrix22)
{
    int newNum = (int)matrix11.size();
    for (int i = 0; i < newNum; i++)
    {
        for (int j = 0; j < newNum; j++)
        {
            matrix11[i][j] = matrixOrigin[i][j];
            matrix12[i][j] = matrixOrigin[i][j + newNum];
            matrix21[i][j] = matrixOrigin[i + newNum][j];
            matrix22[i][j] = matrixOrigin[i + newNum][j + newNum];
        }
    }
}

void Mergematrix(vector< vector<int> > &matrixOrigin, vector< vector<int> > &matrix11, vector< vector<int> > &matrix12,
                 vector< vector<int> > &matrix21, vector< vector<int> > &matrix22)
{
    int newNum = (int)matrix11.size();
    for (int i = 0; i < newNum; i++)
    {
        for (int j = 0; j < newNum; j++)
        {
            matrixOrigin[i][j] = matrix11[i][j];
            matrixOrigin[i][j + newNum] = matrix12[i][j];
            matrixOrigin[i + newNum][j] = matrix21[i][j];
            matrixOrigin[i + newNum][j + newNum] = matrix22[i][j];
        }
    }
}

void Strassen(int n, vector< vector<int> > &matrixA, vector< vector<int> > &matrixB, vector< vector<int> > &matrixC)
{
    if (n<=2)
    {
        MatrixMul(matrixA, matrixB, matrixC);
        return;
    }
    else
    {
        int newRow = n / 2;
        vector<int> newCol(newRow, 0);
        vector < vector<int> > a11(newRow, newCol), a12(newRow, newCol), a21(newRow, newCol), a22(newRow, newCol);
        vector < vector<int> > b11(newRow, newCol), b12(newRow, newCol), b21(newRow, newCol), b22(newRow, newCol);
        vector < vector<int> > m1(newRow, newCol), m2(newRow, newCol), m3(newRow, newCol), m4(newRow, newCol)
                                , m5(newRow, newCol), m6(newRow, newCol), m7(newRow, newCol);
        vector < vector<int> > tempA(newRow, newCol), tempB(newRow, newCol);
        vector < vector<int> > c11(newRow, newCol), c12(newRow, newCol), c21(newRow, newCol), c22(newRow, newCol);

        Submatrix(matrixA, a11, a12, a21, a22);
        Submatrix(matrixB, b11, b12, b21, b22);
        MatrixSum(a11, a22, tempA);
        MatrixSum(b11, b22, tempB);
        Strassen(newRow, tempA, tempB, m1);
        MatrixSum(a21, a22, tempA);
        Strassen(newRow, tempA, b11, m2);
        MatrixSub(b12, b22, tempB);
        Strassen(newRow, a11, tempB, m3);
        MatrixSub(b21, b11, tempB);
        Strassen(newRow, a22, tempB, m4);
        MatrixSum(a11, a12, tempA);
        Strassen(newRow, tempA, b22, m5); 
        MatrixSub(a21, a11, tempA);
        MatrixSum(b11, b12, tempB);
        Strassen(newRow, tempA, tempB, m6); 
        MatrixSub(a12, a22, tempA);
        MatrixSum(b21, b22, tempB);
        Strassen(newRow, tempA, tempB, m7);
        MatrixSum(m1, m4, tempA);
        MatrixSum(tempA, m7, tempB);
        MatrixSub(tempB, m5, c11);
        MatrixSum(m3, m5, c12);
        MatrixSum(m2, m4, c21);
        MatrixSum(m1, m3, tempA);
        MatrixSum(tempA, m6, tempB);
        MatrixSub(tempB, m2, c22);
        Mergematrix(matrixC, c11, c12, c21, c22);
    }
}

int main()
{
    int n=0;
    cout<<"정사각 행렬의 크기를 입력하시오:";
    cin>>n;
    int Row = n;
    int Col = n;
    vector < vector<int> > A(Row, vector<int>(Col, 0));
    vector < vector<int> > B(Row, vector<int>(Col, 0));
    vector < vector<int> > C(Row, vector<int>(Col, 0));
    MatrixInit(A, n);
    MatrixInit(B, n);
    Strassen(n, A, B, C);
    printMat(A,n);
    printMat(B,n);
    printMat(C,n);
    return 0;
}