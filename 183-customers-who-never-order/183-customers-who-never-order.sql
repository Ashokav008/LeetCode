select a.name as Customers from customers a  
left join  orders b
on a.id=b.customerId 
where b.customerid is null;