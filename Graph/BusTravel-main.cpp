#include "BusTravel.cpp"

void printVector(int n, vector<vector<int>> signs);

int main()
{
    int n = 3;
    vector<vector<int>> signs;

    for(int i = 0; i < n; i++)
    {
        vector<int> temp;
        for(int j = 0; j < n; j++)
            temp.push_back(0);
        signs.push_back(temp);
    }

    signs[0][2] = 1;
    signs[1][2] = 1;
    signs[2][1] = 1;

    cout << "Input:\t";
    printVector(n, signs);

    signs = solution(n, signs);

    cout << "Output:\t";
    printVector(n, signs);

    return 0;
}

void printVector(int n, vector<vector<int>> signs)
{
    cout << "[";
    for(int i = 0; i < n; i++)
    {
        cout << "[";
        for(int j = 0; j < n; j++)
        {
            if((j + 1) == n)
            {
                cout << signs[i][j];
                break;
            }
            cout<< signs[i][j] << ",";
        }
        if((i + 1) == n)
        {
            cout << "]";
            break;
        }
        cout << "],";
    }
    cout << "]" << endl;
}