#pragma once
#include "pch.h"

namespace Functions
{
	static Platform::String^ ConvertToString(const std::string& input) {
		std::wstring w_str = std::wstring(input.begin(), input.end());
		const wchar_t* w_chars = w_str.c_str();
		return (ref new Platform::String(w_chars, (unsigned int)w_str.length()));
	}
	static std::string ConvertPlatformStringToStd(Platform::String^ input)
	{
		std::wstring wstr(input->Begin());
		std::string output(wstr.begin(), wstr.end());
		return output;
	}
	static void DisplayPopup(const std::string& popup_msg)
	{
		Windows::UI::Xaml::Controls::ContentDialog^ popupDialog =
			ref new Windows::UI::Xaml::Controls::ContentDialog();
		popupDialog->Title = "Hey there!";
		popupDialog->Content = ConvertToString(popup_msg);
		popupDialog->CloseButtonText = "OK";
		popupDialog->ShowAsync();
	}
}// namespace Functions
