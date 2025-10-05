select e.name
from Employee e
left join Employee em on em.id = e.managerId
where e.salary > em.salary