#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		
		








	}

	double findMedian(vector<int>& n1,vector<int>& n2)   
	{
		if (n1.size() ==1 && n2.size() == 1)
		{
			return ((median(n1) + median(n2)) / 2);
		}
		if (n1.size() == 1)
		{
			n2.pop_back();
			return median(n2);
		}
		if (n2.size() == 1)
		{
			n1.pop_back();
			return median(n1);
		}

		double m1 = median(n1);
		double m2 = median(n2);

		if (m2 < m1)
		{
			vector<int>& temp = n1;
			n1 = n2;
			n2 = temp;

		}
		vector<int>::iterator first = n1.begin() + n1.size() / 2;
		vector<int>::iterator end = n1.end();
		vector<int> v1(first, end);
	
		first = n2.begin();
		end = n2.begin() + n2.size() / 2;
		vector<int> v2(first, end);
		
		return findMedian(v1, v2);

	}

	double median(vector<int>& n)
	{
		int size = n.size();
		if (size % 2 == 1)
			return n[size / 2];
		else
			return ((double)n[size / 2 - 1] + (double)n[size / 2]) / 2;
	}
			
};

void print(vector<int>& n)
{
	for (auto it = n.begin(); it != n.end(); it++)
		cout<<(*it)<<ends;
	cout << endl;
}


/*
int main()
{
	vector<int> n1, n2;
	n1.push_back(1);
	n1.push_back(3);
	n2.push_back(2);
	//n2.push_back(4);
	
	Solution solution;
	cout << solution.median(n1) << endl;
	cout << solution.median(n2) << endl;
	cout << solution.findMedianSortedArrays(n1, n2);
}

*/