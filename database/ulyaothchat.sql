DROP DATABASE IF EXISTS ulyaothchat;
CREATE DATABASE IF NOT EXISTS ulyaothchat;
USE ulyaothchat;

DROP TABLE IF EXISTS members;

CREATE TABLE members (
    member_id      VARCHAR(255)    UNIQUE,
    username       VARCHAR(255)    UNIQUE,
    password       VARCHAR(255)    NOT NULL,
    first_name     VARCHAR(255)    NOT NULL,
    last_name      VARCHAR(255)    NOT NULL,
    email          VARCHAR(255)    UNIQUE,
    birthdate      DATE            NOT NULL,
    create_date    DATE            NOT NULL,
    PRIMARY KEY (member_id)
);