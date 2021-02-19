#include "list.h"

void List::createListMenu() {
	char op;

	system("cls");
	createNewList();
	displayList();

	std::cout << "What do you want to do?\n";
	std::cout << "1) Add new task.\n2) Close.\n";


	op = _getch();

	if (op == '1') {
		addNewTask();
		system("cls");
		openedListMenu();
	}

	else if (op == '2') {
		system("cls");
		std::cout << "Hope you'll be back soon!\n";
	}
}

void List::openedListMenu() {
	char op;
	
	if (loadFromFile()) {
		system("cls");
		displayList();

		std::cout << "What do you want to do?\n";
		std::cout << "1) Add new task.\n2) Remove task.\n3) Mark task as done.\n4) Close\n";

		op = _getch();

		if (op == '1') {
			addNewTask();

			Sleep(1500);

			system("cls");
			openedListMenu();
		}

		else if (op == '2') {
			removeTask();

			Sleep(1500);
			
			system("cls");
			openedListMenu();
		}

		else if (op == '3') {
			system("cls");
			updateTaskStatus();
			Sleep(1500);
			openedListMenu();
		}

		else if (op == '4') {
			system("cls");
			std::cout << "Hope you'll be back soon!\n";
		}
	}

	else {
		std::cout << "You don't have a To-Do List!\nWe are redirecting you to main menu!\n";
		Sleep(1500);
		system("cls");
		mainMenu();
	}
}

void List::mainMenu() {
	std::cout << "Welcome to your To-Do List!\n\n";
	std::cout << "What do you want to do?\n";
	std::cout << "1) Create a new To-Do List.\n2) Open your To-Do List.\n3) Close.\n\n";

	char op;

	op = _getch();

	if (op == '1') {
		createListMenu();
	}

	else if (op == '2') {
		openedListMenu();
	}

	else if (op == '3') {
		system("cls");
		updateTaskStatus();
	}
}

bool List::loadFromFile() {
	std::ifstream fin(filepath);

	if (fin.peek() == EOF) {
		fin.close();
		return 0;
	}

	tasks.clear();

	Task aux;

	while (!fin.eof()) { // read every task while file is not empty
		getline(fin, aux.taskName);
		fin >> aux.taskDueDate.day >> aux.taskDueDate.month >> aux.taskDueDate.year;
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
		sortByDueDate();

		std::cout << "Here is your To-Do List:\n\n";
		for (int i = 0; i < tasks.size(); ++i) {
			std::cout << "Task no. " << i + 1 << ":\n";
			tasks[i].printTask();
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

void List::addNewTask() {
	system("cls");

	Task aux;

	std::cout << "Enter task name: ";
	getline(std::cin, aux.taskName);

	std::cout << "Enter task due date (dd mm yyyy): ";
	std::cin >> aux.taskDueDate.day >> aux.taskDueDate.month >> aux.taskDueDate.year;

	aux.isDone = 0;

	tasks.push_back(aux);

	std::fstream file(filepath, std::ios::app);

	if (tasks.size() > 1)
		file << '\n';

	file << aux.taskName << '\n';
	
	aux.taskDueDate.printDate(file);
	
	file << ' ';
	file << aux.isDone;

	file.close();

	std::cout << "Task added succesfully!\n";
	Sleep(1000);
}

void List::removeTask() {
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

void List::updateTaskStatus() {
	system("cls");
	displayList();

	std::cout << "Enter task id: ";
	int id;
	std::cin >> id;

	tasks[id - 1].markAsDone();
	loadToFile();

	std::cout << "Task marked as done succesfully!\n";

}

void List::loadToFile() {
	std::ofstream fout(filepath);

	for (int i = 0; i < tasks.size(); ++i) {
		fout << tasks[i].taskName << '\n';
		tasks[i].taskDueDate.printDate(fout);
		fout << ' ' << tasks[i].isDone;
		
		if (i < tasks.size() - 1)
			fout << '\n';
	}
}

void List::sortByDueDate() {
	int i, j, n = tasks.size();

	for (i=0;i<n-1;++i)
		for (j=i+1;j<n;++j)
			if (tasks[i].taskDueDate > tasks[j].taskDueDate) {
				Task aux = tasks[i];
				tasks[i] = tasks[j];
				tasks[j] = aux;
			}
}
