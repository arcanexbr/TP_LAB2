#ifndef WORKER_H
#define WORKER_H
class Worker {
public:
	Worker(); //конструктор без параметров
	Worker(char* name, char* work, int start_date); //конструктор с параметрами
	Worker(Worker* prevWorker); // конструктор копирования
	~Worker(); //деструктор
	void setName(char* newName);
	void setWork(char* newWork);
	void setStartDate(int new_start_date);
	char* getName();
	char* getWork();
	int getStartDate();
	int start_date;
	

private:
	char* name;
	char* work;
	
};
#endif