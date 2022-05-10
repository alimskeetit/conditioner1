#ifndef thermometer_h
#define thermometer_h
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Thermometer {
	ifstream ifs;				//������ ��� ������ ���������� �� �����
	ofstream ofs;				//������ ��� ������ ���������� � ����
	string name;				//��� �����, ������ ������ ���������� � �����������
	float temperature_in = 0;   //�����������, ������� ���� ���������
public:
	Thermometer();
	float& get_temperature();
};

Thermometer::Thermometer() {
	cout << "������� ��� ����� � ����������� .txt, ������ ����� ������ � ����������� ��������� � ������ ������: ";
	cin >> name;
	ifs.open(name + ".txt");
	while (!ifs.is_open()) {
		cout << "������ ��������! ������� ��� ����� ��� ���: ";
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