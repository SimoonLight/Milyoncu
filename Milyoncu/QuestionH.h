#pragma once
#include<iostream>
#include<string>
using namespace std;
//#include"File.h"

class Question {
private:
	string _question;
	string _answer1;
	string _answer2;
	string _answer3;
	string _answer4;
	string _true_answer;
public:

	//gets
	string getQuestion()const {
		if (this->_question != "") {
			return this->_question;
		}
		else {
			return "Empty";
		}
	}
	string getAnswer1()const {
		return this->_answer1;
	}
	string getAnswer2()const {
		return this->_answer2;
	}
	string getAnswer3()const {
		return this->_answer3;
	}
	string getAnswer4()const {
		return this->_answer4;
	}
	string getTrueAnswer()const {
		return this->_true_answer;
	}

	//sets

	void setQuestion(string question) {
		if (question.length() == 0) {
			this->_question = "Empty";
		}
		else {
			this->_question = question;
		}
	}
	void setAnswer1(string answer1) {
		if (answer1.length() == 0) {
			this->_answer1 = "Empty";
		}
		else {
			this->_answer1 = answer1;
		}
	}
	void setAnswer2(string answer2) {
		if (answer2.length() == 0) {
			this->_answer2 = "Empty";
		}
		else {
			this->_answer2 = answer2;
		}
	}
	void setAnswer3(string answer3) {
		if (answer3.length() == 0) {
			this->_answer3 = "Empty";
		}
		else {
			this->_answer3 = answer3;
		}
	}
	void setAnswer4(string answer4) {
		if (answer4.length() == 0) {
			this->_answer4 = "Empty";
		}
		else {
			this->_answer4 = answer4;
		}
	}
	void setTrueAnswer(string true_answer) {
		if (true_answer.length() == 0) {
			this->_true_answer = "Empty";
		}
		else {
			this->_true_answer = true_answer;
		}
	}

	//construcktors

	Question() {
		this->setQuestion("");
		this->setAnswer1("");
		this->setAnswer2("");
		this->setAnswer3("");
		this->setAnswer4("");
		this->setTrueAnswer("");
	}

	Question(string question, string answer1, string answer2, string answer3, string answer4, string trueAnswer) :Question() {
		this->setQuestion(question);
		this->setAnswer1(answer1);
		this->setAnswer2(answer2);
		this->setAnswer3(answer3);
		this->setAnswer4(answer4);
		this->setTrueAnswer(trueAnswer);
	}

	~Question() {

	}

	//funks

	void printQuestion() {
		cout << " Question : " << this->getQuestion() << endl;
		cout << " Answer 1 : " << this->getAnswer1() << endl;
		cout << " Answer 2 : " << this->getAnswer2() << endl;
		cout << " Answer 3 : " << this->getAnswer3() << endl;
		cout << " Answer 4 : " << this->getAnswer4() << endl;
		cout << " True Answer  : " << this->getTrueAnswer() << endl;
	}


	
};


