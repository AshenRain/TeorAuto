#include <iostream>
#include <vector>
#include "Sportsmen.h"


int sravnen(int& h, Sportsmen A, Sportsmen N);


int main()
{
#pragma region Dobablenie elementov
	setlocale(LC_ALL, "Russian");

	std::vector<Sportsmen*> mySp;
	std::vector<Sportsmen*> myFiltr;
	std::vector<Sportsmen*> myFiltr2;

	Sportsmen* N1 = new Sportsmen();
	N1->id = 1;
	N1->name = "Спиридонов";
	N1->beg100 = 9.8;
	N1->beg3km = 13.2;
	N1->otgimania = 50; // 50
	N1->podtyag = 12; // 12
	N1->prigok = 2.02;

	Sportsmen* N2 = new Sportsmen();
	N2->id = 2;
	N2->name = "Погодин";
	N2->beg100 = 15;
	N2->beg3km = 10;
	N2->otgimania = 10;
	N2->podtyag = 22; // 22
	N2->prigok = 3;

	Sportsmen* N3 = new Sportsmen();
	N3->id = 3;
	N3->name = "Сапожников";
	N3->beg100 = 9.9;
	N3->beg3km = 8.6;
	N3->otgimania = 70;
	N3->podtyag = 40;
	N3->prigok = 3;

	Sportsmen* N4 = new Sportsmen();
	N4->id = 4;
	N4->name = "Воронков";
	N4->beg100 = 17;
	N4->beg3km = 11;
	N4->otgimania = 25;
	N4->podtyag = 7;
	N4->prigok = 1.7;

	Sportsmen* N5 = new Sportsmen();
	N5->id = 5;
	N5->name = "Владов";
	N5->beg100 = 10;
	N5->beg3km = 9.8;
	N5->otgimania = 55;
	N5->podtyag = 40;
	N5->prigok = 2.5;

	Sportsmen* N6 = new Sportsmen();
	N6->id = 6;
	N6->name = "Гранкин";
	N6->beg100 = 12;
	N6->beg3km = 14;
	N6->otgimania = 75;
	N6->podtyag = 25;
	N6->prigok = 2.5;

	Sportsmen* N7 = new Sportsmen();
	N7->id = 7;
	N7->name = "Волков";
	N7->beg100 = 17;
	N7->beg3km = 12;
	N7->otgimania = 55;
	N7->podtyag = 17;
	N7->prigok = 2.2;

	Sportsmen* N8 = new Sportsmen();
	N8->id = 8;
	N8->name = "Савин";
	N8->beg100 = 22;
	N8->beg3km = 15;
	N8->otgimania = 25;
	N8->podtyag = 10;
	N8->prigok = 1.7;

	Sportsmen* N9 = new Sportsmen();
	N9->id = 9;
	N9->name = "Лужков";
	N9->beg100 = 10;
	N9->beg3km = 9;
	N9->otgimania = 40;
	N9->podtyag = 10;
	N9->prigok = 2.5;


	Sportsmen* N10 = new Sportsmen();
	N10->id = 10;
	N10->name = "Попов";
	N10->beg100 = 9;
	N10->beg3km = 13;
	N10->otgimania = 55;
	N10->podtyag = 21;
	N10->prigok = 2.5;

	Sportsmen* N11 = new Sportsmen();
	N11->id = 11;
	N11->name = "Гренков";
	N11->beg100 = 14;
	N11->beg3km = 10;
	N11->otgimania = 22;
	N11->podtyag = 5;
	N11->prigok = 2;

	Sportsmen* N12 = new Sportsmen();
	N12->id = 12;
	N12->name = "Петров";
	N12->beg100 = 13;
	N12->beg3km = 9;
	N12->otgimania = 40;
	N12->podtyag = 10;
	N12->prigok = 2.5;

	Sportsmen* N13 = new Sportsmen();
	N13->id = 13;
	N13->name = "Сидоров";
	N13->beg100 = 12;
	N13->beg3km = 9.5;
	N13->otgimania = 70;
	N13->podtyag = 22;
	N13->prigok = 3;


	Sportsmen* N14 = new Sportsmen();
	N14->id = 14;
	N14->name = "Лодырев";
	N14->beg100 = 11.6;
	N14->beg3km = 10.5;
	N14->otgimania = 32;
	N14->podtyag = 21;
	N14->prigok = 2.7;


	Sportsmen* N15 = new Sportsmen();
	N15->id = 15;
	N15->name = "Коваленко";
	N15->beg100 = 12;
	N15->beg3km = 10;
	N15->otgimania = 78;
	N15->podtyag = 25;
	N15->prigok = 2.7;

	Sportsmen* N16 = new Sportsmen();
	N16->id = 16;
	N16->name = "Партриков";
	N16->beg100 = 15;
	N16->beg3km = 14;
	N16->otgimania = 20;
	N16->podtyag = 10;
	N16->prigok = 2.2;

	Sportsmen* N17 = new Sportsmen();
	N17->id = 17;
	N17->name = "Никитин";
	N17->beg100 = 14;
	N17->beg3km = 12;
	N17->otgimania = 21;
	N17->podtyag = 15;
	N17->prigok = 2;


	Sportsmen* N18 = new Sportsmen();
	N18->id = 18;
	N18->name = "Овалов";
	N18->beg100 = 9.7;
	N18->beg3km = 9.7;
	N18->otgimania = 32;
	N18->podtyag = 23;
	N18->prigok = 3.1;

	mySp.push_back(N1);
	mySp.push_back(N2);
	mySp.push_back(N3);
	mySp.push_back(N4);
	mySp.push_back(N5);
	mySp.push_back(N6);
	mySp.push_back(N7);
	mySp.push_back(N8);
	mySp.push_back(N9);
	mySp.push_back(N10);
	mySp.push_back(N11);
	mySp.push_back(N12);
	mySp.push_back(N13);
	mySp.push_back(N14);
	mySp.push_back(N15);
	mySp.push_back(N16);
	mySp.push_back(N17);
	mySp.push_back(N18);

	int kr = 1;
	int ko;
#pragma endregion

#pragma region Pareto
	std::cout << std::endl;
	for (int i = 0; i < mySp.size(); i++) {
		std::cout << std::setw(2) << std::right << i + 1 << ". ";
		mySp[i]->printCh();
	}

	std::cout << "\n\nВыборка по Парето" << std::endl;
	std::cout << "  +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << std::endl;
	std::cout << "  |     ";
	for (int i = 0; i < mySp.size(); i++) {
		if (i < 9)std::cout << std::setw(2) << std::right << "|  " << i + 1 << "  ";
		else std::cout << std::setw(2) << std::right << "| " << i + 1 << "  ";
	}


	std::cout << "|";
	std::cout << "\n  +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << std::endl;
	for (int i = 0; i < mySp.size(); i++) {
		std::cout << "  ";
		if (i < 9)std::cout << std::setw(2) << std::right << "|  " << i + 1 << "  ";
		else std::cout << std::setw(2) << std::right << "| " << i + 1 << "  ";
		for (int j = 0; j < mySp.size(); j++) {
			if ((mySp.size() - i + 1) > mySp.size() - j) {
				std::cout << std::setw(5) << std::right << "|     ";
			}
			else {
				kr = 1;
				sravnen(kr, *mySp[i], *mySp[j]);
				if (kr == 1 || kr == 2) {
					std::cout << std::setw(3) << std::right << "| А ";
					if (kr == 1) {
						std::cout << std::setw(2) << i + 1;
						myFiltr2.push_back(mySp[i]);
					}
					else if (kr == 2) {
						std::cout << std::setw(2) << j + 1;
						myFiltr2.push_back(mySp[j]);
					}
					//вставляет в вектор 
					ko = 0;
					while (ko < myFiltr2.size() - 1) {
						if (myFiltr2[myFiltr2.size() - 1]->id == myFiltr2[ko]->id) {				//
							myFiltr2.erase(myFiltr2.begin() + (myFiltr2.size()) - 1);			//
							ko = myFiltr2.size();												// удаление
						}																		// элементов
						ko++;																	//
					}																			//
				}
				else {
					std::cout << std::setw(5) << std::right << "|  н  ";

				}
			}

		}
		std::cout << "|";
		std::cout << "\n  +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << std::endl;
	}

	mySp.clear();
	mySp = myFiltr2;
	myFiltr2.clear();

	std::cout << std::endl;
	for (int i = 0; i < mySp.size(); i++) {
		std::cout << std::setw(2) << std::right << mySp[i]->id << ". ";
		mySp[i]->printCh();
	}
#pragma endregion 

#pragma region Ecsperctnay ocenka
	// В mySp храняться выбранные по парето варианты
	// myFiltr и myFiltr2(?) пустые 
	myFiltr = mySp;

	std::cout << "\n\n\n\nВвывод таблицы после экспертной оценки" << std::endl;
	
	//id | Sportsmen | beg 100m | beg 3km | podtyag | Otgim | Prigok |

	
	for (int i = 0; i < mySp.size(); i++) {
		//Замена в связи с экспертной оценки
		if (mySp[i]->beg100 > 10) mySp[i]->beg100 = 5;
		else if (mySp[i]->beg100 < 12) mySp[i]->beg100 = 15;
		else mySp[i]->beg100 = 10;
		
		if (mySp[i]->beg3km > 9.5) mySp[i]->beg3km = 5;
		else if (mySp[i]->beg3km < 11) mySp[i]->beg3km = 15;
		else mySp[i]->beg3km = 10;

		if (mySp[i]->podtyag < 20) mySp[i]->podtyag = 2;
		else if (mySp[i]->podtyag > 30) mySp[i]->podtyag = 8;
		else mySp[i]->podtyag = 4;
		
		if (mySp[i]->otgimania < 35) mySp[i]->otgimania = 2;
		else if (mySp[i]->otgimania > 60) mySp[i]->otgimania = 8;
		else mySp[i]->otgimania = 4;

		if (mySp[i]->prigok <= 2.5) mySp[i]->prigok = 5;
		else mySp[i]->prigok = 10;



		//Вывод
		std::cout << std::setw(2) << std::right << mySp[i]->id << ". ";
		std::cout << std::setw(12) << std::left << mySp[i]->name << std::setw(4) << mySp[i]->beg100 << "\t" << std::setw(4) << mySp[i]->beg3km << "\t" << std::setw(4) << mySp[i]->podtyag << "\t" << std::setw(4) << mySp[i]->otgimania << "\t" << std::setw(4) << mySp[i]->prigok << "\t" << std::endl;

	}

#pragma endregion

#pragma region Matrix predpologeniu
	// создаем двумерный вектор
	//std::vector <std::vector<double>> array(mySp.size());
	std::vector <std::vector<double>> array(mySp.size(), std::vector<double>(mySp.size()));
	int k = 0, d = 0;
	while (k < mySp.size())
	{
		d = k;
		while (d < mySp.size()) 
		{
			if (d == k) {
				d++; // чтобы не сравнивались одинаковые значения 
				continue;
			}

			int P = 0, N = 0;
			if (mySp[k]->beg100 > mySp[d]->beg100) P += 5;
			else if (mySp[k]->beg100 < mySp[d]->beg100)N += 5;

			if (mySp[k]->beg3km > mySp[d]->beg3km) P += 5;
			else if (mySp[k]->beg3km < mySp[d]->beg3km)N += 5;
			
			if (mySp[k]->podtyag > mySp[d]->podtyag) P += 3;
			else if(mySp[k]->podtyag < mySp[d]->podtyag)N += 3;

			if (mySp[k]->otgimania > mySp[d]->otgimania) P += 3;
			else if(mySp[k]->otgimania < mySp[d]->otgimania)N += 3;

			if (mySp[k]->prigok > mySp[d]->prigok) P += 4;
			else if (mySp[k]->prigok < mySp[d]->prigok)N += 4;

			if (P != 0 && N != 0) 
			{
				if ((double)P / N > 1) {
					array[k][d] = (double)P / N;
					array[d][k] = 0;
				}
				else {
					array[d][k] = (double)N / P;
					array[k][d] = 0;
				}
			}
			else {
				array[k][d] = 0;
				array[d][k] = 0;
			}
			d++;
		}
		k++;
	}

	k = 0;

	std::cout << "\n\nПолная матрица предположений" << std::endl;
	std::cout << "  |     ";
	for (int i = 0; i < mySp.size(); i++) {
		if (i < 9)std::cout << std::setw(4) << std::right << "|  " << i + 1 << "  ";
		else std::cout << std::setw(4) << std::right << "| " << i + 1 << "  ";
	}
	std::cout << " |";
	std::cout << "\n  +------+------+------+------+------+------+------+------+------+------+" << std::endl;

	while (k < mySp.size()) {
		d = 0;
		std::cout << "  ";
		if (k < 9)std::cout << std::setw(2) << std::right << "|  " << k + 1 << "   |  ";
		else std::cout << std::setw(2) << std::right << "| " << k + 1 << "   |  ";
		
		while (d < mySp.size()) {
			if (d == k) {
				d++; 
				std::cout << std::setw(7) << std::left << "x";
				continue;
			}
			if (array[k][d] == 0) {
				std::cout << std::setw(7) << std::left << "-";
			}
			else std::cout << std::setw(7) << std::left << round(array[k][d]*100)/100;

			d++;
		}
		std::cout << std::endl;
		k++;
	 }
#pragma endregion

#pragma region Porog (c)
	double c = 1.9;
	std::cout << "\nУстановка порога c =" << c <<  std::endl;
	k = 0;
	d = 0;
	while (k < mySp.size())
	{
		d = 0;
		while (d < mySp.size())
		{
			if (d == k) {
				d++; // чтобы не сравнивались одинаковые значения 
				continue;
			}			
			if (array[k][d] != 0 && array[k][d] < c)
			{
				
				array[k][d] = 0;
				
			}
			d++;
		}
		k++;
	}

	k = 0;


	std::cout << "  |     ";
	for (int i = 0; i < mySp.size(); i++) {
		if (i < 9)std::cout << std::setw(4) << std::right << "|  " << i + 1 << "  ";
		else std::cout << std::setw(4) << std::right << "| " << i + 1 << "  ";
	}
	std::cout << " |";
	std::cout << "\n  +------+------+------+------+------+------+------+------+------+------+" << std::endl;

	while (k < mySp.size()) {
		d = 0;
		std::cout << "  ";
		if (k < 9)std::cout << std::setw(2) << std::right << "|  " << k + 1 << "   |  ";
		else std::cout << std::setw(2) << std::right << "| " << k + 1 << "   |  ";

		while (d < mySp.size()) {
			if (d == k) {
				d++;
				std::cout << std::setw(7) << std::left << "x";
				continue;
			}
			if (array[k][d] == 0) {
				std::cout << std::setw(7) << std::left << "-";
			}
			else std::cout << std::setw(7) << std::left << round(array[k][d] * 100) / 100;

			d++;
		}
		std::cout << std::endl;
		k++;
	}

#pragma endregion

}


int sravnen(int& h, Sportsmen A, Sportsmen N) {
	if (((A.beg100 <= N.beg100) == 1 && h == 1 || (A.beg100 <= N.beg100) == 1 && h == 2) == 0) {
		if (h == 1) {
			h = 2;
			sravnen(h, N, A);
		}
		h = 0;
		return 0;
	}
	if (((A.beg3km <= N.beg3km) == 1 && h == 1 || (A.beg3km <= N.beg3km) == 1 && h == 2) == 0) {
		if (h == 1) {
			h = 2;
			sravnen(h, N, A);
		}
		h = 0;
		return 0;
	}
	if (((A.podtyag >= N.podtyag) == 1 && h == 1 || (A.podtyag >= N.podtyag) == 1 && h == 2) == 0) {
		if (h == 1) {
			h = 2;
			sravnen(h, N, A);
		}
		h = 0;
		return 0;
	}
	if (((A.otgimania >= N.otgimania) == 1 && h == 1 || (A.otgimania >= N.otgimania) == 1 && h == 2) == 0) {
		if (h == 1) {
			h = 2;
			sravnen(h, N, A);
		}
		h = 0;
		return 0;
	}
	if (((A.prigok >= N.prigok) == 1 && h == 1 || (A.prigok >= N.prigok) == 1 && h == 2) == 0) {
		if (h == 1) {
			h = 2;
			sravnen(h, N, A);
		}
		h = 0;
		return 0;
	}

	return 0;
}




