#ifndef crc_h
#define crc_h
#include "conditioner.h"
class CRC {
	Conditioner& conditioner;
public:
	CRC(Conditioner& conditioner);
	bool on();
	bool off();
};

CRC::CRC(Conditioner& conditioner) : conditioner(conditioner) {}

bool CRC::on() {
	conditioner.on();
	return false;
}

bool CRC::off() {
	conditioner.off();
	return false;
}
#endif // !crc_h