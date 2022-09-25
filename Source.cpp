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

void creat_image(double radios, bin_image& A) {
	for (int i = 0; i < 2 * radios + 2; i++) {
		for (int j = 0; j < 2 * radios + 2; j++) {
			double a = sqrt(((radios + 1) - i) * ((radios + 1) - i) + ((radios + 1) - j) * ((radios + 1) - j));
			if (a <= radios) {
				try {
					A(i, j)=true;
				}
				catch (const char*) {
					std::cout << "Ошибка при создании изображения\n";
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
		std::cout << "\nЭто программа по работе с бинарными изображениями окружности\n";
		std::cout << "\nВведите радиус и координаты центра(х,у) окружности\n";
		double R, x, y;
		std::cin >> R >> x >> y ;
		while (R <= 0) {
			std::cout << "Неверный радиус окружности, введите еще раз\n";
			std::cin >> R;
		}
		bin_image A(2*R+2, 2*R+2);
		creat_image(R, A);
		while (true) {
			system("cls");
			std::cout << A;
			std::cout << "\nОкружность радиуса R="<<R<<"с центром в точке О"<<"("<<x<<";"<<y<<")\n";
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
					//как делать
					break;
				case 50:
					// как делать
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