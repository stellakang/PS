# Write your MySQL query statement below

select Name As Customers
from Customers
where Customers.Id not in(
    select distinct CustomerId
    from Orders
)
    
