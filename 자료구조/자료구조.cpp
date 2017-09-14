// 자료구조.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <iostream>
#include <string>
using namespace std;

template <typename E>
struct SLinkedList
{
public:
	SLinkedList();
	~SLinkedList();
	bool isEmpty() const;
	const E& front() const;
	void addFront(const E& e);
	void removeFront();
private:
	Node<E>* head;
};

template <typename E>
struct Node
{
private:
	string name;
	int score;
	Node<E> *next;
	friend struct SLinkedList<E>;
};

int main()
{
    return 0;
}

template<typename E>
SLinkedList<E>::SLinkedList()	// 생성자
{
}

template<typename E>
SLinkedList<E>::~SLinkedList()	// 소멸자
{
	while (!isEmpty())
	{
		removeFront();
	}
}

template<typename E>
bool SLinkedList<E>::isEmpty() const	// 비어있는가?
{
	return head == NULL;
}

template<typename E>
const E & SLinkedList<E>::front() const		// 앞 부분 반환
{
	return head;	// todo : 뭘 반환해야 할 지 아직 모르겠음
}

template<typename E>
void SLinkedList<E>::addFront(const E & e)	// 앞에 추가
{
	Node<E> * node = new Node<E>;
	node->name = e;	// todo : name score 두개 넣어야함
	node->next = head;
	head = node;
}

template<typename E>
void SLinkedList<E>::removeFront()	// 앞을 삭제
{
	Node<E> before = head;
	head = before->next;
	delete before;
}
