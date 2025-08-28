# Write your MySQL query statement below
Select email 
FROM Person
Group By email
HAVING count(email) > 1;