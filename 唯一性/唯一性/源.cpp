#include<iostream>
using namespace std;

#include<iostream>
using namespace std;

class Solution
{
public:
	Solution(int* p, int l)
	{
		arra = new int[l];
		this->len = l;
		for (int i = 0; i < l; ++i)
			this->arra[i] = p[i];
		sort();
		unique();
	}
	~Solution()
	{
		cout << "This arra is releasing... ..." << endl;
		if (arra != nullptr)
			delete[] arra;
		arra = nullptr;
		len = NULL;
	}

	void sort()
	{
		quick_sort(0, len - 1);
	}
	void show()
	{
		cout << "[ ";
		for (int i = 0; i < len; ++i)
		{
			cout << arra[i];
			if (i != len - 1)
				cout << ",";
		}
		cout << " ]" << endl;
	}
private:
	//递归调用
	//意义:对[l,r]进行排序
	void quick_sort(int l, int r)
	{
		if (l >= r)
			return;
		//为区间添加随机性
		int q = rand() % (r - l + 1);
		temp(arra[l], arra[l + q]);
		int p = partition(l, r);
		quick_sort(l, p - 1);
		quick_sort(p + 1, r);
	}
	int partition(int l, int r)
	{
		int j = l;
		int e = l + 1;
		for (e; e <= r; ++e)
		{
			if (arra[e] < arra[l])
			{
				j++;
				temp(arra[j], arra[e]);
			}
		}
		temp(arra[l], arra[j]);
		return j;
	}
	//互换
	void temp(int& i, int& j)
	{
		int temp = i;
		i = j;
		j = temp;
	}
	//去除数组中重复的元素
	//保证数组的唯一性
	void unique()
	{
		int i = 0;
		int j = i + 1;
		while (j < this->len)
		{
			if (arra[i] == arra[j])
				++j;
			else
			{
				i++;
				temp(arra[i], arra[j]);
				j++;
			}
		}
		this->len = i + 1;
	}
public:
	int* arra;
	int len;
};

int main()
{
	int p[10] = { 2,3,4,5,6,7,7,8,9,10 };
	Solution s(p, 10);
	s.show();
	return 0;
}