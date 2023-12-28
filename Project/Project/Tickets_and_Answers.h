#pragma once
#include "Header.h"



/*Функция выводит вопросы и варианты ответов и возвращает (в char) id правильного ответа
* idTicket - номер билета(max 5)
* idQuestion - номер вопроса(max 4)
*/
char GetQuestion(char idTicket, char idQuestion);

/*Функция возвращает (в char) кол-во ответов
* idTicket - номер билета(max 5)
* idQuestion - номер вопроса(max 4)
*/
char GetSizeQuestion(char idTicket, char idQuestion)