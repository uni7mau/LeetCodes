select p.email
from Person p
where count(p.id) == 2