# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/24 03:36:49 by sgertrud          #+#    #+#              #
#    Updated: 2020/06/27 05:33:48 by sgertrud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster
RUN apt-get -y update && apt-get -y upgrade
RUN apt-get install -y nginx curl supervisor wget mariadb-server mariadb-client php-fpm
RUN apt-get install -y php-common php-mbstring php-xmlrpc php-soap php-gd php-intl php-mysql php-cli php-ldap php-zip php-curl
#RUN sed -i -e '/location.*\/.*{/a autoindex on\;' /etc/nginx/sites-available/default
#RUN sed -i -e '/location.*\/.*{/a fastcgi_pass localhost:9000\;' /etc/nginx/sites-available/default
RUN	openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt -subj "/C=RU/ST=Moscow/L=Moscow/O=School 21/CN=sgertrud"
WORKDIR /var/www/
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz https://wordpress.org/latest.tar.gz
RUN tar -xvzf latest.tar.gz && tar -xvzf phpMyAdmin-5.0.2-all-languages.tar.gz && mv phpMyAdmin-5.0.2-all-languages wordpress/phpMyAdmin
RUN apt-get -y install nano
RUN apt-get -y install certbot python-certbot-nginx
COPY srcs/ .
RUN chmod +x *.sh
RUN mv localhost.conf /etc/nginx/sites-available/default
#EXPOSE 80 443
#RUN mv wp-config.php wordpress/
#&& mv config.inc.php phpMyAdmin/
RUN bash start.sh
CMD [ "bash", "run.sh" ]
