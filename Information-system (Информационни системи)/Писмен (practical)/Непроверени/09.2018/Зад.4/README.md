# Задача 4 (септември 2018)

Да се напише заявка, която извежда име на клас, годината на първата битка, в която кораб на този клас е участвал, годината на последната битка, в която кораб на този клас е участвал, и броя на всички различни битки, в които кораби на този клас са участвали, само за тези класове, започващи с буквата N. Ако за даден клас няма кораб, който да е участвал в битка, за съответните години да се върне стойност null.

```sql
SELECT CLS.CLASS, MIN(BTL.DATE) AS FIRST_BATTLE, MAX(BTL.DATE) AS LAST_BATTLE, COUNT(BTL.NAME)
FROM CLASSES CLS, SHIPS SH, BATTLES BTL, OUTCOMES OUTC
WHERE SH.NAME = OUTC.SHIP AND BTL.NAME = OUTC.BATTLE AND CLS.CLASS = SH.CLASS
AND CLS.CLASS LIKE "N%"
GROUP BY CLS.CLASS;
```
