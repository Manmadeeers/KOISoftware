#include "Header.h"

// ��������� ��� �������
struct Question {
    string questionText;
    vector<string> options;
    int correctOptionIndex;
};

// ��������� ��� ������
struct Ticket {
    vector<Question> questions;
};

// ������� ��� ���������� �����
void conductTest(const vector<Ticket>& tickets) {
    int correctAnswers = 0;
    int totalQuestions = 0;

    for (int i = 0; i < 5; ++i) {
        // ����� ���������� ������ � �������
        int ticketIndex = rand() % tickets.size();
        int questionIndex = rand() % tickets[ticketIndex].questions.size();
        const Question& question = tickets[ticketIndex].questions[questionIndex];

        cout << "������ " << i + 1 << ": " << question.questionText << endl;

        // ����� ��������� �������
        for (int j = 0; j < question.options.size(); ++j) {
            cout << j + 1 << ". " << question.options[j] << endl;
        }

        // ����� �� ������������
        int userAnswer;
        cout << "��� �����: ";
        while (!(cin >> userAnswer) || userAnswer < 1 || userAnswer > question.options.size()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "����������, ������� ����� �� 1 �� " << question.options.size() << ": ";
        }

        // �������� ������������ ������
        if (userAnswer == question.correctOptionIndex + 1) {
            cout << "\033[42m���������!\033[0m" << endl;
            correctAnswers++;
        }
        else {
            cout << "\033[41m�����������.\033[0m\n���������� �����: " << question.options[question.correctOptionIndex] << endl;
        }

        totalQuestions++;

        cout << "������� ����� ������� ��� �����������...";
        _getch();
        system("cls");
    }

    cout << "����������:" << endl;
    cout << "���������� �������: " << correctAnswers << " �� " << totalQuestions << endl;
    cout << "������� ���������� �������: ";
    cout << (((float(correctAnswers) / totalQuestions) * 100) < 40 ? "\033[41m" : "\033[42m");
    cout << (float(correctAnswers) / totalQuestions) * 100 << "%\033[0m" << endl;
}
void TestYourKnowledge() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    vector<Ticket> tickets{
        {
            {{"������ 1 (����� 1)", {"����� 1", "����� 2", "����� 3"}, 0},
             {"������ 2 (����� 1)", {"����� 1", "����� 2", "����� 3"}, 1},
             {"������ 3 (����� 1)", {"����� 1", "����� 2", "����� 3"}, 2}}
        },
        {
            {{"������ 1 (����� 2)", {"����� 1", "����� 2", "����� 3"}, 0},
             {"������ 2 (����� 2)", {"����� 1", "����� 2", "����� 3"}, 1},
             {"������ 3 (����� 2)", {"����� 1", "����� 2", "����� 3"}, 2}}
        },
        {
            {{"������ 1 (����� 3)", {"����� 1", "����� 2", "����� 3"}, 0},
             {"������ 2 (����� 3)", {"����� 1", "����� 2", "����� 3"}, 1},
             {"������ 3 (����� 3)", {"����� 1", "����� 2", "����� 3"}, 2}}
        }
    };

    char choice;
    do {
        conductTest(tickets);

        cout << "������� ������ ���� ��� ���? (y/n): ";
        while (!(cin >> choice) || (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "����������, ������� 'y' ��� 'n': ";
        }
        system("cls");
    } while (choice == 'y' || choice == 'Y');

    cout << "�� ��������!" << endl;
}
