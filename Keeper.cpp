#include "Keeper.h"
#include "Worker.h"
#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

Keeper::Keeper()
{
	
}

Keeper::~Keeper()
{
	for (int i = 0; i < count; i++) {
		delete workers[i];
	}
	
	cout << this << " (Keeper) deleted.\n";
}

void Keeper::addWorker(Worker* newWorker)
{
	count++;
	if (workers != nullptr) {
		Worker** newWorkers = new Worker* [count];
		int i = 0;
		for (i = 0; i < (count-1); i++) {
			newWorkers[i] = workers[i];
		}
		newWorkers[i] = newWorker;
		delete[] workers;
		workers = newWorkers;
	}
	else {
		workers =  new Worker * [1];
		workers[0] = newWorker;
	}

	std::sort(workers, workers + count-1, [](Worker* a, Worker* b) { return  (strcmp(a->getName(), b->getName())) < 0; });
}

void Keeper::deleteWorker(Worker* deleteWorker)
{
	for (int i = 0; i < count; i++) {
		if (workers[i] == deleteWorker) {
			count--;
			Worker** newWorkers = new Worker * [count];
			int k2 = 0;
			for (int k1 = 0; k1 < count ; k1++) {
				if (workers[k2] == deleteWorker) {
					k2++;
					
				};
				newWorkers[k1] = workers[k2];
				k2++;
			}
			deleteWorker->~Worker();
			
			delete[] workers;
			workers = newWorkers;
			if (count != 0) {
				std::sort(workers, workers + count - 1, [](Worker* a, Worker* b) { return  (strcmp(a->getName(), b->getName())) < 0; });
			}
			return;
		}
	}
	cout << "Данный работник не найден\n";
	return;
}

Worker* Keeper::getWorker(int index)
{
	try {
		if (index >= count) {
			throw "Ошибка - работник под таким номером не найден.\n";
		}
		return workers[index];
	}
	catch (const char* err) {
		cout << err;
		return nullptr;
	}
}

int Keeper::getCount()
{
	return count;
}

void Keeper::saveToFile()
{

	if (count == 0) {
		return;
	}
	ofstream fout;
	fout.open("file.txt");
	fout << count << '\n';
	for (int i = 0; i < count; i++) {
		fout << workers[i]->getName() << endl << workers[i]->getWork() << endl << workers[i]->getStartDate() << endl;
	}
	fout.close();
}

void Keeper::loadFromFile()
{
	int read_count;
	ifstream fin;
	fin.open("file.txt");
	char buff[50];
	fin.getline(buff, 50);
	read_count = buff[0] - 48;
	for (int i = 0; i < read_count; i++) {
		addWorker(new Worker());
		fin.getline(buff, 50);
		workers[i]->setName(buff);
		fin.getline(buff, 50);
		workers[i]->setWork(buff);
		fin.getline(buff, 50);
		workers[i]->setStartDate((int) (buff[0]-48));
	}
}




