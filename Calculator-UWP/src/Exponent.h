#pragma once
#include "pch.h"
namespace Exponent
{
    static double m_input = 0.0;
    static bool m_calculatingPower = false;
    void Reset();
    void Initialize(std::string &input);
    double Calculate(double power);
    bool GetPowerState();
    double GetInput();
}; // namespace Exponent
