/*
написать функцию IsKPeriodic, которая проверяет, является ли строка кратной числу .
Кратность — повторяемость строки каждые  символов ( должно быть больше ). 
Например, abcabcabcabc имеет кратность  ,  так как она состоит из подстрок abc, имеющих длину .
*/
#include <iostream>
#include <string>
using namespace std;

void computeLPS(string pat, int* lps)
{
    int j = 0;

    lps[0] = 0; 

    int i = 1;
    while (i < pat.size()) {
        if (pat[i] == pat[j]) {
            j++;
            lps[i] = j;
            i++;
        }
        else
        {
            if (j != 0) {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
bool IsKPeriodic(const string& pat, const string& txt)
{
    int* lps = new int[pat.size()];

    computeLPS(pat, lps);

    int i = 0;
    int j = 0;
    int K = 0;

    while (i < txt.size()) {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == pat.size()) 
        {
            K += 1;   //прибавляем каждый раз когда находим вхождение
            j = lps[j - 1];
        }
        else if (i < txt.size() && pat[j] != txt[i]) {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i = i + 1;
            }
        }
    }
    if (K == 0)
        return false;
    else
        return true;

}
