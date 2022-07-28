# select distinct p1.email from person p1 
# inner join person p2
# on p1.email=p2.email where p1.id<>p2.id;

 select distinct p1.email from person p1 where email in (select email from person p2 where p1.email=p2.email and p1.id<> p2.id);