#include "Header.h"

//char rightAnswer << GetQuestion(idTicket, idQuestion) + 64; для символа вида 'A'
//char rightAnswer << GetQuestion(idTicket, idQuestion) + 48; для символа вида '1'
//char rightAnswer << GetQuestion(idTicket, idQuestion); просто значение
//Пример вызова моей функции
//при наведении на функцию, почитайте подсказки!

void main()
{
	//setlocale(LC_ALL, "Russian");	
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	//сделать интерфейс
	char switch_on;
	do {
		cin >> switch_on;
		switch_on -= 48;
		switch (switch_on)
		{
		case 1: TestYourKnowledge();
			break;
		case 2: //функцмя 2
			break;
		case 0:break;
		default: //error
			break;
		}
	} while (switch_on);
}
