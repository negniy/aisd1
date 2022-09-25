#include "bin_image.h"

bin_image::bin_image(unsigned int length = 3, unsigned int width = 3) {


}

char bin_image::operator ()(unsigned int str_index, unsigned int col_index) const {


}

bin_image& bin_image::operator *(const bin_image& image) {


}

bin_image& bin_image:: operator +(const bin_image& image) {


}

bin_image& bin_image:: operator !() {


}

unsigned int bin_image::fill_factor() const {


}

bin_image::~bin_image(){
	for (int i = 0; i < length; i++) {
		delete[]data[i];
	}
	length = 0;
	width = 0;
}

std::ostream& operator <<(std::ostream& s, const bin_image& image)
{
	s << "(";
	
	s << ")";
	return s;
}
