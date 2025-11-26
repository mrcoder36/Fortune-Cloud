DELIMITER // CREATE FUNCTION enter_month(num int) RETURNS VARCHAR(100) BEGIN
DECLARE day_num VARCHAR(100);
CASE
    num
    WHEN 1 THEN day_num := 'Jan';
WHEN 2 THEN day_num := 'Feb';
WHEN 3 THEN day_num := 'Mar';
ELSE
SET day_num := 'Invalid input';
END CASE
;
RETURN day_num;
END // DELIMITER;