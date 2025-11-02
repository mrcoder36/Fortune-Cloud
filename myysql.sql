CREATE TABLE student(
    sid INT primary key auto_increment,
    email VARCHAR(255) not null unique,
    bio TEXT,
    country VARCHAR(2)
);