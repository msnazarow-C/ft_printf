sed -i -e "s/\$server_port/$server_port/" /etc/nginx/sites-available/default
supervisord -c supervisord.conf