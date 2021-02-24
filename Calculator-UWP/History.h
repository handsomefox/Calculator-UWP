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
	void AddToHistory(string& expression, string& result)
	{
		auto entry = std::make_pair(expression, result);
		m_history.push_back(entry);
		m_entries++;
		UpdateHistory();
	}
}s_History;

