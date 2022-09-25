#include "bin_image.h"
#include "stdio.h"
#include <stdlib.h>
#include <string>
#include <ctype.h>
#include <math.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <iostream>
/*����� �������� ����������� ������������� �������.
��� �������, ������������:
� ����������� � �����������: ������� �����������;
� �������� () ��� ������/������ �������� �� ��������� ��������;
� ��������� ��������� * (������������ �Ȼ) � �������� + (������������ ���Ȼ) �����������;
� ��������� ��������� * (������������ �Ȼ) � �������� + (������������ ���Ȼ) ����������� � ���������� ��������� bool (���������� ���������������);
� �������� ! ��� �������������� �������� �����������;
� ���������� ������������ ���������� �����������;
� ������������� �������� ������ ������ �������� ����������� �������, ��������, ��� ����������� false ������������ ������ ����� . ��� �������  , ��� true � �����-������ ������ (��������, 1):
1...1
.1.1.
..1..
.1.1.
1...1

������:
��������� ���� � ������������ ������ x,y � �������� r.
*/

int get_key()
{
	int key = _getch();
	if ((key == 0) || (key == 224)) key = _getch();
	return key;
};

int menu_1()
{
	std::cout << "��������, ��� �� ������ ���������� ������:\n";
	std::cout << "������������� �����������: Enter\n������� � ������ ������������: 1\n�������� �� ������ �����������: 2\n������� � ��������� ���������: 3\n�������� �� ��������� ��������: 2\n����� �� ����-��: Esc\n";
	while (true)
	{
		int key = get_key();
		if ((key == 13) || (key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 27)) return key;
	}
}

int menu_2()
{
	std::cout << "���������: Enter\n����� �� ����-��: Esc\n";
	while (true)
	{
		int key = get_key();
		if ((key == 13) || (key == 27)) return key;
	}
}

void creat_image(double radios, bin_image& A) {
	for (int i = 0; i < 2 * radios + 2; i++) {
		for (int j = 0; j < 2 * radios + 2; j++) {
			double a = sqrt(((radios + 1) - i) * ((radios + 1) - i) + ((radios + 1) - j) * ((radios + 1) - j));
			if (a <= radios) {
				try {
					A(i, j)=true;
				}
				catch (const char*) {
					std::cout << "������ ��� �������� �����������\n";
				}
			}
		}
	}

}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");
	while(true){
		system("cls");
		std::cout << "\n��� ��������� �� ������ � ��������� ������������� ����������\n";
		std::cout << "\n������� ������ � ���������� ������(�,�) ����������\n";
		double R, x, y;
		std::cin >> R >> x >> y ;
		while (R <= 0) {
			std::cout << "�������� ������ ����������, ������� ��� ���\n";
			std::cin >> R;
		}
		bin_image A(2*R+2, 2*R+2);
		creat_image(R, A);
		while (true) {
			system("cls");
			std::cout << A;
			std::cout << "\n���������� ������� R="<<R<<"� ������� � ����� �"<<"("<<x<<";"<<y<<")\n";
			int m1 = menu_1();
			switch (m1) {
				case 27: 
					return 0;
					break;
				case 13:
					A=!A;
					while (true) {
						system("cls");
						std::cout << "��������������� �����������:\n";
						std::cout << A;
						int m2 = menu_2();
						if (m2 == 27) return 0;
						if (m2 == 13) {
							A = !A;
							break;
						}
					}
					break;
				case 49:
					//��� ������
					break;
				case 50:
					// ��� ������
					break;
				case 51:

					break;
				case 52:

					break;
			}
		}
	}
	return 0;
}