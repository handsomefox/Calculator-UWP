//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace Calculator_UWP;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

std::string input;
double result = 0.0;
bool leftBracketCreated = false;

Platform::String^ convertFromString(const std::string& input) {
    std::wstring w_str = std::wstring(input.begin(), input.end());
    const wchar_t* w_chars = w_str.c_str();
    return (ref new Platform::String(w_chars, (unsigned int)w_str.length()));
}

bool CheckForSpecialSymbols(std::string& input)
{
	 size_t length = input.length() - 1;
     if (input[length] == '*' || input[length] == '/' || input[length] == '+' || input[length] == '-' || input[length] == '%')
         return true;
     else return false;
}
bool CheckForSpecialSymbols(std::string& input, bool checkForBrackets)
{
    size_t length = input.length() - 1;
    if (input[length] != '*' || input[length] != '/' || input[length] != '+' || input[length] != '-' || input[length] != '(' || input[length] != ')' || input[length] == '%')
        return true;
    else return false;
}
struct Exponentiation {
private:
    double m_input = 0.0; bool m_calculatingPower = false;
    void Reset() {
        m_input = 0;
        m_calculatingPower = false;
        input.clear();
    }
public:
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
} s_powerOf;

MainPage::MainPage() { InitializeComponent(); }

void Calculator_UWP::MainPage::UpdateCalculatorOutput()
{
    this->CalculatorOutputTextBox->Text = convertFromString(input);
}

double CalculateExpression()
{
    return te_interp(input.c_str(), 0);
}

void Calculator_UWP::MainPage::RemoveTrailingZeroesAndUpdate(double result)
{
    double i, f;
    f = modf(result, &i);
    if (f == 0.0)
        input = std::to_string((int64)i);
    else {
        input = std::to_string(result);
        input.erase(input.find_last_not_of('0') + 1, std::string::npos);
    }
    UpdateCalculatorOutput();
}
void Calculator_UWP::MainPage::ButtonClear_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    this->CalculatorOutputTextBox->Text = "";
    this->CalculatorOutputTextBox->PlaceholderText = "0";
    leftBracketCreated = false;
    input.clear();
}
void Calculator_UWP::MainPage::Button1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    input += "1";
    UpdateCalculatorOutput();
}
void Calculator_UWP::MainPage::Button2_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    input += "2";
    UpdateCalculatorOutput();
}
void Calculator_UWP::MainPage::Button3_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    input += "3";
    UpdateCalculatorOutput();
}
void Calculator_UWP::MainPage::Button4_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    input += "4";
    UpdateCalculatorOutput();
}
void Calculator_UWP::MainPage::Button5_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    input += "5";
    UpdateCalculatorOutput();
}
void Calculator_UWP::MainPage::Button6_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    input += "6";
    UpdateCalculatorOutput();
}
void Calculator_UWP::MainPage::Button7_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    input += "7";
    UpdateCalculatorOutput();
}
void Calculator_UWP::MainPage::Button8_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    input += "8";
    UpdateCalculatorOutput();
}
void Calculator_UWP::MainPage::Button9_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    input += "9";
    UpdateCalculatorOutput();
}
void Calculator_UWP::MainPage::Button0_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    input += "0";
    UpdateCalculatorOutput();
}
void Calculator_UWP::MainPage::Button_Addition_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    if (input.length() > 0) {
        if (CheckForSpecialSymbols(input))
            input[input.length() - 1] = '+';
        else input += '+';
    }
    UpdateCalculatorOutput();
}
void Calculator_UWP::MainPage::Button_Subtraction_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    if (input.length() > 0) {
       if (CheckForSpecialSymbols(input))
            input[input.length() - 1] = '-';
        else input += '-';  
    }
    else input += '-';
    UpdateCalculatorOutput();
}
void Calculator_UWP::MainPage::Button_Division_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    if (input.length() > 0) {
        if (CheckForSpecialSymbols(input))
            input[input.length() - 1] = '/';
        else input += '/';
    }
    UpdateCalculatorOutput();
}
void Calculator_UWP::MainPage::Button_Multiplication_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    if (input.length() > 0) {
        if (CheckForSpecialSymbols(input))
            input[input.length() - 1] = '*';
        else input += '*';
    }
    UpdateCalculatorOutput();
}
void Calculator_UWP::MainPage::Button_Equals_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    double result = 0.0;
    if (s_powerOf.GetPowerState() == true) {
        result = s_powerOf.Calculate(CalculateExpression());
        this->CalculatorOutputTextBox->PlaceholderText = "0";
    }
    else result = CalculateExpression();
    RemoveTrailingZeroesAndUpdate(result);
}
void Calculator_UWP::MainPage::Button_Bracket_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    if (leftBracketCreated == false) input += "(";
    else input += ")";
    leftBracketCreated = !leftBracketCreated;
    UpdateCalculatorOutput();
}
void Calculator_UWP::MainPage::Button_Sq_Root_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    if (input.length() > 0) {
        double result = sqrt(CalculateExpression());
        RemoveTrailingZeroesAndUpdate(result);
    }
}
void Calculator_UWP::MainPage::Button_Back_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    if (input.length() > 0) input.pop_back();
    UpdateCalculatorOutput();
}
void Calculator_UWP::MainPage::Button_Sqr_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    if (input.length() > 0) {
        double result = (CalculateExpression() * CalculateExpression());
        RemoveTrailingZeroesAndUpdate(result);
    }
}
void Calculator_UWP::MainPage::Button_Dot_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    if (input.length() > 0) {
        if (CheckForSpecialSymbols(input, 1)){
            input += ".";
        }
    }
    else input += "0.";
    UpdateCalculatorOutput();
}

void Calculator_UWP::MainPage::Button_Mod_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    if (input.length() > 0) {
        if (CheckForSpecialSymbols(input))
            input[input.length() - 1] = '%';
        else input += '%';
    }
    UpdateCalculatorOutput();
}
void Calculator_UWP::MainPage::Button_ln_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    if (input.length() > 0) {
        double result = (log(CalculateExpression()));
        RemoveTrailingZeroesAndUpdate(result);
    }
}
void Calculator_UWP::MainPage::Button_powerOf_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    if (input.length() > 0) {
        if (CheckForSpecialSymbols(input, 1)) {
            double value_to_calculate = (CalculateExpression());
            s_powerOf.Initialize(value_to_calculate);
            input.clear();
            this->CalculatorOutputTextBox->PlaceholderText = "Enter needed power: ";
            UpdateCalculatorOutput();
        }
    }
}
void Calculator_UWP::MainPage::Button_Inverse_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    if (input.length() > 0) {
        double result = 1 / (CalculateExpression());
        RemoveTrailingZeroesAndUpdate(result);
    }
}
