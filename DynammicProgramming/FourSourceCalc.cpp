#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>

using namespace std;

int solution(vector<string> arr)
{
    int max_arr[200][200];
    int min_arr[200][200];
	int answer = 1;
	int num = arr.size() / 2 + 1;
	memset(max_arr, -1000000, 40000);
	memset(min_arr, 1000000, 40000);

	for (int i = 0; i < num; i++) {
		max_arr[i][i] = atoi(arr[i * 2].c_str());
		min_arr[i][i] = atoi(arr[i * 2].c_str());
	}

	for (int result = 1; result < num; result++) {
		for (int i = 0; i < num - result; i++) {
			int j = result + i;
			for (int k = i; k < j; k++) {
				if (arr[k * 2 + 1] == "-") {
					max_arr[i][j] = max(max_arr[i][k] - min_arr[k + 1][j], max_arr[i][j]);
					min_arr[i][j] = min(min_arr[i][k] - max_arr[k + 1][j], min_arr[i][j]);
				}
				else if (arr[k * 2 + 1] == "+") {
					max_arr[i][j] = max(max_arr[i][k] + max_arr[k + 1][j], max_arr[i][j]);
					min_arr[i][j] = min(min_arr[i][k] + min_arr[k + 1][j], min_arr[i][j]);
				}
			}
		}

	}
	answer = max_arr[0][num - 1];
	return answer;
}