#pragma once
#include <string>
#include "Date.h"

class Task {
public:
	std::string taskName;
	Date taskDueDate;
	bool isDone;

	void printTask();
};

