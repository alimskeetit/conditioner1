#ifndef conditioner_h
#define conditioner_h
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <chrono>
#include <fstream>
#include "thermometer.h"
#include "functions.h"
using namespace std;
class Conditioner {
	enum COMANDS { OFF, ON };						//команды выключения/включения
	enum DEFAULT_MODE { HEAT, COOL, FAN, DRY };		//режими по умолчанию
	bool on_off = OFF;								//состояние кондиционера: включён или выключен
	float default_temp;								//температура, устанавливаемая во время включения
	float temperature;								//температура, по которой работает кондиционер
	float temperature_max, temperature_min;

	string model;				//название/модель кондиционера
	Thermometer* thermometer;
	struct Mode {
		int new_temp;
	};
	thread* th_ptr = nullptr;	//указатель на поток
	vector<Mode> modes;
	void work();
public:
	bool on();
	bool off();
	int get_temperature();
	bool set_thermometer(Thermometer* thermometer);
	Conditioner(Thermometer* thermometer);
	~Conditioner();
};

bool Conditioner::set_thermometer(Thermometer* thermometer)
{
	this->thermometer = thermometer;
	return false;
}

Conditioner::Conditioner(Thermometer* thermometer) : thermometer(thermometer) {
	cout << "Кондиционер создан\n";
	cout << "Введите название/модель кондиционера: ";
	cin >> model;
	cout << "Введите наименьшую температуру, которую будет выдерживать кондиционер:";
	get_float(temperature_min);
	cout << "Введите наибольшую температуру, которую будет выдерживать кондиционер : ";
	get_float(temperature_min);
	cout << "Введите какая температура будет по умолчанию, при включении кондиционера: ";
	get_float(default_temp);
	temperature = default_temp;
}
Conditioner::~Conditioner() {
	delete th_ptr;
}

bool Conditioner::on() {
	if (!on_off) {
		cout << "Кондиционер включен\n";
		on_off = ON;
		th_ptr = new thread(&Conditioner::work, this);
	}
	return 0;
}

bool Conditioner::off() {
	if (on_off) {
		cout << "Кондиционер выключен\n";
		on_off = OFF;
		th_ptr->detach();
	}
	return 0;
}

void Conditioner::work() {
	while (true) {
		thermometer->get_temperature();
		this_thread::sleep_for(chrono::milliseconds(3000));
	}
}
#endif