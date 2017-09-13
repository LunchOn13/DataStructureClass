// Declare Singly Linked List
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
		break;
	case 'E':
		// Implement Empty
		break;
	case 'H':
		// Implement Head
		break;
	case 'T':
		// Implement Traverse List
		break;
	default:
		cout << "Wrong Input" << endl;
		break;
	}

	cin >> ch;

}