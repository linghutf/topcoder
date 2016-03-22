1. 联合查询
select content from poetries left join poets on poetries.poet_id = poets.id where poets.name = '李白' (order by);

2. 授权
grant [select|insert] on (table name) to (role)
grant select,insert,delete on users.userinfo to 'xxc'@'localhost'
