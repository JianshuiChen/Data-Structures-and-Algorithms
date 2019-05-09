// TitleProject_Cpp.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 707_�������
/*
��������ʵ�֡�������ѡ��ʹ�õ������˫�����������еĽڵ�Ӧ�þ����������ԣ�val �� next��val �ǵ�ǰ�ڵ��ֵ��next ��ָ����һ���ڵ��ָ��/���á����Ҫʹ��˫����������Ҫһ������ prev ��ָʾ�����е���һ���ڵ㡣���������е����нڵ㶼�� 0-index �ġ�
����������ʵ����Щ���ܣ�
get(index)����ȡ�����е� index ���ڵ��ֵ�����������Ч���򷵻�-1��
addAtHead(val)��������ĵ�һ��Ԫ��֮ǰ���һ��ֵΪ val �Ľڵ㡣������½ڵ㽫��Ϊ����ĵ�һ���ڵ㡣
addAtTail(val)����ֵΪ val �Ľڵ�׷�ӵ���������һ��Ԫ�ء�
addAtIndex(index,val)���������еĵ� index ���ڵ�֮ǰ���ֵΪ val  �Ľڵ㡣��� index ��������ĳ��ȣ���ýڵ㽫���ӵ������ĩβ����� index ���������ȣ��򲻻����ڵ㡣
deleteAtIndex(index)��������� index ��Ч����ɾ�������еĵ� index ���ڵ㡣
ʾ����
MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1,2);   //�����Ϊ1-> 2-> 3
linkedList.get(1);            //����2
linkedList.deleteAtIndex(1);  //����������1-> 3
linkedList.get(1);            //����3
��ʾ��
����ֵ���� [1, 1000] ֮�ڡ�
������������  [1, 1000] ֮�ڡ�
�벻Ҫʹ�����õ� LinkedList �⡣
*/
// 52ms(85.8%), 19.2MB(99.8%)
class MyLinkedList {

	class Node
	{
	public:
		Node(int val) {
			this->val = val;
			next = nullptr;
		}
		int val;
		Node* next;
	};

public:
	/** Initialize your data structure here. */
	MyLinkedList() {
		head = nullptr;
		count = 0;
	}

	Node* head;
	int count;

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		if (index < 0 || index >= count) return -1;

		Node * cur = head;
		for (size_t i = 0; i < index; i++)
		{
			cur = cur->next;
		}
		return cur->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		Node* res = new Node(val);
		res->next = head;
		head = res;
		count++;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		if (head == nullptr)
		{
			head = new Node(val);
			return;
		}
		Node* cur = head;
		while (cur->next != nullptr)
		{
			cur = cur->next;
		}
		cur->next = new Node(val);
		count++;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	// ����������, ���index<0, Ĭ����0
	void addAtIndex(int index, int val) {
		if (index > count) return;
		else if (index <= 0)
		{
			addAtHead(val);
			return;
		}
		else if (index == count)
		{
			addAtTail(val);
			return;
		}

		Node* cur = head;
		for (size_t i = 0; i < index - 1; i++)
		{
			cur = cur->next;
		}
		Node* tmp = cur->next;
		cur->next = new Node(val);
		cur->next->next = tmp;
		count++;
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (index < 0 || index >= count) return;
		else if (index == 0)
		{
			head = head->next;
			return;
		}

		Node* cur = head;
		for (size_t i = 0; i < index - 1; i++)
		{
			cur = cur->next;
		}
		cur->next = cur->next->next;
		count--;
	}
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
#pragma endregion

int main()
{

}

