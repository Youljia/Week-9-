#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> v{ 1,2,3,4,5,6,7,7 };
	//求容器元素和
	int sum = accumulate(v.begin(), v.end(),0);
	cout << sum << endl;
	//求容器中的最大元素和最小元素
	int max = *max_element(v.begin(), v.end());
	int min = *min_element(v.begin(), v.end());
	cout << max << endl;
	cout << min << endl;
	return 0;
}