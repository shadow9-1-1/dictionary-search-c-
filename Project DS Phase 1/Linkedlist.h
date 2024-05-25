#include<iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#pragma once


//class node for the linked list
class Node {
public:
	string Data;
	Node* Next;
};


class Linkedlist
{
public:
	Node* Head;


	//defined the linked list

	Linkedlist() { 
		Head = NULL;
	}


	//to check if the linked list empty of not

	bool isempty() {

		return (Head == NULL); //if empty return true
	}


	
	//function to insert in the first of the linked list 

	void InsetFirst(string NewData) {
		Node* NewNode = new Node;
		NewNode->Data = NewData;
		

		if (isempty()) {
			NewNode->Next = NULL;
		}
		else
		{
			NewNode->Next = Head;
		}
		Head = NewNode;
	}


	//function to insert before specific element in the linked list (NOT used in this project)

	void InsertBefor(string Data, string NewData) {
		if (search(Data) > 0) {
			Node* temp = Head;
			while (temp != NULL || temp->Next->Data == Data) {
				temp = temp->Next;
			}
			Node* NewNode = new Node;
			NewNode->Data = NewData;
			NewNode->Next = temp->Next;
			temp->Next = NewNode;
		}
		else
		{
			cout << "Data Not Found";
		}

	}


	//function to insert normally in the linked list element after element

	void Append(string NewData) {
		if (isempty()) {
			InsetFirst(NewData);
		}
		else
		{
			Node* temp = Head;
			Node* NewNode = new Node;
			NewNode->Data = NewData;
			while (temp->Next != NULL) {
				temp = temp->Next;
			}
			NewNode->Next = NULL;
			temp->Next = NewNode;
		}

	}



	//function to display the element that in the linked list 

	void Display() {
		Node* temp = Head;
		while (temp != NULL)
		{
			cout << temp->Data << endl;
			temp = temp->Next;
		}
	}


	//function to count how many element in the linked list 

	int Count() {
		int counter = 0;
		Node* temp = Head;
		while (temp != NULL)
		{
			counter++;
			temp = temp->Next;
		}
		return counter;
	}


	//search Function to search for a specific element in the list  

	int search(string Word) {
		int searchP = 0;
		Node* temp = Head;
		while (temp != NULL)
		{
			searchP++; //to locate where the word is in the file and the linked list
			if (temp->Data == Word) {

				return searchP;
				break;
			}
			else
			{

				temp = temp->Next;
			}

		}
		return 0;
	}


	//starts With Function to search for the elements in the list that start with specific letters

	vector<string> StartsWith(string key) {
		vector<string> matches; //vector to store the match words
		Node* temp = Head;
		while (temp != NULL) {
			int match = 0; //reset match count for each node
			for (int i = 0; i < key.size(); i++) {
				if (temp->Data[i] != key[i]) {
					break; //stop comparing if a match is NOT found
				}
				match++;
			}
			if (match == key.size()) { //if match count = key size then ther was a match and add it to the vector
				matches.push_back(temp->Data);
			}
			temp = temp->Next;
		}
		return matches;
	}



	//end With Function to search for the elements in the list that end with specific letters

	vector<string> EndsWith(string key) {
		vector<string> matches; //vector to store the match words
		Node* temp = Head;
		while (temp != NULL) {
			int keysize = key.size() - 1; //to set the size of the key for the while loop to go backward 
			int wordsize = temp->Data.size() - 1; //to set the size of the word for the while loop to go backward
			int match = 0;
			while (keysize >= 0 && wordsize >= 0) {
				if (temp->Data[wordsize] != key[keysize]) {
					break;
				}
				match++;
				keysize--;
				wordsize--;
			}
			if (match == key.size()) { //if match count = key size then ther was a match and add it to the vector
				matches.push_back(temp->Data);
			}
			temp = temp->Next;
		}
		return matches;
	}

	//chick inside the word function is a helper function for the find function that check inside the word it self 
	bool CheckInsideW(string word, string key) {
		for (int i = 0; i < word.size(); i++) {
			int j;
			for (j = 0; j < key.size(); j++) {
				if (word[i + j] != key[j]) {
					break;
				}
			}
			if (j == key.size()) {
				return true; 
			}
		}
		return false;
	}


	//find Function to search for the elements in the list that contains specific letters

	vector<string> Find(string key) {
		vector<string> matches;
		Node* temp = Head;
		while (temp != NULL) {
			if (CheckInsideW(temp->Data, key)) { //if true then ther was a match and add it to the vector
				matches.push_back(temp->Data);
			}
			temp = temp->Next;
		}
		return matches;
	}

};

