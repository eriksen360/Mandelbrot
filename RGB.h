#pragma once

struct RGB {

	double red;
	double green;
	double blue;
	RGB(double r, double g, double b) : red(r), green(g), blue(b) {}
};

//RGB& operator-(const RGB& operand, const RGB& other) {
//	RGB result{ operand.red - other.red, operand.green - other.green, operand.blue - other.blue };
//	return result;
//}