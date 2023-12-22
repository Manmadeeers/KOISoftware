#include "Header.h"


void main()
{
	setlocale(LC_ALL, "Russian");
	for (int i = 0; i < 20; i++) {
		cout << "вопрос номер " << i + 1 << ":" << endl;
		questions()
	}
}