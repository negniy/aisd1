#include "bin_image.h"

bin_image::bin_image(int length, int width): length(length), width(width)
{
	if (length < 1 || width < 1) { throw "Incorrect length and width calculations"; }
	data = new bool*[length];
	for (int i = 0; i < length; i++) {
		data[i] = new bool[width];
		for (int j = 0; j < width; j++) {
			data[i][j] = false;
		}
	}
}

bool& bin_image::operator ()( int str_index, int col_index) const {
	if (str_index < 0 || str_index >= length) { throw "Invalid str_index"; }
	if (col_index < 0 || col_index >= width) { throw "Invalid col_index"; }
	bool& a = data[str_index][col_index];
	return a;
}

bin_image operator+(const bin_image& image_1, const bin_image& image_2)//сложение изображений bool
{
	if (image_1.length != image_2.length || image_1.width != image_2.width) { throw "Addition error"; }
	bin_image image(image_1.length, image_1.width);
	for (int i = 0; i < image_1.length; i++) {
		for (int j = 0; j < image_1.width; j++) {
			image.data[i][j] = (image_1.data[i][j] || image_2.data[i][j]);
		}
	}
	return image;
}

bin_image operator*(const bin_image& image_1, const bin_image& image_2)//умножение изображений bool
{
	if (image_1.length != image_2.length || image_1.width != image_2.width) { throw "Addition error"; }
	bin_image image(image_1.length, image_1.width);
	for (int i = 0; i < image_1.length; i++) {
		for (int j = 0; j < image_1.width; j++) {
			image.data[i][j] = (image_1.data[i][j] && image_2.data[i][j]);
		}
	}
	return image;
}

bin_image operator*(bin_image image, bool a)
{
	for (int i = 0; i < image.length; i++) {
		for (int j = 0; j < image.width; j++) {
			image.data[i][j] = (image.data[i][j] || a);
		}
	}
	return image;
}

bin_image operator+(bin_image image, bool a)
{
	for (int i = 0; i < image.length; i++) {
		for (int j = 0; j < image.width; j++) {
			image.data[i][j] = (image.data[i][j] || a);
		}
	}
	return image;
}

bin_image& bin_image:: operator !() {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (data[i][j] == 0) { 
				data[i][j] = 1; 
			}
			else { 
				data[i][j] = 0;
			}
		}
	}
	return *this;
}

double bin_image::fill_factor() const {
	int count_0 = 0;
	int count_1 = 0;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (data[i][j] == 0) { count_0 += 1; }
			if (data[i][j] == 1) { count_1 += 1; }
		}
	}
	return (double)(count_1) / (count_0 + count_1);
}

bin_image::~bin_image(){
	for (int i = 0; i < length; i++) {
		delete[]data[i];
	}
	length = 0;
	width = 0;
}

bin_image::bin_image(const bin_image& a){
	length = a.length;
	width = a.width;
	for (int i = 0; i < length; i++) {
		data[i] = new bool[width];
		for (int j = 0; j < width; j++) {
			data[i][j] = a.data[i][j];
		}
	}
}

std::ostream& operator <<(std::ostream& s, const bin_image& image)
{
	for (int i = 0; i < image.length; i++) {
		for (int j = 0; j < image.width; j++) {
			if (image.data[i][j] == 0) { s<<" ."; }
			if (image.data[i][j] == 1) { s << " 1"; }
		}
		s << "\n";
	}
	return s;
}
