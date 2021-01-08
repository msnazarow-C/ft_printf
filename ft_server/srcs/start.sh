#!/bin/bash
service mysql start && service php7.3-fpm start  && service nginx start && bash mysql.sh && bash wp_install.sh