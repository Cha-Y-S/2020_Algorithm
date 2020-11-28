#include <iostream>
#include<vector>
using namespace std;

vector<vector<int> > solution(int n, vector<vector<int> > signs)
{

    vector<vector<int> > answer = signs;
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if ((answer[i][k] == 1) && (answer[k][j] == 1))
                    answer[i][j] = 1;
            }
        }
    }
    return answer;
}