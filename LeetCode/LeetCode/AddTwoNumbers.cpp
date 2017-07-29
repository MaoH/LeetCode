#include<cstddef>
#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		bool overflow=false;
		ListNode *l,*p,*q,*m;
		p = l1;
		q = l2;
		l = NULL;
		m = NULL;
		while (p && q)
		{
			
			int sum = p->val + q->val;
			if (overflow)
				sum += 1;

			if (sum >= 10)
			{
				overflow = true;
				sum -= 10;
			}
			else
				overflow = false;

			ListNode* s = new ListNode(sum);
			if (!m)
				l = s;
			else
				m->next = s;
			m = s;
			p = p->next;
			q = q->next;
			
		}
		while(p)
		{
			int sum = p->val;
			if (overflow)
				sum += 1;

			if (sum >= 10)
			{
				sum -= 10;
				overflow = true;
			}
			else
			{
				overflow = false;
			}

			ListNode* s = new ListNode(sum);
			m->next = s;
			m = s;
			p = p->next;
		}
		while (q)
		{
			int sum = q->val;
			if (overflow)
				sum += 1;

			if (sum >= 10)
			{
				sum -= 10;
				overflow = true;
			}
			else
			{
				overflow = false;
			}

			ListNode* s = new ListNode(sum);
			m->next = s;
			m = s;
			q = q->next;
		}
		if (overflow)
			m->next = new ListNode(1);
		return l;

	}

	
};


//void  createList(ListNode* &L)
//{
//	ListNode* p = NULL;
//	for (int i = 0; i < 3; i++)
//	{
//		ListNode* s = new ListNode(i + 4);
//		if (p == NULL)
//		{
//			L = s;
//		}
//		else
//		{
//			p->next = s;
//		}
//		p = s;
//	}
//	
//}
//
//void  createList1(ListNode* &L)
//{
//	ListNode* p = NULL;
//	for (int i = 0; i < 2; i++)
//	{
//		ListNode* s = new ListNode(i + 4);
//		if (p == NULL)
//		{
//			L = s;
//		}
//		else
//		{
//			p->next = s;
//		}
//		p = s;
//	}
//
//}
//
//void print(ListNode* L)
//{
//	ListNode* p = L;
//	while (p)
//	{
//		cout << p->val << " ";
//		p = p->next;
//	}
//	cout << endl;
//}
//
//int main()
//{
//	ListNode* l1 = NULL;
//	ListNode* l2 = NULL;
//	createList1(l1);
//	createList(l2);
//	print(l1);
//	print(l2);
//	Solution solu;
//	ListNode* sum = solu.addTwoNumbers(l1, l2);
//	print(sum);
//
//}