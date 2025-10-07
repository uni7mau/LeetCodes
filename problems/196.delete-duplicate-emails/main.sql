delete from Person p1 where p1.id in (
    select p2.id
    from Person p2
    join Person p3 on p2.email = p3.email and p2.id > p3.id
);

-- Khi join thì xóa các phần tử = email và id của nó nhỏ hơn id của phần tử hiện tại

-- a   a
-- b   b
-- a   a
-- a   a

-- -> 
-- a: 0 0 0 0
-- b: 0 0 0 0
-- a: a 0 0 0
-- a: a 0 a a

-- -> xóa 2 a cuối
