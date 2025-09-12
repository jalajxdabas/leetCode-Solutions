# Write your MySQL query statement below
SELECT *, 
if(x+y > z AND y + z > x && x + z > y, "Yes", "No") as triangle 
FROM triangle;
