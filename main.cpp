#include <iostream>
#include <Windows.h>
#include "Keeper.h"
#include "Worker.h"
using namespace std;
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Worker worker1;
	Worker worker2;
	Worker worker3;
	Keeper keeper;
	worker1.setName(_strdup("АБ"));
	worker2.setName(_strdup("АА"));
	worker3.setName(_strdup("АВ"));
	worker1.setWork(_strdup("Столяр"));
	worker2.setWork(_strdup("Маляр"));
	worker3.setWork(_strdup("Фрезеровщик"));
	worker1.setStartDate(2002);
	worker2.setStartDate(2008);
	worker3.setStartDate(2015);

	keeper.addWorker(&worker1);
	keeper.addWorker(&worker2);
	keeper.addWorker(&worker3);
	cout << keeper.getWorker(0)->getName() << endl;
	cout << keeper.getWorker(1)->getName() << endl;
	cout << keeper.getWorker(2)->getName() << endl;



}

