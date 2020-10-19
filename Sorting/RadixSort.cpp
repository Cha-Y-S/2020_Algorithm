#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int digit16(int v, int d){
// 양의 정수 v 의 16진수 d 번째 숫자를 반환하는 함수
// 예를 들어 v 의 값이 78320238 (= 0x04ab126e) 이고 d 가 1 이라면 6 을 반환
// 예를 들어 v 의 값이 78320238 (= 0x04ab126e) 이고 d 가 4 라면 11 (= 0xb) 을 반환
  v = v >> d*4;
  return v & 0xf;
}

void countingSort16(vector<pair<int, string> >& v,int d);

int main(void) {
    int n;
    vector<pair<int, string> > v;
    cin >> n;
    for (int i=0; i<n; i++){
        int d;
        string s;
        cin >> d >> s;
        v.push_back(pair<int,string>(d,s));
    }
    //radixsort
    for (int d=0; d<8; d++) countingSort16(v, d);

    for (int i=0; i<n; i++){
        cout << v[i].first << ' ' << v[i].second << endl;
    }
    return 0;
}

void countingSort16(vector<pair<int, string> >& v,int d)
{
    vector<pair<int, string>> origin;
    vector<int> count;

    for(int i = 0; i < 16; i++)
        count.push_back(0);

    for(int i = 0; i < v.size(); i++)
        origin.push_back(v[i]);

    for(int i = 0; i < origin.size(); i++)
        count[digit16(origin[i].first,d)] += 1;

    for(int i = 1; i < 16; i++)
        count[i] += count[i-1];

    for(int i = origin.size() - 1; i >= 0; i--)
    {
        v[count[digit16(origin[i].first,d)] - 1] = origin[i];
        count[digit16(origin[i].first,d)] -= 1;
    }    
}