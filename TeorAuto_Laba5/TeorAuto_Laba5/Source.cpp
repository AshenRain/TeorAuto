#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

double parse(int kol, int j, int str, std::vector<std::string>);

int main()
{
#pragma region obrabotka dannih
	setlocale(LC_ALL, "Russian");

	//const int len = 30, strings = 5;
	//char s;
	//char mass[len][strings];

	int ch = 0;  //��� ����������, � ������� ����� ��������� �������
	std::string s;  //��� ������, ��� � ������� ����� �������
	std::vector<std::string> v; //������ ����� 

	int i;

	//������� ����� � ���������������
	std::ifstream in("kk.txt");     //������� ��� ������  ����
	while ((ch = in.get()) != EOF) {   //���������� ����
		if (char(ch) != '\n') s = s + char(ch);  //��������� ������ �� ����� � ����� ��������� ��� �� ������� �������� ������. 
		else {
			v.push_back(s); //���� ������� ������ �������, �� ���������� ������ � ������
			s.clear(); //������� ������
		}
	}    v.push_back(s); //���������� ��������� ������ � ������.
	in.close(); //��������� ����

	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << std::endl;
	}




	
	const int len_1 = 7, strings_1 = 4;
	double m[len_1][strings_1] = { 0 };

	for (int i = 0; i < v.size() - 3; i++) // ��� ���������� 4 ������
	{
		int j = 0;
		int zn_m = -1;  // ����� ����������� �����
		int zn = 1;		// ���� �����������
		int rav_m = 0;	// ����� ���������
		int rav;	// ���� ���������� 
		

		
		while (j < v[i].length()) {
			if (v[i][j] != 'x') {
				if (v[i][j] == '-') {
					zn_m = j;
					zn = -1;
				}
				else if (v[i][j] == '+') {
					zn_m = j;
					zn = 1;
				}
				else if (v[i][j] == '<') {
					rav_m = j;
					rav = 1;
				}
				else if (v[i][j] == '>') {
					rav_m = j;
					rav = -1;
				}
				
			}
			else if (j != 0) { // �� ���� mass[j][i] = 'x' � �� �������� ������ ��������
				if (v[i][j + 1] == '1') {
					if (zn_m != -1) {
						m[0][i] = parse(j - zn_m - 2, j, i, v) * zn;
					}
					else m[0][i] = parse(j, j, i, v) * zn; // ����������, �� ������ ���� ��� ������� ����� (�. �. + �� �������
				}
				else if (v[i][j + 1] == '2') {
					if (zn_m != -1) {
						m[1][i] = parse(j - zn_m - 2, j, i, v) * zn;
					}
					else m[1][i] = parse(j, j, i, v) * zn; // ����������, �� ������ ���� ��� ������� ����� (�. �. + �� �������)
				}
				else std::cout << "error of index" << std::endl;
			}
			else {
				if (v[i][j + 1] == '1') {
					m[0][i] = 1;
				}
				else if (v[i][j + 1] == '2') {
					m[1][i] = 1;
				}
				else std::cout << "error of index and j = 0" << std::endl;
			}
			

			j++;
		}
		
		if (rav_m != 0) m[6][i] = parse(j - rav_m - 3, j, i, v);
		else std::cout << "error of ravenstvo" << std::endl;
		
	#pragma endregion

#pragma region tablica vectorov
		//��������� <
		//rav - ���� ���������
		//rav_m - ��� ����������
		std::string tmp = "          ";
		int c = 0;
		while (c < (j - rav_m - 1)) { // ������ � tmp ��� ��� ������ �� ���������
			tmp[c] = v[i][c + rav_m +1];
			c++;
		}
		
		v[i].resize(v[i].size() - (j - rav_m - 1)); // �������� ��� ��� ��������� ������ �� ��������� 
		
		if (rav == -1) v[i][rav_m] = '-';
		else v[i][rav_m] = '+';
		
		rav_m+= 3;
		//v[i] += ' ' + 'x';
		v[i].resize(v[i].size() + 4 + (j - rav_m - 1));
		v[i].insert(rav_m - 2, " x");
		v[i][rav_m] = i + 3 + '0';
		rav_m++;
		v[i].insert(rav_m, " ");
		rav_m++;
		v[i].insert(rav_m, tmp);
		std::cout << v[i] << std::endl;
	}

	m[2][0] = 1;
	m[3][1] = 1;
	m[4][2] = 1;
	m[5][3] = 1;

	std::cout << std::endl;

	std::cout << std::setw(5) << "A1" << std::setw(5) << "A2" << std::setw(5) << "A3" << std::setw(5) << "A4" << std::setw(5) << "A5" << std::setw(5) << "A6" << std::setw(5) <<  std::endl;
	for (int i = 0; i < 4; i++) {
		std::cout << std::setw(5) << m[0][i] << std::setw(5) << m[1][i] << std::setw(5) << m[2][i] << std::setw(5) << m[3][i] << std::setw(5) << m[4][i] << std::setw(5) << m[5][i] << std::setw(5) << m[6][i] << std::endl;
	}
	
	
#pragma endregion


	double x[6] = {1,2,3,4,5,6};
	double cv[6] = { 0 }; // Cj
	cv[0] = v[5][7] - '0'; //��� �������� �������
	cv[1] = v[5][13] - '0';
	double del_1, del_2, q = 0;
	del_1 = -cv[0];
	del_2 = -cv[1];

	if (del_1 < 0 && del_2 < 0) {
		std::cout << "\n�������� �������" << std::endl;
		std::cout << std::setw(5) << "       |" << std::setw(5) << "   Cj  |" << std::setw(5) << cv[0] << std::setw(8) << cv[1] << std::endl;
		std::cout << "       +-------+-------+-------+-------+" << std::endl;
		std::cout << std::setw(5) << "   Cv  |" << std::setw(5) << "       |" << std::setw(5) << "   x" << x[0] << " |" << std::setw(5) << "   x" << x[1] << " |" << std::setw(5) << "   !A0 |" << std::endl;
		std::cout << "       +-------+-------+-------+-------+" << std::endl;
		for (int i = 0; i < 4; i++) {
			std::cout << std::setw(5) << cv[i + 2] << "  |" << std::setw(5) << "x" << x[i + 2] << " |" << std::setw(5) << m[0][i] << "  |" << std::setw(5) << m[1][i] << "  |" << std::setw(5) << m[6][i] << "  |" << std::endl;
		}
		std::cout << "       +-------+-------+-------+-------+" << std::endl;
		std::cout << std::setw(5) << "       |" << std::setw(5) << "   f   |" << std::setw(5) << del_1 << "  |" << std::setw(5) << del_2 << "  |" << std::setw(5) << q << "  |" << std::endl;
		std::cout << "       +-------+-------+-------+-------+" << std::endl;
	
		//���� ����������� �������
		int raz,raz2; //����������� �������
		if (del_1 < del_2) raz = 0;
		else raz = 1;

		int key = -1;
		double min = 100000;
		for (int i = 0; i < 4; i++) { //���������� ����������� ������
			if (m[raz][i] != 0 && m[6][i] / m[raz][i] < min && m[6][i] / m[raz][i] > 0) {
				min = m[6][i] / m[raz][i];
				key = i;
			}
		}
		
		std::cout << "\n\n����������� ������� - " << raz + 1 << std::endl;
		std::cout << "����������� ������ - " << key + 1 << std::endl;
		std::cout << "����������� ������� - " << m[raz][key] << std::endl;
		double razkey = m[raz][key],razkey2,razkey3; //�������� ����������� ������

		int tmp_1 = x[key + 2];
		x[key + 2] = x[raz]; //������ x ��
		x[raz] = tmp_1;

		tmp_1 = cv[key + 2];
		cv[key + 2] = cv[raz]; //������ Cj � Cv ��
		cv[raz] = tmp_1;

		m[raz][key] = 1 / m[raz][key];//������ ����������� ��-� �� �������� 
		if (raz == 0) raz2 = 1;
		else raz2 = 0;
		razkey2 = m[raz2][key];
		m[raz2][key] = m[raz2][key]/razkey;

		razkey3 = m[6][key];
		m[6][key] = m[6][key] / razkey;

		std::cout << "\n�������� �������" << std::endl;
		std::cout << std::setw(5) << "       |" << std::setw(5) << "   Cj  |" << std::setw(5) << cv[0] << std::setw(8) << cv[1] << std::endl;
		std::cout << "       +-------+-------+-------+-------+" << std::endl;
		std::cout << std::setw(5) << "   Cv  |" << std::setw(5) << "       |" << std::setw(5) << "   x" << x[0] << " |" << std::setw(5) << "   x" << x[1] << " |" << std::setw(5) << "   !A0 |" << std::endl;
		std::cout << "       +-------+-------+-------+-------+" << std::endl;
		for (int i = 0; i < 4; i++) {
			if (i != key) {
				m[6][i] = (m[6][i] * razkey - m[raz2][i] * razkey3) / razkey;
				if (m[raz][i] != 0) m[raz][i] = (m[raz][i] / razkey) * (-1); // ����� ����������� ������� �� ��� �� � � ������ ����
				m[raz2][i] = (m[raz2][i] * razkey - m[raz][i] * razkey2) / razkey; // ������ �� ������� ������������
			}				
			std::cout << std::setw(5) << cv[i + 2] << "  |" << std::setw(5) << "x" << x[i + 2] << " |" << std::setw(5) << round(m[0][i] * 100) / 100 << "  |" << std::setw(5) << round(m[1][i] * 100) / 100 << "  |" << std::setw(5) << round(m[6][i] * 100) / 100 << "  |" << std::endl;
		}
		
		if (raz == 0) {
			del_2 = (del_2 * razkey - del_1 * razkey2) / razkey;
			del_1 = (del_1 / razkey) * (-1);
		}
		else {
			del_1 = (del_1 * razkey2 - del_2 * razkey) / razkey;
			del_2 = (del_2 / razkey) * (-1);
		}
		q = cv[2] * m[6][0] + cv[3] * m[6][1] + cv[4] * m[6][2] + cv[5] * m[6][3];

		std::cout << "       +-------+-------+-------+-------+" << std::endl;
		std::cout << std::setw(5) << "       |" << std::setw(5) << "   f   |" << std::setw(5) << round(del_1 * 100) / 100 << "  |" << std::setw(5) << round(del_2 * 100) / 100 << "  |" << std::setw(5) << round(q * 100) / 100 << "  |" << std::endl;
		std::cout << "       +-------+-------+-------+-------+" << std::endl;

		

	}
	else std::cout << "del>=0" << std::endl;
	
	//end while

	std::cout << "\n\n � ��������� ������ f �� ���������� ������������� ������, \n ��� ��������������� �� ������������� ���������� �������, \n ��� ������������ �����: " << q << std::endl;

}

			// ������� ����
					// ��������� ������� ����� ������ ������
							// ������
double parse(int kol, int j, int str, std::vector<std::string> v) {
	int i = 0;
	int k = 1;
	double chislo = 0;
	while(i < kol)
	{
		chislo += (v[str][j - 1] - '0') * k;
		k *= 10;
		j--;
		i++;
	}

	if (i == 0) return 1;
	else return chislo;
}