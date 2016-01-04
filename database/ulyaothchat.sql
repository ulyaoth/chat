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

INSERT INTO members (memberid, username, password, first_name, last_name, email, birthdate, create_date) VALUES ("0", "admin", "e7ff9104bc83d09e1603bb0abcc030ae6b30cf80c7e4d81695db4b85383980bcc54d8de7f1dfbf5e0a018cf9b766f913a5d37cb1f7fae71ed443a97edb1e9202", "Admin", "Admin", "admin@admin.com", "01/01/2006", NOW());
