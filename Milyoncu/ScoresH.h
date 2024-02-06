#pragma once
#include<iostream>
using namespace std;

class Score {
private:
	string* _name;
	string* _score;
public:

	//gets
	
	string getName()const {
		return *this->_name;
	}
	string getScore()const {
		return *this->_score;
	}

	//sets

	void setName(string name) {
		if (this->_name != NULL) {
			delete this->_name;
		}
		if (name.length() == 0) {
			this->_name = new string;
			*this->_name = "Empty";
		}
		else {
			this->_name = new string;
			*this->_name = name;
		}
	}	
	void setScore(string score) {
		if (this->_score != NULL) {
			delete this->_score;
		}
		if (score.length() == 0) {
			this->_score = new string;
			*this->_score = "Empty";
		}
		else {
			this->_score = new string;
			*this->_score = score;
		}
	}

	//construcktors

	Score() {
		this->setName("");
		this->setScore("");
	}
	Score(string name, string score):Score() {
		this->setName(name);
		this->setScore(score);
	}
	/*~Score() {
		if (this->_name != NULL) {
			delete this->_name;
		}
		if (this->_score != NULL) {
			delete this->_score;
		}
	}*/



};

class Scores_DataBase {
private:
	Score** _scores;
	int _count_scores;
public:
	//gets
	Score** getScores()const {
		return this->_scores;
	}
	int getCount_scores()const {
		return this->_count_scores;
	}
	//sets
	void setCount_scores(int new_count) {
		if (new_count < 0) {
			this->_count_scores = 0;
		}
		else {
			this->_count_scores=new_count;
		}
	}
	//construcktors
	Scores_DataBase() {
		this->_scores = NULL;
		this->setCount_scores(0);
	}
	~Scores_DataBase() {
		delete this->_scores;
	}
	//funks
	void print_all_scores() {
		for (size_t i = 0; i < this->getCount_scores(); i++)
		{
			cout << " " << this->_scores[i]->getName() << " - " << this->_scores[i]->getScore() << endl;
		}
	}
	

	void Add_score_to_Scores(string name, string score) {
		Score* new_score = new Score(name, score);
		Score** new_scores = new Score * [this->_count_scores + 1];
		for (int i = 0; i < this->_count_scores; i++) {
			new_scores[i] = this->_scores[i];
		}
		new_scores[this->_count_scores] = new_score;
		delete[] this->_scores;
		this->_scores = new_scores;
		this->_count_scores++;
	}
};