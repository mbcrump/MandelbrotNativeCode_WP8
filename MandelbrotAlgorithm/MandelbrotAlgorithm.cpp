// MandelbrotAlgorithm.cpp
#include "pch.h"
#include "MandelbrotAlgorithm.h"

using namespace MandelbrotAlgorithm;
using namespace Platform;

MandelbrotAlgorithmRuntimeComponent::MandelbrotAlgorithmRuntimeComponent()
{	
	m_mandelbrot = new Mandelbrot();
}

void MandelbrotAlgorithmRuntimeComponent::Render(int width, 
												 int height, 
												 Platform::WriteOnlyArray<double>^ result, 
												 double *max)
{		
 	m_mandelbrot->Render(width, height, result->Data, max);
}
