#include "Tickets_and_Answers.h"

; char GetQuestion(char idTicket, char idQuestion) {
	idTicket--;
	char id = (idTicket * 4) + idQuestion;
	string bufQ, bufA, bufB, bufC, bufD; char returnchar ;
	ifstream questions("noDB\\questions.koi");
	ifstream answers("noDB\\answers.koi");
	ifstream correctAnswers("noDB\\correctAnswers.koi");
	if (questions.is_open() && answers.is_open() && correctAnswers.is_open())
	{
		for (char i = 0; i < id; i++) {
			getline(questions, bufQ);
			getline(answers, bufA); getline(answers, bufB); getline(answers, bufC); getline(answers, bufD);
			correctAnswers >> returnchar;
		}
	}
	else {
		cout << "Не удалось получить доступ к данным :(" << endl;
		return NULL;
	}
	questions.close();
	answers.close();
	correctAnswers.close();
	cout << bufQ << endl << '\t' << bufA << endl << '\t' << bufB << endl
		<< '\t' << bufC << endl << '\t' << bufD << endl;
	return returnchar - 64;
}

char GetSizeQuestion(char idTicket, char idQuestion) {
	idTicket--;
	char id = (idTicket * 4) + idQuestion;
	ifstream answers("noDB\\answers.koi");
	string buf;
	char countch = 0;
	if (answers.is_open())
	{
		for (char i = 0; i < id-1; i++) {
			for (char j = 0; j < 4; j++) {
				getline(answers, buf);
			}
		}
		for (char j = 0; j < 4; j++) {
			getline(answers, buf);
			if (buf != "\n") {
				countch++;
			}
		}
	}
	else {
		cout << "Не удалось получить доступ к данным :(" << endl;
		return NULL;
	}
	answers.close();
	return countch;
}

