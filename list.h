#pragma once
#include <vector>
#include <conio.h>
#include <Windows.h>
#include "Task.h"

class List {
private:
	std::vector<Task> tasks;
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

	void mainMenu();
	void createListMenu();
	void openedListMenu();
	
	bool loadFromFile();
	void displayList();
	void createNewList();
	void addNewTask();
	void removeTask();
	void updateTaskStatus();
	void loadToFile();
	void sortByDueDate();
};
