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
	cout << "Добро пожаловать в програму для подготовки к экзамену по ОПИ!\n";
	char switch_on;
	do {
		cout << "Выберете опцию:\n"
			<< "1 - Проверка знаний\n"
			<< "2 - Решение билета\n"
			<< "0 - Выход\n";
		cin >> switch_on;
		cin.clear();
		cin.ignore(32767, '\n');
		switch_on -= 48;
		switch (switch_on)
		{
		case 1: TestYourKnowledge();
			break;
		case 2: Preapare();
			break;
		case 0:break;
		default: cout << "Введите от 0 до 2! Нажмите кнопку для продолжения..." << endl;
			_getch();
			break;
		}
		system("cls");
	} while (switch_on);
	cout << "До свидания! Увидемся позже!";
}
