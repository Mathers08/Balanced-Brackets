// PLM_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

struct Stack {
	char info;
	Stack* next;
};

Stack* pushFirst(int x) {
	Stack* p = new Stack;
	p->info = x;
	p->next = NULL;
	return p;
}

void push(Stack*& p, char x) {
	Stack* q = new Stack;
	q->info = x;
	q->next = p;
	p = q;
}

char pop(Stack*& p) {
	Stack* q = p;
	p = q->next;
	q->next = NULL;
	char x = q->info;
	delete q;
	return x;
}

bool isEmpty(Stack* p) {
	return !p;
}

bool brackets(char opening, char closing) {
	if (opening == '(' && closing == ')') return true;
	else if (opening == '{' && closing == '}') return true;
	else if (opening == '[' && closing == ']') return true;
	return false;
}

bool areBracketsBalanced(string exp) {
	Stack* s = nullptr;

	for (int i = 0; i < exp.length(); i++) {
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			push(s, exp[i]);
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
			if (isEmpty(s) || !brackets(s->info, exp[i]))
				return false;
			else
				pop(s);
		}
	}
	return isEmpty(s);
}

int main() {
	string expression;
	int count;
	cout << "Enter the count of expressions: ";
	cin >> count;

	for (int i = 1; i <= count; i++) {
		cout << endl << "Enter the " << i << " expression:" << endl;
		cin >> expression;
		cout << endl;
		if (areBracketsBalanced(expression))
			cout << "Balanced" << endl;
		else
			cout << "Not Balanced" << endl;
	}

	return 0;
}
