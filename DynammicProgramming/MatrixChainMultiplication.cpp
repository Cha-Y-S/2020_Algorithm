#include <vector>
#include <climits>
#include <iostream>

#define MAX_ARRAY 1000
using namespace std;

// void printOptimalParens(int i, int j);
long long m[MAX_ARRAY][MAX_ARRAY];
int s[MAX_ARRAY - 1][MAX_ARRAY - 1];

int main(void) {
    int n;
    vector<int> v;

    cin >>  n;
    for (int i = 0; i < n+1; i++){
        int d;
        cin >> d;
        v.push_back(d);
    }
    // 6 30 35 15 5 10 20 25
    

    // solve here and print the result using cout 

     // initialize

    // long long m[n][n];
    // int s[n - 1][n - 1];

    for(int i = 0; i < n; i++)
        m[i][i] = 0;
    
    for(int l = 2; l < n + 1; l++)
    {
        
        for(int i = 0; i < n - l + 1; i++)
        {
            int j = i + l - 1;
            m[i][j] = LLONG_MAX;
            for(int k = i; k < j; k++)
            {
                long long q = m[i][k] + m[k + 1][j] + v[i] * v[k + 1] * v[j + 1];
                if(q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j - 1] = k;
                }
            }
        }
    }
    // cout << "====================" << endl;
    // cout << "\t0\t1\t2\t3\t4\t5" << endl;
    // for(int i = 0; i < n; i++)
    // {        
    //     cout << i << "\t";
    //     for(int j = 0; j < n; j++)
    //     {
    //         cout << m[i][j] << "\t";
    //     }
    //     cout << endl;
    // }

    // cout << "====================" << endl;
    // cout << "\t0\t1\t2\t3\t4" << endl;
    // for(int i = 0; i < n-1; i++)
    // {
    //     cout << i << "\t";
    //     for(int j = 0; j < n-1; j++)
    //     {
    //         cout << s[i][j] << "\t";
    //     }
    //     cout << endl;
    // }
    // cout << "====================" << endl;
    
    // printOptimalParens(0, n - 1);

    cout << m[0][n - 1] << endl;
    return 0;
}

// void printOptimalParens(int i, int j)
// {
//     if(i == j)
//     {
//         cout << "A" << i;
//         return;
//     }
//     else
//     {
//         cout << "(";
//         printOptimalParens(i, s[i][j - 1]);
//         printOptimalParens(s[i][j - 1] + 1, j);
//         cout << ")";
//     }
// }