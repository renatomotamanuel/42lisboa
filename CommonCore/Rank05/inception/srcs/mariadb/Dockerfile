FROM debian:oldstable

RUN apt-get update && apt-get install -y mariadb-server mariadb-client && rm -rf /var/lib/apt/lists/* && rm -rf /var/lib/mysql/*

COPY config/99-inception.cnf /etc/mysql/mariadb.conf.d/99-inception.cnf

COPY /tools/init.sh /usr/local/bin

RUN chmod +x /usr/local/bin/init.sh

EXPOSE 3306

ENTRYPOINT ["/usr/local/bin/init.sh"]
