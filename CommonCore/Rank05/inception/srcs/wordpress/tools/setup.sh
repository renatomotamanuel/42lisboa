#!/bin/bash
set -e

DB_PASSWORD="$(cat /run/secrets/db_password)"
WP_ADMIN_PASSWORD="$(grep '^WP_ADMIN_PASSWORD=' /run/secrets/credentials | cut -d '=' -f2-)"
WP_USER_PASSWORD="$(grep '^WP_USER_PASSWORD=' /run/secrets/credentials | cut -d '=' -f2-)"

echo "Initializing WordPress"

mkdir -p /run/php

echo "Waiting for MariaDB"
i=0
until mysql -h mariadb -u"${DB_USER}" -p"${DB_PASSWORD}" -e "SELECT 1;" >/dev/null 2>&1; do
	i=$((i+1)); [ "$i" -ge 30 ] && { echo "MariaDB unreachable"; exit 1; }
	sleep 2
done
	echo "MariaDB setted up"

cd /var/www/html

if [ ! -f wp-load.php ]; then
	echo "Downloading WordPress"
	wp core download --allow-root
fi

if [ ! -f wp-config.php ]; then
	echo "Creating wp-config.php"
	wp config create --allow-root --dbname="${DB_NAME}" --dbuser="${DB_USER}" --dbpass="${DB_PASSWORD}" --dbhost="mariadb" --path="/var/www/html"
fi

if ! wp core is-installed --allow-root --path="/var/www/html" >/dev/null 2>&1; then
	echo "Installing WordPress"
	wp core install --allow-root --url="https://${DOMAIN_NAME}" --title="${WP_TITLE}" --admin_user="${WP_ADMIN_USER}" --admin_password="${WP_ADMIN_PASSWORD}" --admin_email="${WP_ADMIN_EMAIL}" --skip-email
	wp user create --allow-root "${WP_USER}" "${WP_USER_EMAIL}" --user_pass="${WP_USER_PASSWORD}" --role=author
	echo "WordPress installed"
else
	echo "WordPress already installed"
fi

THEME_SLUG="the-cozy-blog"
if wp theme is-installed "$THEME_SLUG" --allow-root --path="/var/www/html"; then
	wp theme activate "$THEME_SLUG" --allow-root --path="/var/www/html"
else
	wp theme install "$THEME_SLUG" --activate --allow-root --path="/var/www/html"
fi
chown -R www-data:www-data /var/www/html
echo "Starting php-fpm"
exec php-fpm8.2 -F