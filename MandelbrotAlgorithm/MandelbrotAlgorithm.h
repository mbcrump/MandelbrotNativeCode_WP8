#pragma once

#include "Mandelbrot.h"

namespace MandelbrotAlgorithm
{
    public ref class MandelbrotAlgorithmRuntimeComponent sealed
    {
    public:
        MandelbrotAlgorithmRuntimeComponent();
		void Render(int width, int height, Platform::WriteOnlyArray<double>^ result, double *max);
	private:
		Mandelbrot *m_mandelbrot;
    };
}

