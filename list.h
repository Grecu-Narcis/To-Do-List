#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>

struct Item {
	std::string taskName, taskDueDate;
	bool isDone;
};

class List {
private:
	std::vector<Item> tasks;
	const char filepath[10] = "list.txt";

public:
	List() { // creates a file to store the list
		std::ifstream fin(filepath);

		if (fin.is_open() == 0) {
			std::ofstream fout(filepath);
			fout.close();
		}

		else
			fin.close();
	}

	void menu();
	bool loadFromFile();
	void displayList();
	void createNewList();
	void addNewObjective();
	void removeObjective();
	void loadToFile();
};

