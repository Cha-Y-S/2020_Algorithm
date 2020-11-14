#include <iostream>
#include "AssignmentMeetingRoom.cpp"

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        return -1;
    }
    vector<vector<int>> v;
    vector<int> tmp1;
    vector<int> tmp2;
    vector<int> tmp3;
    
    if(atoi(argv[1]) == 1)
    {
        tmp1.push_back(1);
        tmp1.push_back(2);
        tmp2.push_back(2);
        tmp2.push_back(4);
        tmp3.push_back(2);
        tmp3.push_back(2);
        v.push_back(tmp1);
        v.push_back(tmp2);
        v.push_back(tmp3);
    }
    else if(atoi(argv[1]) == 2)
    {
        tmp1.push_back(1);
        tmp1.push_back(4);
        tmp2.push_back(3);
        tmp2.push_back(5);
        tmp3.push_back(0);
        tmp3.push_back(6);
        vector<int> tmp4;
        vector<int> tmp5;
        vector<int> tmp6;
        vector<int> tmp7;
        vector<int> tmp8;
        vector<int> tmp9;
        vector<int> tmp10;
        vector<int> tmp11;
        tmp4.push_back(5);
        tmp4.push_back(7);
        tmp5.push_back(3);
        tmp5.push_back(9);
        tmp6.push_back(5);
        tmp6.push_back(9);
        tmp7.push_back(6);
        tmp7.push_back(10);
        tmp8.push_back(8);
        tmp8.push_back(11);
        tmp9.push_back(8);
        tmp9.push_back(12);
        tmp10.push_back(2);
        tmp10.push_back(14);
        tmp11.push_back(12);
        tmp11.push_back(16);
        v.push_back(tmp1);
        v.push_back(tmp2);
        v.push_back(tmp3);
        v.push_back(tmp4);
        v.push_back(tmp5);
        v.push_back(tmp6);
        v.push_back(tmp7);
        v.push_back(tmp8);
        v.push_back(tmp9);
        v.push_back(tmp10);
        v.push_back(tmp11);       
    }
    else    
    {
        tmp1.push_back(1);
        tmp1.push_back(4);
        tmp2.push_back(2);
        tmp2.push_back(6);
        tmp3.push_back(4);
        tmp3.push_back(7);
        v.push_back(tmp1);
        v.push_back(tmp2);
        v.push_back(tmp3);
    }

    cout << solution(v) << endl;
    
    return 0;
}