#include "Prepare.h"

void Preapare() {
	char choice;
	system("cls");
	do {
		int userTicketID;
		cout << "������� �����(�� 0 �� 5, ��� 0 - �����): ";
		while (!(cin >> userTicketID) || (userTicketID < 0 || userTicketID > 5)) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "����������, ������� ����� �� 0 �� " << 5 << ": ";
		}
		if (!userTicketID) return;
			system("cls");
		int correctAnswers = 0;
		for (char i = 1; i <= 4; i++) {
			char rightAnswer = GetQuestion(userTicketID, i);
			char maxOptions = GetSizeQuestion(userTicketID, i);
			char userAnswer;
			cout << "��� �����: ";
			while (!(cin >> userAnswer) || ((userAnswer < '1' || userAnswer >  maxOptions + 48) && (userAnswer < 'A' || userAnswer > maxOptions + 64) && (userAnswer < 'a' || userAnswer > maxOptions + 96))) {
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "����������, ������� ����� �� A �� " << char(maxOptions + 64) << ": ";
			}
			cin.clear();
			cin.ignore(32767, '\n');
			// �������� ������������ ������
			if (userAnswer == rightAnswer + 64 || userAnswer == rightAnswer + 48 || userAnswer == rightAnswer + 96) {
				Beep(1000, 500);
				cout << "\033[42m���������!\033[0m" << endl;
				correctAnswers++;
			}
			else {
				Beep(200, 500);
				cout << "\033[41m�����������.\033[0m\n���������� �����: " << char(rightAnswer + 64) << endl;
			}
			cout << "������� ����� ������� ��� �����������...";
			_getch();
			system("cls");
		}
		cout << "����������:" << endl;
		cout << "���������� �������: " << correctAnswers << " �� " << 4 << endl;
		cout << "������� ���������� �������: ";
		cout << (((float(correctAnswers) / 4) * 100) < 40 ? "\033[41m" : "\033[42m");
		cout << (float(correctAnswers) / 4) * 100 << "%\033[0m" << endl;
		cout << "������� ������ ���� ��� ���? (y/n): ";
		while (!(cin >> choice) || (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "����������, ������� 'y' ��� 'n': ";
		}
		system("cls");
	} while (choice == 'y' || choice == 'Y');


	system("cls");
}


