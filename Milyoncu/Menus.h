#pragma once
#include<iostream>
#include<conio.h>
using namespace std;
//#include"File.h"
void Exit_menu() {
	system("cls");
	cout << "\n\n\n\t\t\t Program finished \t\t\t\n\n\n " << endl;
	system("pause");
}

int Start_program() {
	int choice_start_program = 0;
	while (true) {
		system("cls");
		cout << "\n\n\n\t\t\t MILYONCHU \t\t\t\n\n\n" << endl;
		if (choice_start_program == 0) {
			cout << " Admin <--- " << endl;
			cout << " Player " << endl;
			cout << " Exit \n\n\n " << endl;
		}
		else if (choice_start_program == 1) {
			cout << " Admin " << endl;
			cout << " Player <--- "<<endl;
			cout << " Exit \n\n\n " << endl;

		}
		else if (choice_start_program == 2) {
			cout << " Admin " << endl;
			cout << " Player " << endl;
			cout << " Exit <--- \n\n\n " << endl;
		}
		else {
			return 2;
			break;
		}
		int choice_start_program_up_down;
		choice_start_program_up_down = _getch();
		int second_choice;
		if (choice_start_program_up_down != 13) {
			second_choice = _getch();
		}
		if (choice_start_program_up_down == 13) {
			return choice_start_program;
			break;
		}
		else if (choice_start_program_up_down == 224 && second_choice == 72) {//yuxari
			if (choice_start_program != 0) {
				choice_start_program -= 1;
			}
		}
		else if (choice_start_program_up_down == 224 && second_choice == 80) {
			if (choice_start_program != 2) {
				choice_start_program += 1;
			}
		}
	}
	return 2;
}

int Admin_menu() {
	int choice_admin_menu = 0;
	while (true) {
		system("cls");
		cout << "\n\n\n\t\t\t MILYONCHU \t\t\t\n\n\n" << endl;
		if (choice_admin_menu == 0) {
			cout << " Add Exam <--- " << endl;
			cout << " Start Exam " << endl;
			cout << " Scores " << endl;
			cout << " Back \n\n\n " << endl;
		}
		else if (choice_admin_menu == 1) {
			cout << " Add Exam  " << endl;
			cout << " Start Exam <--- " << endl;
			cout << " Scores " << endl;
			cout << " Back \n\n\n " << endl;
		}
		else if (choice_admin_menu == 2) {
			cout << " Add Exam " << endl;
			cout << " Start Exam " << endl;
			cout << " Scores <--- " << endl;
			cout << " Back \n\n\n " << endl;
		}
		else if (choice_admin_menu == 3) {
			cout << " Add Exam " << endl;
			cout << " Start Exam " << endl;
			cout << " Scores " << endl;
			cout << " Back <--- \n\n\n " << endl;
		}
		else {
			return 3;
		}
		int choice_admin_up_down;
		choice_admin_up_down = _getch();
		int second_choice;
		if (choice_admin_up_down != 13) {
			second_choice = _getch();
		}
		if (choice_admin_up_down == 13) {
			return choice_admin_menu;
		}
		else if (choice_admin_up_down == 224 && second_choice == 72) {//yuxari
			if (choice_admin_menu != 0) {
				choice_admin_menu -= 1;
			}
		}
		else if (choice_admin_up_down == 224 && second_choice == 80) {
			if (choice_admin_menu != 3) {
				choice_admin_menu += 1;
			}
		}
	}
	return 3;
}

int Player_menu() {
	int choice_admin_menu = 0;
	while (true) {
		system("cls");
		cout << "\n\n\n\t\t\t MILYONCHU \t\t\t\n\n\n" << endl;
		if (choice_admin_menu == 0) {
			cout << " Start Exam <--- " << endl;
			cout << " About " << endl;
			cout << " Scores " << endl;
			cout << " Back \n\n\n " << endl;
		}
		else if (choice_admin_menu == 1) {
			cout << " Start Exam  " << endl;
			cout << " About <--- " << endl;
			cout << " Scores " << endl;
			cout << " Back \n\n\n " << endl;
		}
		else if (choice_admin_menu == 2) {
			cout << " Start Exam " << endl;
			cout << " About " << endl;
			cout << " Scores <--- " << endl;
			cout << " Back \n\n\n " << endl;
		}
		else if (choice_admin_menu == 3) {
			cout << " Start Exam " << endl;
			cout << " About " << endl;
			cout << " Scores " << endl;
			cout << " Back <--- \n\n\n " << endl;
		}
		else {
			return 3;
		}
		int choice_admin_up_down;
		choice_admin_up_down = _getch();
		int second_choice;
		if (choice_admin_up_down != 13) {
			second_choice = _getch();
		}
		if (choice_admin_up_down == 13) {
			return choice_admin_menu;
		}
		else if (choice_admin_up_down == 224 && second_choice == 72) {//yuxari
			if (choice_admin_menu != 0) {
				choice_admin_menu -= 1;
			}
		}
		else if (choice_admin_up_down == 224 && second_choice == 80) {
			if (choice_admin_menu != 3) {
				choice_admin_menu += 1;
			}
		}
	}
	return 3;
}
