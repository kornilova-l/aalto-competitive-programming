# Internet connection

The internet connection between Teemu and Taina has had problems lately. Before more investigation on the subject, Teemu decided to find out the theoretical maximum rate at which he can send data to Taina.

Can you help Teemu to calculate the maximum speed?

## Input

The first line of the input has two integers n and m: the number of computers and number of connections in the network. Computers are numbered 1,2,…,n. Computer numbered 1 is owned by Teemu and computer n is owned by Taina.

After the first line mm lines follow, each of which describe one connection between computers. The line has three integers a, b and c. This means that computer aa can send data to computer b at a rate of c byte/s.

## Output

Your program should print one integer: the maximum rate (byte/s) at which Teemu can send data to Taina.

Limits:
* 2 ≤ n ≤ 100
* 1 ≤ m ≤ 1000
* 1 ≤ a,b ≤ n
* 1 ≤ c ≤ 109

Example

Input:  
4 5  
1 2 2  
1 3 5  
2 4 3  
3 2 2  
3 4 1  

Output:  
4