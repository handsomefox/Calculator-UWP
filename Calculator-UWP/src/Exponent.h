#pragma once
#include "pch.h"
namespace Exponent
{
	static double m_input = 0.0;
	static bool m_calculatingPower = false;
	
	double Calculate(double power);
	void Initialize(std::string& input);
	bool GetPowerState();
	double GetInput();
	void Reset();
} // namespace Exponent
