#include "FindMaxSubArray.cpp"

int main()
{
    //int aa[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    int aa[] = {21, 3, -5, 45, -66, -75, -95};

    vector<int> a(aa, aa+7);

    int answer = solution(a);

    cout << answer << endl;
}