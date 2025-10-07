select w2.id
from Weather w1
join Weather w2 on w2.recorddate - w1.recorddate = 1 and w2.temperature > w1.temperature;