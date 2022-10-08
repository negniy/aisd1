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
	std::cout << "������������� �����������: Enter\n������� � ������ ������������: 1\n�������� �� ������ �����������: 2\n������� � ��������� ���������: 3\n�������� �� ��������� ��������: 4\n��������� ����������� ���������� �����������: 5\n����� �� ����-��: Esc\n";
	while (true)
	{
		int key = get_key();
		if ((key == 13) || (key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 27)) return key;
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

int menu_3()
{
	std::cout << "���������: Enter\n������� ����������� ��� ���: 1\n����� �� ����-��: Esc\n";
	while (true)
	{
		int key = get_key();
		if ((key == 13) || (key == 27) || (key == 49)) return key;
	}
}

bin_image create_image() {
	std::cout << "\n������� ������� �����������(�����, ������)\n";
	int length, width;
	std::cin >> length >> width;
	try {
		bin_image A(length, width);
		return A;
	}
	catch (const char* message) {
		std::cout << message;
		while (true) {
			std::cout << "\n������� ������� �����������(�����, ������)\n";
			std::cin >> length >> width;
			try {
				bin_image A(length, width);
				return A;
			}
			catch (const char* message) {
				std::cout << message;
			}
		}
	}
}

void create_circle(double radios, int x, int y, bin_image& A) {
	int center_x = A.get_length() / 2;
	int center_y = A.get_width() / 2;
	x = x + center_x;
	y = center_y - y;
	for (int i = 0; i < A.get_length(); i++) {
		for (int j = 0; j <A.get_width(); j++) {
			bool& item = A(i, j);
			double a = sqrt((x - i)*(x - i) + (y - j)*(y - j));
			if (a <= radios) {
				item=true;
			}
			else{ item = false; }
		}
	}

}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");
	while (true) {
		system("cls");
		std::cout << "\n��� ��������� �� ������ � ��������� ������������� ����������\n";
		bin_image A = create_image();
		std::cout << "\n������� ������ � ���������� ������(�,�) ����������\n";
		double R;
		int x, y;
		std::cin >> R >> x >> y;
		while (R <= 0) {
			std::cout << "�������� ������ ����������, ������� ��� ���\n";
			std::cin >> R;
		}

		try {
			create_circle(R, x, y, A);
		}
		catch (const char* message) {
			std::cout << message;
			while (true) {
				std::cout << "������������ ���������� ������ ������� ��� ��� (�,�)\n";
				std::cin >> x >> y;
				try {
					create_circle(R, x, y, A);
					break;
				}
				catch (const char* message) {
					std::cout << message;
				}
			}
		}
		while (true) {
			system("cls");
			std::cout << A;
			std::cout << "\n���������� ������� R=" << R << " � ������� � ����� �" << "(" << x << ";" << y << ")\n";
			int m1 = menu_1();
//����� �� ���������
			if (m1 == 27) return 0;
//��������������
			if (m1 == 13) { 
				A = !A;
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
			}
// ���� ����������
			if (m1 == 53) {
				while (true) {
					system("cls");
					std::cout << "����������� ���������� = " << A.fill_factor() << "\n";
					int m2 = menu_2();
					if (m2 == 27) return 0;
					if (m2 == 13) {
						break;
					}
				}
			}
// ������� � �����
			if (m1 == 49) {
				bin_image B = create_image();
				std::cout << "\n������� ������ � ���������� ������(�,�) ����������\n";
				double R;
				int x, y;
				std::cin >> R >> x >> y;
				while (R <= 0) {
					std::cout << "�������� ������ ����������, ������� ��� ���\n";
					std::cin >> R;
				}
				try {
					create_circle(R, x, y, B);
				}
				catch (const char* message) {
					std::cout << message;
					while (true) {
						std::cout << "������������ ���������� ������ ������� ��� ��� (�,�)\n";
						std::cin >> x >> y;
						try {
							create_circle(R, x, y, A);
							break;
						}
						catch (const char* message) {
							std::cout << message;
						}
					}
				}
				try {
					bin_image C = A + B;
					while (true) {
						system("cls");
						std::cout << "���������� �����������\n";
						std::cout << C;
						int m2 = menu_2();
						if (m2 == 27) return 0;
						if (m2 == 13) break;
					}
				}
				catch(const char* message){
					std::cout << message;
					while (true) {
						system("cls");
						std::cout << "���������� ������� 2 �����������\n";
						int m3 = menu_3();
						if (m3 == 27) return 0;
						if (m3 == 13) break;
						if (m3 == 49) {
							B = create_image();
							try {
								bin_image C = A + B;
								break;
							}
							catch (const char* message) { std::cout << message; }
						}
					}
				}
			}
//�������� �� �����
			if (m1 == 50) {
				bin_image B = create_image();
				std::cout << "\n������� ������ � ���������� ������(�,�) ����������\n";
				double R;
				int x, y;
				std::cin >> R >> x >> y;
				while (R <= 0) {
					std::cout << "�������� ������ ����������, ������� ��� ���\n";
					std::cin >> R;
				}
				try {
					create_circle(R, x, y, B);
				}
				catch (const char* message) {
					std::cout << message;
					while (true) {
						std::cout << "������������ ���������� ������ ������� ��� ��� (�,�)\n";
						std::cin >> x >> y;
						try {
							create_circle(R, x, y, A);
							break;
						}
						catch (const char* message) {
							std::cout << message;
						}
					}
				}
				try {
					bin_image C = A * B;
					while (true) {
						system("cls");
						std::cout << "���������� �����������\n";
						std::cout << C;
						int m2 = menu_2();
						if (m2 == 27) return 0;
						if (m2 == 13) break;
					}
				}
				catch (const char* message) {
					std::cout << message;
					while (true) {
						system("cls");
						std::cout << "���������� �������� 2 �����������\n";
						int m3 = menu_3();
						if (m3 == 27) return 0;
						if (m3 == 13) break;
						if (m3 == 49) {
							B = create_image();
							try {
								bin_image C = A * B;
								break;
							}
							catch (const char* message) { std::cout << message; }
						}
					}
				}
			}
// ������� � ���������
			if (m1 == 51) {
				system("cls");
				std::cout << "������� ��������� ��������:(0/1)\n";
				bool n;
				std::cin >> n;
				bin_image tmp = A + n;
				while (true) {
					system("cls");
					std::cout << "���������� �����������:\n";
					std::cout << tmp;
					int m2 = menu_2();
					if (m2 == 27) return 0;
					if (m2 == 13) break;
				}
			}
// �������� �� ���������
			if (m1 == 52) {
				system("cls");
				std::cout << "������� ��������� ��������:(0/1)\n";
				bool n;
				std::cin >> n;
				bin_image tmp = n * A;
				while (true) {
					system("cls");
					std::cout << "���������� �����������:\n";
					std::cout << tmp;
					int m2 = menu_2();
					if (m2 == 27) return 0;
					if (m2 == 13) break;
				}
			}
		}
	}
    return 0;
}
///�������������