#include "conditioner.h"
#include "thermometer.h"
#include "functions.h"
#include "crc.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "");
	Thermometer thermometer;
	Conditioner conditioner(&thermometer);
	CRC pult(conditioner);
}