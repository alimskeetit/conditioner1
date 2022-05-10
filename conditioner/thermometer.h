#ifndef thermometer_h
#define thermometer_h
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Thermometer {
	ifstream ifs;				//объект для чтения информации из файла
	ofstream ofs;				//объект для записи информации в файл
	string name;				//имя файла, откуда берётся информация о температуре
	float temperature_in = 0;   //температура, которую снял термометр
public:
	Thermometer();
	float& get_temperature();
};

Thermometer::Thermometer() {
	cout << "Введите имя файла с расширением .txt, откуда взять данные о температуре помещения в данный момент: ";
	cin >> name;
	ifs.open(name + ".txt");
	while (!ifs.is_open()) {
		cout << "Ошибка открытия! Введите имя файла ещё раз: ";
		cin >> name;
		ifs.open(name + ".txt");
	}
	ifs.close();
}

float& Thermometer::get_temperature() {
	ifs.open(name + ".txt");
	ifs >> temperature_in;
	ifs.close();
	return temperature_in;
}
#endif