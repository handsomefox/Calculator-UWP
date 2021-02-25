#include "History.h"

void History::AddToHistory(std::string& expression, std::string result)
{
	if (m_entries >= 23)
	{
		m_history.clear();
		m_entries = 0;
	}
	auto entry = std::make_pair(expression, result);
	m_history.push_back(entry);
	m_entries++;
	UpdateHistory();
}
void History::ClearHistory()
{
	m_entries = 0;
	m_history.clear();
}
size_t History::GetEntries() { return m_entries; }
std::string History::UpdateHistory()
{
	std::string history = "";
	for (size_t i = 0; i < m_entries; ++i)
	{
		history += m_history.at(i).first;
		history += " = ";
		history += m_history.at(i).second;
		history += "\n";
	}
	return history;
}
