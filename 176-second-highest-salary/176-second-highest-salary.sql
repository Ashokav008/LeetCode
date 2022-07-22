# Write your MySQL query statement below

# select salary  as SecondHighestSalary from employee  order by salary  desc limit 1,1;

select max(e2.salary) as SecondHighestSalary 
from employee e1, employee e2
where e1.salary >e2.salary;