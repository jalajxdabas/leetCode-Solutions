# Write your MySQL query statement below
SELECT P.firstname, P.lastname, A.city, A.state
from Person p LEFT JOIN
address a
on p.personId = a.personId;