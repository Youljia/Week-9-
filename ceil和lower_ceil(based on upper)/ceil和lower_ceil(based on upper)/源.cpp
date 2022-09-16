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
	}
	~Solution()
	{
		cout << "This arra is releasing... ..." << endl;
		if (arra != nullptr)
			delete[] arra;
		arra = nullptr;
		len = NULL;
	}

	//upper���Ҵ���target����Сֵ����С����
	int upper(double target)
	{
		int l = 0;
		int r = this->len;
		while (l < r)
		{
			int mid = l + ((r - l) / 2);
			if (arra[mid] > target)
				r = mid;
			else
				l = mid + 1;
		}
		return l;
	}

	//��Ԫ�ش��ڣ����ظ�Ԫ�ص��������
	//�������ڣ��򷵻ش��ڸ�Ԫ�ص���Сֵ����С����
	int ceil(double target)
	{
		int i = upper(target);
		if (i != 0 && arra[i - 1] == target)
			return i - 1;
		else
			return i;
	}

	//��Ԫ�ش��ڣ����ظ�Ԫ�ص���С����
	//��Ԫ�ز����ڣ����ش��ڸ�Ԫ����Сֵ����С����
	int lower_ceil(double target)
	{
		int i = upper(target);
		if (i != 0 && arra[i - 1] == target)
		{
			while (arra[i - 1] == target)
			{
				i--;
				if (i == 0)
					return i;
			}
			return i;
		}
		else
			return i;
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
	//�ݹ����
	//����:��[l,r]��������
	void quick_sort(int l, int r)
	{
		if (l >= r)
			return;
		//Ϊ������������
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
	//����
	void temp(int& i, int& j)
	{
		int temp = i;
		i = j;
		j = temp;
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
	int i = s.upper(5.5);
	cout << i << endl;
	cout << s.arra[i] << endl;

	i = s.ceil(7);
	cout << i << endl;
	cout << s.arra[i] << endl;

	i = s.lower_ceil(7);
	cout << i << endl;
	cout << s.arra[i] << endl;

	i = s.lower_ceil(5.5);
	cout << i << endl;
	cout << s.arra[i] << endl;

	i = s.ceil(5.5);
	cout << i << endl;
	cout << s.arra[i] << endl;
	return 0;
}