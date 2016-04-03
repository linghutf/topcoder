```SQL
/*
FUin(ID)     FName(车系)     FScore(评分)
12345           A             85
23456           B             80
12345           C             90
23456           D             75
23412           E             80
23432           F             85
*/
//查找同一用户投票一次以上的评价平均分
select FUin,avg(FScore) as AVER from t_score group by FUin having count(FUin)>1 order by AVER desc;
```
