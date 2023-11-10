#include "Keeper.h"
#include "Worker.h"
#include <algorithm>
#include <fstream>
using namespace std;

Keeper::Keeper()
{
	
}

Keeper::~Keeper()
{
	delete [] workers;
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
}

Worker* Keeper::getWorker(int index)
{
	return workers[index];
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
	
}


void Keeper::sorting()
{

}

