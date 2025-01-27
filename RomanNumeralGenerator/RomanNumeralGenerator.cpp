#include <string>
#include <map>
#include <stdio.h>
#include <iostream>

std::map<int, std::string> values = 
{
    {1,     "I"},
    {4,     "IV"},
    {5,     "V"},
    {9,     "IX"},
    {10,    "X"},
    {40,    "XL"},
    {50,    "L"},
    {90,    "XC"},
    {100,   "C"},
    {400,   "CD"},
    {500,   "D"},
    {900,   "CM"},
    {1000,  "M"}
};

class Converter
{
public:
    /// <summary>
    /// Converts an integer between 1 and 3999 to a Roman numeral.
    /// </summary>
    /// <param name="num">The integer value to be converted to a Roman numeral. Must be between 1 and 3999.</param>
    /// <returns>A string representing the Roman numeral equivalent of the input integer.</returns>
    static std::string intToRoman(int num)
    {
        std::string result = "";

        for (auto it = values.rbegin(); it != values.rend(); ++it)
        {
            int key = it->first;
            std::string val = it->second;

            while (num >= key)
            {
                num -= key;
                result.append(val);
            }
        }

        return result;
    }
};

int main()
{
    std::cout << Converter::intToRoman(2025) << std::endl;
    return 0;
}