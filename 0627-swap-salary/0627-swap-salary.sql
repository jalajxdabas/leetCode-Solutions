# Write your MySQL query statement below
update salary set sex = 
CASE
    WHEN sex = 'm' then 'f'
    ELSE 'm'
    END;