#include <iostream>
#include <vector>
#include "Sportsmen.h"

void kriteriu(std::vector<Sportsmen*>& mySp, std::vector<Sportsmen*>& myFiltr, std::vector<Sportsmen*>& myFiltr2, int k, int h);
//void syboptim(std::vector<Sportsmen*>& mySp, std::vector<Sportsmen*>& myFiltr, std::vector<Sportsmen*>& myFiltr2, int k);

int main()
{
	setlocale(LC_ALL, "Russian");

	std::vector<Sportsmen*> mySp;
	std::vector<Sportsmen*> myFiltr;
	std::vector<Sportsmen*> myFiltr2;

	Sportsmen *N1 = new Sportsmen();
	N1->name = "Спиридонов";
	N1->beg100 = 9.8;
	N1->beg3km = 13.2;
	N1->otgimania = 50; // 50
	N1->podtyag = 12; // 12
	N1->prigok = 2.02;

	Sportsmen *N2 = new Sportsmen();
	N2->name = "Погодин";
	N2->beg100 = 15;
	N2->beg3km = 10;
	N2->otgimania = 10;
	N2->podtyag = 22; // 22
	N2->prigok = 3;

	Sportsmen *N3 = new Sportsmen();
	N3->name = "Сапожников";
	N3->beg100 = 9.9;
	N3->beg3km = 8.6;
	N3->otgimania = 70;
	N3->podtyag = 40;
	N3->prigok = 3;

	Sportsmen *N4 = new Sportsmen();
	N4->name = "Воронков";
	N4->beg100 = 17;
	N4->beg3km = 11;
	N4->otgimania = 25;
	N4->podtyag = 7;
	N4->prigok = 1.7;

	Sportsmen *N5 = new Sportsmen();
	N5->name = "Владов";
	N5->beg100 = 10;
	N5->beg3km = 9.8;
	N5->otgimania = 55;
	N5->podtyag = 40;
	N5->prigok = 2.5;

	Sportsmen *N6 = new Sportsmen();
	N6->name = "Гранкин";
	N6->beg100 = 12;
	N6->beg3km = 14;
	N6->otgimania = 75;
	N6->podtyag = 25;
	N6->prigok = 2.5;

	Sportsmen *N7 = new Sportsmen();
	N7->name = "Волков";
	N7->beg100 = 17;
	N7->beg3km = 12;
	N7->otgimania = 55;
	N7->podtyag = 17;
	N7->prigok = 2.2;

	Sportsmen *N8 = new Sportsmen();
	N8->name = "Савин";
	N8->beg100 = 22;
	N8->beg3km = 15;
	N8->otgimania = 25;
	N8->podtyag = 10;
	N8->prigok = 1.7;

	Sportsmen *N9 = new Sportsmen();
	N9->name = "Лужков";
	N9->beg100 = 10;
	N9->beg3km = 9;
	N9->otgimania = 40;
	N9->podtyag = 10;
	N9->prigok = 2.5;

	mySp.push_back(N1);
	mySp.push_back(N2);
	mySp.push_back(N3);
	mySp.push_back(N4);
	mySp.push_back(N5);
	mySp.push_back(N6);
	mySp.push_back(N7);
	mySp.push_back(N8);
	mySp.push_back(N9);

	std::cout << std::endl;
	for (int i = 0; i < mySp.size(); i++) {
		std::cout << i + 1 << ". ";
		mySp[i]->printCh();
	}


	std::cout << "\nВыбор метода: " << std::endl;
	std::cout << "1. Указание верхних/нижних границ критериев" << std::endl;
	std::cout << "2. Субоптимизация" << std::endl;
	std::cout << "3. Лексикографическая оптимизация" << std::endl;

	int n = 0;

	while (n == 0) {

		std::cout << "\n\nВвод:";
		std::cin >> n;

		if (n == 1) {
			kriteriu(mySp, myFiltr, myFiltr2, 1, 1);
			for (int i = 0; i < myFiltr2.size(); i++) {
				std::cout << i + 1 << ". ";
				myFiltr2[i]->printCh();
			}

		}
		else if (n == 2) {
			int vib = 0;

			while (vib == 0) {
				std::cout << "\nВыберие главный критерий:" << std::endl;
				std::cout << "1. Бег 100м" << std::endl;
				std::cout << "2. Бег 3км" << std::endl;
				std::cout << "3. Подтягивания" << std::endl;
				std::cout << "4. Отжимания" << std::endl;
				std::cout << "5. Прыжок" << std::endl;
				std::cin >> vib;

				if (vib != 1 && vib != 2 && vib != 3 && vib != 4 && vib != 5)   {
					std::cout << "////Неверный ввод, повториту попытку////" << std::endl;
					vib = 0;
				}
			}

			kriteriu(mySp, myFiltr, myFiltr2, 1, 2);
			for (int i = 0; i < myFiltr2.size(); i++) {
				std::cout << i + 1 << ". ";
				myFiltr2[i]->printCh();
			}
			if (myFiltr2.size() != 0) {
				myFiltr.clear(); // очищаем вектор
				myFiltr.push_back(myFiltr2[0]);
				for (int i = 1; i < myFiltr2.size(); i++) {
					if (vib == 1 && myFiltr[0]->beg100 > myFiltr2[i]->beg100) myFiltr[0] = myFiltr2[i];
					else if (vib == 2 && myFiltr[0]->beg3km > myFiltr2[i]->beg3km) myFiltr[0] = myFiltr2[i];
					else if (vib == 3 && myFiltr[0]->podtyag < myFiltr2[i]->podtyag) myFiltr[0] = myFiltr2[i];
					else if (vib == 4 && myFiltr[0]->otgimania < myFiltr2[i]->otgimania) myFiltr[0] = myFiltr2[i];
					else if (vib == 5 && myFiltr[0]->podtyag < myFiltr2[i]->podtyag) myFiltr[0] = myFiltr2[i];
				}
				std::cout << "Оптимальный выбор:" << std::endl;
				myFiltr[0]->printCh();
			}
			else { std::cout << "Нет спортсменов подходящих данным требованиям" << std::endl; }

		}
		else if (n == 3) {
			
			do {
				int vib = 0;
				while (vib == 0) {
					std::cout << "\nВыбирите критерии по их относительной важности (начиная с самого важного)" << std::endl;
					std::cout << "1. Бег 100м" << std::endl;
					std::cout << "2. Бег 3км" << std::endl;
					std::cout << "3. Подтягивания" << std::endl;
					std::cout << "4. Отжимания" << std::endl;
					std::cout << "5. Прыжок" << std::endl;
					std::cout << "\n\nВвод: ";
					std::cin >> vib;

					if (vib != 1 && vib != 2 && vib != 3 && vib != 4 && vib != 5) {
						std::cout << "////Неверный ввод, повториту попытку////" << std::endl;
						vib = 0;
					}
				}
				myFiltr.clear();
				myFiltr.push_back(mySp[0]);
				for (int i = 1; i < mySp.size(); i++)
				{
					if ((mySp[i]->parametr(vib, *myFiltr[0])) == 1) {
						myFiltr.clear();
						myFiltr.push_back(mySp[i]);
					}
					else if ((mySp[i]->parametr(vib, *myFiltr[0])) == 2) myFiltr.push_back(mySp[i]);
				}

				for (int i = 0; i < myFiltr.size(); i++) {
					std::cout << i + 1 << ". ";
					myFiltr[i]->printCh();
				}

				mySp.clear();
				mySp = myFiltr;				
			} while (myFiltr.size() != 1);
			
		}
		else {
			std::cout << "//////Неверный выбор варианта, повторите попытку///////" << std::endl;
			n = 0;
		}

	}
}

            //kriteriu(               myFiltr,                        myFiltr2,                         mySp,         2,     h)


void kriteriu(std::vector<Sportsmen*> &mySp, std::vector<Sportsmen*> &myFiltr, std::vector<Sportsmen*>& myFiltr2, int k, int h) {

	if (k == 2) {
		for (int i = 0; i < mySp.size(); i++) {
			std::cout << i + 1 << ". ";
			mySp[i]->printCh();
		}
	}

	

	std::cout << "\nВыбирите "<<k<<" критерий: " << std::endl;
	std::cout << "1. Бег 100м" << std::endl;
	std::cout << "2. Бег 3км" << std::endl;
	std::cout << "3. Подтягивания" << std::endl;
	std::cout << "4. Отжимания" << std::endl;
	std::cout << "5. Прыжок" << std::endl;

	int t = 0; //номер критерия
	
	while (t == 0) {
		std::cout << "\n\nВвод:";
		std::cin >> t;
		
		if (h == 1){
			std::cout << "\n\nВведите какую границу вы установите:" << std::endl;
			std::cout << "1. Верхняя" << std::endl;
			std::cout << "2. Нижняя" << std::endl;

		}
		int fl = 0; // верхняя/нижняя граница

		while (fl == 0)
		{
			if(h == 1){
				std::cout << "\n\nВвод:";
				std::cin >> fl;
			
			}
			else if (h == 2) {
				fl = 2;
			}

			if (t == 1 && fl == 1 && h != 2) {
				double beg = -1;
				while (beg <= 0 || beg >= 15000) {
					std::cout << "Введите верхнюю границу(cек): ";
					std::cin >> beg;
					if (beg <= 0 || beg >= 15000) { std::cout << "////Неверный ввод, повториту попытку////" << std::endl; }
				}

				for (int i = 0; i < mySp.size(); i++) {
					if (mySp[i]->beg100 >= beg) {
						myFiltr.push_back(mySp[i]);
					}
				}
				if (k == 1) { kriteriu(myFiltr, myFiltr2, mySp, 2, h); }
			}
			else if (t == 1 && fl == 2) {
				double beg = -1;
				while (beg <= 0 || beg >= 15000) {
					std::cout << "Введите нижнюю границу(cек): " ;
					std::cin >> beg;
					if (beg <= 0 || beg >= 15000) { std::cout << "////Неверный ввод, повториту попытку////" << std::endl; }
				}

				for (int i = 0; i < mySp.size(); i++) {
					if (mySp[i]->beg100 <= beg) {
						myFiltr.push_back(mySp[i]);
					}
				}
				if (k == 1) { kriteriu(myFiltr, myFiltr2, mySp, 2, h); }
			}
			else if (t == 2 && fl == 1 && h != 2) {
				double beg = -1;
				while (beg <= 0 || beg >= 15000) {
					std::cout << "Введите верхнюю границу(мин): ";
					std::cin >> beg;
					if (beg <= 0 || beg >= 15000) { std::cout << "////Неверный ввод, повториту попытку////" << std::endl; }
				}

				for (int i = 0; i < mySp.size(); i++) {
					if (mySp[i]->beg3km <= beg) {
						myFiltr.push_back(mySp[i]);
					}
				}
				if (k == 1) { kriteriu(myFiltr, myFiltr2, mySp, 2, h); }
			}
			else if (t == 2 && fl == 2) {
				double beg = -1;
				while (beg <= 0 || beg >= 15000) {
					std::cout << "Введите нижнюю границу(мин): " ;
					std::cin >> beg;
					if (beg <= 0 || beg >= 15000) { std::cout << "////Неверный ввод, повториту попытку////" << std::endl; }
				}

				for (int i = 0; i < mySp.size(); i++) {
					if (mySp[i]->beg3km >= beg) {
						myFiltr.push_back(mySp[i]);
					}
				}
				if (k == 1) { kriteriu(myFiltr, myFiltr2, mySp, 2, h); }
			}
			else if (t == 3 && fl == 1 && h != 2) {
				int pod = -1;
				while (pod <= 0 || pod >= 15000) {
					std::cout << "Введите верхнюю границу: " ;
					std::cin >> pod;
					if (pod <= 0 || pod >= 15000) { std::cout << "////Неверный ввод, повториту попытку////" << std::endl; }
				}

				for (int i = 0; i < mySp.size(); i++) {
					if (mySp[i]->podtyag <= pod) {
						myFiltr.push_back(mySp[i]);
					}
				}
				if (k == 1) { kriteriu(myFiltr, myFiltr2, mySp, 2, h); }

			}
			else if (t == 3 && fl == 2) {
				int pod = -1;
				while (pod <= 0 || pod >= 15000) {
					std::cout << "Введите нижнюю границу: " ;
					std::cin >> pod;
					if (pod <= 0 || pod >= 15000) { std::cout << "////Неверный ввод, повториту попытку////" << std::endl; }
				}

				for (int i = 0; i < mySp.size(); i++) {
					if (mySp[i]->podtyag >= pod) {
						myFiltr.push_back(mySp[i]);
					}
				}
				if (k == 1) { kriteriu(myFiltr, myFiltr2, mySp, 2, h); }

			}
			else if (t == 4 && fl == 1 && h != 2) {
				int otgim = -1;
				while (otgim <= 0 || otgim >= 15000) {
					std::cout << "Введите верхнюю границу: " ;
					std::cin >> otgim;
					if (otgim <= 0 || otgim >= 15000) { std::cout << "////Неверный ввод, повториту попытку////" << std::endl; }
				}

				for (int i = 0; i < mySp.size(); i++) {
					if (mySp[i]->otgimania <= otgim) {
						myFiltr.push_back(mySp[i]);
					}
				}
				if (k == 1) { kriteriu(myFiltr, myFiltr2, mySp, 2, h); }
			}
			else if (t == 4 && fl == 2) {
				int otgim = -1;
				while (otgim <= 0 || otgim >= 15000) {
					std::cout << "Введите нижнюю границу: " ;
					std::cin >> otgim;
					if (otgim <= 0 || otgim >= 15000) { std::cout << "////Неверный ввод, повториту попытку////" << std::endl; }
				}

				for (int i = 0; i < mySp.size(); i++) {
					if (mySp[i]->otgimania >= otgim) {
						myFiltr.push_back(mySp[i]);
					}
				}
				if (k == 1) { kriteriu(myFiltr, myFiltr2, mySp, 2, h); }
			}
			else if (t == 5 && fl == 1 && h != 2) {
				double prig = -1;
				while (prig <= 0 || prig >= 15000) {
					std::cout << "Введите верхнюю границу: " ;
					std::cin >> prig;
					if (prig <= 0 || prig >= 15000) { std::cout << "////Неверный ввод, повториту попытку////" << std::endl; }
				}

				for (int i = 0; i < mySp.size(); i++) {
					if (mySp[i]->prigok <= prig) {
						myFiltr.push_back(mySp[i]);
					}
				}
				if (k == 1) { kriteriu(myFiltr, myFiltr2, mySp, 2, h); }
			}
			else if (t == 5 && fl == 2) {
				double prig = -1;
				while (prig <= 0 || prig >= 15000) {
					std::cout << "Введите нижнюю границу: " ;
					std::cin >> prig;
					if (prig <= 0 || prig >= 15000) { std::cout << "////Неверный ввод, повториту попытку////" << std::endl; }
				}

				for (int i = 0; i < mySp.size(); i++) {
					if (mySp[i]->prigok >= prig) {
						myFiltr.push_back(mySp[i]);
					}
				}
				if (k == 1) { kriteriu(myFiltr, myFiltr2, mySp, 2, h); }
			}
			else {
				std::cout << "//////Неверный выбор варианта, повторите попытку///////" << std::endl;
				t = 0;
			}
		}
			
	}
		
}



