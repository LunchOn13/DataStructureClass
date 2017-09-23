#include<iostream>
#include<string>

#pragma warning
using namespace std;

class Node; // A : 오류 코드 C4430 때문에 암시
class SLinkedList {
public:
	SLinkedList();		// 생성자
	~SLinkedList();		// 소멸자
	bool empty() const;	// 비어있는 리스트인가
	const Node& front() const;	// head 반환
	void addFront(const string &a, const int &i);	// 앞에 node 삽입
	void removeFront();		// 앞 노드를 지운다
	void printAll() const;	// 리스트에 있는 모든 node 에 대한 elelment를 출력
private:
	Node *head;
};

class Node {
public:
	string getName() const;		// name 받아온다
	int getScore() const;		// score 받아온다
	void printElement() const;	// name score 출력
	Node getNext() const;		// 다음 node 반환
private:
	string name;
	int score;
	Node * next;

	friend class SLinkedList;
};



SLinkedList::SLinkedList() : head(NULL)		// 생성자
{

}

SLinkedList::~SLinkedList()		// 소멸자
{
	while (!empty())
	{
		removeFront();
	}
}

bool SLinkedList::empty() const		// head가 비어있으면 true 
{
	return head == NULL;
}

const Node & SLinkedList::front() const	// head 에 할당되어 있는 node 반환
{
	return *head;
}

void SLinkedList::printAll() const	// 리스트 안의 모든 node의 element 를 출력
{
	Node tmp = this->front();	// 계속해서 바뀔 node를 받아둘곳
	tmp.printElement();			// tmp에 받아온 head의 element 출력
	
	while (tmp.next != NULL)	// tmp의 다음 node가 있다면
	{
		tmp.getNext().printElement();	// tmp 다음 node 의 element 출력
		tmp = tmp.getNext();	// tmp 에 원래 tmp의 다음 node 를 할당
	}
	cout << endl;
}

void SLinkedList::addFront(const string & s, const int & i)	// 앞에 node 하나 삽입
{
	Node * a = new Node;
	a->name = s;
	a->score = i;
	a->next = head;
	head = a;
}

void SLinkedList::removeFront()	// 앞의 node 삭제
{
	Node * old = head;
	head = old->next;
	delete old;
}

string Node::getName() const
{
	return name;
}

int Node::getScore() const
{
	return score;
}

void Node::printElement() const	// 해당 node 의 name 과 score 출력
{
	cout << "(" << this->getName() << ", " << this->getScore() << ") ";
}

Node Node::getNext() const
{
	return *next;
}


int main()
{
	// 교수님이 주신 query.cpp
	SLinkedList a;

	char ch;
	string name;
	int score;

	cin >> ch;

	while (ch != 'X') {
		switch (ch) {
		case 'I':
			cin >> name >> score;
			a.addFront(name, score);
			break;
		case 'R':
			// Implement Remove Front
			if (!a.empty())
				a.removeFront();
			else
				cout << "Invalid Removal\n";
			break;
		case 'E':
			// Implement Empty
			if (a.empty())
				cout << "T\n";
			else
				cout << "F\n";
			break;
		case 'H':
			// Implement Head
			if (!a.empty())
			{
				a.front().printElement();
				cout << endl;
			}
			else
				cout << "Empty List\n";
			break;
		case 'T':
			// Implement Traverse List
			if (!a.empty())
				a.printAll();
			else
				cout << "Empty List\n";
			break;
		default:
			cout << "Wrong Input" << endl;
			break;
		}

		cin >> ch;

	}
}
