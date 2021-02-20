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
// The Blank Page item template is documented at
// https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409
Platform::String^ convertFromString(const std::string& input) {
    std::wstring w_str = std::wstring(input.begin(), input.end());
    const wchar_t* w_chars = w_str.c_str();

    return (ref new Platform::String(w_chars, (unsigned int)w_str.length()));
} struct PowerOf {
private:
    double m_input = 0.0;
    void Reset() {
        m_input = 0;
        m_calculatingPower = false;
    }

public:
    bool m_calculatingPower = false;
    void Initialize(double input) {
        m_input = input;
        m_calculatingPower = true;
    }
    double Calculate(double power) {
        double result = pow(m_input, power);
        Reset();
        return result;
    };
} s_powerOf;
std::string input;
std::string x;
std::string y;
char operation;
double result = 0.0;
bool leftBracketCreated = false;
MainPage::MainPage() { InitializeComponent(); }
void Calculator_UWP::MainPage::ButtonClear_Click(
    Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    this->calcOutput->Text = "";
    this->calcOutput->PlaceholderText = "0";
    leftBracketCreated = false;
    input = "";
}
void Calculator_UWP::MainPage::Button1_Click(
    Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    input += "1";
    this->calcOutput->Text = convertFromString(input);
}
void Calculator_UWP::MainPage::Button2_Click(
    Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    input += "2";
    this->calcOutput->Text = convertFromString(input);
}
void Calculator_UWP::MainPage::Button3_Click(
    Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    input += "3";
    this->calcOutput->Text = convertFromString(input);
}
void Calculator_UWP::MainPage::Button4_Click(
    Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    input += "4";
    this->calcOutput->Text = convertFromString(input);
}
void Calculator_UWP::MainPage::Button5_Click(
    Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    input += "5";
    this->calcOutput->Text = convertFromString(input);
}
void Calculator_UWP::MainPage::Button6_Click(
    Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    input += "6";
    this->calcOutput->Text = convertFromString(input);
}
void Calculator_UWP::MainPage::Button7_Click(
    Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    input += "7";
    this->calcOutput->Text = convertFromString(input);
}
void Calculator_UWP::MainPage::Button8_Click(
    Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    input += "8";
    this->calcOutput->Text = convertFromString(input);
}
void Calculator_UWP::MainPage::Button9_Click(
    Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    input += "9";
    this->calcOutput->Text = convertFromString(input);
}
void Calculator_UWP::MainPage::Button0_Click(
    Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    input += "0";
    this->calcOutput->Text = convertFromString(input);
}
void Calculator_UWP::MainPage::Button_Addition_Click(
    Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    if (input.length() > 0) {
        size_t length = input.length() - 1;
        if (input[length] == '*' || input[length] == '/' || input[length] == '+' ||
            input[length] == '-' || input[length] == '%' || input[length] == '!') {
            input[length] = '+';
            this->calcOutput->Text = convertFromString(input);
        }
        else {
            input += '+';
        }
    }
    this->calcOutput->Text = convertFromString(input);
}
void Calculator_UWP::MainPage::Button_Subtraction_Click(
    Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    if (input.length() > 0) {
        size_t length = input.length() - 1;
        if (input[length] == '*' || input[length] == '/' || input[length] == '+' ||
            input[length] == '-' || input[length] == '%' || input[length] == '!') {
            input[length] = '-';
            this->calcOutput->Text = convertFromString(input);
        }
        else {
            input += '-';
        }
    }
    else
        input += '-';
    this->calcOutput->Text = convertFromString(input);
}
void Calculator_UWP::MainPage::Button_Division_Click(
    Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    if (input.length() > 0) {
        size_t length = input.length() - 1;
        if (input[length] == '*' || input[length] == '/' || input[length] == '+' ||
            input[length] == '-' || input[length] == '%' || input[length] == '!') {
            input[length] = '/';
            this->calcOutput->Text = convertFromString(input);
        }
        else {
            input += '/';
        }
    }
    this->calcOutput->Text = convertFromString(input);
}
void Calculator_UWP::MainPage::Button_Multiplication_Click(
    Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    if (input.length() > 0) {
        size_t length = input.length() - 1;
        if (input[length] == '*' || input[length] == '/' || input[length] == '+' ||
            input[length] == '-' || input[length] == '%' || input[length] == '!') {
            input[length] = '*';
            this->calcOutput->Text = convertFromString(input);
        }
        else {
            input += '*';
        }
    }
    this->calcOutput->Text = convertFromString(input);
}
void Calculator_UWP::MainPage::Button_Equals_Click(
    Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    double result = 0.0;
    std::string answer;
    double i, f;
    if (s_powerOf.m_calculatingPower == true) {
        result = s_powerOf.Calculate(te_interp(input.c_str(), 0));
        this->calcOutput->PlaceholderText = "0";
    }
    else {
        result = te_interp(input.c_str(), 0);
    }
    f = modf(result, &i);
    if (f == 0.0) {
        answer = std::to_string((int64)i);
        this->calcOutput->Text = convertFromString(answer);
    }
    else {
        answer = std::to_string(result);
        answer.erase(answer.find_last_not_of('0') + 1, std::string::npos);
        this->calcOutput->Text = convertFromString(answer);
    }
}
void Calculator_UWP::MainPage::Button_Bracket_Click(
    Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    if (leftBracketCreated == false) {
        input += "(";
    }
    else {
        input += ")";
    }
    leftBracketCreated = !leftBracketCreated;
    this->calcOutput->Text = convertFromString(input);
}
void Calculator_UWP::MainPage::Button_Sq_Root_Click(
    Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    double calculate = te_interp(input.c_str(), 0);
    if (input.length() > 0) {
        double result = sqrt(calculate);
        double i, f;
        f = modf(result, &i);
        if (f == 0.0) {
            input = std::to_string((int64)i);
            this->calcOutput->Text = convertFromString(input);
        }
        else {
            input = std::to_string(result);
            input.erase(input.find_last_not_of('0') + 1, std::string::npos);
            this->calcOutput->Text = convertFromString(input);
        }
    }
    this->calcOutput->Text = convertFromString(input);
}
void Calculator_UWP::MainPage::Button_Back_Click(
    Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    if (input.length() > 0)
        input.pop_back();
    this->calcOutput->Text = convertFromString(input);
}
void Calculator_UWP::MainPage::Button_Sqr_Click(
    Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    double calculate = te_interp(input.c_str(), 0);
    if (input.length() > 0) {
        double result = (calculate * calculate);
        double i, f;
        f = modf(result, &i);
        if (f == 0.0) {
            input = std::to_string((int64)i);
            this->calcOutput->Text = convertFromString(input);
        }
        else {
            input = std::to_string(result);
            input.erase(input.find_last_not_of('0') + 1, std::string::npos);
            this->calcOutput->Text = convertFromString(input);
        }
    }
    this->calcOutput->Text = convertFromString(input);
}
void Calculator_UWP::MainPage::Button_Dot_Click(
    Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    if (input.length() > 0) {
        size_t length = input.length() - 1;
        if (input[length] != '*' || input[length] != '/' || input[length] != '+' ||
            input[length] != '-' || input[length] != '(' || input[length] != ')' ||
            input[length] == '%' || input[length] == '!') {
            input += ".";
        }
    }
    else {
        input += "0.";
    }
    this->calcOutput->Text = convertFromString(input);
}

void Calculator_UWP::MainPage::Button_Mod_Click(
    Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    if (input.length() > 0) {
        size_t length = input.length() - 1;
        if (input[length] == '*' || input[length] == '/' || input[length] == '+' ||
            input[length] == '-' || input[length] == '%' || input[length] == '!') {
            input[length] = '%';
            this->calcOutput->Text = convertFromString(input);
        }
        else {
            input += '%';
        }
    }
    this->calcOutput->Text = convertFromString(input);
}
void Calculator_UWP::MainPage::Button_ln_Click(
    Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {

    double calculate = te_interp(input.c_str(), 0);
    if (input.length() > 0) {
        double result = (log(calculate));
        double i, f;
        f = modf(result, &i);
        if (f == 0.0) {
            input = std::to_string((int64)i);
            this->calcOutput->Text = convertFromString(input);
        }
        else {
            input = std::to_string(result);
            input.erase(input.find_last_not_of('0') + 1, std::string::npos);
            this->calcOutput->Text = convertFromString(input);
        }
    }
    this->calcOutput->Text = convertFromString(input);
}
void Calculator_UWP::MainPage::Button_powerOf_Click(
    Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    if (input.length() > 0) {
        size_t length = input.length() - 1;
        if (input[length] != '*' || input[length] != '/' || input[length] != '+' ||
            input[length] != '-' || input[length] != '(' || input[length] != ')' ||
            input[length] == '%' || input[length] == '!') {
            double val = (te_interp(input.c_str(), 0));
            s_powerOf.Initialize(val);
            input = "";
            this->calcOutput->PlaceholderText = "Enter needed power: ";
            this->calcOutput->Text = convertFromString(input);
        }
    }
}
void Calculator_UWP::MainPage::Button_Inverse_Click(
    Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    if (input.length() > 0) {
        double result = 1 / (te_interp(input.c_str(), 0));
        ;
        double i, f;
        f = modf(result, &i);
        if (f == 0.0) {
            input = std::to_string((int64)i);
            this->calcOutput->Text = convertFromString(input);
        }
        else {
            input = std::to_string(result);
            input.erase(input.find_last_not_of('0') + 1, std::string::npos);
            this->calcOutput->Text = convertFromString(input);
        }
    }
    this->calcOutput->Text = convertFromString(input);
}
