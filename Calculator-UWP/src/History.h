#pragma once
#include "pch.h"
namespace History
{
    static size_t m_entries = 0;
    static std::vector<std::pair<std::string, std::string>> m_history;
    std::string UpdateHistory();
    void AddToHistory(std::string &expression, std::string result);
    void ClearHistory();
    size_t GetEntries();
}; // namespace History
