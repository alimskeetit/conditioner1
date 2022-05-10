#ifndef functions_h
#define functions_h
#include <iostream>
#include <string>
#include <fstream>
#include "thermometer.h"
using namespace std;

void get_int(int& x) {
	cin >> x;
}

void get_float(float& x) {
	cin >> x;
}

void work(string name) {
	ofstream ofs;
	ofs.open(name + ".txt", ofstream::out | ofstream::trunc);
	ofs.close();
	ofs.open(name + ".txt");
}
#endif