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
	bool empty();
private:

};

struct Node
{
public:
	string name;
	int score;

	friend struct SLinkedList;
};

int main()
{
    return 0;
}

