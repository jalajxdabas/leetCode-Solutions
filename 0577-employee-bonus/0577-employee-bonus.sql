# Write your MySQL query statement below
SELECT E.name, B.bonus
FROM Employee E
LEFT JOIN Bonus B
ON e.empId = b.empId
WHERE b.bonus < 1000 OR b.bonus IS NULL;