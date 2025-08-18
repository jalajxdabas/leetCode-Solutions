# Write your MySQL query statement below
SELECT EMPLOYEEUNI.unique_id, EMPLOYEES.name
FROM employees 
LEFT JOIN employeeUNI
ON employees.id = employeeUNI.id;