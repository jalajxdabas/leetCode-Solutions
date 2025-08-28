# Write your MySQL query statement below
SELECT MAX(num) as num
FROM (
    SELECT num FROM myNumbers
    GROUP BY num
    HAVING count(num) = 1
) AS ANS