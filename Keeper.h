#ifndef KEEPER_H
#define KEEPER_H
#include "Worker.h"
class Keeper {
public:
	Keeper(); //����������� ��� ����������
	~Keeper(); //����������
	void addWorker(Worker* newWorker);
	void deleteWorker(Worker* deleteWorker);
	Worker* getWorker(int index);
	void saveToFile();
	void loadFromFile();
	

private:
	int count = 0;
	Worker** workers;
	void sorting();
	
};
#endif