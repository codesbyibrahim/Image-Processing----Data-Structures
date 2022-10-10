#pragma once
#include"Dice Coefficients.h"
using namespace std;
class node {
public:
	int data;
	node* next;
	node(int data = 0, node* temp = NULL)
	{
		this->data = data;
		next = temp;
	}
};
class linkedList
{
public:
	node* head;
	linkedList* next;
	linkedList()
	{
		head = NULL;
		next = NULL;
	}
	void insertAtTail(int val)
	{
		if (!head)
		{
			head = new node(val);
			return;
		}
		node* temp = head;
		while (temp->next)
			temp = temp->next;
		temp->next = new node(val);
	}
	void insertLinkedList()
	{
		next = new linkedList;
	}
};
void FillRow(linkedList* ptr, unsigned char* image, int len)
{
	if (*image)
		ptr->insertAtTail(0);
	for (int i = 1; i < len; i++)
	{
		if (image[i] != image[i - 1])
		{
			if (image[i] == 255)
				ptr->insertAtTail(i);
			else
				ptr->insertAtTail(i - 1);
		}
	}
	ptr->insertAtTail(-1);
}
void RunLengthCode(linkedList& RLC, unsigned char** image, int r, int c)
{
	RLC.insertAtTail(r);
	RLC.insertAtTail(c);
	RLC.insertLinkedList();
	linkedList* ptr = RLC.next;
	for (int i = 0; i < r; i++)
	{
		FillRow(ptr, *(image + i), c);
		ptr->insertLinkedList();
		ptr = ptr->next;
	}
}
void printRow(node* head)
{
	node* temp = head;
	while (temp)
	{
		cout << temp->data << "  ";
		temp = temp->next;
	}
}
void printLists(linkedList lists)
{
	linkedList* ptr = &lists;
	while (ptr)
	{
		printRow(ptr->head);
		cout << "\n\n\n";
		ptr = ptr->next;
	}
}
void task4(string filename)
{
	int r, c;
	unsigned char** image = ReadMatrix(r, c, 4, filename);
	linkedList RLC;
	RunLengthCode(RLC, image, r, c);
	printLists(RLC);
}

