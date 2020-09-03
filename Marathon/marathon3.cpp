#include <list>
#include "marathon.h"

const int H_SZ = 10000;
string solution(vector<string> participant, vector<string> completion)
{
    hash<string> h;
    list<string> e;
    vector<list<string>> t(H_SZ, e);

    string answer = "";
    for(auto it = completion.begin(); it != completion.end(); it++)
    {
        size_t i = h(*it) % H_SZ;
        t[i].push_back(*it);
    }
    for(auto it = participant.begin(); it != participant.end(); it++)
    {
        size_t i = h(*it) % H_SZ;
        bool found = false;
        answer = *it;
        for(auto it2 = t[i].begin(); it2 != t[i].end(); it2++)
        {
            if(*it2 == *it){ found = true; t[i].erase(it2); break; }
        }
        if(!found) break;
    }
    return answer;
}