# Write your MySQL query statement below

# # select name as  Employee from Employee  e1 where salary >

# # (select salary from Employee  e2 where e1.managerId=e2.id );

# select name as Employee from employee e1 where e1.salary > 
# (select salary from employee e2 where e1.managerId=e2.id);


select name as Employee from employee e1
where e1.salary > (select salary from employee e2 where e2.id=e1.managerid);