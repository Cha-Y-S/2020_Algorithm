#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> a, vector<int> b);

int solution(vector<vector<int>> arr)
{
    int answer = 1;
    int n = arr.size();
    int k = 0;

    // cout << "=====before Sorting=====" << endl; 
    // for(int i = 0; i < n; i++)
    // {
    //     cout << "-----Team " << i << "-----"<< endl;
    //     cout << "start: " << arr[i][0] << "\tend: " << arr[i][1] << endl;
    // }

    sort(arr.begin(), arr.end(), comp);

    // cout << "\n=====after Sorting=====" << endl;
    // for(int i = 0; i < n; i++)
    // {
    //     cout << "-----Team " << i << "-----"<< endl;
    //     cout << "start: " << arr[i][0] << "\tend: " << arr[i][1] << endl;
    // }

    for(int m = 1; m < n; m++)
    {
        
        if(arr[m][0] >= arr[k][1])
        {
            k = m;
            answer += 1;
        }

    }
    return answer;
}

bool comp(vector<int> a, vector<int> b)
{
    if(a[1] == b[1])
        return a[0] < b[0];
    else
        return a[1] < b[1];
}