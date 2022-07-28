CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN 
    declare M INT;
    set M=n-1;
  RETURN (
    # select (salary)  from employee order by salary desc limit M,1
      select distinct(e1.salary) from employee e1 where 
      n-1= (select count(distinct salary) from employee e2 where e2.salary > e1.salary)
     
      
      
  );
END