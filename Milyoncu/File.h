#pragma once
//#include<iostream>
#include <fstream>
using namespace std;
#include"QuestionH.h"
#include"ExamH.h"
#include"DataBaseH.h"
#include"ScoresH.h"

void write_QuestionToFile(Exam& exam) {

	ofstream f("milyoncu questions.txt", ios::app);

	if (!f.is_open()) {
		cout << " Txt filesi acilmadi " << endl;

	}

	f << exam.getName() << endl;
	for (size_t i = 0; i < 5; i++)
	{
		f << exam.getQuestions()[i].getQuestion() << " " << exam.getQuestions()[i].getAnswer1() << " " << exam.getQuestions()[i].getAnswer2() << " " << exam.getQuestions()[i].getAnswer3() << " " << exam.getQuestions()[i].getAnswer4() << " " << exam.getQuestions()[i].getTrueAnswer() << endl;;
	}


	f.close();

}

void write_ScoreToFile(Score& score) {

	ofstream f("scores.txt", ios::app);

	if (!f.is_open()) {
		cout << " Txt filesi acilmadi " << endl;

	}

	f << score.getName() <<" "<<score.getScore() << endl;
	


	f.close();

}


void Add_question_for_file() {
	system("cls");
	cout << "\n\n\n\t\t\t MILYONCHU \t\t\t\n\n\n" << endl;
	cin.ignore();
	string new_question_name;
	cout << " Enter Exam's name : ";
	getline(cin, new_question_name);

	Exam new_exam(new_question_name);

	for (size_t i = 0; i < 5; i++)
	{

		string new_question_question;
		cout << " Enter question : ";
		getline(cin, new_question_question);

		string new_question_answer1;
		cout << " Enter first answer : ";
		getline(cin, new_question_answer1);

		string new_question_answer2;
		cout << " Enter second answer : ";
		getline(cin, new_question_answer2);

		string new_question_answer3;
		cout << " Enter third answer : ";
		getline(cin, new_question_answer3);

		string new_question_answer4;
		cout << " Enter fourth answer : ";
		getline(cin, new_question_answer4);

		string new_question_true_answer;
		cout << " Enter true answer : ";
		getline(cin, new_question_true_answer);

		Question new_question(new_question_question, new_question_answer1, new_question_answer2, new_question_answer3, new_question_answer4, new_question_true_answer);

		new_exam.add_QuestionToExam(new_question);

	}


	write_QuestionToFile(new_exam);


}

void read_Question_from_file(DataBase& db) {
	ifstream file("milyoncu questions.txt", ios::in);

	if (!file.is_open())
	{
		cout << "File is not find" << endl;
		return;
	}
	if (!file.is_open())
	{
		cout << "File is not find" << endl;
		return;
	}
	while (!file.eof())
	{
		//if (!file) {

		if(!file.eof()){
			Exam e;
			string exam_name;
			if (!file.eof()) {
				file >> exam_name;

			}
			e.setNameExam(exam_name);
			for (size_t i = 0; i < 5; i++)
			{

				string question;
				string answer1;
				string answer2;
				string answer3;
				string answer4;
				string true_answer;

				file >> question;
				file >> answer1;
				file >> answer2;
				file >> answer3;
				file >> answer4;
				file >> true_answer;

				Question new_question(question, answer1, answer2, answer3, answer4, true_answer);

				e.add_QuestionToExam(new_question);

			}
			db.AddExam(e);
		}
		else {
			break;
		}
		
	}




	file.close();

}

void read_Score_from_file(Scores_DataBase& s_db) {
	ifstream file("scores.txt", ios::in);

	if (!file.is_open())
	{
		cout << "File is not find" << endl;
		return;
	}
	if (!file)
	{
		cout << "File is not find" << endl;
		return;
	}

	while (!file.eof())
	{

		string name;
		string score;
		file >> name;
		file >> score;
		if (!file.eof()) {
			Score sc(name, score);
			s_db.Add_score_to_Scores(sc.getName(), sc.getScore());

		}
	}


	file.close();

}


