#!/bin/sh
set -e

DB_PASSWORD="$(cat /run/secrets/db_password)"
DB_ROOT_PASSWORD="$(cat /run/secrets/db_root_password)"

export DB_PASSWORD DB_ROOT_PASSWORD

mkdir -p /run/mysqld
chown -R mysql:mysql /var/lib/mysql /run/mysqld

if [ ! -f "/var/lib/mysql/.initialized" ]; then
	echo "Initializing database"
	mariadb-install-db --user=mysql --datadir=/var/lib/mysql > /dev/null
	mariadbd --bootstrap --user=mysql --datadir=/var/lib/mysql <<-EOSQL
		FLUSH PRIVILEGES;
		CREATE DATABASE IF NOT EXISTS \`${DB_NAME}\`;
		CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
		GRANT ALL PRIVILEGES ON \`${DB_NAME}\`.* TO '${DB_USER}'@'%';
		ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';
		FLUSH PRIVILEGES;
	EOSQL
	touch /var/lib/mysql/.initialized
	chown mysql:mysql /var/lib/mysql/.initialized
	echo "Database setted up"
else
	echo "Database already setted up"
fi
	echo "Starting MariaDB"

exec mariadbd --user=mysql --datadir=/var/lib/mysql
