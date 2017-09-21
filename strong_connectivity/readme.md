# Road network

There are n intersections and m roads connecting them in the city. Your task is to check if it is possible to get from every intersection to every other intersection by roads.

## Input

On the first line of the input there is two integers n and m: the number of intersections and number of roads. Intersections are numbered 1,2,…,n.

Then m lines follow, each describing one road. Each line has two integers a and b. This means that there is a road connecting intersection a to intersection b. All roads are unidirectional.

## Output

Print YES if there exists a route from every intersection to every other intersection, or NO otherwise.

If the answer is NO, continue output by printing an example of intersections a and b such that there exists no route from aa to bb.

### Limits
1 ≤ n ≤ 10^5  
1 ≤ m ≤ 2⋅10^5  
1 ≤ a, b ≤ n  

### Example

Input:  
4 5  
1 2  
2 3  
3 1  
1 4  
3 4

Output:  
NO  
4 2