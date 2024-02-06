#pragma once
#include<iostream>
#include<fstream>
using namespace std;
#include"ExamH.h"
#include"QuestionH.h"

class DataBase {
private:

	Exam* _exams;
	int _exam_count;

public:

	//construcktors

	DataBase() {
		this->_exams = NULL;
		this->_exam_count = 0;
	}

	//gets

	Exam* getExam()const {
		return this->_exams;
	}
	int getExamCount()const {
		return this->_exam_count;
	}

	//sets

	void setExamCount(int new_count) {
		if (new_count > 0) {
			this->_exam_count = new_count;
		}
		else {
			this->_exam_count = 0;
		}
	}

	//funks

	void AddExam(Exam new_exam) {
		Exam* new_exams = new Exam  [this->_exam_count + 1];
		for (int i = 0; i < this->_exam_count; i++) {
			new_exams[i] = this->_exams[i];
		}
		new_exams[this->_exam_count] = new_exam;
		delete[] this->_exams;
		this->_exams = new_exams;
		this->_exam_count++;
	}

	void printDataBase() {
		for (size_t i = 0; i < this->getExamCount(); i++)
		{
			this->getExam()[i].print_all_Questions();
			
		}
	}

	void printDataBase_questionsName() {
		for (size_t i = 0; i < this->getExamCount(); i++)
		{
			this->getExam()[i].getName();
		}
	}


};

int select_Exam(DataBase db) {

	int select_exam_first_choice = 0;

	while (true) {
		system("cls");
		cout << "\n\n\n\t\t\t MILYONCHU \t\t\t\n\n\n" << endl;
		for (size_t i = 0; i < db.getExamCount() + 1; i++)
		{
			if (i == db.getExamCount()) {
				cout << "Exit";
			}
			else {

				cout << db.getExam()[i].getName();
			}
			if (i == select_exam_first_choice) {
				cout << " <--- ";
			}
			cout << endl;

		}
		int choice_examScene_program_up_down;
		choice_examScene_program_up_down = _getch();
		int second_choice;
		if (choice_examScene_program_up_down != 13) {
			second_choice = _getch();
		}
		if (choice_examScene_program_up_down == 13) {
			return select_exam_first_choice;
			break;
		}
		else if (choice_examScene_program_up_down == 224 && second_choice == 72) {//yuxari
			if (select_exam_first_choice != 0) {
				select_exam_first_choice -= 1;
			}
		}
		else if (choice_examScene_program_up_down == 224 && second_choice == 80) {
			if (select_exam_first_choice != db.getExamCount()) {
				select_exam_first_choice += 1;
			}
		}

	}
	return db.getExamCount();
}
