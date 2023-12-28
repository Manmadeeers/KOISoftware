#include "Header.h"

/*/ ��������� ��� �������
struct Question {
    string questionText;
    vector<string> options;
    int correctOptionIndex;
};

// ��������� ��� ������
struct Ticket {
    vector<Question> questions;
};*/

void PrintHelloScreen() {
   // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    //cout << "_______________________________________________________$$________________________________________________\n";
    //cout << "___$$$$$$_$$$$$$__$$$$__$$$$$$__$$$$__$$$$$__$$___$$_$$__$$____$$___$$__$$$$____$$$___$$__$$____$$$_$$___\n";
    //cout << "_____$$___$$_____$$__$$___$$___$$__$$_$$__$$_$$___$$_$$__$$____$$$_$$$_$$__$$__$$_$$___$$_$$___$_$$_$$___\n";
    //cout << "_____$$___$$$$___$$_______$$___$$__$$_$$$$$__$$$$_$$_$$_$$$____$$_$_$$_$$__$$__$$_$$____$$$$__$__$$_$$$$$\n";
    //cout << "_____$$___$$_____$$__$$___$$___$$__$$_$$__$$_$$_$_$$_$$$_$$____$$___$$_$$__$$_$$$$$$$_____$$_$$__$$_$$_$$\n";
    //cout << "_____$$___$$$$$$__$$$$____$$____$$$$__$$$$$__$$$$_$$_$$__$$____$$___$$__$$$$__$_____$___$$$__$$__$$_$$$$$\n";
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

    COORD cursorPos;
    cursorPos.X = 1; 
    cursorPos.Y = 28;  

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
    cout << "������� ����� ������� ��� ������ �����(esc ��� ������)...";
    
}

// ������� ��� ���������� �����
void conductTest(/*const vector<Ticket>& tickets*/) {
    char maxTicketIndex = 3;
    char maxQuestionIndex = 4;
    int correctAnswers = 0;
    int totalQuestions = 0;

    for (int i = 0; i < 5; ++i) {
        // ����� ���������� ������ � �������
        char ticketIndex = (rand() % maxTicketIndex)+1;
        char questionIndex = (rand() % maxQuestionIndex)+1;
     
        //const Question& question = tickets[ticketIndex].questions[questionIndex];

        cout << "������ " << i + 1 << ": ����� " << char(ticketIndex + 48) << " ������ " << char(questionIndex + 48) << endl;

        char correctOptionIndex = GetQuestion(ticketIndex, questionIndex);
        char maxOptions = GetSizeQuestion(ticketIndex, questionIndex);

        // ����� ��������� �������
       /* for (int j = 0; j < question.options.size(); ++j) {
            cout << j + 1 << ". " << question.options[j] << endl;
        }*/

        // ����� �� ������������
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
        if (userAnswer == correctOptionIndex + 64 || userAnswer == correctOptionIndex + 48 || userAnswer == correctOptionIndex + 96) {
            Beep(1000, 500);
            cout << "\033[42m���������!\033[0m" << endl;
            correctAnswers++;
        }
        else {
            cout << "\033[41m�����������.\033[0m\n���������� �����: " << char(correctOptionIndex + 64) << endl;
            Beep(200, 500);
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
    //setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    
    system("cls");
    PrintHelloScreen();

int ch=_getch();
if (ch != 27) {
    system("cls");
   /* vector<Ticket> tickets{
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
    };*/

    char choice;
    do {
        conductTest();

        cout << "������� ������ ���� ��� ���? (y/n): ";
        while (!(cin >> choice) || (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "����������, ������� 'y' ��� 'n': ";
        }
        system("cls");
    } while (choice == 'y' || choice == 'Y');
}

    system("cls");
}
