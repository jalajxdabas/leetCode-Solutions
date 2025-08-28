# Write your MySQL query statement below
SELECT user_id, 
concat(upper(left(name, 1)), lower(substr(name, 2))) as name
FROM Users
ORDER BY user_id;
