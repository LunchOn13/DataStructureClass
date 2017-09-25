#include<iostream>
#include<string>
#include<vector>
#pragma warning
using namespace std;

class SLinkedList;
class stack {

public:
	stack();	// ������
	~stack();	// �Ҹ���
	void push(const string& s);	// ���ÿ� push
	void pop();			// ���ÿ��� pop
	string top();	const		// ���� �� ���� �� ����
	const bool isEmpty();		// ������ ����ִ°�
	int size();			// ���� ������ ����
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
	void addFront(const string &a);	// �տ� node ����
	void removeFront();		// �� ��带 �����
private:
	Node *head;

	friend class stack;
};

class Node {
public:
	Node();
	string getEle() const;		// ele �޾ƿ´�
	Node getNext() const;		// ���� node ��ȯ
private:
	string ele;
	Node * next;

	friend class SLinkedList;
};

// html tag���� �޾ƿ��� �Լ�
vector<string> getHtmlTags() {
	vector<string> tags;
		string line; 
		getline(cin, line);
		int pos = 0;
		int ts = line.find("<", pos);
		// ������ html tag �и�
		while (ts != string::npos)
		{
			int te = line.find(">", ts + 1);
			tags.push_back(line.substr(ts, te - ts + 1));
			pos = te + 1;
			ts = line.find("<",pos);
		}
	return tags;
}

// ������ html tag�� ������ tag�� ¦������ �Ǿ��ִ��� Ȯ��
bool isHtmlMatched(const vector<string> & tags)
{
	// tag���� �־�� ����
	stack S;
	typedef vector <string> ::const_iterator Iter;

	// < ~ > ����
	for (Iter p = tags.begin(); p != tags.end(); ++p)
	{
		// / �� ������ ���ÿ� ����
		if (p->at(1) != '/')
			S.push(*p);
		
		// / �� ������
		else
		{
			// ���� ��� ������ html ������ �ƴ�
			if (S.isEmpty())
				return false;
		
			// �±װ� ¦������ ���� ������ ������ �ƴ�
			string open = S.top().substr(1);
			string close = p->substr(2);
			if (open.compare(close) != 0)
				return false;

			// ������ ���
			else S.pop();
		}
	}
	// ������ ��� ��� html ��ü �±׻��°� ������
	if (S.isEmpty())
		return true;
	// �±� ���°� ������ �ƴ�
	else
		return false;
}


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

void SLinkedList::addFront(const string & s)	// �տ� node �ϳ� ����
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
}

string Node::getEle() const
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

void stack::push(const string& e)
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

string stack::top()
{
	if (this->isEmpty())
		throw exception("Empty Stack");
	return s->head->getEle();
}

const bool stack::isEmpty()
{
	if (n == 0)
		return true;
	return false;
}

int stack::size()
{
	return n;
}

int main()
{
	int testcase;
	char tmp;
	cin >> testcase;
	cin.get(tmp);
	while (testcase != 0)
	{
		if (isHtmlMatched(getHtmlTags()))
		{
			cout << "Correct" << endl;
		}
		else
		{
			cout << "Incorrect" << endl;
		}
		testcase--;
	}
}
