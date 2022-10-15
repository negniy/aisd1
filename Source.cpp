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
/*Класс бинарных изображений произвольного размера.
Как минимум, предоставить:
• конструктор с параметрами: размеры изображения;
• оператор () для чтения/записи элемента по указанным индексам;
• операторы умножения * (поэлементное «И») и сложения + (поэлементное «ИЛИ») изображений;
• операторы умножения * (поэлементное «И») и сложения + (поэлементное «ИЛИ») изображения с логическим значением bool (обеспечить коммутативность);
• оператор ! для инвертирования значений изображения;
• вычисление коэффициента заполнения изображения;
• перегруженный оператор вывода должен выводить изображение красиво, например, для отображения false использовать символ точки . или пробела  , для true – какой-нибудь символ (например, 1):
1...1
.1.1.
..1..
.1.1.
1...1

Задачи:
Нарисуйте круг с координатами центра x,y и радиусом r.
*/

int get_key()
{
	int key = _getch();
	if ((key == 0) || (key == 224)) key = _getch();
	return key;
};

int menu_1()
{
	std::cout << "Выберите, как вы хотите продолжить работу:\n";
	std::cout << "Инвертировать изображение: Enter\nСложить с другим изображением: 1\nУмножить на другое изображение: 2\nСложить с булевским значением: 3\nУмножить на булевское значение: 4\nВычислить коэффициент заполнения изображения: 5\nВыход из прог-мы: Esc\n";
	while (true)
	{
		int key = get_key();
		if ((key == 13) || (key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 27)) return key;
	}
}

int menu_2()
{
	std::cout << "Вернуться: Enter\nВыход из прог-мы: Esc\n";
	while (true)
	{
		int key = get_key();
		if ((key == 13) || (key == 27)) return key;
	}
}


bin_image create_image() {
	std::cout << "\nВведите размеры изображения(длина, ширина)\n";
	int length, width;
	std::cin >> length >> width;
	try {
		bin_image A(length, width);
		return A;
	}
	catch (const char* message) {
		std::cout << message;
		while (true) {
			std::cout << "\nВведите размеры изображения(длина, ширина)\n";
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
		std::cout << "\nЭто программа по работе с бинарными изображениями окружности\n";
		bin_image A = create_image();
		std::cout << "\nВведите радиус и координаты центра(х,у) окружности\n";
		double R;
		int x, y;
		std::cin >> R >> x >> y;
		while (R <= 0) {
			std::cout << "Неверный радиус окружности, введите еще раз\n";
			std::cin >> R;
		}

		try {
			create_circle(R, x, y, A);
		}
		catch (const char* message) {
			std::cout << message;
			while (true) {
				std::cout << "Некорректные координаты центра введите еще раз (х,у)\n";
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
			std::cin.clear();
			system("cls");
			std::cout << A;
			std::cout << "\nОкружность радиуса R=" << R << " с центром в точке О" << "(" << x << ";" << y << ")\n";
			int m1 = menu_1();
//выход из программы
			if (m1 == 27) return 0;
//интвертировать
			if (m1 == 13) { 
				A = !A;
				while (true) {
					system("cls");
					std::cout << "Инвертированное изображение:\n";
					std::cout << A;
					int m2 = menu_2();
					if (m2 == 27) return 0;
					if (m2 == 13) {
						A = !A;
						break;
					}
				}
			}
// коэф заполнения
			if (m1 == 53) {
				while (true) {
					system("cls");
					std::cout << "Коэффициент заполнения = " << A.fill_factor() << "\n";
					int m2 = menu_2();
					if (m2 == 27) return 0;
					if (m2 == 13) {
						break;
					}
				}
			}
// сложить с изобр
			if (m1 == 49) {
				bin_image B = create_image();
				std::cout << "\nВведите радиус и координаты центра(х,у) окружности\n";
				double R;
				int x, y;
				std::cin >> R >> x >> y;
				while (R <= 0) {
					std::cout << "Неверный радиус окружности, введите еще раз\n";
					std::cin >> R;
				}
				try {
					create_circle(R, x, y, B);
				}
				catch (const char* message) {
					std::cout << message;
					while (true) {
						std::cout << "Некорректные координаты центра введите еще раз (х,у)\n";
						std::cin >> x >> y;
						try {
							create_circle(R, x, y, B);
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
						std::cout << "Полученное изображение\n";
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
						std::cout << "Невозвожно сложить 2 изображения\n";
						int m3 = menu_2();
						if (m3 == 27) return 0;
						if (m3 == 13) break;
					}
				}
			}
//умножить на изобр
			if (m1 == 50) {
				bin_image B = create_image();
				std::cout << "\nВведите радиус и координаты центра(х,у) окружности\n";
				double R;
				int x, y;
				std::cin >> R >> x >> y;
				while (R <= 0) {
					std::cout << "Неверный радиус окружности, введите еще раз\n";
					std::cin >> R;
				}
				try {
					create_circle(R, x, y, B);
				}
				catch (const char* message) {
					std::cout << message;
					while (true) {
						std::cout << "Некорректные координаты центра введите еще раз (х,у)\n";
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
						std::cout << "Полученное изображение\n";
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
						std::cout << "Невозвожно умножить 2 изображения\n";
						int m3 = menu_2();
						if (m3 == 27) return 0;
						if (m3 == 13) break;
					}
				}
			}
// сложить с булевским
			if (m1 == 51) {
				system("cls");
				std::cout << "Введите булевское значение:(0/1)\n";
				bool n;
				std::cin >> n;
				bin_image tmp = A + n;
				while (true) {
					system("cls");
					std::cout << "Полученное изображение:\n";
					std::cout << tmp;
					int m2 = menu_2();
					if (m2 == 27) return 0;
					if (m2 == 13) break;
				}
			}
// умножить на булевское
			if (m1 == 52) {
				system("cls");
				std::cout << "Введите булевское значение:(0/1)\n";
				bool n;
				std::cin >> n;
				bin_image tmp = n * A;
				while (true) {
					system("cls");
					std::cout << "Полученное изображение:\n";
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