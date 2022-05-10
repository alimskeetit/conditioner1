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
	enum COMANDS { OFF, ON };						//������� ����������/���������
	enum DEFAULT_MODE { HEAT, COOL, FAN, DRY };		//������ �� ���������
	bool on_off = OFF;								//��������� ������������: ������� ��� ��������
	float default_temp;								//�����������, ��������������� �� ����� ���������
	float temperature;								//�����������, �� ������� �������� �����������
	float temperature_max, temperature_min;

	string model;				//��������/������ ������������
	Thermometer* thermometer;
	struct Mode {
		int new_temp;
	};
	thread* th_ptr = nullptr;	//��������� �� �����
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
	cout << "����������� ������\n";
	cout << "������� ��������/������ ������������: ";
	cin >> model;
	cout << "������� ���������� �����������, ������� ����� ����������� �����������:";
	get_float(temperature_min);
	cout << "������� ���������� �����������, ������� ����� ����������� ����������� : ";
	get_float(temperature_min);
	cout << "������� ����� ����������� ����� �� ���������, ��� ��������� ������������: ";
	get_float(default_temp);
	temperature = default_temp;
}
Conditioner::~Conditioner() {
	delete th_ptr;
}

bool Conditioner::on() {
	if (!on_off) {
		cout << "����������� �������\n";
		on_off = ON;
		th_ptr = new thread(&Conditioner::work, this);
	}
	return 0;
}

bool Conditioner::off() {
	if (on_off) {
		cout << "����������� ��������\n";
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