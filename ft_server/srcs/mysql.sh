#!bin/bash
mysql -e "CREATE DATABASE wp_database"
mysql -e "CREATE USER 'admin'@'localhost' IDENTIFIED BY 'admin';"
mysql -e "GRANT ALL ON *.* TO 'admin'@'localhost' IDENTIFIED BY 'admin' WITH GRANT OPTION;"
mysql -e "FLUSH PRIVILEGES"