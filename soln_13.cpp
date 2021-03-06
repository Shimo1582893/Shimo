#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int num = 0;
		int temp;
		char rome;

		for (int i = 0; i < s.size(); ++i)
		{
			rome = s[i];
			temp = i + 1;
			switch(rome){
                case'M':
					num += 1000;
					break;

				case'D':
					num += 500;
					break;

				case'C':
					if (temp < s.size() && (s[temp] == 'D' || s[temp] == 'M'))
						num -= 100;
					else
						num += 100;
					break;

				case'L':
					num += 50;
					break;

				case'X':
					if (temp < s.size() && (s[temp] == 'L' || s[temp] == 'C'))
						num -= 10;
					else
						num += 10;
					break;

				case'V':
					num += 5;
					break;

				case'I':
					if (temp < s.size() && (s[temp] == 'V' || s[temp] == 'X'))
						num -= 1;
					else
						num += 1;
					break;
			}
		}
		return num;
	}
};

int main() {
	Solution soln;
	string str1 = "III";
	string str2 = "IV";
	string str3 = "IX";
	string str4 = "LVIII";
	string str5 = "MCMXCIV";
	try {
		cout << "Roman: " << str1 << endl << "Integer: " << soln.romanToInt(str1) << endl;
		cout << "Roman: " << str2 << endl << "Integer: " << soln.romanToInt(str2) << endl;
		cout << "Roman: " << str3 << endl << "Integer: " << soln.romanToInt(str3) << endl;
		cout << "Roman: " << str4 << endl << "Integer: " << soln.romanToInt(str4) << endl;
		cout << "Roman: " << str5 << endl << "Integer: " << soln.romanToInt(str5) << endl;
	}
	catch (...)
	{
		cout << "Exception is thrown";
	}
	return 0;
}