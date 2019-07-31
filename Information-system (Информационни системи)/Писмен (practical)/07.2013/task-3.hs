-- За списък от цели числа [x1,x2,…,xn] едноместна функция f казваме, че "запазва" елемент, ако f(x) също принадлежи на списъка. 
-- която за функция (f) и списък от цели числа (l) връща дали функцията "запазва" елементите на l;
-- която за списък от цели числа l и списък от функции lf проверява дали всяка функция запазва всички елементи на списъка;
-- preservedby l lf = -- която за списък от цели ч исла l и списък от функции lf връща списък с функциите, които запазват всички елементи на списъка;

-- Solution:

preserved :: (Integer -> Integer) -> [Integer] -> Bool
preserved f l = and [ (f x) `elem` l | x <- l]

preserve :: [Integer] -> [(Integer -> Integer)] -> Bool
preserve l lf = and [ preserved f l | f <- lf]

preservedby :: [Integer] -> [(Integer -> Integer)] -> [(Integer -> Integer)]
preservedby l lf = [ f | f <- lf, preserved f l]

result x = head (preservedby [1,2,3] [\x -> x, \x -> x]) x

main = do

    print (preserved (\x -> x) [1, 2, 3])
    print (preserve [1,2,3] [\x -> x, \x -> x])
    print (result 5)
