#pragma once
#include <iostream>
#include <iomanip>

class Sportsmen
{	
	public:
		
		std::string name;
		double beg100, beg3km, prigok;
		int podtyag, otgimania;

		void printCh();
		int parametr(int h, Sportsmen N);

};

