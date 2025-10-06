select c.name
from Customers c
join Oders o on c.id = o.customerId
having count(c.id) == 0