CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN 
    declare M INT;
    set M=n-1;
  RETURN (
    select distinct(salary)  from employee order by salary desc limit M,1
      
  );
END