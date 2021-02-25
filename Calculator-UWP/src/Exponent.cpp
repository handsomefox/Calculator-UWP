#include "Exponent.h"
void Exponent::Reset()
{
	m_input = 0;
	m_calculatingPower = false;
}

void Exponent::Initialize(std::string &input)
{
	double res = te_interp(input.c_str(), 0);
	m_input = res;
	m_calculatingPower = true;
}
double Exponent::Calculate(double power)
{
	double result = pow(m_input, power);
	Reset();
	return result;
}

bool Exponent::GetPowerState() { return m_calculatingPower; };

double Exponent::GetInput() { return m_input; }
