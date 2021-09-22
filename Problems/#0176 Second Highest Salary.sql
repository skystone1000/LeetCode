/*
#0176. Second Highest Salary
https://leetcode.com/problems/second-highest-salary/

*/

# Write your MySQL query statement below

SELECT MAX(Salary) AS SecondHighestSalary 
FROM Employee
WHERE Salary <> (
    SELECT MAX(Salary)
    FROM Employee
);