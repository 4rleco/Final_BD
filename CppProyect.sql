create database CppProyect;

use  CppProyect;

create table Users
(
	userId int auto_increment not null,
    userName varchar(15) not null,
    userPassword varchar(15) not null,
    primary key(userId)
);

create table People
(
    peopleName varchar(15) not null,
    peopleDNI varchar(8) not null,
    primary key(peopleDNI)
);

create table Games
(
	gameId int auto_increment not null,
    gameName varchar(15) not null,
    primary key(gameId)
);

create table Characters
(
	characterId int auto_increment not null,
    characterName varchar(15) not null,
    characterSkill varchar(15)not null,
    primary key(characterId)
);

create table Enterprises
(
	enterpriseId int auto_increment not null,
    enterpriseName varchar(15) not null,
    primary key(enterpriseId)
);

drop tables;