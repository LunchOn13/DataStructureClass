#include<iostream>
#include<string>
#pragma warning
using namespace std;

class SLinkedList;
class stack {

public:
	stack();	// ������
	~stack();	// �Ҹ���
	void push(char e);	// ���ÿ� push
	void pop();			// ���ÿ��� pop
	char top();			// ���� �� ���� �� ����
	bool isEmpty();		// ������ ����ִ°�
	int size();			// ���� ������ ����
	void refreshStack();	// ���� refresh
private:
	SLinkedList *s;
	int n;	// size	
};


class Node; // A : ���� �ڵ� C4430 ������ �Ͻ�
class SLinkedList {
public:
	SLinkedList();		// ������
	~SLinkedList();		// �Ҹ���
	bool empty() const;	// ����ִ� ����Ʈ�ΰ�
	const Node& front() const;	// head ��ȯ
	void addFront(const char &a);	// �տ� node ����
	void removeFront();		// �� ��带 �����
private:
	Node *head;

	friend class stack;
};

class Node {
public:
	Node();
	char getEle() const;		// ele �޾ƿ´�
	Node getNext() const;		// ���� node ��ȯ
private:
	char ele;
	Node * next;

	friend class SLinkedList;
};



SLinkedList::SLinkedList() : head(NULL)		// ������
{

}

SLinkedList::~SLinkedList()		// �Ҹ���
{
	while (!empty())
	{
		removeFront();
	}
}

bool SLinkedList::empty() const		// head�� ��������� true 
{
	return head == NULL;
}

const Node & SLinkedList::front() const	// head �� �Ҵ�Ǿ� �ִ� node ��ȯ
{
	return *head;
}

void SLinkedList::addFront(const char & s)	// �տ� node �ϳ� ����
{
	Node * a = new Node;
	a->ele = s;
	a->next = head;
	head = a;
}

void SLinkedList::removeFront()	// ���� node ����
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
	bool fail = false;	// stack�� ����������� pop �Ϸ��� �Ҷ�, �� html �±װ� �̹� Ȯ���� Ʋ�� ���� �˶�
	cin >> testcase;
	cin.get(tmp);	// testcase ������ ���๮�� �ޱ�

	bool isSlash = false;

	while (testcase != 0)
	{
		stack myStack;

		while (cin.get(tmp))
		{
			// ���� ���� �ν�
			if (tmp == '\n')
				break;

			// ���� ���� ó��
			if (tmp == ' ')
			{
				tmp = NULL;
				continue;
			}

			// �ݴ� ���� �ν�
			if (tmp == '>')
			{
				isSlash = false;

				// ������ �̹� ����ִ� ���¿��� �ݴ� ���踦 ������ Ȯ���� �±װ� �߸���
				if (myStack.isEmpty())
					fail = true;

				// fail �� true �̸� pop ��Ű�� ����
				if (fail == false)
					myStack.pop();
			}
			// �������� ������ , �ݴ� �±׸� �ν�
			else if (!isSlash)
			{
				// ���ÿ� ����ִ� body �� li, hl ���� ���ֱ�
				if (tmp == '/')
				{
					isSlash = true;
					tmp = NULL;
					continue;
				}
				else
				{
					// ���ÿ� ���� ���� push
					myStack.push(tmp);
				}
			}
			// �������� ���� ���� > �� �ޱ� ������ ���ÿ��� ����ؼ� ����
			else
			{
				// �̹� ������ ��� �־� Ȯ���� Ʋ����Ȳ
				if (myStack.isEmpty())
				{
					fail = true;
				}
				// ���ÿ��� ������
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