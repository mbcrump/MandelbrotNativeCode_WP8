#include "pch.h"
#include <algorithm>
// add this to use the complex type version
//#include <complex>
#include <math.h>
#include "Mandelbrot.h"

using namespace std;

Mandelbrot::Mandelbrot(void)
{
}

void Mandelbrot::Render(int pixelWidth, int pixelHeight, double *result, double *maxResult)
{
	// initial values, should be dynamic
	int maxiterations = 25;	
	double initialReal = -2.25, initialImg = -1.65;
	double zoomLevel = 0.0055;
	double escapeRadius = 4.0;
	
	for (int x = 0; x < pixelWidth; x++)
	{
		double currentReal = initialReal + x * zoomLevel;

		for (int y = 0; y < pixelHeight; y++)
		{
			double currentImg = initialImg + y * zoomLevel;

			// iterate
			int n = 0;
			double magSquared = 0.0;
			double iterationX = 0.0;
			double iterationY = 0.0;
			while (magSquared < escapeRadius && n < maxiterations)
			{
				double tempX = iterationX * iterationX - iterationY * iterationY + currentReal;
				double tempY = 2 * iterationX * iterationY + currentImg;

				// calculate mag squared
				magSquared = tempX * tempX + tempY * tempY;

				// new reference values
				iterationX = tempX;
				iterationY = tempY;
				n++;
			}
			
			// calculate color
			double color;
			if (n < maxiterations)
			{
				color = n + 1 - log(log(magSquared)) / log(escapeRadius);			
			}
			else
			{
				color = 0.0;
			}

			// store max color value and color
			if (color > *maxResult)
			{
				*maxResult = color;
			}
						
			result[y * pixelWidth + x] = color;			
		}
	}	
}

//// complex type version
//void Mandelbrot::Render(int pixelWidth, int pixelHeight, double *result, double *maxResult)
//{
//	// initial values, should be dynamic
//	int maxiterations = 25;	
//	double initialReal = -2.5, initialImg = -1.1;
//	double zoomLevel = 0.0055;
//	double escapeRadius = 4.0;
//
//	for (int x = 0; x < pixelWidth; x++)
//	{
//		for (int y = 0; y < pixelHeight; y++)
//		{
//			complex<double> c (initialReal + x * zoomLevel, initialImg + y * zoomLevel);
//			complex<double> z (0.0, 0.0);
//
//			int n = 0;
//			while (norm(z) < escapeRadius && n < maxiterations)
//			{
//				z = z * z + c;
//				n++;
//			}
//
//			// calculate color
//			double color;
//			if (n < maxiterations)
//			{
//				color = n + 1 - log(log(norm(z))) / log(escapeRadius);			
//			}
//			else
//			{
//				color = 0.0;
//			}
//
//			// store max color value and color
//			if (color > *maxResult)
//			{
//				*maxResult = color;
//			}
//						
//			result[y * pixelWidth + x] = color;
//		}
//	}
//}


