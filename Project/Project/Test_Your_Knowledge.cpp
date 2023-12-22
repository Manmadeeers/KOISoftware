#include "Header.h"

// Структура для вопроса
struct Question {
    string questionText;
    vector<string> options;
    int correctOptionIndex;
};

// Структура для билета
struct Ticket {
    vector<Question> questions;
};

// Функция для проведения теста
void conductTest(const vector<Ticket>& tickets) {
    int correctAnswers = 0;
    int totalQuestions = 0;

    for (int i = 0; i < 5; ++i) {
        // Выбор случайного билета и вопроса
        int ticketIndex = rand() % tickets.size();
        int questionIndex = rand() % tickets[ticketIndex].questions.size();
        const Question& question = tickets[ticketIndex].questions[questionIndex];

        cout << "Вопрос " << i + 1 << ": " << question.questionText << endl;

        // Вывод вариантов ответов
        for (int j = 0; j < question.options.size(); ++j) {
            cout << j + 1 << ". " << question.options[j] << endl;
        }

        // Ответ от пользователя
        int userAnswer;
        cout << "Ваш ответ: ";
        while (!(cin >> userAnswer) || userAnswer < 1 || userAnswer > question.options.size()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Пожалуйста, введите число от 1 до " << question.options.size() << ": ";
        }

        // Проверка правильности ответа
        if (userAnswer == question.correctOptionIndex + 1) {
            cout << "\033[42mПравильно!\033[0m" << endl;
            correctAnswers++;
        }
        else {
            cout << "\033[41mНеправильно.\033[0m\nПравильный ответ: " << question.options[question.correctOptionIndex] << endl;
        }

        totalQuestions++;

        cout << "Нажмите любую клавишу для продолжения...";
        _getch();
        system("cls");
    }

    cout << "Статистика:" << endl;
    cout << "Правильных ответов: " << correctAnswers << " из " << totalQuestions << endl;
    cout << "Процент правильных ответов: ";
    cout << (((float(correctAnswers) / totalQuestions) * 100) < 40 ? "\033[41m" : "\033[42m");
    cout << (float(correctAnswers) / totalQuestions) * 100 << "%\033[0m" << endl;
}
void TestYourKnowledge() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    vector<Ticket> tickets{
        {
            {{"Вопрос 1 (Билет 1)", {"Ответ 1", "Ответ 2", "Ответ 3"}, 0},
             {"Вопрос 2 (Билет 1)", {"Ответ 1", "Ответ 2", "Ответ 3"}, 1},
             {"Вопрос 3 (Билет 1)", {"Ответ 1", "Ответ 2", "Ответ 3"}, 2}}
        },
        {
            {{"Вопрос 1 (Билет 2)", {"Ответ 1", "Ответ 2", "Ответ 3"}, 0},
             {"Вопрос 2 (Билет 2)", {"Ответ 1", "Ответ 2", "Ответ 3"}, 1},
             {"Вопрос 3 (Билет 2)", {"Ответ 1", "Ответ 2", "Ответ 3"}, 2}}
        },
        {
            {{"Вопрос 1 (Билет 3)", {"Ответ 1", "Ответ 2", "Ответ 3"}, 0},
             {"Вопрос 2 (Билет 3)", {"Ответ 1", "Ответ 2", "Ответ 3"}, 1},
             {"Вопрос 3 (Билет 3)", {"Ответ 1", "Ответ 2", "Ответ 3"}, 2}}
        }
    };

    char choice;
    do {
        conductTest(tickets);

        cout << "Желаете пройти тест еще раз? (y/n): ";
        while (!(cin >> choice) || (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Пожалуйста, введите 'y' или 'n': ";
        }
        system("cls");
    } while (choice == 'y' || choice == 'Y');

    cout << "До свидания!" << endl;
}
