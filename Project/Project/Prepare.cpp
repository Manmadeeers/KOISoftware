#include "Prepare.h"

void Preapare() {
	char choice;
	system("cls");
	do {
		int userTicketID;
		cout << "Введите билет(от 0 до 5, где 0 - выход): ";
		while (!(cin >> userTicketID) || (userTicketID < 0 || userTicketID > 5)) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Пожалуйста, введите число от 0 до " << 5 << ": ";
		}
		if (!userTicketID) return;
			system("cls");
		int correctAnswers = 0;
		for (char i = 1; i <= 4; i++) {
			char rightAnswer = GetQuestion(userTicketID, i);
			char maxOptions = GetSizeQuestion(userTicketID, i);
			char userAnswer;
			cout << "Ваш ответ: ";
			while (!(cin >> userAnswer) || ((userAnswer < '1' || userAnswer >  maxOptions + 48) && (userAnswer < 'A' || userAnswer > maxOptions + 64) && (userAnswer < 'a' || userAnswer > maxOptions + 96))) {
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Пожалуйста, введите число от A до " << char(maxOptions + 64) << ": ";
			}
			cin.clear();
			cin.ignore(32767, '\n');
			// Проверка правильности ответа
			if (userAnswer == rightAnswer + 64 || userAnswer == rightAnswer + 48 || userAnswer == rightAnswer + 96) {
				Beep(1000, 500);
				cout << "\033[42mПравильно!\033[0m" << endl;
				correctAnswers++;
			}
			else {
				Beep(200, 500);
				cout << "\033[41mНеправильно.\033[0m\nПравильный ответ: " << char(rightAnswer + 64) << endl;
			}
			cout << "Нажмите любую клавишу для продолжения...";
			_getch();
			system("cls");
		}
		cout << "Статистика:" << endl;
		cout << "Правильных ответов: " << correctAnswers << " из " << 4 << endl;
		cout << "Процент правильных ответов: ";
		cout << (((float(correctAnswers) / 4) * 100) < 40 ? "\033[41m" : "\033[42m");
		cout << (float(correctAnswers) / 4) * 100 << "%\033[0m" << endl;
		cout << "Желаете пройти тест еще раз? (y/n): ";
		while (!(cin >> choice) || (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Пожалуйста, введите 'y' или 'n': ";
		}
		system("cls");
	} while (choice == 'y' || choice == 'Y');


	system("cls");
}


