-- Ensure database exists and select it
CREATE DATABASE IF NOT EXISTS Pune;
USE Pune;
-- @block
CREATE TABLE IF NOT EXISTS stud(
    id INT,
    Name VARCHAR(100),
    Address varchar(50)
);
-- @block
select *
from stud;
-- @block
INSERT INTO stud
VALUES(4, 'Vamika', 'UP');
-- Ensure a matching row for joins
INSERT INTO stud
VALUES(2, 'Aakash', 'Pune');
-- @block
CREATE TABLE IF NOT EXISTS Details(
    id INT,
    Contact VARCHAR(10),
    Pincode INT
);
-- @block
SELECT *
FROM details;
-- @block
INSERT INTO details
VALUES(2, 9834764589, 411050);
-- Ensure a matching row for joins
INSERT INTO details
VALUES(4, 9876500000, 110001);
-- @block
SELECT *
FROM stud
    LEFT JOIN details ON stud.id = Details.id;
-- @block
SELECT *
FROM stud
    RIGHT JOIN details ON stud.id = Details.id;
-- @block
SELECT *
FROM stud
    INNER JOIN details ON stud.id = Details.id;
-- @block
SELECT *
FROM stud
    LEFT JOIN details ON stud.id = details.id
UNION
SELECT *
FROM stud
    RIGHT JOIN details ON stud.id = details.id;
-- @block
SELECT *
FROM stud
    CROSS JOIN details;

-- @block   Use for joining three tables at once
SELECT * FROM tb1_name INNER JOIN tb2_name ON tb1_name.id = tb2_name.id INNER JOIN tb3_name ON tb2_name.id = tb3_name.id