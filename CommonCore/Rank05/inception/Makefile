LOGIN = rmota-ma
DATA_DIR = /home/$(LOGIN)/data
COMPOSE  = docker compose -f srcs/docker-compose.yml

all: up

up:
	@mkdir -p $(DATA_DIR)/mariadb $(DATA_DIR)/wordpress
	$(COMPOSE) up -d --build

down:
	$(COMPOSE) down

start:
	$(COMPOSE) start

stop:
	$(COMPOSE) stop

status:
	$(COMPOSE) ps

logs:
	$(COMPOSE) logs -f

clean:
	$(COMPOSE) down --rmi local

fclean:
	$(COMPOSE) down -v --rmi all
	sudo rm -rf $(DATA_DIR)/mariadb $(DATA_DIR)/wordpress

re: fclean all

.PHONY: all up down start stop status logs clean fclean re