select email
from (select Email, count(Email) as num
      from Person
      group by Email) as a
where a.num != 1;