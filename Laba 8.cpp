#include <iostream>
#include <string>
#include <algorithm>

bool isArmstrong(int32_t num, std::string str) {
    int32_t sum = 0;

    for (int i = 0; i < str.size(); i++) {
        sum += pow(str[i] - '0', str.size());
    }

    if (sum == num) return true;
    else return false;
}

std::string solve(std::string sep, std::string str) {
    int32_t num = 0, flag = 0;
    std::string ans, word;

    for (int i = 0; i < str.size(); i++) {
        if (std::find(sep.begin(), sep.end(), str[i]) != sep.end() || i == str.size() - 1) {
            if (i == str.size() - 1 && std::find(sep.begin(), sep.end(), str[i]) == sep.end()) {
                word += str[i];
                num *= 10;
                num += str[i] - '0';
                if (isalpha(str[i])) {
                    flag = 1;
                }
            }
            if (flag == 0 && isArmstrong(num, word)) {
                ans += word + " ";
            }
            flag = 0;
            num = 0;
            word.clear();
        }
        else {
            word += str[i];
            num *= 10;
            num += str[i] - '0';
            if (isalpha(str[i])) {
                flag = 1;
            }
        }
    }

    return ans;
}

int main()
{
    setlocale(LC_ALL, "");
    std::string sep, str;
    std::cout << "Введите строку с разделителями: ";
    getline(std::cin, sep);
    std::cout << "Введите строку со словами: ";
    getline(std::cin, str);

    std::cout << solve(sep, str) << "\n";
}
