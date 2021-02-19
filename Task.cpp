#include "Task.h"

void Task::printTask() {
	std::cout << "Task name: " << this->taskName << '\n';
	std::cout << "Task due date: ";
	this->taskDueDate.printDate();
	std::cout << '\n';
	std::cout << "Task status: " << (this->isDone == true ? "Finished" : "Not Finished") << "\n\n";
}

void Task::markAsDone() {
	isDone = true;
}
