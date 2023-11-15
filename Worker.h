#ifndef WORKER_H
#define WORKER_H
#include <iostream>
using namespace std;
class Worker {
public:
	Worker(); //����������� ��� ����������
	Worker(char* name, char* work, int start_date); //����������� � �����������
	Worker(Worker* prevWorker); // ����������� �����������
	~Worker(); //����������
	void setName(char* newName);
	void setWork(char* newWork);
	void setStartDate(int new_start_date);
	char* getName();
	char* getWork();
	int getStartDate();
	int start_date;
	friend istream& operator >> (istream& is, Worker& w) {
		char buff[50];
		is.getline(buff, 50);
		if (buff[0] == '\0') {
			is.getline(buff, 50);
		}
		w.setName(buff);
		is.getline(buff, 50);
		w.setWork(buff);
		is.getline(buff, 50);
		w.setStartDate(atoi(buff));
		return is;
	}
	friend ostream& operator << (ostream& os, Worker& w) {
		os << "���: " << w.getName() << endl << "���������: " << w.getWork() << endl << "��� ����������� �� ���������: " << w.getStartDate() << endl;
		return os;
	}
	

private:
	char* name;
	char* work;
	
};
#endif