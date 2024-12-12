#include <mysql.h>
#include <iostream>

using namespace std;

void main()
{
	enum Options
	{
		Exit,
		Change,
		Verify,
		Insertion,
		Update,
		Eliminate
	};
	Options options;

	enum Tables
	{
		Users = 1,
		People,
		Games,
		Characters,
		Enterprises
	};
	Tables tables;

	MYSQL* connection;

	MYSQL_ROW row;
	MYSQL_RES* res;

	string change = "Users";
	string verify = "";
	string insertion = "";
	string update = "";
	string eliminate = "";

	string user = "";
	string password = "";
	string userID = "";
	string characterID = "";
	string gameID = "";
	string enterpriseID;

	int status = 0;

	int option = 0;

	int table = 0;

	const char* query;

	connection = mysql_init(0);

	connection = mysql_real_connect(connection, "localhost", "root", "4rlEqu1n3000", "CppProyect", 3306, NULL, 0);

	if (connection)
	{
		cout << "Successful connection" << endl;
	}

	else
	{
		cout << "Unsuccessful connection " << endl;
		return;
	}

	do
	{
		printf("\n\n*********************************** Option Menu ***********************************");
		printf("\n\n 1. Change table");
		printf("\n\n 2. Verify User Data");
		printf("\n\n 3. Insert New User");
		printf("\n\n 4. Actualice User Data");
		printf("\n\n 5. Errase user");
		printf("\n\n 0. Finish The Program");
		printf("\n\nOption Select:  ");

		cin >> option;

		options = (Options)option;

		switch (option)
		{
		case Options::Change:

			printf("\n\n*********************************** Table Menu ***********************************");
			printf("\n\n 1. Users table");
			printf("\n\n 2. People table");
			printf("\n\n 3. Games table");
			printf("\n\n 4. Characters table");
			printf("\n\n 5. Enterprises table");
			printf("\n\nOption Select:  ");

			cin >> table;

			tables = (Tables)table;

			switch (tables)
			{
			case Tables::Users:
				printf("Changed to Users table");
				change = "Users";
				break;

			case Tables::People:
				printf("Changed to People table");
				change = "People";
				break;

			case Tables::Games:
				printf("Changed to Games table");
				change = "Games";
				break;

			case Tables::Characters:
				printf("Changed to Characters table");
				change = "Characters";
				break;

			case Tables::Enterprises:
				printf("Changed to Enterprises table");
				change = "Enterprises";
				break;

			default:
				cout << "You are in " << change << " table" << endl;
				break;
			}

			break;

		case Options::Verify:
			if (change == "Users")
			{
				verify = "select * from " + change;

				query = verify.c_str();

				status = mysql_query(connection, query);

				if (!status)
				{
					res = mysql_store_result(connection);

					cout << change << " Data Result" << endl;


					while (row = mysql_fetch_row(res))
					{
						cout << "\nUser Id: " << row[0] << ", user name: " << row[1] << ", user password: " << row[2] << endl;
					}
				}
			}

			if (change == "People")
			{
				verify = "select * from " + change;

				query = verify.c_str();

				status = mysql_query(connection, query);

				if (!status)
				{
					res = mysql_store_result(connection);

					cout << change << " Data Result" << endl;

					while (row = mysql_fetch_row(res))
					{
						cout << "\nPeople_name: " << row[0] << ", people_DNI: " << row[1] << ", id_user: " << row[2] <<
							", id_game: " << row[3] << ", id_character: " << row[4] << endl;
					}
				}

			}

			if (change == "Games")
			{
				verify = "select * from " + change;

				query = verify.c_str();

				status = mysql_query(connection, query);

				if (!status)
				{

					res = mysql_store_result(connection);

					cout << change << " Data Result" << endl;

					while (row = mysql_fetch_row(res))
					{
						cout << "\nGame Id: " << row[0] << ", game name: " << row[1] << ", id_enterprise: " << row[2] << endl;
					}
				}
			}

			if (change == "Characters")
			{
				verify = "select * from " + change;

				query = verify.c_str();

				status = mysql_query(connection, query);

				if (!status)
				{

					res = mysql_store_result(connection);

					cout << change << " Data Result" << endl;

					while (row = mysql_fetch_row(res))
					{
						cout << "\nCharacter Id: " << row[0] << ", character name: " << row[1] << ", character skill: " << row[2] << endl;
					}
				}
			}

			if (change == "Enterprises")
			{
				verify = "select * from " + change;

				query = verify.c_str();

				status = mysql_query(connection, query);

				if (!status)
				{

					res = mysql_store_result(connection);

					cout << change << " Data Result" << endl;

					while (row = mysql_fetch_row(res))
					{
						cout << "\nEnterprise Id: " << row[0] << ", enterprise name: " << row[1] << endl;
					}
				}
			}
			break;

		case Options::Insertion:
			if (change == "Users")
			{
				printf("\n\n Insert the name: ");
				cin >> user;

				printf("\n\n Insert the password: ");
				cin >> password;

				insertion = "insert into " + change + "(user_name, user_password) values('" + user + "', '" + password + "')";
			}

			if (change == "People")
			{
				printf("\n\n Insert the name: ");
				cin >> user;

				printf("\n\n Insert the DNI: ");
				cin >> password;

				printf("\n\n Insert the user id: ");
				cin >> userID;

				printf("\n\n Insert the game id: ");
				cin >> gameID;

				printf("\n\n Insert the character id: ");
				cin >> characterID;

				insertion = "insert into " + change + "(people_name, people_DNI, id_user, id_game, id_character) values('"
					+ user + "', '" + password + "', '" + userID +"' , '" + gameID + "', '" + characterID + "')";
			}

			if (change == "Games")
			{
				printf("\n\n Insert the name: ");
				cin >> user;

				printf("\n\n Insert the enterprise id: ");
				cin >> enterpriseID;

				insertion = "insert into " + change + "(game_name,id_enterprise) values('" + user + "', '" + enterpriseID + "')";
			}

			if (change == "Characters")
			{
				printf("\n\n Insert the name: ");
				cin >> user;

				printf("\n\n Insert the skill: ");
				cin >> password;

				insertion = "insert into " + change + "(character_name, character_skill) values('" + user + "', '" + password + "')";
			}

			if (change == "Enterprises")
			{
				printf("\n\n Insert the name: ");
				cin >> user;

				insertion = "insert into " + change + "(enterprise_name) values('" + user + "')";
			}

			query = insertion.c_str();

			status = mysql_query(connection, query);

			if (!status)
			{
				printf("\nUser inserted correctly");
			}
			else
			{
				printf("\nUser not inserted");
			}
			break;

		case Options::Update:
			if (change != "Games" && change != "Enterprise")
			{

				printf("\nInsert the user to modify: ");
				cin >> user;

				printf("\nInsert new password for that user: ");
				cin >> password;


				if (change == "Users")
				{
					update = "update " + change + " set user_password = '" + password + "' where user_name = '" + user + "'";
				}

				if (change == "People")
				{
					update = "update " + change + " set people_DNI = '" + password + "' where people_name = '" + user + "'";
				}

				if (change == "Characters")
				{
					update = "update " + change + " set character_skill = '" + password + "' where character_name = '" + user + "'";
				}

				query = update.c_str();

				status = mysql_query(connection, query);

				if (!status)
				{
					printf("\nUser updated correctly");
				}
				else
				{
					printf("\nUser not updated");
				}
			}

			else
			{
				printf("\nUser can't update");
			}


			break;

		case Options::Eliminate:
			printf("\nInsert the user to delete: ");
			cin >> user;

			if (change == "Users")
			{
				eliminate = "delete from " + change + " where user_name = '" + user + "'";
			}

			if (change == "People")
			{
				eliminate = "delete from " + change + " where people_name = '" + user + "'";
			}

			if (change == "Games")
			{
				eliminate = "delete from " + change + " where game_name = '" + user + "'";
			}

			if (change == "Characters")
			{
				eliminate = "delete from " + change + " where character_name = '" + user + "'";
			}

			if (change == "Enterprises")
			{
				eliminate = "delete from " + change + " where enterprise_name = '" + user + "'";
			}

			query = eliminate.c_str();

			status = mysql_query(connection, query);

			if (!status)
			{
				printf("\nUser deleted correctly");
			}
			else
			{
				printf("\nUser not deleted");
			}
			break;
		}

	} while (option != 0);
}