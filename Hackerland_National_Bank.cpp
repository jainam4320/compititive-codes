
// HackerLand National Bank has a simple policy for warning clients about possible fraudulent account activity. If the amount spent by a client on a particular day is greater than or equal to  the client's median spending for a trailing number of days, they send the client a notification about potential fraud. The bank doesn't send the client any notifications until they have at least that trailing number of prior days' transaction data.

// Given the number of trailing days  and a client's total daily expenditures for a period of  days, find and print the number of times the client will receive a notification over all  days.

// For example,  and . On the first three days, they just collect spending data. At day , we have trailing expenditures of . The median is  and the day's expenditure is . Because , there will be a notice. The next day, our trailing expenditures are  and the expenditures are . This is less than  so no notice will be sent. Over the period, there was one notice sent.

// Note: The median of a list of numbers can be found by arranging all the numbers from smallest to greatest. If there is an odd number of numbers, the middle one is picked. If there is an even number of numbers, median is then defined to be the average of the two middle values. (Wikipedia)

// Function Description

// Complete the function activityNotifications in the editor below. It must return an integer representing the number of client notifications.

// activityNotifications has the following parameter(s):

// expenditure: an array of integers representing daily expenditures
// d: an integer, the lookback days for median spending
// Input Format

// The first line contains two space-separated integers  and , the number of days of transaction data, and the number of trailing days' data used to calculate median spending.
// The second line contains  space-separated non-negative integers where each integer  denotes .

// Constraints

// Output Format

// Print an integer denoting the total number of times the client receives a notification over a period of  days.

// Sample Input 0

// 9 5
// 2 3 4 2 3 6 8 4 5
// Sample Output 0

// 2
// Explanation 0

// We must determine the total number of  the client receives over a period of  days. For the first five days, the customer receives no notifications because the bank has insufficient transaction data: .

// On the sixth day, the bank has  days of prior transaction data, , and  dollars. The client spends  dollars, which triggers a notification because : .

// On the seventh day, the bank has  days of prior transaction data, , and  dollars. The client spends  dollars, which triggers a notification because : .

// On the eighth day, the bank has  days of prior transaction data, , and  dollars. The client spends  dollars, which does not trigger a notification because : .

// On the ninth day, the bank has  days of prior transaction data, , and a transaction median of  dollars. The client spends  dollars, which does not trigger a notification because : .

// Sample Input 1

// 5 4
// 1 2 3 4 4
// Sample Output 1

// 0
// There are  days of data required so the first day a notice might go out is day . Our trailing expenditures are  with a median of  The client spends  which is less than  so no notification is sent.



// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cassert>
using namespace std;
#define SZ(x) ((int)(x.size()))
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)


typedef long long ll;
const int INF = 1e9;

const int N = 2e5;
const int V = 200;

int a[N];

int cnt[V+1];

int main()
{
    ios_base::sync_with_stdio(0);
    int n, d;
    cin >> n >> d;
    assert(n >= 1 && n <= N);
    assert(d >= 1 && d <= n);
    FOR(i, n) cin >> a[i];
    FOR(i, n) assert(a[i] >= 0 && a[i] <= V);
    int res = 0;

    FOR(i, d) cnt[a[i]]++;
    REP(i, d, n-1)
    {
        //SOLVE HERE
        int acc = 0;
        int low_median = -1, high_median = -1;
        REP(v, 0, V)
        {
            acc += cnt[v];
            if(low_median == -1 && acc >= int(floor((d+1)/2.0)))
            {
                low_median = v;
            }
            if(high_median == -1 && acc >= int(ceil((d+1)/2.0)))
            {
                high_median = v;
            }
        }
        assert(acc == d);
        int double_median = low_median + high_median;
        //cout << low_median << " " << high_median << " -> " << median << endl;
        if(a[i] >= double_median)
        {
            res++;
        }
        cnt[a[i-d]]--;
        cnt[a[i]]++;
    }
    cout << res << endl;
    return 0;
}