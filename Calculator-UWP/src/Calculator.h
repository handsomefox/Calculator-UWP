#pragma once
#include "pch.h"

namespace Calculator
{
    static std::string m_input;
    static std::string m_output;
    static double m_result = 0.0;
    void Append(char symbol);
    void Append(const char *symbol);
    std::string Input();
    std::string Output();
    std::string calculate();
    void Back(Platform::String ^ input);
    void Square(const std::string &input);
    void SquareRoot(const std::string &input);
    void Log(const std::string &input);
    void Exponent(const std::string &input);
    void Inverse(const std::string &input);
    ;
    double GetResult();
    void AppendResult(double res);
    void AppendResult(double res, std::string &input);
    void Clear();
    bool Empty();
    bool InputHasSpecialSymbols(bool CheckForBrackets);
    const size_t Length();
    void ReplaceAt(size_t length, char symbol);
    bool InputContainsNumbers();
    std::string RemoveTrailingZeroes(double result);
}; // namespace Calculator
