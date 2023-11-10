#include "Worker.h"
#include <string.h>
#include <iostream>
using namespace std;

Worker::Worker()
{
	name = new char[] {"Имя не задано"};
	work = new char[] {"Должность не задана"};
	start_date = 2023;
}

Worker::Worker(char* newName, char* newWork, int new_start_date)
{
	name = new char[strlen(newName) + 1];
	strcpy_s(name, strlen(newName) + 1, newName);
	work = new char[strlen(newWork) + 1];
	strcpy_s(work, strlen(newWork) + 1, newWork);
	start_date = new_start_date;
}

Worker::Worker(Worker* prevWorker)
{
	name = prevWorker->getName();
	work = prevWorker->getWork();
	start_date = prevWorker->getStartDate();
}

Worker::~Worker()
{
	if (name != nullptr) {
		delete[] name;
	}
	if (work != nullptr) {
		delete[] work;
	}
	cout << this << " (Worker) deleted.\n";
}

void Worker::setName(char* newName) {
	if (name != nullptr) {
		delete[] name;
	}
	name = new char[strlen(newName) + 1];
	strcpy_s(name, strlen(newName) + 1, newName);
}

void Worker::setWork(char* newWork)
{
	if (work != nullptr) {
		delete[] work;
	}
	work = new char[strlen(newWork) + 1];
	strcpy_s(work, strlen(newWork) + 1, newWork);
}

void Worker::setStartDate(int new_start_date)
{
	start_date = new_start_date;
}

char* Worker::getName()
{
	char* returnName = new char[strlen(name) + 1];
	strcpy_s(returnName, strlen(name) + 1, name);
	return returnName;
}

char* Worker::getWork()
{
	char* returnWork = new char[strlen(work) + 1];
	strcpy_s(returnWork, strlen(work) + 1, work);
	return returnWork;
}

int Worker::getStartDate()
{
	return start_date;
}
