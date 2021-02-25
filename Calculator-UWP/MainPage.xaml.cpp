//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "Calculator.h"
#include "Exponent.h"
#include "Functions.h"
#include "History.h"

using namespace Calculator_UWP;
using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::ViewManagement;
using namespace Windows::UI::Popups;

bool LeftBracketCreated = false;
Windows::Foundation::Size PrefferedApplicationWindowSize(548, 564);

void MainPage::UpdateCalculatorInput()
{
	this->CalculatorOutputTextBox->Text =
		Functions::ConvertToString(Calculator::Input());
}
void MainPage::UpdateCalculatorOutput()
{
	this->CalculatorOutputTextBox->Text =
		Functions::ConvertToString(Calculator::Output());
	this->History_Block->Text =
		Functions::ConvertToString(History::UpdateHistory());
}
void MainPage::OnSizeChanged(Object^ sender, SizeChangedEventArgs^ e)
{
	auto view = ApplicationView::GetForCurrentView();
	view->TryResizeView(PrefferedApplicationWindowSize);
}
MainPage::MainPage()
{
	InitializeComponent();
	ApplicationView::GetForCurrentView()->SetPreferredMinSize(
		PrefferedApplicationWindowSize);
}
void MainPage::ButtonClear_Click(Object^ sender, RoutedEventArgs^ e)
{
	this->CalculatorOutputTextBox->Text = "";
	this->CalculatorOutputTextBox->PlaceholderText = "0";
	LeftBracketCreated = false;
	Calculator::Clear();
}
void MainPage::Button1_Click(Object^ sender, RoutedEventArgs^ e)
{
	Calculator::Append('1');
	UpdateCalculatorInput();
}
void MainPage::Button2_Click(Object^ sender, RoutedEventArgs^ e)
{
	Calculator::Append('2');
	UpdateCalculatorInput();
}
void MainPage::Button3_Click(Object^ sender, RoutedEventArgs^ e)
{
	Calculator::Append('3');
	UpdateCalculatorInput();
}
void MainPage::Button4_Click(Object^ sender, RoutedEventArgs^ e)
{
	Calculator::Append('4');
	UpdateCalculatorInput();
}
void MainPage::Button5_Click(Object^ sender, RoutedEventArgs^ e)
{
	Calculator::Append('5');
	UpdateCalculatorInput();
}
void MainPage::Button6_Click(Object^ sender, RoutedEventArgs^ e)
{
	Calculator::Append('6');
	UpdateCalculatorInput();
}
void MainPage::Button7_Click(Object^ sender, RoutedEventArgs^ e)
{
	Calculator::Append('7');
	UpdateCalculatorInput();
}
void MainPage::Button8_Click(Object^ sender, RoutedEventArgs^ e)
{
	Calculator::Append('8');
	UpdateCalculatorInput();
}
void MainPage::Button9_Click(Object^ sender, RoutedEventArgs^ e)
{
	Calculator::Append('9');
	UpdateCalculatorInput();
}
void MainPage::Button0_Click(Object^ sender, RoutedEventArgs^ e)
{
	Calculator::Append('0');
	UpdateCalculatorInput();
}
void MainPage::Button_Addition_Click(Object^ sender, RoutedEventArgs^ e)
{
	if (!Calculator::Empty())
	{
		if (Calculator::InputHasSpecialSymbols(false))
		{
			if (Calculator::Length() == 1)
				return;
			Calculator::ReplaceAt(Calculator::Length() - 1, '+');
		}
		else
			Calculator::Append('+');
	}
	UpdateCalculatorInput();
}
void MainPage::Button_Subtraction_Click(Object^ sender, RoutedEventArgs^ e)
{
	if (!Calculator::Empty())
	{
		if (Calculator::InputHasSpecialSymbols(false))
			Calculator::ReplaceAt(Calculator::Length() - 1, '-');
		else
			Calculator::Append('-');
	}
	else
		Calculator::Append('-');
	UpdateCalculatorInput();
}
void MainPage::Button_Division_Click(Object^ sender, RoutedEventArgs^ e)
{
	if (!Calculator::Empty())
	{
		if (Calculator::InputHasSpecialSymbols(false))
		{
			if (Calculator::Length() == 1)
				return;
			Calculator::ReplaceAt(Calculator::Length() - 1, '/');
		}
		else
			Calculator::Append('/');
	}
	UpdateCalculatorInput();
}
void MainPage::Button_Multiplication_Click(Object^ sender,
	RoutedEventArgs^ e)
{
	if (!Calculator::Empty())
	{
		if (Calculator::InputHasSpecialSymbols(false))
		{
			if (Calculator::Length() == 1)
				return;
			Calculator::ReplaceAt(Calculator::Length() - 1, '*');
		}
		else
			Calculator::Append('*');
	}
	UpdateCalculatorInput();
}
void MainPage::Button_Equals_Click(Object^ sender, RoutedEventArgs^ e)
{
	if (Calculator::Input().empty()) return;
	double result = 0.0;
	if (Exponent::GetPowerState() == true)
	{
		std::string history_form = Calculator::RemoveTrailingZeroes((Exponent::GetInput())) + "^";
		result = Exponent::Calculate(Calculator::GetResult());
		history_form += (Calculator::Input());
		Calculator::AppendResult(result, history_form);
		this->CalculatorOutputTextBox->PlaceholderText = "0";
	}
	else
		Calculator::Calculate();
	UpdateCalculatorOutput();
}
void MainPage::Button_Bracket_Click(Object^ sender, RoutedEventArgs^ e)
{
	if (LeftBracketCreated == false)
		Calculator::Append('(');
	else
		Calculator::Append(')');
	LeftBracketCreated = !LeftBracketCreated;
	UpdateCalculatorInput();
}
void MainPage::Button_Sq_Root_Click(Object^ sender, RoutedEventArgs^ e)
{
	if (Calculator::InputContainsNumbers())
	{
		Calculator::SquareRoot(Calculator::Input());
		UpdateCalculatorOutput();
	}
}
void MainPage::Button_Back_Click(Object^ sender, RoutedEventArgs^ e)
{
	String^ data = (this->CalculatorOutputTextBox->Text);
	Calculator::Back(data);
	UpdateCalculatorInput();
}
void MainPage::Button_Sqr_Click(Object^ sender, RoutedEventArgs^ e)
{
	if (Calculator::InputContainsNumbers())
	{
		Calculator::Square(Calculator::Input());
		UpdateCalculatorOutput();
	}
}
void MainPage::Button_Dot_Click(Object^ sender, RoutedEventArgs^ e)
{
	if (!Calculator::Empty())
	{
		if (Calculator::InputHasSpecialSymbols(false))
		{
			if (Calculator::Length() == 1)
				return;
			Calculator::ReplaceAt(Calculator::Length() - 1, '.');
		}
		else
			Calculator::Append('.');
	}
	else
		Calculator::Append("0.");
	UpdateCalculatorInput();
}
void MainPage::Button_Mod_Click(Object^ sender, RoutedEventArgs^ e)
{
	if (!Calculator::Empty())
	{
		if (Calculator::InputHasSpecialSymbols(false))
		{
			if (Calculator::Length() == 1)
				return;
			Calculator::ReplaceAt(Calculator::Length() - 1, '%');
		}
		else
			Calculator::Append('%');
	}
	UpdateCalculatorInput();
}
void MainPage::Button_ln_Click(Object^ sender, RoutedEventArgs^ e)
{
	if (Calculator::InputContainsNumbers())
	{
		Calculator::Log(Calculator::Input());
		UpdateCalculatorOutput();
	}
}
void MainPage::Button_Inverse_Click(Object^ sender, RoutedEventArgs^ e)
{
	if (Calculator::InputContainsNumbers())
	{
		Calculator::Inverse(Calculator::Input());
		UpdateCalculatorOutput();
	}
}
void Calculator_UWP::MainPage::ButtonClearHistory_Click(
	Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	History::ClearHistory();
	this->History_Block->Text =
		Functions::ConvertToString(History::UpdateHistory());
}
void MainPage::Button_powerOf_Click(Platform::Object^ sender,
	Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (Calculator::InputContainsNumbers())
	{
		if (!Calculator::InputHasSpecialSymbols(false))
		{
			Exponent::Initialize(Calculator::Input());
			Calculator::Clear();
			this->CalculatorOutputTextBox->PlaceholderText = "Enter needed power: ";
			UpdateCalculatorInput();
		}
	}
}
