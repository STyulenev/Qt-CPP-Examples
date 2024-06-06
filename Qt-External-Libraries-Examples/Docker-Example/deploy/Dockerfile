# Сборка ---------------------------------------

# В качестве базового образа для сборки используем docker-qt
FROM a12e/docker-qt:6.4-linux as build

# Указываем ip хоста для получения GUI с помощью VcXsrv Windows X Server
ARG IP_ADDRESS
ENV DISPLAY_IP_ADDRESS $IP_ADDRESS

ENV DISPLAY=${IP_ADDRESS}:0
RUN echo 'export DISPLAY=${DISPLAY_IP_ADDRESS}:0' >> /home/user/.bashrc

# Скопируем проект в контейнер
ADD . /app/src

# Установим рабочую директорию для сборки проекта
WORKDIR /app/build

# Выполним сборку нашего проекта
RUN cmake ../src && \
    cmake --build .

# Установим точку входа
ENTRYPOINT ["./bin/Docker-Example"]
