#include<iostream>
#include<string>
#include<vector>
#pragma warning
using namespace std;

class SLinkedList;
class stack {

public:
	stack();	// 생성자
	~stack();	// 소멸자
	void push(const string& s);	// 스택에 push
	void pop();			// 스택에서 pop
	string top();	const		// 스택 맨 위의 값 리턴
	const bool isEmpty();		// 스택이 비어있는가
	int size();			// 스택 사이즈 리턴
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
	void addFront(const string &a);	// 앞에 node 삽입
	void removeFront();		// 앞 노드를 지운다
private:
	Node *head;

	friend class stack;
};

class Node {
public:
	Node();
	string getEle() const;		// ele 받아온다
	Node getNext() const;		// 다음 node 반환
private:
	string ele;
	Node * next;

	friend class SLinkedList;
};

// html tag들을 받아오는 함수
vector<string> getHtmlTags() {
	vector<string> tags;
		string line; 
		getline(cin, line);
		int pos = 0;
		int ts = line.find("<", pos);
		// 가져온 html tag 분리
		while (ts != string::npos)
		{
			int te = line.find(">", ts + 1);
			tags.push_back(line.substr(ts, te - ts + 1));
			pos = te + 1;
			ts = line.find("<",pos);
		}
	return tags;
}

// 가져온 html tag를 가지고 tag가 짝맞춤이 되어있는지 확인
bool isHtmlMatched(const vector<string> & tags)
{
	// tag들을 넣어둘 스택
	stack S;
	typedef vector <string> ::const_iterator Iter;

	// < ~ > 까지
	for (Iter p = tags.begin(); p != tags.end(); ++p)
	{
		// / 가 없으면 스택에 삽입
		if (p->at(1) != '/')
			S.push(*p);
		
		// / 가 있으면
		else
		{
			// 스택 비어 있으면 html 정상이 아님
			if (S.isEmpty())
				return false;
		
			// 태그가 짝맞춤이 되지 않으면 정상이 아님
			string open = S.top().substr(1);
			string close = p->substr(2);
			if (open.compare(close) != 0)
				return false;

			// 정상인 경우
			else S.pop();
		}
	}
	// 스택이 모두 비어 html 전체 태그상태가 정상임
	if (S.isEmpty())
		return true;
	// 태그 상태가 정상이 아님
	else
		return false;
}


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

void SLinkedList::addFront(const string & s)	// 앞에 node 하나 삽입
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
