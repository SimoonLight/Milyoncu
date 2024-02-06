#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"QuestionH.h"
//#include"ScoresH.h"
//#include"DataBaseH.h"
//#include "File.h"

class Exam {
private:
	string _exam_name;
	Question* _questions;
	int _count_questions;

public:

	//gets

	int getCountQuestions() const {
		return this->_count_questions;
	}
	Question* getQuestions()const {
		return this->_questions;
	}
	string getName()const {
		return this->_exam_name;
	}

	//sets

	void setCountQuestions(int new_count) {
		if (new_count > 0) {
			this->_count_questions = new_count;
		}
		else {
			this->_count_questions = 0;
		}
	}
	void setNameExam(string new_name) {
		if (new_name.length() == 0) {
			this->_exam_name = "Empty";
		}
		else {
			this->_exam_name = new_name;
		}
	}

	//construcktors

	Exam() {
		this->_questions = NULL;
		this->setCountQuestions(0);
		this->setNameExam("Empty");
	}

	Exam(string name) :Exam() {
		this->_questions = NULL;
		this->setCountQuestions(0);
		this->setNameExam(name);
	}

	~Exam() {}

	//methods

	void print_all_Questions() {
		cout << " Exam name : " << this->_exam_name << endl;
		for (size_t i = 0; i < this->getCountQuestions(); i++)
		{
			//this->getQuestions()[i]->printQuestion();
			//this->getQuestions()[i].printQuestion();


			this->_questions[i].printQuestion();
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
		}
	}

	void add_QuestionToExam(Question new_question) {
		Question* new_questions = new Question[this->_count_questions + 1];
		for (int i = 0; i < this->_count_questions; i++) {
			new_questions[i] = this->_questions[i];
		}
		new_questions[this->_count_questions] = new_question;
		delete[] this->_questions;
		this->_questions = new_questions;
		this->_count_questions++;
	}

};

void prepare_questions(Exam& empty_exam, Exam full_exam) {
	int arr[4]{ -1,-1,-1,-1 };
	int count = 0;
	int size = sizeof(arr) / sizeof(arr[0]);
	empty_exam.setNameExam(full_exam.getName());
	while (count != 4) {
		int random1 = 0 + rand() % (3 - 0 + 1);
		bool check_number = true;
		for (size_t i = 0; i < 4; i++)
		{
			if (arr[i] == random1) {
				check_number = false;
			}
		}
		if (check_number == true) {

			arr[count] = random1;
			count += 1;

		}
	}
	for (size_t i = 0; i < 4; i++)
	{
		string quest;
		string question1;
		string question2;
		string question3;
		string question4;
		string questionTrue;
		questionTrue = full_exam.getQuestions()[i].getTrueAnswer();
		quest = full_exam.getQuestions()[i].getQuestion();

		if (arr[0] == 0) {
			question1 = full_exam.getQuestions()[i].getAnswer1();
		}
		else if (arr[0] == 1) {
			question1 = full_exam.getQuestions()[i].getAnswer2();
		}
		else if (arr[0] == 2) {
			question1 = full_exam.getQuestions()[i].getAnswer3();
		}
		else if (arr[0] == 3) {
			question1 = full_exam.getQuestions()[i].getAnswer4();
		}

		if (arr[1] == 0) {
			question2 = full_exam.getQuestions()[i].getAnswer1();
		}
		else if (arr[1] == 1) {
			question2 = full_exam.getQuestions()[i].getAnswer2();
		}
		else if (arr[1] == 2) {
			question2 = full_exam.getQuestions()[i].getAnswer3();
		}
		else if (arr[1] == 3) {
			question2 = full_exam.getQuestions()[i].getAnswer4();
		}

		if (arr[2] == 0) {
			question3 = full_exam.getQuestions()[i].getAnswer1();
		}
		else if (arr[2] == 1) {
			question3 = full_exam.getQuestions()[i].getAnswer2();
		}
		else if (arr[2] == 2) {
			question3 = full_exam.getQuestions()[i].getAnswer3();
		}
		else if (arr[2] == 3) {
			question3 = full_exam.getQuestions()[i].getAnswer4();
		}

		if (arr[3] == 0) {
			question4 = full_exam.getQuestions()[i].getAnswer1();
		}
		else if (arr[3] == 1) {
			question4 = full_exam.getQuestions()[i].getAnswer2();
		}
		else if (arr[3] == 2) {
			question4 = full_exam.getQuestions()[i].getAnswer3();
		}
		else if (arr[3] == 3) {
			question4 = full_exam.getQuestions()[i].getAnswer4();
		}

		Question new_q(quest, question1, question2, question3, question4, questionTrue);

		empty_exam.add_QuestionToExam(new_q);

	}
}

int start_Exam(Exam& ex) {

	int count_ex = 0;

	string answer1="";
	string answer2="";
	string answer3="";
	string answer4="";
	string answer5="";
	while (true) {

		system("cls");
		cout << "\n\n\n\t\t\t MILYONCHU \t\t\t\n\n\n" << endl;
		cout << " " << count_ex + 1 << ") " << ex.getQuestions()[count_ex].getQuestion() << endl << endl;
		cout << " " << "a) " << ex.getQuestions()[count_ex].getAnswer1() << endl;
		cout << " " << "b) " << ex.getQuestions()[count_ex].getAnswer2() << endl;
		cout << " " << "c) " << ex.getQuestions()[count_ex].getAnswer3() << endl;
		cout << " " << "d) " << ex.getQuestions()[count_ex].getAnswer4() << endl;
		
		cout << " Previously [p]   Next [n]   Submit [s] " << endl;

		string answer;

		cout << " Enter : ";
		cin >> answer;

		if (answer == "p") {
			if (count_ex != 0) {
				count_ex -= 1;
			}
		}
		else if (answer == "n") {
			if (count_ex != 3) {
				count_ex += 1;
			}
		}
		else if (answer == "s") {
			int point = 0;
			if (answer1 == ex.getQuestions()[0].getTrueAnswer()) {
				point += 10;
			}
			if (answer2 == ex.getQuestions()[1].getTrueAnswer()) {
				point += 10;
			}
			if (answer3 == ex.getQuestions()[2].getTrueAnswer()) {
				point += 10;
			}
			if (answer4 == ex.getQuestions()[3].getTrueAnswer()) {
				point += 10;
			}
			/*if (answer5 == ex.getQuestions()[4].getTrueAnswer()) {
				point += 10;
			}*/
			return point;
			break;
		}
		else if (answer == "a") {
			if (count_ex == 0) {
				answer1 = ex.getQuestions()[0].getAnswer1();
			}
			else if (count_ex == 1) {
				answer2 = ex.getQuestions()[0].getAnswer1();
			}
			else if (count_ex == 3) {
				answer3 = ex.getQuestions()[0].getAnswer1();
			}
			else if (count_ex == 4) {
				answer4 = ex.getQuestions()[0].getAnswer1();
			}
		}
		else if (answer == "b") {
			if (count_ex == 0) {
				answer1 = ex.getQuestions()[1].getAnswer2();
			}
			else if (count_ex == 1) {
				answer2 = ex.getQuestions()[1].getAnswer2();
			}
			else if (count_ex == 3) {
				answer3 = ex.getQuestions()[1].getAnswer2();
			}
			else if (count_ex == 4) {
				answer4 = ex.getQuestions()[1].getAnswer2();
			}
		}
		else if (answer == "c") {
			if (count_ex == 0) {
				answer1 = ex.getQuestions()[2].getAnswer3();
			}
			else if (count_ex == 1) {
				answer2 = ex.getQuestions()[2].getAnswer3();
			}
			else if (count_ex == 3) {
				answer3 = ex.getQuestions()[2].getAnswer3();
			}
			else if (count_ex == 4) {
				answer4 = ex.getQuestions()[2].getAnswer3();
			}
		}
		else if (answer == "d") {
			if (count_ex == 0) {
				answer1 = ex.getQuestions()[3].getAnswer4();
			}
			else if (count_ex == 1) {
				answer2 = ex.getQuestions()[3].getAnswer4();
			}
			else if (count_ex == 3) {
				answer3 = ex.getQuestions()[3].getAnswer4();
			}
			else if (count_ex == 4) {
				answer4 = ex.getQuestions()[3].getAnswer4();
			}
		}
	}


}
