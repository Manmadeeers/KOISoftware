#include "Tickets_and_Answers.h"


char GetQuestion(char idTicket, char idQuestion) {
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
	cout << bufQ << endl << bufA << endl << bufB << endl
		<< bufC << endl << bufD << endl;
	return returnchar - 64;
}
