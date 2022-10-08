#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        int latestYear = 10000;
        int latestMonth = 13;
        int latestDay = 32;
        int ways = 0;
        string s = "";
        string temp;
        for (int i = 0; i < 3; ++i)
        {
            cin >> temp;
            s += temp;
        }
        sort(s.begin(), s.end());
        // cout<<s<<"\n";
        while (next_permutation(s.begin(), s.end()))
        {
            int year = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 + (s[3] - '0');
            if (year >= 2000)
            {
                int month = (s[4] - '0') * 10 + (s[5] - '0');
                if (month <= 12 && month >= 1)
                {

                    int day = (s[6] - '0') * 10 + (s[7] - '0');
                    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                    {
                        if (day <= 31 && day >= 1)
                        {
                            ways++;
                            if (year < latestYear)
                            {
                                latestYear = year;
                                latestMonth = month;
                                latestDay = day;
                            }
                            else if (year == latestYear)
                            {
                                if (month < latestMonth)
                                {
                                    latestYear = year;
                                    latestMonth = month;
                                    latestDay = day;
                                }
                                else if (month == latestMonth)
                                {
                                    if (day < latestDay)
                                    {
                                        latestYear = year;
                                        latestMonth = month;
                                        latestDay = day;
                                    }
                                }
                            }
                        }
                    }
                    else if (month == 4 || month == 6 || month == 9 || month == 11)
                    {
                        if (day <= 30 && day >= 1)
                        {
                            ways++;
                            if (year < latestYear)
                            {
                                latestYear = year;
                                latestMonth = month;
                                latestDay = day;
                            }
                            else if (year == latestYear)
                            {
                                if (month < latestMonth)
                                {
                                    latestYear = year;
                                    latestMonth = month;
                                    latestDay = day;
                                }
                                else if (month == latestMonth)
                                {
                                    if (day < latestDay)
                                    {
                                        latestYear = year;
                                        latestMonth = month;
                                        latestDay = day;
                                    }
                                }
                            }
                        }
                    }
                    else if (month == 2)
                    {
                        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                        {
                            if (day <= 29 && day >= 1)
                            {
                                ways++;
                                if (year < latestYear)
                                {
                                    latestYear = year;
                                    latestMonth = month;
                                    latestDay = day;
                                }
                                else if (year == latestYear)
                                {
                                    if (month < latestMonth)
                                    {
                                        latestYear = year;
                                        latestMonth = month;
                                        latestDay = day;
                                    }
                                    else if (month == latestMonth)
                                    {
                                        if (day < latestDay)
                                        {
                                            latestYear = year;
                                            latestMonth = month;
                                            latestDay = day;
                                        }
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (day <= 28 && day >= 1)
                            {
                                ways++;
                                if (year < latestYear)
                                {
                                    latestYear = year;
                                    latestMonth = month;
                                    latestDay = day;
                                }
                                else if (year == latestYear)
                                {
                                    if (month < latestMonth)
                                    {
                                        latestYear = year;
                                        latestMonth = month;
                                        latestDay = day;
                                    }
                                    else if (month == latestMonth)
                                    {
                                        if (day < latestDay)
                                        {
                                            latestYear = year;
                                            latestMonth = month;
                                            latestDay = day;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (ways == 0)
        {
            cout << ways << "\n";
            // cout<< numReverse<<"\n";
        }
        else
        {
            cout << ways << ' ';
            // cout<< numReverse<<"\n";
            if (latestDay < 10)
            {
                cout << '0' << latestDay << ' ';
            }
            else
            {
                cout << latestDay << ' ';
            }
            if (latestMonth < 10)
            {
                cout << '0' << latestMonth << ' ';
            }
            else
            {
                cout << latestMonth << ' ';
            }
            cout << latestYear << "\n";
        }
    }
    return 0;
}