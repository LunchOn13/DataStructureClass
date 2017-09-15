// 자료구조.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <iostream>
#include <string>
using namespace std;


struct SLinkedList
{
public:
	SLinkedList();
	~SLinkedList();
	bool isEmpty() const;
	Node & front() const;
	void addFront(string name , int score);
	void removeFront();
private:
	Node* head;
};


struct Node
{
public:
	string getName();
	int getScore();
	void printElement();
	Node *getNext();
private:
	string name;
	int score;
	Node *next;
	friend struct SLinkedList;
};


SLinkedList::SLinkedList()	// 생성자
{
}


SLinkedList::~SLinkedList()	// 소멸자
{
	while (!isEmpty())
	{
		removeFront();
	}
}


bool SLinkedList::isEmpty() const	// 비어있는가?
{
	return head == NULL;
}


Node & SLinkedList::front() const		// 앞 부분 반환
{
	return *head;	// todo : 뭘 반환해야 할 지 아직 모르겠음
}


void SLinkedList::addFront(string name , int score)	// 앞에 추가
{
	Node * node = new Node;
	node->name = name;	
	node->score = score;
	node->next = head;
	head = node;
}


void SLinkedList::removeFront()	// 앞을 삭제
{
	Node * before = head;
	head = before->next;
	delete before;
}

int main()
{
	SLinkedList a;

	char ch;
	string name;
	int score;

	cin >> ch;
	while (ch != 'X') {
		switch (ch) {
		case 'I':
			// Implement Insert Data
			cin >> name >> score;
			a.addFront(name, score);
			break;
		case 'R':
			// Implement Remove Front
			if (a.isEmpty())
			{
				// head 가 비어있다면
				cout << "Invalid Removal\n";
			}
			else
			{
				// head 가 비어 있지 않다면 삭제
				a.removeFront();
			}
			break;
		case 'E':
			// Implement Empty
			if (a.isEmpty())
			{
				cout << "T\n";
			}
			else
			{
				cout << "F\n";
			}

			break;
		case 'H':
			// Implement Head
			if (a.isEmpty())
			{
				cout << "Empty List\n";
			}
			else
			{
				a.front().printElement();
			}
			break;
		case 'T':
			// Implement Traverse List
			if (a.isEmpty())
			{
				cout << "Empty List\n";
			}
			else
			{
				Node old = a.front();
				while ()
				{

				}
				
			}
			break;
		default:
			cout << "Wrong Input" << endl;
			break;
		}

		cin >> ch;

	}
}

string Node::getName()
{
	return this->name;
}

int Node::getScore()
{
	return this->score;
}

void Node::printElement()
{
	cout << this->getName() << " " << this->getScore();
}

Node * Node::getNext()
{
	return this->next;
}
