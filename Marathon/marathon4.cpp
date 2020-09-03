#include <unordered_set>
#include <algorithm>
#include "marathon.h"

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    unordered_multiset<string> s;
    for(auto it = completion.begin(); it != completion.end(); it++)
        s.insert(*it);
    
    for(auto it = participant.begin(); it != participant.end(); it++)
    {
        answer = *it;
        auto found = s.find(answer);
        if(found == s.end())    break;
        else                    s.erase(found);
               
    }
    return answer;
}