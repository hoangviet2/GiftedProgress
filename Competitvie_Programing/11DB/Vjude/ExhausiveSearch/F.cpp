#include <bits/stdc++.h>

using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int testcase;
    cin >> testcase;
    while(testcase--)
    {
        int latestYear = 10000, m0 = 13, d0 = 32;
        char s[15];
        cin>>s>>s+2>>s+4;
        sort(s, s+8);
        cout<<"This is s: "<<s<<"\n";
        int num = 0;
        int numReverse = 0;
        while(next_permutation(s, s+8))
        {
            ++numReverse;
            int yy = (s[0]-'0')*1000+(s[1]-'0')*100+(s[2]-'0')*10+(s[3]-'0');
            if(yy>=2000)
            {
                int mm = (s[4]-'0')*10+(s[5]-'0');
                if(mm<=12&&mm>=1)
                {
                    int dd = (s[6]-'0')*10+(s[7]-'0');
                    if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)
                    {
                        if(dd<=31&&dd>=1)
                        {
                            num++;
                            if(yy<latestYear)
                            {
                                latestYear = yy;
                                m0 = mm;
                                d0 = dd;
                            }
                            else if(yy==latestYear)
                            {
                                if(mm<m0)
                                {
                                    latestYear = yy;
                                    m0 = mm;
                                    d0 = dd;
                                }
                                else if(mm == m0)
                                {
                                    if(dd<d0)
                                    {
                                        latestYear = yy;
                                        m0 = mm;
                                        d0 = dd;
                                    }
                                }
                            }
                        }
                    }
                    else if(mm==4||mm==6||mm==9||mm==11)
                    {
                        if(dd<=30&&dd>=1)
                        {
                            num++;
                            if(yy<latestYear)
                            {
                                latestYear = yy;
                                m0 = mm;
                                d0 = dd;
                            }
                            else if(yy==latestYear)
                            {
                                if(mm<m0)
                                {
                                    latestYear = yy;
                                    m0 = mm;
                                    d0 = dd;
                                }
                                else if(mm == m0)
                                {
                                    if(dd<d0)
                                    {
                                        latestYear = yy;
                                        m0 = mm;
                                        d0 = dd;
                                    }
                                }
                            }
                        }
                    }
                    else if(mm == 2)
                    {
                        if((yy%4==0&&yy%100!=0)||yy%400==0)
                        {
                            if(dd<=29&&dd>=1)
                            {
                                num++;
                                if(yy<latestYear)
                                {
                                    latestYear = yy;
                                    m0 = mm;
                                    d0 = dd;
                                }
                                else if(yy==latestYear)
                                {
                                    if(mm<m0)
                                    {
                                        latestYear = yy;
                                        m0 = mm;
                                        d0 = dd;
                                    }
                                    else if(mm == m0)
                                    {
                                        if(dd<d0)
                                        {
                                            latestYear = yy;
                                            m0 = mm;
                                            d0 = dd;
                                        }
                                    }
                                }
                            }
                        }
                        else
                        {
                            if(dd<=28&&dd>=1)
                            {
                                num++;
                                if(yy<latestYear)
                                {
                                    latestYear = yy;
                                    m0 = mm;
                                    d0 = dd;
                                }
                                else if(yy==latestYear)
                                {
                                    if(mm<m0)
                                    {
                                        latestYear = yy;
                                        m0 = mm;
                                        d0 = dd;
                                    }
                                    else if(mm == m0)
                                    {
                                        if(dd<d0)
                                        {
                                            latestYear = yy;
                                            m0 = mm;
                                            d0 = dd;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(num==0){
            cout << num << "\n";
            cout<< numReverse<<"\n";
        }
        else
        {
            cout << num << '\n';
            cout<< numReverse<<"\n";
            if(d0<10){
                cout << '0' << d0 << ' ';
            }
            else{ 
                cout << d0 << ' ';
            }
            if(m0<10){
                cout << '0' << m0 << ' ';
            }
            else{
                cout << m0 << ' ';
            }
            cout << latestYear <<"\n";
        }
    }
    return 0;
}
