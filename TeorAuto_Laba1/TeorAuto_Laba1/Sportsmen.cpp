#include "Sportsmen.h"

void Sportsmen::printCh() {
	std::cout << std::setw(12) << std::left << name << std::setw(4) << beg100 << "\t" << std::setw(4) << beg3km << "\t" << std::setw(4) << podtyag << "\t" << std::setw(4) << otgimania << "\t" << std::setw(4) << prigok << "\t" << std::endl;
}

int Sportsmen::parametr(int h, Sportsmen N)
{
	if (h == 1) {
		if ((beg100 < N.beg100) == 1) return 1;
		if ((beg100 == N.beg100) == 1) return 2;
		if ((beg100 < N.beg100) == 0) return 0;
	}
	else if (h == 2) {
		if ((beg3km < N.beg3km) == 1) return 1;
		if ((beg3km == N.beg3km) == 1) return 2;
		if ((beg3km < N.beg3km) == 0) return 0;

	}
	else if (h == 3) {
		if ((podtyag > N.podtyag)== 1) return 1;
		if ((podtyag == N.podtyag) == 1) return 2;
		if ((podtyag > N.podtyag) == 0) return 0;
	}
	else if (h == 4) {
		if ((otgimania > N.otgimania) == 1) return 1;
		if ((otgimania == N.otgimania) == 1) return 2;
		if ((otgimania > N.otgimania) == 0) return 0;

	}
	else if (h == 5) {
		if ((prigok> N.prigok) == 1) return 1;
		if ((prigok == N.prigok) == 1) return 2;
		if ((prigok > N.prigok) == 0) return 0;
	}
	
}


