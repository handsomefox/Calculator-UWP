#pragma once
#include "pch.h"

namespace Calculator
{
	static std::string m_input;
	static std::string m_output;
	static double m_result = 0.0;
	static bool LeftBracketCreated = false;
	void Append(char symbol);
	void Append(const char* symbol);
	void AppendResult(double res);
	void AppendResult(double res, std::string& input);
	void Back(Platform::String^ input);
	std::string Calculate();
	bool ExpressionIsValid();
	void Clear();
	bool Empty();
	void Exponent(const std::string& input);
	double GetResult();
	bool InputHasSpecialSymbols(bool CheckForBrackets);
	bool InputContainsNumbers();
	void Inverse(const std::string& input);
	std::string Input();
	const size_t Length();
	bool LastSymbolIsBracket();
	void Log(const std::string& input);
	std::string Output();
	void ReplaceAt(size_t length, char symbol);
	std::string RemoveTrailingZeroes(double result);
	void Square(const std::string& input);
	void SquareRoot(const std::string& input);
} // namespace Calculator
