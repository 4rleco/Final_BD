create database CppProyect;

use  CppProyect;

create table Users
(
	user_id int auto_increment not null,
    user_name varchar(15) not null,
    user_password varchar(15) not null,
    primary key(user_id)    
);

create table Enterprises
(
	enterprise_id int auto_increment not null,
    enterprise_name varchar(15) not null,
    primary key(enterprise_id)
);

create table Characters
(
	character_id int auto_increment not null,
    character_name varchar(15) not null,
    character_skill varchar(15)not null,
    primary key(character_id)
);

create table Games
(
	game_id int auto_increment not null,
    game_name varchar(15) not null,
    id_enterprise int not null,
    primary key(game_id),
     constraint FK_id_enterprise foreign key(id_enterprise)
    references Enterprises(enterprise_id)
);

create table People
(
    people_name varchar(15) not null,
    people_DNI varchar(8) not null,
    id_user int not null,
    id_game int not null,
    id_character int not null,
    primary key(people_DNI),
    constraint FK_id_user foreign key(id_user)
    references Users(user_id),
     constraint FK_id_game foreign key(id_game)
    references Games(game_id),
     constraint FK_id_character foreign key(id_character)
    references Characters(character_id)
);

#drop database cppproyect;