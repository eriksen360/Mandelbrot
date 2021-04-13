#include "Mandelbrot.h"
#include <complex>
#include <math.h>


Mandelbrot::Mandelbrot(const int height, const int width) : m_height(height), m_width(width) {
	zoomList.setWidth(m_width);
	zoomList.setHeight(m_height);
}

void Mandelbrot::addZoom(const int height, const int width) {

	Zoom newZoom(width, height, 2.0/width);
	zoomList.add(newZoom);
}

// map numberOfIterations to color
int Mandelbrot::getIteration(const double& xCoor, const double& yCoor) {

	std::complex<double> z_n{ 0.0, 0.0 };
	std::complex<double> c{ xCoor, yCoor };
	unsigned int numberOfIterations = 0;

	while (numberOfIterations < MAX_ITERATIONS) {

		// Mandelbrot fractal
		z_n = pow(z_n, 2) + c;

		// Other common fractal functions include
		// c*sin(z_n), c*exp(z_n), c*j*cos(z_n), c*z_n(1-z_n)


		// a complex number is in the Mandelbrot set if |z_n| < 2
		// all points outside of |z_n| > 2 is colered red, can this be changed? 
		if (std::abs(z_n) >= 2) {
			break;
		}
		numberOfIterations++;
	}
	// if we succesfully iterated through MAX_ITERATIONS without going out of bounds, return true
	return numberOfIterations;
}

RGB Mandelbrot::getShadingFromIterations(const int& iterations) {

	// Hvordan implementerer vi en langt mere glidende overgang? 
	double p = (double)iterations / MAX_ITERATIONS;
	return RGB(255, 255*p, 255*p);
}


void Mandelbrot::generateImage(const unsigned int& height, const unsigned int& width, Bitmap& bitMap) {
	
	if (height <= 0 || width <= 0) { return; }

	int iterations;
	double hue;
	std::pair<double, double> coords{ 0.0, 0.0 };
	RGB colorDiff(0, 0, 0), startColor(0, 0, 0);
	uint8_t red, green, blue;

	for (unsigned int y = 0; y < height; y++) {
		for (unsigned int x = 0; x < width; x++) {
			
			coords = zoomList.doZoom(x, y);
			iterations = getIteration(coords.first, coords.second);
			hue = (double)iterations / MAX_ITERATIONS;

			//Vi kan ved at tweeke farvekombinationerne få nogle rimelige imponerede strukturer
			colorDiff = getShadingFromIterations(iterations);
			red = startColor.red + colorDiff.red * hue * fabs(coords.first - coords.second);
			green = startColor.green + colorDiff.green * hue;
			blue = startColor.blue + colorDiff.blue * hue * 3*fabs(coords.first + coords.second);

			if (hue != 1) 
				bitMap.setPixel(x, y, red, green, blue);
			else {
				bitMap.setPixel(x, y, 0, 0, 0);
			}
		}
	}
}


