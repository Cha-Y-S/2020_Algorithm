#include <string>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

void FindMaxCrossingSubarray(vector<int> &arr, int &low, int mid ,int &high, int &sum);
void FindMaxSubarray(vector<int> &arr, int &low, int &high, int &sum);
int solution(vector<int> arr);

int solution(vector<int> arr)
{
    int left = 0; int right = arr.size() - 1; int sum = 0;
    FindMaxSubarray(arr, left, right, sum);

    return sum;
}

void FindMaxSubarray(vector<int> &arr, int &low, int &high, int &sum)
{
    if (high == low)
    {
        sum = arr[low];
        return;
    }
    else
    {
        int mid = (low + high) / 2;
        int Llow = low;  int Lhigh = mid;  int Lsum = 0;
        int Rlow = mid + 1;  int Rhigh = high;  int Rsum = 0;
        int Clow = low;  int Chigh = high; int Csum = 0;
        FindMaxSubarray(arr, Llow, Lhigh, Lsum);
        FindMaxSubarray(arr, Rlow, Rhigh, Rsum);
        FindMaxCrossingSubarray(arr, Clow, mid, Chigh, Csum);
        if ((Lsum >= Rsum) && (Lsum >= Csum))
        {
            low = Llow;
            high = Lhigh;
            sum = Lsum;
            return;            
        }
        else if((Rsum >= Lsum) && (Rsum >= Csum))
        {
            low = Rlow;
            high = Rhigh;
            sum = Rsum;
            return;
        }
        else
        {
            low = Clow;
            high = Chigh;
            sum = Csum;
        }
    }    
}

void FindMaxCrossingSubarray(vector<int> &arr, int &low, int mid, int &high, int &sum)
{
    int Lsum = INT_MIN;
    int temp = 0;
    int i_limit = low;
    for(int i = mid; i > i_limit - 1; i--)
    {
        temp += arr[i];
        if (temp > Lsum)
        {
            Lsum = temp;
            low = i;
        }
    }

    int Rsum = INT_MIN;
    temp = 0;
    int j_limit = high;
    for(int j = mid + 1; j < j_limit + 1; j++)
    {
        temp += arr[j];
        if(temp > Rsum)
        {
            Rsum = temp;
            high = j;
        }
    }
    sum = Lsum + Rsum;    
}