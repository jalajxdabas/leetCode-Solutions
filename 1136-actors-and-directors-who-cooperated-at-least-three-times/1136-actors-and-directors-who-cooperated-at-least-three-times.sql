# Write your MySQL query statement below
SELECT actor_id, director_id
FROM actorDirector
group by actor_id, director_id
having count(timestamp) >= 3;