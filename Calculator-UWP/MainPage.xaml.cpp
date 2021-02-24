//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "History.h"

using namespace Calculator_UWP;
using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::ViewManagement;
using namespace Windows::UI::Popups;

using std::string;
using std::to_string;
using std::wstring;

string input;
double result = 0.0;
bool LeftBracketCreated = false;
Windows::Foundation::Size PrefferedApplicationWindowSize(548, 564);

void MainPage::OnSizeChanged(Object^ sender, SizeChangedEventArgs^ e) {
	auto view = ApplicationView::GetForCurrentView();
	view->TryResizeView(PrefferedApplicationWindowSize);
}

String^ ConvertToString(const string& input) {
	wstring w_str = wstring(input.begin(), input.end());
	const wchar_t* w_chars = w_str.c_str();
	return (ref new String(w_chars, (unsigned int)w_str.length()));
}

bool CheckForSpecialSymbols(const string& input) {
	size_t length = input.length() - 1;
	if (input[length] == '*' || input[length] == '/' || input[length] == '+' ||
		input[length] == '-' || input[length] == '%' || input[length] == '.')
		return true;
	else
		return false;
}
bool CheckForSpecialSymbols(const string& input, bool CheckForBrackets) {
	size_t length = input.length() - 1;
	if (input[length] != '*' || input[length] != '/' || input[length] != '+' ||
		input[length] != '-' || input[length] != '(' || input[length] != ')' ||
		input[length] == '%' || input[length] == '.')
		return true;
	else
		return false;
}

void DisplayPopup(const string& popup_msg)
{
	Controls::ContentDialog^ popupDialog = ref new Controls::ContentDialog();
	popupDialog->Title = "Hey there!";
	popupDialog->Content = ConvertToString(popup_msg);
	popupDialog->CloseButtonText = "OK";
	popupDialog->ShowAsync();
}

bool StrContainsNumber(const string& input) {
	const string numbers = "1234567890";

	if (input.empty()) {
		DisplayPopup(string("You need to enter some numbers first!"));
		return false;
	}
	else {
		for (char i : input)
			for (char number : numbers)
				if (i == number)
					return true;
	}
	DisplayPopup(string("Your input doesn't have any numbers!"));
	return false;
}

struct Exponentiation {
private:
	double m_input = 0.0;
	bool m_calculatingPower = false;

public:
	void Reset() {
		m_input = 0;
		m_calculatingPower = false;
		input.clear();
	}
	
	void Initialize(double input) {
		m_input = input;
		m_calculatingPower = true;
	}
	double Calculate(double power) {
		double result = pow(m_input, power);
		Reset();
		return result;
	};

	bool GetPowerState() { return m_calculatingPower; };
} s_Exponentiation;

MainPage::MainPage() {
	InitializeComponent();
	ApplicationView::GetForCurrentView()->SetPreferredMinSize(PrefferedApplicationWindowSize);
}

void MainPage::UpdateCalculatorOutput() {
	this->CalculatorOutputTextBox->Text = ConvertToString(input);
	this->History_Block->Text = ConvertToString(s_History.UpdateHistory());
}

double CalculateExpression() { return te_interp(input.c_str(), 0); }

void MainPage::RemoveTrailingZeroesAndUpdate(double result) {
	double i, f;
	f = modf(result, &i);
	if (f == 0.0)
		input = to_string((int64)i);
	else {
		input = to_string(result);
		input.erase(input.find_last_not_of('0') + 1, string::npos);
	}
	UpdateCalculatorOutput();
}
void MainPage::ButtonClear_Click(Object^ sender, RoutedEventArgs^ e) {
	this->CalculatorOutputTextBox->Text = "";
	this->CalculatorOutputTextBox->PlaceholderText = "0";
	LeftBracketCreated = false;
	s_Exponentiation.Reset();
	input.clear();
}
void MainPage::Button1_Click(Object^ sender, RoutedEventArgs^ e) {
	input += "1";
	UpdateCalculatorOutput();
}
void MainPage::Button2_Click(Object^ sender, RoutedEventArgs^ e) {
	input += "2";
	UpdateCalculatorOutput();
}
void MainPage::Button3_Click(Object^ sender, RoutedEventArgs^ e) {
	input += "3";
	UpdateCalculatorOutput();
}
void MainPage::Button4_Click(Object^ sender, RoutedEventArgs^ e) {
	input += "4";
	UpdateCalculatorOutput();
}
void MainPage::Button5_Click(Object^ sender, RoutedEventArgs^ e) {
	input += "5";
	UpdateCalculatorOutput();
}
void MainPage::Button6_Click(Object^ sender, RoutedEventArgs^ e) {
	input += "6";
	UpdateCalculatorOutput();
}
void MainPage::Button7_Click(Object^ sender, RoutedEventArgs^ e) {
	input += "7";
	UpdateCalculatorOutput();
}
void MainPage::Button8_Click(Object^ sender, RoutedEventArgs^ e) {
	input += "8";
	UpdateCalculatorOutput();
}
void MainPage::Button9_Click(Object^ sender, RoutedEventArgs^ e) {
	input += "9";
	UpdateCalculatorOutput();
}
void MainPage::Button0_Click(Object^ sender, RoutedEventArgs^ e) {
	input += "0";
	UpdateCalculatorOutput();
}
void MainPage::Button_Addition_Click(Object^ sender, RoutedEventArgs^ e) {
	if (input.length() > 0) {
		if (CheckForSpecialSymbols(input)) {
			if (input.length() == 1)
				return;
			input[input.length() - 1] = '+';
		}
		else
			input += '+';
	}
	UpdateCalculatorOutput();
}
void MainPage::Button_Subtraction_Click(Object^ sender, RoutedEventArgs^ e) {
	if (input.length() > 0) {
		if (CheckForSpecialSymbols(input))
			input[input.length() - 1] = '-';
		else
			input += '-';
	}
	else
		input += '-';
	UpdateCalculatorOutput();
}
void MainPage::Button_Division_Click(Object^ sender, RoutedEventArgs^ e) {
	if (input.length() > 0) {
		if (CheckForSpecialSymbols(input)) {
			if (input.length() == 1)
				return;
			input[input.length() - 1] = '/';
		}
		else
			input += '/';
	}
	UpdateCalculatorOutput();
	
}
void MainPage::Button_Multiplication_Click(Object^ sender, RoutedEventArgs^ e) {
	if (input.length() > 0) {
		if (CheckForSpecialSymbols(input)) {
			if (input.length() == 1)
				return;
			input[input.length() - 1] = '*';
		}
		else
			input += '*';
	}
	UpdateCalculatorOutput();
}
void MainPage::Button_Equals_Click(Object^ sender, RoutedEventArgs^ e) {
	double result = 0.0;
	if (s_Exponentiation.GetPowerState() == true) {
		result = s_Exponentiation.Calculate(CalculateExpression());
		this->CalculatorOutputTextBox->PlaceholderText = "0";
	}
	else
		result = CalculateExpression();
	
	s_History.AddToHistory(input, result);
	RemoveTrailingZeroesAndUpdate(result);
}
void MainPage::Button_Bracket_Click(Object^ sender, RoutedEventArgs^ e) {
	if (LeftBracketCreated == false)
		input += "(";
	else
		input += ")";
	LeftBracketCreated = !LeftBracketCreated;
	UpdateCalculatorOutput();
}
void MainPage::Button_Sq_Root_Click(Object^ sender, RoutedEventArgs^ e) {
	if (StrContainsNumber(input)) {
		double result = sqrt(CalculateExpression());
		RemoveTrailingZeroesAndUpdate(result);
	}
}
void MainPage::Button_Back_Click(Object^ sender, RoutedEventArgs^ e) {
	if (input.length() > 0)
		input.pop_back();
	UpdateCalculatorOutput();
}
void MainPage::Button_Sqr_Click(Object^ sender, RoutedEventArgs^ e) {
	if (StrContainsNumber(input)) {
		double result = (CalculateExpression() * CalculateExpression());
		RemoveTrailingZeroesAndUpdate(result);
	}
}
void MainPage::Button_Dot_Click(Object^ sender, RoutedEventArgs^ e) {
	if (input.length() > 0) {
		if (CheckForSpecialSymbols(input)) {
			if (input.length() == 1)
				return;
			input[input.length() - 1] = '.';
		}
		else
			input += '.';
	}
	else
		input += "0.";
	UpdateCalculatorOutput();
}

void MainPage::Button_Mod_Click(Object^ sender, RoutedEventArgs^ e) {
	if (input.length() > 0) {
		if (CheckForSpecialSymbols(input)) {
			if (input.length() == 1)
				return;
			input[input.length() - 1] = '%';
		}
		else
			input += '%';
	}
	UpdateCalculatorOutput();
}
void MainPage::Button_ln_Click(Object^ sender, RoutedEventArgs^ e) {
	if (StrContainsNumber(input)) {
		double result = (log(CalculateExpression()));
		RemoveTrailingZeroesAndUpdate(result);
	}
}
void MainPage::Button_powerOf_Click(Object^ sender, RoutedEventArgs^ e) {
	if (StrContainsNumber(input)) {
		if (CheckForSpecialSymbols(input, 1)) {
			double value_to_calculate = (CalculateExpression());
			s_Exponentiation.Initialize(value_to_calculate);
			input.clear();
			this->CalculatorOutputTextBox->PlaceholderText = "Enter needed power: ";
			UpdateCalculatorOutput();
		}
	}
}
void MainPage::Button_Inverse_Click(Object^ sender, RoutedEventArgs^ e) {
	if (StrContainsNumber(input)) {
		double result = 1 / (CalculateExpression());
		RemoveTrailingZeroesAndUpdate(result);
	}
}

void MainPage::ButtonClearHistory_Click(Object^ sender, RoutedEventArgs^ e)
{
	s_History.ClearHistory();
	this->History_Block->Text = ConvertToString(s_History.UpdateHistory());
}
