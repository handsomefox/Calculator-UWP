#include "Exponent.h"

double Exponent::Calculate(double power)
{
	double result = pow(m_input, power);
	Reset();
	return result;
}
void Exponent::Initialize(std::string& input)
{
	double res = te_interp(input.c_str(), 0);
	m_input = res;
	m_calculatingPower = true;
}
bool Exponent::GetPowerState() { return m_calculatingPower; };
double Exponent::GetInput() { return m_input; }
void Exponent::Reset()
{
	m_input = 0;
	m_calculatingPower = false;
}
