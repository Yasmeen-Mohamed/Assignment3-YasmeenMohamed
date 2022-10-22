#include <iostream>
using namespace std;

struct Node
{
	int data;
	int occ = 1;
	Node* next;
};

class LinkedList
{
public:
	Node* head;

	LinkedList()
	{
		head = NULL;
	}

	void addNode(int n)
	{
		Node* p = new Node;
		Node* temp = head;
		if (head == NULL)
		{
			p->data = n;
			p->next = NULL;
			head = p;
		}
		else
		{
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			Node* p = new Node;
			p->data = n;
			temp->next = p;
			p->next = NULL;
		}
	}

	void removeNode(int n)
	{
		Node* delptr = head;
		if (head->data == n)
		{
			head=head->next;
			delete delptr;
		}
		else
		{
			Node* prev = NULL;
			delptr = head;
			while (delptr->data != n)
			{
				prev = delptr;
				delptr = delptr->next;
			}
			prev->next = delptr->next;
			delete delptr;
		}
	}

	void printAll()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	bool isFound(int n)
	{
		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->data == n)
			{
				temp->occ++;
				return true;
			}
			temp = temp->next;
		}
		return false;
	}

	int sum()
	{
		Node* temp = head;
		int total = 0;
		while (temp != NULL)
		{
			total = total + temp->data;
			temp = temp->next;
		}
		return total;
	}
};