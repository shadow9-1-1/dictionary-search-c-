#include<iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Linkedlist.h"
using namespace std;

int main() {

	//loading the word from the file into the linked list
	cout << "The file is loading, please wait...\n";
	Linkedlist lst;
	string file_name = "usa.txt";
	ifstream file(file_name);
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			lst.Append(line);
		}
		file.close();
		cout << "Load Complete From File \"" << file_name << "\"" << endl;
		cout << "list contains " << lst.Count() << " Item" << endl;
	}
	else {
		cout << "Error: Unable to open file \"" << file_name << "\"" << endl;
		return 0; //if the file can't open for any reason the program will end 
	}


	//welcome message for the program
	cout << "--------------------------------------------------------" << endl;
	cout << "|----****                                      ****----|" << endl;
	cout << "|----**      Welcome to the dictionary search    **----|" << endl;
	cout << "|----****                                      ****----|" << endl;
	cout << "|------------------------------------------------------|" << endl;
	cout << "|  To use the program enter the number of your choose  |" << endl;
	cout << "|  to end the program enter end or 0 in the main menu  |" << endl;
	cout << "--------------------------------------------------------" << endl;


	//while loop for the project to not to stop until the user want
	while (true) {

		//main menu
		string choose;
		cout << "1. Search for a specific word" << endl;
		cout << "2. Search for a word that starts with.." << endl;
		cout << "3. Search for a word that ends with.." << endl;
		cout << "4. Search for a word that contains.." << endl;
		cout << "Enter your choice: ";
		cin >> choose;

		if (choose == "1") { //the part for the specific word
			string wordinput;
			cout << "Enter the word to search for it: ";
			cin >> wordinput;
			int wordoutput = lst.search(wordinput); //the function search to get the location of the word
			if (wordoutput > 0) {
				cout << "word \"" << wordinput << "\" Found At line: " << wordoutput << endl;
			}
			else
			{
				cout << "word \"" << wordinput << "\" Not Found \n";
			}
			

		}
		else if (choose == "2") { //the part for the start with
			string wordinputSW;
			cout << "Enter the letters to search for it(starts with): ";
			cin >> wordinputSW;
			vector<string> matches = lst.StartsWith(wordinputSW); //the function StartsWith that return vector contain the word
			if (matches.empty()) { //if empty is true then there is no word match the input
				cout << "No words found starting with the letters '" << wordinputSW << "'" << endl;
			}
			else {
				cout << matches.size() << " Words Found starting with the letters '" << wordinputSW << "':" << endl;
				for (string word : matches) {
					cout << word << endl;
				}
			}
			

		}
		else if (choose == "3") { //the part for the end with
			string wordinputEW;
			cout << "Enter the letters to search for it(ends with): ";
			cin >> wordinputEW;
			vector<string> matches = lst.EndsWith(wordinputEW); //the function EndsWith that return vector contain the word
			if (matches.empty()) { //if empty is true then there is no word match the input
				cout << "No words found ending with the letters '" << wordinputEW << "'" << endl;
			}
			else {
				cout << matches.size() << " Words Found ending with the letters '" << wordinputEW << "':" << endl;
				for (string word : matches) {
					cout << word << endl;
				}
			}
			

		}
		else if (choose == "4") { //the part for the contains
			string wordinputF;
			cout << "Enter the letters to search for it(contains): ";
			cin >> wordinputF;
			vector<string> matches = lst.Find(wordinputF); //the function Find that return vector contain the word
			if (matches.empty()) { //if empty is true then there is no word match the input
				cout << "No words found contain the letters '" << wordinputF << "'" << endl;
			}
			else {
				cout << matches.size() << " Words Found contain the letters '" << wordinputF << "':" << endl;
				for (string word : matches) {
					cout << word << endl;
				}
			}
			

		}
		else if (choose == "0" || choose == "end" || choose == "End") { //the part for the program to end or close 
			cout << "--------------------------------------------------------" << endl;
			cout << "|----****                                      ****----|" << endl;
			cout << "|----**  thanks for using the dictionary search  **----|" << endl;
			cout << "|----****                                      ****----|" << endl;
			cout << "|------------------------------------------------------|" << endl;
			cout << "|                     Program End                      |" << endl;
			cout << "--------------------------------------------------------" << endl;
			return 0;
		}
		else //the part for the input if not correct or valid
		{
			cout << "check your input" << endl;
			
		}
		cout << "--------------------------------------------------------" << endl; //to show that the one lap is done
	}

	return 0;


}