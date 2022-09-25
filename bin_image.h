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
class bin_image
{
	friend std::ostream& operator <<(std::ostream& s, const bin_image& image);
private:
	bool** data;
	unsigned int length, width;
public:
	bin_image(unsigned int length = 3, unsigned int width = 3);
	char operator ()(unsigned int str_index, unsigned int col_index) const;
	bin_image& operator *(const bin_image& image);
	bin_image& operator +(const bin_image& image);
	bin_image& operator !();
	unsigned int fill_factor() const;
	~bin_image();
};
