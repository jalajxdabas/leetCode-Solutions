# Write your MySQL query statement be
select p.product_name, SUM(o.unit) as unit
from orders o
left join products p
on o.product_id = p.product_id
where o.order_date >= '2020-02-01' AND o.order_date < '2020-03-01'
group by o.product_id
having SUM(o.unit) >= 100;
