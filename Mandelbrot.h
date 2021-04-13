#pragma once
#include "Bitmap.h"
#include "ZoomList.h"
#include "RGB.h"

class Mandelbrot {
	int m_height;
	int m_width;
	ZoomList zoomList{ m_height, m_width };
public:
	static const int MAX_ITERATIONS = 100;

	Mandelbrot(const int height, const int width);
	void addZoom(const int height, const int width);
	static int getIteration(const double& xCoor, const double& yCoor);
	RGB getShadingFromIterations(const int& iterations);
	void generateImage(const unsigned int& height, const unsigned int& width, Bitmap& bitmap);
};