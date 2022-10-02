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
	std::cout << "Инвертировать изображение: Enter\nСложить с другим изображением: 1\nУмножить на другое изображение: 2\nСложить с булевским значением: 3\nУмножить на булевское значение: 2\nВыход из прог-мы: Esc\n";
	while (true)
	{
		int key = get_key();
		if ((key == 13) || (key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 27)) return key;
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
	while(true){
		system("cls");
		std::cout << "\nЭто программа по работе с бинарными изображениями окружности\n";
		bin_image A;
		A = create_image();
		std::cout << "\nВведите радиус и координаты центра(х,у) окружности\n";
		double R;
		int x, y;
		std::cin >> R >> x >> y ;
		while (R <= 0) {
			std::cout << "Неверный радиус окружности, введите еще раз\n";
			std::cin >> R;
		}
		// exception
		create_circle(R, x, y, A);
		while (true) {
			system("cls");
			std::cout << A;
			std::cout << "\nОкружность радиуса R="<<R<<" с центром в точке О"<<"("<<x<<";"<<y<<")\n";
			int m1 = menu_1();
			switch (m1) {
				case 27: 
					return 0;
					break;
				case 13:
					A=!A;
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
					break;
				case 49:
					//как делать сложить с изобр
					break;
				case 50:
					// как делать умнож с изобр
					break;
				case 51:
					system("cls");
					std::cout << "Введите булевское значение:(true/false)\n";
					bool n;
					std::cin >> n;
					A=n+A;
					while (true) {
						system("cls");
						std::cout << "Полученное изображение:\n";//поправить
						std::cout << A;
						int m2 = menu_2();
						if (m2 == 27) return 0;
						if (m2 == 13) {
							A = !A;
							break;
						}
					}
					break;
				case 52:

					break;
			}
		}
	}
	return 0;
}