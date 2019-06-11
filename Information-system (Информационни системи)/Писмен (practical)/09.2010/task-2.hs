-- Задача 2: Да се дефинира функция на Haskell sumProd, която по даден списък от списъци от цели числа ll 
-- да намира сумата от произведенията на елементите на тези списъци в ll, които не съдържат отрицателни числа.

-- Solution:

allPositive :: [Integer] -> Bool
allPositive xs = and[ False | x <- xs, x <= 0 ]

sumProd :: [[Integer]] -> Integer
sumProd [] = 0
sumProd [[]] = 0
sumProd ll = sum[product l| l <- ll, allPositive l]

main = do

    print (allPositive [1, 2, 3])
    print (allPositive [0, 2, 4])
    print (allPositive [4, 2, 6])
    print (allPositive [2, (-2), 4])
    print (sumProd [[1, 2, 3], [0, 2, 4], [4, 2, 6], [2, (-2), 4]])
    print (sumProd [[1, 2, 3]])
    print (sumProd [[2, (-2), 4]])
    print (sumProd [])
    print (sumProd [[]])
