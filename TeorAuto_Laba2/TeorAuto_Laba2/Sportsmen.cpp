#include "Sportsmen.h"

void Sportsmen::printCh() {
	std::cout << std::setw(12) << std::left << name << std::setw(4) << beg100 << "\t" << std::setw(4) << beg3km << "\t" << std::setw(4) << podtyag << "\t" << std::setw(4) << otgimania << "\t" << std::setw(4) << prigok << "\t" << std::endl;
}