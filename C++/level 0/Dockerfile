# Используем официальный образ Debian как базовый
FROM debian:latest

# Установка компилятора g++ и libcurl
RUN apt-get update && \
    apt-get install -y g++ libcurl4-openssl-dev

# Создание директории для вашего приложения
WORKDIR /app

# Копирование исходного кода в контейнер
COPY . /app

# Компиляция вашего приложения
RUN g++ -o testj Jira_test.cpp -lcurl

# Запуск вашего приложения при старте контейнера
CMD [ "./testj" ]
