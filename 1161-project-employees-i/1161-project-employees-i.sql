# Write your MySQL query statement below
SELECT p.project_id, ROUND(AVG(e.experience_years), 2) as average_years
FROM project p
LEFT JOIN employee e
on p.employee_id = e.employee_id
group by project_id;