#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

void mergesort(vector<pair<int, string> >& v, int p, int r);
void merge(vector<pair<int, string> >& v, int p, int q, int r);

int main(void) {
    int n;
    vector<pair<int, string> > v;

    cin >> n;
    // 3 1 a 1 b 1 c
    // 5 10 mac 5 windows 99 ubuntu 8 debian 752 redhat
    for (int i=0; i<n; i++){
        int d;
        string s;
        cin >> d >> s;
        v.push_back(pair<int,string>(d,s));
    }

    // merge sort
    mergesort(v, 0, v.size()-1);

    for (int i=0; i<n; i++){
        cout << v[i].first << ' ' << v[i].second << endl;
    }

    return 0;
}

void mergesort(vector<pair<int, string> >& v, int p, int r)
{
    if(p < r)
    {
        int q = (p + r) / 2;
        mergesort(v, p, q);
        mergesort(v, q + 1, r);
        merge(v, p, q, r);
    }
}

void merge(vector<pair<int, string> >& v, int p, int q, int r)
{
    vector<pair<int, string> > left;
    vector<pair<int, string> > right;
    int n1 = q - p + 1;   
    int n2 = r - q;

    for(int i = 0; i < n1; i++)
        left.push_back(v[p + i - 1]);
    for(int i = 0; i < n2; i++)
        right.push_back(v[q + i]);
    left.push_back(pair<int, string>(INT_MAX, NULL));
    right.push_back(pair<int, string>(INT_MAX, NULL));

    int i = 0; int j = 0;
    for(int k = p; k < r; k++)
    {
        if (left[i] <= right[j])
        {
            v[k] = left[i];
            i++;
        }
        else
        {
            v[k] = right[j];
            j++;
        }
    }
}