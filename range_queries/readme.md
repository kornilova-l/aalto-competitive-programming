# Bank Account

Teemu has a bank account. On some days he deposits or withdraws money. Some days he doesn't do anything with the account

Now he wonders how much his balance has changed between the morning of day a and evening of day b

## Input
The first line contains a two integer, n and q, the number of days and the number of queries, respectively.

The second line contains n integers, x1, x2, …, xn. If xi > 0, Teemu deposited total of xi units of money on ith day. If xi < 0, Teemu withdrew total of |xi| units of money on ith day. If xi = 0, Teemu didn't touch the account on ith day.

Each next q lines contain two integers, aj and bj, the first and last days of query j.

## Output
Output q lines, one for each query. The jth line should contain a single integer, the amount of money that the balance has changed between the morning of day aj (i.e. before any deposits or withdrawals on that day) and the evening of the day bj (i.e. after all deposits and withdrawals on that day).

### Limits
The balance of the account is always non-negative, i.e. ≥ 0, and at most 10^6  
−100 ≤ xi ≤ 100  
1 ≤ n,q ≤ 10^4

## Example

Input:  
6 10  
10 -5 -5 100 50 -100  
1 6  
1 2  
5 6  
4 4  
4 6  
2 3  
1 3  
3 4  
3 6  
2 4

Output:  
50  
5  
-50  
100  
50  
-10  
0  
95  
45  
90
