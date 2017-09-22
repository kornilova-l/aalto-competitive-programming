# 3SAT solver

SAT solvers find satisfying assignments to Boolean formulas. The formulas are given in the conjunctive normal form:
the formula is a conjunction of m clauses: c1 ∧ c2 ∧ …
each clause cj is a disjunction of literals: ℓ1 ∨ ℓ2 ∨ …
each literal ℓk is either a Boolean variable xi or is negation ¬xi.
Here ∧∧ is the "AND" operation, ∨∨ is the "OR" operation, and ¬ is the "NOT" operation. We will always assume that the variables are called x1,x2,…,xn.

For example, here is aa Boolean formula in the conjunctive normal form; we have m=3 clauses and n=3 variables:  
(x1 ∨ x2 ∨ x3) ∧ (¬x1 ∨ ¬x2 ∨ ¬x3) ∧ (¬x1 ∨ x2 ∨ x3).

This formula is satisfiable; we can find the following variable assignment that makes the formula true:  
x1=false, x2=true, x3=true.

Such formulas are commonly represented in the standard DIMACS format: the first line contains the magic words "p" ("problem") and "cnf" ("conjunctive normal form"), and then it is followed by the number of variables n and the number of clauses m. This is followed by m lines, each describing one clause. The line contains just one number per literal: a positive literal xi is written as i, and a negated literal ¬xi is written as −i. The clause is terminated with a 0.

For example, the above formula would be written as follows in the DIMACS format:

p cnf 3 3  
1 2 3 0  
-1 -2 -3 0  
-1 2 3 0  

Now we could take a commonly used SAT solver, for example "picosat", and ask it to solve this. We will get e.g. the following output:

s SATISFIABLE
v -1 2 3 0

Here the first line of output that starts with an "s" indicates that this formula was indeed satisfiable, and the second line of output that starts with a "v" gives the variable assingment. For each i=1,…,n, we write i if xi is true and −i if xi is false. Again, the list is terminated with a 0.

Your task here is to write a SAT solver that solves formulas in certain special cases.

## Input

The input is a Boolean formula in the conjunctive normal form, given in the DIMACS format.

We promise the following:
Each clause contains exactly 3 literals.
Each variable occurs at most 3 times in the entire formula (either negated or unengaged).
The same variable does not occur multiple times in a one clause.
The formula will be satisfiable; there will be a way to solve it.

## Output

Output a satisfying assignment in a format similar to the one used in the "picosat" example above. There should be two lines of output: first one that says "s SATISFIABLE", and then one that starts with "v", then contains nn values that indicate the satisfying assignment, and finally a "0".

### Limits
Number of variables: 3 ≤ n ≤ 10^5  
Number of clause: 3 ≤ n ≤ 10^4

## Example

Input:  
p cnf 8 5  
4 -5 3 0  
-5 -2 -4 0  
8 -1 2 0  
-3 5 6 0  
2 1 8 0  

Output:  
s SATISFIABLE  
v -1 2 -3 -4 -5 6 -7 8 0

Note that all variables occur at most 3 times in the entire formula: e.g. variable x5 occurs 3 times and x8 occurs 2 times.