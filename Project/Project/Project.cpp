#include "Header.h"

//char rightAnswer << GetQuestion(idTicket, idQuestion) + 64; для символа вида 'A'
//char rightAnswer << GetQuestion(idTicket, idQuestion) + 48; для символа вида '1'
//char rightAnswer << GetQuestion(idTicket, idQuestion); просто значение
//Пример вызова моей функции
//при наведении на функцию, почитайте подсказки!

void main()
{
	SetConsoleTitle(TEXT("BSTU Exam Master"));
	//setlocale(LC_ALL, "Russian");	
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	cout << "Вас привествует BSTU Exam Master\n";
	char switch_on, switch_on_sec;
	do {
		cout << "Выберете дисциплину:\n"
			<< "1 - ОПИ\n"
			<< "2 - ОАИП\n"
			<< "3 - ЛАиАГ\n"
			<< "4 - АЛОВС\n"
			<< "0 - выход\n";
		cin >> switch_on; 
		cin.clear();
		cin.ignore(32767, '\n');
		switch_on -= 48;
		system("cls");
		switch (switch_on)
		{
		case 1:
		do{
			cout << "Выберете опцию:\n"
				<< "1 - Проверка знаний\n"
				<< "2 - Решение билета\n"
				<< "0 - Выход\n";
			cin >> switch_on_sec;
			cin.clear();
			cin.ignore(32767, '\n');
			switch_on_sec -= 48;
			switch (switch_on_sec)
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
		} while (switch_on_sec);
		break;

		case 2: system("cls");
			cout << "Это часть ещё в разработке. Простите за неудобство =(\nНажмите для продолжения...";
			_getch(); system("cls"); break;
		case 3: system("cls");
			cout << "Это часть ещё в разработке. Простите за неудобство =(\nНажмите для продолжения...";
			_getch(); system("cls"); break;
		case 4: system("cls");
			cout << "Это часть ещё в разработке. Простите за неудобство =(\nНажмите для продолжения...";
			_getch(); system("cls"); break;
		case 0:break;

		default: cout << "Введите от 0 до 4! Нажмите кнопку для продолжения..." << endl;
			_getch();
			break;
		}
	} while (switch_on);
	cout << "До свидания! Увидемся позже!";
}
