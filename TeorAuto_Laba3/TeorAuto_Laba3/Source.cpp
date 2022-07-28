#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>


//void charVdouble(char(&array)[30][5], double(&mass)[5][5]);	// перевод из char в double
void stringVdouble(std::string(&array)[25], double(&mass)[5][5]);

int main() 
{
	#pragma region Schitivanie elementov iz faila
	setlocale(LC_ALL, "Russian");
	
	std::string s;
	std::string array[25];
	int g;

	#pragma region kk file
	std::ifstream file("kk.txt");
	g = 0;
	if (file.is_open()) // вызов метода is_open()
		std::cout << " Файл kk успешно открыт!\n\n" << std::endl;
	else
	{
		std::cout << "Файл не открыт!\n\n" << std::endl;
		return -1;
	}
	
	for (file >> s; !file.eof(); file >> s)
	{
		array[g] = s;
		g++;
	}
	file.close();
	
	double kk[5][5];
	stringVdouble(array, kk);

	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 5; i++) {
			std::cout << kk[j][i] << "|";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	#pragma endregion

	#pragma region k1 file

	std::ifstream file1("k1.txt");
	g = 0;
	if (file1.is_open()) // вызов метода is_open()
		std::cout << " Файл k1 успешно открыт!\n\n" << std::endl;
	else
	{
		std::cout << "Файл не открыт!\n\n" << std::endl;
		return -1;
	}

	for (file1 >> s; !file1.eof(); file1 >> s)
	{
		array[g] = s;
		g++;
	}
	file1.close();

	double k1[5][5];
	stringVdouble(array, k1);
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 5; i++) {
			std::cout << k1[j][i] << "|";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	#pragma endregion
	
	#pragma region k2 file
	std::ifstream file2("k2.txt");
	g = 0;
	if (file2.is_open()) // вызов метода is_open()
		std::cout << " Файл k2 успешно открыт!\n\n" << std::endl;
	else
	{
		std::cout << "Файл не открыт!\n\n" << std::endl;
		return -1;
	}

	for (file2 >> s; !file2.eof(); file2 >> s)
	{
		array[g] = s;
		g++;
	}
	file2.close();

	double k2[5][5];
	stringVdouble(array, k2);
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 5; i++) {
			std::cout << k2[j][i] << "|";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	#pragma endregion

	#pragma region k3 file

	std::ifstream file3("k3.txt");
	g = 0;
	if (file3.is_open()) // вызов метода is_open()
		std::cout << " Файл k3 успешно открыт!\n\n" << std::endl;
	else
	{
		std::cout << "Файл не открыт!\n\n" << std::endl;
		return -1;
	}

	for (file3 >> s; !file3.eof(); file3 >> s)
	{
		array[g] = s;
		g++;
	}
	file3.close();

	double k3[5][5];
	stringVdouble(array, k3);
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 5; i++) {
			std::cout << k3[j][i] << "|";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	#pragma endregion

	#pragma region k4 file
	std::ifstream file4("k4.txt");
	g = 0;
	if (file4.is_open()) // вызов метода is_open()
		std::cout << " Файл k4 успешно открыт!\n\n" << std::endl;
	else
	{
		std::cout << "Файл не открыт!\n\n" << std::endl;
		return -1;
	}

	for (file4 >> s; !file4.eof(); file4 >> s)
	{
		array[g] = s;
		g++;
	}
	file4.close();

	double k4[5][5];
	stringVdouble(array, k4);
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 5; i++) {
			std::cout << k4[j][i] << "|";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	#pragma endregion

	#pragma region k5 file

	std::ifstream file5("k5.txt");
	g = 0;
	if (file5.is_open()) // вызов метода is_open()
		std::cout << " Файл k5 успешно открыт!\n\n" << std::endl;
	else
	{
		std::cout << "Файл не открыт!\n\n" << std::endl;
		return -1;
	}

	for (file5 >> s; !file5.eof(); file5 >> s)
	{
		array[g] = s;
		g++;
	}
	file5.close();

	double k5[5][5];
	stringVdouble(array, k5);
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 5; i++) {
			std::cout << k5[j][i] << "|";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	#pragma endregion
	#pragma endregion

	#pragma region KK raschet
	std::cout << "\nРасчет значений для kk" << std::endl;
	//рассчитаем среднее геометрическое для каждой строки каждой таблицы
	int i = 0;
	double sumV = 0;	//нормирующий коэффициент
	double gV[5];		//произведение строки
	double v_W[5];		//вектор приоритетов
	double sumS[5];		//сумма столбцов
	double sumP = 0;	//максимальное среднее значение
	double id;			//индекс согласованности ИС
	double idS = 1.12;  //случайный индекс согласованности
	double os;			//отношение согласованности ОС
	while (i < 5) {
		int j = 0;
		gV[i] = 1;
		sumS[i] = 0;
		while (j < 5) {
			sumS[i] += kk[j][i];
			gV[i] *= kk[i][j];
			j++;
		}
		sumV += pow(gV[i], 0.2);
		i++;
	}

	i = 0;
	std::cout << "Вектор приоритетов | Пропорциональность предпочтений" << std::endl;
	while (i < 5)
	{
		v_W[i] = pow(gV[i], 0.2) / sumV;
		std::cout<< i+1 << ". " << round(v_W[i]*1000)/1000 <<std::setw(12)<<"|"<<round(sumS[i]* v_W[i]*100)/100 << std::endl;
		sumP += sumS[i] * v_W[i];
		i++;
	}
	id = (sumP - 5) / 4;
	os = id / idS;
	std::cout << "\nsumV = " << round(sumV * 100) / 100 << std::endl;
	std::cout << "sumP = " << round(sumP * 100) / 100 << std::endl;
	std::cout << "ИС = " << round(id * 1000) / 1000 << std::endl;
	std::cout << "ОС = " << round(os * 1000) / 1000 << std::endl;

	#pragma endregion

	std::vector <double*> matx;
	matx.push_back(&k1[0][0]);
	matx.push_back(&k2[0][0]);
	matx.push_back(&k3[0][0]);
	matx.push_back(&k4[0][0]);
	matx.push_back(&k5[0][0]);

	double prioriW[5];		//приоритеты альтернатив 
	int k = 0;
	while (k < 5) {
		
		std::cout << "\nРасчет значений для k" << k + 1 << std::endl;
		//рассчитаем среднее геометрическое для каждой строки каждой таблицы
		int i = 0;
		double sumV = 0;	//нормирующий коэффициент
		double gV[5];		//произведение строки
		double vW[5];		//вектор приоритетов
		double sumS[5];		//сумма столбцов
		double sumP = 0;	//максимальное среднее значение
		double id;			//индекс согласованности ИС
		double idS = 1.12;  //случайный индекс согласованности
		double os;			//отношение согласованности ОС
		while (i < 5) {
			int j = 0;
			gV[i] = 1;
			sumS[i] = 0;
			while (j < 5) {
				sumS[i] += *(matx[k] + j * 5 + i);//kk[j][i];
				gV[i] *= *(matx[k] + i * 5 + j);//kk[i][j];
				j++;
			}
			sumV += pow(gV[i], 0.2);
			i++;
		}

		i = 0;
		prioriW[k] = 0;
		std::cout << "Вектор приоритетов | Пропорциональность предпочтений" << std::endl;
		while (i < 5)
		{
			vW[i] = pow(gV[i], 0.2) / sumV;
			std::cout << i + 1 << ". " << round(vW[i] * 1000) / 1000 << std::setw(12) << "|" << round(sumS[i] * vW[i] * 100) / 100 << std::endl;
			sumP += sumS[i] * vW[i];
			prioriW[k] += vW[i] * v_W[i]; // рассчет относительной важности
			i++;
		}
		id = (sumP - 5) / 4;
		os = id / idS;
		std::cout << "\nsumV = " << round(sumV * 100) / 100 << std::endl;
		std::cout << "sumP = " << round(sumP * 100) / 100 << std::endl;
		std::cout << "ИС = " << round(id * 1000) / 1000 << std::endl;
		std::cout << "ОС = " << round(os * 1000) / 1000 << std::endl;
		k++;
	}

	std::cout << std::endl;
	i = 0;
	while (i < 5) {
		std::cout << "W" << i + 1 << " = " << round(prioriW[i]*1000)/1000 << std::endl;
		i++;
	}

}


void stringVdouble(std::string(&array)[25], double(&mass)[5][5])
{
	int i = 0, str = 0;
	double lol,loll;
	int j = 0;
	while (j < 25 && str < 5)
	{
		if (array[j].length() != 1) 
		{
			lol = double(array[j][0] - '0');
			loll = double(array[j][2] - '0');
			mass[str][i] = double(array[j][0] - '0') / double(array[j][2] - '0');
			i++;
		}
		else {
			lol = double(array[j][0] - '0');
			mass[str][i] = double(array[j][0] - '0');
			i++;
		}

		if (i == 5) 
		{
			i = 0;
			str++;
		}

		j++;
	}


	
}
