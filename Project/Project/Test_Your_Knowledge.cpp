#include "Header.h"

/*/ Структура для вопроса
struct Question {
    string questionText;
    vector<string> options;
    int correctOptionIndex;
};

// Структура для билета
struct Ticket {
    vector<Question> questions;
};*/

void PrintHelloScreen() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    cout << "_______________________________________________________$$________________________________________________\n";
    cout << "___$$$$$$_$$$$$$__$$$$__$$$$$$__$$$$__$$$$$__$$___$$_$$__$$____$$___$$__$$$$____$$$___$$__$$____$$$_$$___\n";
    cout << "_____$$___$$_____$$__$$___$$___$$__$$_$$__$$_$$___$$_$$__$$____$$$_$$$_$$__$$__$$_$$___$$_$$___$_$$_$$___\n";
    cout << "_____$$___$$$$___$$_______$$___$$__$$_$$$$$__$$$$_$$_$$_$$$____$$_$_$$_$$__$$__$$_$$____$$$$__$__$$_$$$$$\n";
    cout << "_____$$___$$_____$$__$$___$$___$$__$$_$$__$$_$$_$_$$_$$$_$$____$$___$$_$$__$$_$$$$$$$_____$$_$$__$$_$$_$$\n";
    cout << "_____$$___$$$$$$__$$$$____$$____$$$$__$$$$$__$$$$_$$_$$__$$____$$___$$__$$$$__$_____$___$$$__$$__$$_$$$$$\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

    COORD cursorPos;
    cursorPos.X = 1; 
    cursorPos.Y = 28;  

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
    cout << "Нажмите любую клавишу для начала теста(esc для выхода)...";
    
}

// Функция для проведения теста
void conductTest(/*const vector<Ticket>& tickets*/) {
    char maxTicketIndex = 3;
    char maxQuestionIndex = 4;
    int correctAnswers = 0;
    int totalQuestions = 0;

    for (int i = 0; i < 5; ++i) {
        // Выбор случайного билета и вопроса
        char ticketIndex = (rand() % maxTicketIndex)+1;
        char questionIndex = (rand() % maxQuestionIndex)+1;
     
        //const Question& question = tickets[ticketIndex].questions[questionIndex];

        cout << "Вопрос " << i + 1 << ": Билет " << char(ticketIndex + 48) << " Вопрос " << char(questionIndex + 48) << endl;

        char correctOptionIndex = GetQuestion(ticketIndex, questionIndex);
        char maxOptions = GetSizeQuestion(ticketIndex, questionIndex);

        // Вывод вариантов ответов
       /* for (int j = 0; j < question.options.size(); ++j) {
            cout << j + 1 << ". " << question.options[j] << endl;
        }*/

        // Ответ от пользователя
        char userAnswer;
        cout << "Ваш ответ: ";
        while (!(cin >> userAnswer) || ((userAnswer < '1' || userAnswer >  maxOptions + 48) && (userAnswer < 'A' || userAnswer > maxOptions + 64) && (userAnswer < 'a' || userAnswer > maxOptions + 96))) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Пожалуйста, введите число от A до " << char(maxOptions + 64) << ": ";
        }

        // Проверка правильности ответа
        if (userAnswer == correctOptionIndex + 64 || userAnswer == correctOptionIndex + 48 || userAnswer == correctOptionIndex + 96) {
            cout << "\033[42mПравильно!\033[0m" << endl;
            correctAnswers++;
        }
        else {
            cout << "\033[41mНеправильно.\033[0m\nПравильный ответ: " << char(correctOptionIndex + 64) << endl;
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
    //setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    
    system("cls");
    PrintHelloScreen();

int ch=_getch();
if (ch != 27) {
    system("cls");
   /* vector<Ticket> tickets{
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
    };*/

    char choice;
    do {
        conductTest();

        cout << "Желаете пройти тест еще раз? (y/n): ";
        while (!(cin >> choice) || (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Пожалуйста, введите 'y' или 'n': ";
        }
        system("cls");
    } while (choice == 'y' || choice == 'Y');
}

    system("cls");
}
