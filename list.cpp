#include "list.h"

void List::menu() {
	std::cout << "Welcome to your To-Do List!\n\n";
	std::cout << "What do you want to do?\n";
	std::cout << "1) Create a new To-Do List.\n2) Open your To-Do List.\n3) Close.\n\n";

	char op;

	std::cin.get(op);
	std::cin.get();

	if (op == '1') {
		system("cls");
		createNewList();
		displayList();

		std::cout << "What do you want to do?\n";
		std::cout << "1) Add new task.\n2) Close.\n";


		std::cin.get(op);
		std::cin.get();

		if (op == '1') {
			addNewObjective();
			system("cls");
			menu();
		}

		else if (op == '2') {
			system("cls");
			std::cout << "Hope you'll be back soon!\n";
		}
	}

	else if (op == '2') {
		if (loadFromFile()) {
			system("cls");
			displayList();

			std::cout << "What do you want to do?\n";
			std::cout << "1) Add new task.\n2) Remove task.\n3) Close.\n";

			std::cin.get(op);
			std::cin.get();

			if (op == '1') {
				addNewObjective();
				system("cls");
				menu();
			}

			else if (op == '2') {
				removeObjective();

				std::cout << "We are redirecting you to main menu!\n";
				Sleep(1500);
				system("cls");

				menu();
			}

			else if (op == '3') {
				system("cls");
				std::cout << "Hope you'll be back soon!\n";
			}
		}

		else {
			std::cout << "You don't have a To-Do List!\nWe are redirecting you to main menu!\n";
			Sleep(1500);
			system("cls");
			menu();
		}

	}

	else if (op == '3') {
		system("cls");
		std::cout << "Hope you'll be back soon!\n";
	}
}

bool List::loadFromFile() {
	std::ifstream fin(filepath);

	if (fin.peek() == EOF) {
		fin.close();
		return 0;
	}

	tasks.clear();

	Item aux;

	while (!fin.eof()) {
		getline(fin, aux.taskName);
		getline(fin, aux.taskDueDate);
			
		fin >> aux.isDone;
		fin.get();

		tasks.push_back(aux);
	}
	fin.close();

	return 1;
}

void List::displayList() {
	if (tasks.size() == 0)
		std::cout << "Your To-Do List is empty!\n\n";
	else {
		std::cout << "Here is your To-Do List:\n\n";
		for (int i = 0; i < tasks.size(); ++i) {
			std::cout << "Task no. " << i + 1 << ":\n";
			std::cout << "Task name: " << tasks[i].taskName << '\n';
			std::cout << "Task due date: " << tasks[i].taskDueDate << '\n';
			std::cout << "Task status: " << (tasks[i].isDone == true ? "Finished" : "Not Finished") << "\n\n";

		}
		std::cout << '\n';
	}
}

void List::createNewList() {
	std::ofstream fout(filepath);
	fout.close();

	tasks.clear();

	std::cout << "New To-Do list created succesfully!\n\n";
}

bool isCorrectDate(std::string date) {
	return 1;
}

void List::addNewObjective() {
	system("cls");

	Item aux;

	std::cout << "Enter task name: ";
	getline(std::cin, aux.taskName);

	std::cout << "Enter task due date (dd mm yyyy): ";
	getline(std::cin, aux.taskDueDate);

	aux.isDone = 0;

	tasks.push_back(aux);

	std::fstream file(filepath, std::ios::app);

	if (tasks.size() > 1)
		file << '\n';

	file << aux.taskName << '\n';
	file << aux.taskDueDate << '\n';
	file << aux.isDone;

	file.close();

	std::cout << "Task added succesfully!\n";
	Sleep(1000);
}

void List::removeObjective() {
	system("cls");
	displayList();

	std::cout << "Please number of task you want to remove: ";
	int n;
	std::cin >> n; --n;

	if (n >= 0 && n < tasks.size())
		tasks.erase(tasks.begin() + n);

	loadToFile();

	std::cout << "Task removed succesfully!\n\n";
}

void List::loadToFile() {
	std::ofstream fout(filepath);

	for (int i = 0; i < tasks.size(); ++i) {
		fout << tasks[i].taskName << '\n' << tasks[i].taskDueDate<<'\n'<<tasks[i].isDone;
		
		if (i < tasks.size() - 1)
			fout << '\n';
	}
}