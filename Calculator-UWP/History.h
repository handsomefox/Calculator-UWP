#pragma once
#include "pch.h"

using std::vector;
using std::string;
using std::pair;

class History
{
	size_t m_entries = 0;
	vector<pair<string, string>> m_history;
public:

	string UpdateHistory()
	{
		string history = "";
		for (size_t i = 0; i < m_entries; ++i)
		{
			history += m_history.at(i).first;
			history += " = ";
			history += m_history.at(i).second;
			history += "\n";
		}
		return history;
	}
	void AddToHistory(string& expression, double result)
	{
		double i, f;
		string input;
		f = modf(result, &i);
		if (f == 0.0)
			input = std::to_string((int64)i);
		else {
			input = std::to_string(result);
			input.erase(input.find_last_not_of('0') + 1, string::npos);
		}
		if (m_entries >= 23)
		{
			m_history.clear();
			m_entries = 0;
		}
		auto entry = std::make_pair(expression, input);
		m_history.push_back(entry);
		m_entries++;
		UpdateHistory();
	}
	void ClearHistory()
	{
		m_entries = 0; m_history.clear();
	}
	size_t GetEntries() { return m_entries; }
}s_History;

