#include "Calculator.h"
#include "Exponent.h"
#include "Functions.h"
#include "History.h"

using namespace Calculator_UWP;

std::string Calculator::RemoveTrailingZeroes(double result)
{
  std::string output;
  double i, f;
  f = modf(result, &i);
  if (f == 0.0)
    output = std::to_string((int64)i);
  else
  {
    output = std::to_string(result);
    output.erase(output.find_last_not_of('0') + 1, std::string::npos);
  }
  return output;
}
std::string Calculator::Input() { return m_input; }
std::string Calculator::Output() { return m_output; }
void Calculator::Append(char symbol) { m_input += symbol; }
void Calculator::Append(const char *symbol) { m_input += symbol; }
std::string Calculator::calculate()
{
  m_result = te_interp(m_input.c_str(), 0);
  m_output = RemoveTrailingZeroes(m_result);
  History::AddToHistory(m_input, m_output);
  return m_output;
}

double Calculator::GetResult()
{
  double calculated = te_interp(m_input.c_str(), 0);
  return calculated;
}

void Calculator::AppendResult(double res)
{
  m_output = RemoveTrailingZeroes(res);
  History::AddToHistory(m_input, m_output);
}

void Calculator::AppendResult(double res, std::string &input)
{
  m_output = RemoveTrailingZeroes(res);
  History::AddToHistory(input, m_output);
}

void Calculator::Clear()
{
  m_input.clear();
  m_output.clear();
  m_result = 0.0;
}

bool Calculator::Empty()
{
  if (m_input.empty())
    return true;
  else
    return false;
}

bool Calculator::InputHasSpecialSymbols(bool CheckForBrackets)
{
  std::string special_symbols = "*/+-%.";
  const std::string brackets = "()";
  if (Empty())
    return false;
  if (CheckForBrackets == true)
    special_symbols += brackets;

  for (size_t j = 0; j < special_symbols.length(); ++j)
    if (m_input[Calculator::Length()] == special_symbols[j])
      return true;
  return false;
}

const size_t Calculator::Length() { return m_input.length(); }
void Calculator::ReplaceAt(size_t length, char symbol)
{
  if (length <= m_input.length())
  {
    m_input[length] = symbol;
  }
}

bool Calculator::InputContainsNumbers()
{
  const std::string numbers = "1234567890";

  if (m_input.empty())
  {
    Functions::DisplayPopup(
        std::string("You need to enter some numbers first!"));
    return false;
  }
  else
  {
    for (char i : m_input)
      for (char number : numbers)
        if (i == number)
          return true;
  }
  Functions::DisplayPopup(std::string("Your input doesn't have any numbers!"));
  return false;
}

void Calculator::Square(const std::string &input)
{
  std::string history = input + "^2";
  double val = te_interp(input.c_str(), 0);
  double res = val * val;
  m_output = RemoveTrailingZeroes(res);
  History::AddToHistory(history, m_output);
}

void Calculator::SquareRoot(const std::string &input)
{
  std::string history = "sqrt(" + input + ")";
  double val = te_interp(input.c_str(), 0);
  double res = sqrt(val);
  m_output = RemoveTrailingZeroes(res);
  History::AddToHistory(history, m_output);
}

void Calculator::Log(const std::string &input)
{
  std::string history = "ln(" + input + ")";
  double val = te_interp(input.c_str(), 0);
  double res = log(val);
  m_output = RemoveTrailingZeroes(res);
  History::AddToHistory(history, m_output);
}

void Calculator::Exponent(const std::string &input)
{
  std::string history = input + "^2";
  double val = te_interp(input.c_str(), 0);
  double squared = val * val;
  m_output = RemoveTrailingZeroes(squared);
  History::AddToHistory(history, m_output);
}

void Calculator::Inverse(const std::string &input)
{
  std::string history = "1/" + input;
  double val = te_interp(input.c_str(), 0);
  double res = 1 / val;
  m_output = RemoveTrailingZeroes(res);
  History::AddToHistory(history, m_output);
}

void Calculator::Back(Platform::String ^ input)
{
  if (m_output == Functions::ConvertPlatformStringToStd(input))
  {
    if (!m_output.empty())
      m_output.pop_back();
  }
  else
  {
    if (!m_input.empty())
      m_input.pop_back();
  }
}
