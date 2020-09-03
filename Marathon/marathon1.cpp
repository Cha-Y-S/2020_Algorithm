#include <algorithm>
#include "marathon.h"

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    for(int i = 0; i < participant.size(); i++)
    {
        answer = participant[i];
        auto it = find(completion.begin(), completion.end(), answer);
        if(it == completion.end()) break;
        else    completion.erase(it);
    }
    return answer;
} 