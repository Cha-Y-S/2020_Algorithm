#include "marathon.h"

string solution(vector<string> participant, vector<string> completion);

int main()
{
    // string _p[] = {"mislav", "stanko", "mislav", "ana"};
    // string _c[] = {"stanko", "ana", "mislav"};
    vector<string> p,c;
    int n; string s;
    cout << "Enter N: ";
    cin >> n;
    cout << "-----participant-----" << endl;
    for (int i = 0; i < n; i++) { cin >> s; p.push_back(s);}
    cout << "-----completion-----" << endl;
    for (int i = 1; i < n; i++) { cin >> s; c.push_back(s);}

    string answer = solution(p, c);
    cout <<"----answer----"<<endl;
    cout << answer << endl;

    return 0;
}