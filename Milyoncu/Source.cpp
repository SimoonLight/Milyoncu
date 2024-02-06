#include<iostream>
using namespace std;
#include"QuestionH.h"
#include"ExamH.h"
#include"Menus.h"
#include"File.h"
#include"AboutH.h"
void main() {

	while (true) {
	go_back_main_menu:
		int first_choice = Start_program();

		if (first_choice == 0) {
		go_back_admin_menu:
			int admin_choice_in_main_menu = Admin_menu();
			if (admin_choice_in_main_menu == 0) {
				Add_question_for_file();
				system("cls");
				cout << "\n\n\n\t\t\t MILYONCHU \t\t\t\n\n\n" << endl;
				cout << "\t\t\t Exam added \t\t\t \n\n\n" << endl;
				system("pause");
			}
			else if (admin_choice_in_main_menu == 1) {//start exam
				DataBase db;
				read_Question_from_file(db);
				int choice = select_Exam(db);//db


				if (choice == db.getExamCount()) {
					goto go_back_admin_menu;
				}

				Exam milyoncu_suallari;
				prepare_questions(milyoncu_suallari, db.getExam()[choice]);

				int xal=start_Exam(milyoncu_suallari);
				string a = to_string(xal);
				
				Score sco("admin", a);

				write_ScoreToFile(sco);
				

			}
			else if (admin_choice_in_main_menu == 2) {
				Scores_DataBase sc_db;
				system("cls");
				cout << "\n\n\n\t\t\t Scores \t\t\t\n\n\n" << endl;
				read_Score_from_file(sc_db);
				sc_db.print_all_scores();
				system("pause");
			}
			else if (admin_choice_in_main_menu == 3) {
				goto go_back_main_menu;
			}
		}
		else if (first_choice == 1) {
			system("cls");
			cout << "\n\n\n\t\t\t MILYONCHU \t\t\t\n\n\n" << endl;
			string player_name;
			cout << " Enter your name : ";
			cin >> player_name;
		go_back_player_menu:
			int player_choice_in_main_menu = Player_menu();
			if (player_choice_in_main_menu == 0) {
				DataBase db;
				read_Question_from_file(db);
				int choice = select_Exam(db);//db


				if (choice == db.getExamCount()) {
					goto go_back_admin_menu;
				}

				Exam milyoncu_suallari;
				prepare_questions(milyoncu_suallari, db.getExam()[choice]);

				int xal = start_Exam(milyoncu_suallari);
				string a = to_string(xal);

				Score sco(player_name, a);

				write_ScoreToFile(sco);

			}
			else if (player_choice_in_main_menu == 1) {
				system("cls");
				cout << "\n\n\n\t\t\t MILYONCHU \t\t\t\n\n\n" << endl;
				cout << about_milyoncu;
				system("pause");
				goto go_back_player_menu;
			}
			else if (player_choice_in_main_menu == 2) {
				Scores_DataBase sc_db;
				system("cls");
				cout << "\n\n\n\t\t\t Scores \t\t\t\n\n\n" << endl;
				read_Score_from_file(sc_db);
				sc_db.print_all_scores();
				system("pause");
				goto go_back_player_menu;
			}
			else if (player_choice_in_main_menu == 3) {
				goto go_back_main_menu;
			}
		}
		else {
			Exit_menu();
			break;
		}
	}

}