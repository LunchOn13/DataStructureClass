#include<iostream>
#include<string>
#pragma warning
using namespace std;

class SLinkedList;
class stack {

public:
	stack();	// 생성자
	~stack();	// 소멸자
	void push(char e);	// 스택에 push
	void pop();			// 스택에서 pop
	char top();			// 스택 맨 위의 값 리턴
	bool isEmpty();		// 스택이 비어있는가
	int size();			// 스택 사이즈 리턴
	void refreshStack();	// 스택 refresh
private:
	SLinkedList *s;
	int n;	// size	
};


class Node; // A : 오류 코드 C4430 때문에 암시
class SLinkedList {
public:
	SLinkedList();		// 생성자
	~SLinkedList();		// 소멸자
	bool empty() const;	// 비어있는 리스트인가
	const Node& front() const;	// head 반환
	void addFront(const char &a);	// 앞에 node 삽입
	void removeFront();		// 앞 노드를 지운다
private:
	Node *head;

	friend class stack;
};

class Node {
public:
	Node();
	char getEle() const;		// ele 받아온다
	Node getNext() const;		// 다음 node 반환
private:
	char ele;
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

void SLinkedList::addFront(const char & s)	// 앞에 node 하나 삽입
{
	Node * a = new Node;
	a->ele = s;
	a->next = head;
	head = a;
}

void SLinkedList::removeFront()	// 앞의 node 삭제
{
	Node * old = head;
	head = old->next;
	delete old;
}

Node::Node()
{
	ele = NULL;
	next = NULL;
}

char Node::getEle() const
{
	return ele;
}

Node Node::getNext() const
{
	return *next;
}

stack::stack() : n(0)
{
	s = new SLinkedList();
}

stack::~stack()
{
	delete s;
}

void stack::push(char e)
{
	s->addFront(e);
	n++;
}

void stack::pop()
{
	if (this->isEmpty())
		throw exception("Empty Stack");
	s->removeFront();
	n--;
}

char stack::top()
{
	if (this->isEmpty())
		throw exception("Empty Stack");
	return s->head->getEle();
}

bool stack::isEmpty()
{
	return s->empty();
}

int stack::size()
{
	return n;
}

void stack::refreshStack()
{
	delete s;
	s = new SLinkedList();
}

int main()
{
	int testcase;
	char tmp;
	bool fail = false;	// stack이 비어있음에도 pop 하려고 할때, 즉 html 태그가 이미 확실히 틀린 것을 알때
	cin >> testcase;
	cin.get(tmp);	// testcase 이후의 개행문자 받기

	bool isSlash = false;

	while (testcase != 0)
	{
		stack myStack;

		while (cin.get(tmp))
		{
			// 개행 문자 인식
			if (tmp == '\n')
				break;

			// 공백 예외 처리
			if (tmp == ' ')
			{
				tmp = NULL;
				continue;
			}

			// 닫는 꺽쇠 인식
			if (tmp == '>')
			{
				isSlash = false;

				// 스택이 이미 비어있는 상태에서 닫는 꺽쇠를 받으면 확실히 태그가 잘못됨
				if (myStack.isEmpty())
					fail = true;

				// fail 이 true 이면 pop 시키지 않음
				if (fail == false)
					myStack.pop();
			}
			// 슬래쉬를 받으면 , 닫는 태그를 인식
			else if (!isSlash)
			{
				// 스택에 들어있는 body 나 li, hl 들을 없애기
				if (tmp == '/')
				{
					isSlash = true;
					tmp = NULL;
					continue;
				}
				else
				{
					// 스택에 받은 것을 push
					myStack.push(tmp);
				}
			}
			// 슬래쉬를 받은 이후 > 를 받기 전까지 스택에서 계속해서 빼냄
			else
			{
				// 이미 스택이 비어 있어 확실히 틀린상황
				if (myStack.isEmpty())
				{
					fail = true;
				}
				// 스택에서 빼낸다
				if (fail == false)
					myStack.pop();
			}
			tmp = NULL;
		}
		if (myStack.isEmpty() && fail == false)
			cout << "Correct\n";
		else
		{
			cout << "Incorrect\n";
			fail = false;
		}
		myStack.refreshStack();
		testcase--;
	}

}