#!/bin/bash
if [[ "$1" == "on" || "$1" == "off" ]]; then
sed -i -e "s/autoindex [a-z]*/autoindex $1/" /etc/nginx/sites-available/default
service nginx restart
else
echo "incorrect input"
fi