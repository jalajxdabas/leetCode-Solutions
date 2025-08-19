# Write your MySQL query statement below
  
SELECT 
    a1.machine_id,
    ROUND(AVG(A2.timestamp - A1.timestamp),3) AS processing_time 
FROM Activity a1
JOIN Activity a2
    ON  A1.machine_id = a2.machine_id
    AND A1.process_id = A2.process_id
    AND A1.activity_type = 'start'
    AND A2.activity_type = 'end'
Group by a1.machine_id;