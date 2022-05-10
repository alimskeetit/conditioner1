#include "conditioner.h"
#include "thermometer.h"
#include "functions.h"
#include "crc.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "");
	Thermometer thermometer2;
	Conditioner conditioner(&thermometer2);
	CRC pult(conditioner);
}