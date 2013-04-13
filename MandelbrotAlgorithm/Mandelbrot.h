#pragma once
class Mandelbrot sealed
{
public:
	Mandelbrot(void);
	void Render(int rows, int cols, double *result, double *maxResult);
};

