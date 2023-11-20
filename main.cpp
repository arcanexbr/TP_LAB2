#include <iostream>
#include <Windows.h>
#include "Keeper.h"
#include "Worker.h"
#include "TextCorrector.h"
using namespace std;
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Keeper keeper;
	keeper.loadFromFile();
	cout << "Сотрудники загружены из файла.\n";
	int c = 0;
	
	while (c < 5) {
		cout << "Список соттрудников: \n";
		for (int i = 0; i < keeper.getCount(); i++) {
			cout << i + 1 << ")\n" << *(keeper.getWorker(i)) << endl;
		}
		cout << "Функции: \n1.Добавить работника\n2.Редактировать работника\n3.Удалить работника\n4.Вывести имена сотрудников со стажем выше заданного\n5.Выход\n";
		cin.clear();
		cin >> c;
		int b = 0;
		int k = 0;
		switch (c) {
			
		case (1):
			cout << "Перечислите ФИО, Должность и год вступления на должность отдельно через Enter:\n";
			keeper.addWorker(new Worker());
			cin >> *(keeper.getWorker(keeper.getCount() - 1));
			keeper.sort();
			break;
		case(2):
			cout << "Введите номер сотрудника:\n";
			cin >> k;
			if (keeper.getWorker(k - 1) == nullptr) {
				cout << "Сотрудника под таким номером нет.\n";
				break;
			}
			cout << "Что изменить?\n1.ФИО\n2.Должность\n3.Год вступления в должность\n";
			cin >> b;
			char buff[50];
			cin.getline(buff, 50);
			switch (b) {	
			case(1):
				cout << "Новое ФИО: ";

				cin.getline(buff, 50);
				keeper.getWorker(k - 1)->setName(buff);
				keeper.sort();
				cout << endl;
				break;
			case(2):
				cout << "Новая должность: ";
				cin.getline(buff, 50);
				keeper.getWorker(k - 1)->setWork(buff);
				cout << endl;
				break;
			case(3):
				cout << "Новый год вступления на должность: ";
				cin.getline(buff, 50);
				keeper.getWorker(k - 1)->setStartDate(atoi(buff));
				cout << endl;
				break;
			}
			break;
		case(3):
			cout << "Номер сотрудника для удаления: ";
			cin >> k;
			cout << endl;
			keeper.deleteWorker(keeper.getWorker(k-1));
			break;
		case(4):
			cout << "Минимальный стаж: ";
			int st = 0;
			cin >> st;
			for (int i = 0; i < keeper.getCount(); i++) {
				if (2023 - keeper.getWorker(i)->getStartDate() > st) {
					cout << i + 1 << ")\n" << *(keeper.getWorker(i));
				}
			}
			
			break;

		}
		cout << "--------------------------------------\n";
	}
	keeper.saveToFile();

	TextCorrector::start2();


}

