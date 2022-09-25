#pragma once
#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <iostream>
/* ласс бинарных изображений произвольного размера.
 ак минимум, предоставить:
Х конструктор с параметрами: размеры изображени€;
Х оператор () дл€ чтени€/записи элемента по указанным индексам;
Х операторы умножени€ * (поэлементное Ђ»ї) и сложени€ + (поэлементное Ђ»Ћ»ї) изображений;
Х операторы умножени€ * (поэлементное Ђ»ї) и сложени€ + (поэлементное Ђ»Ћ»ї) изображени€ с логическим значением bool (обеспечить коммутативность);
Х оператор ! дл€ инвертировани€ значений изображени€;
Х вычисление коэффициента заполнени€ изображени€;
Х перегруженный оператор вывода должен выводить изображение красиво, например, дл€ отображени€ false использовать символ точки . или пробела  , дл€ true Ц какой-нибудь символ (например, 1):
....|.....
.111|111..
.111|111..
....|.....

«адачи:
Ќарисуйте круг с координатами центра x,y и радиусом r.
*/
class bin_image
{
	friend std::ostream& operator <<(std::ostream& s, const bin_image& image);
private:
	bool** data;
	int length, width;
public:
	bin_image( int length = 10, int width = 10);
	bool& operator ()( int str_index, int col_index) const;
	bin_image& operator *(const bin_image& image);
	bin_image& operator +(const bin_image& image);
	bin_image& operator *( bool a);
	bin_image& operator +( bool a);
	bin_image& operator !();
	double fill_factor() const;
	~bin_image();
	bin_image(const bin_image& a);
};
