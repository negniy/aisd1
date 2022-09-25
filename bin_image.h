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
....|.....
.111|111..
.111|111..
....|.....

������:
��������� ���� � ������������ ������ x,y � �������� r.
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
