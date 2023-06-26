# Сборка ---------------------------------------

# В качестве базового образа для сборки используем docker-qt
FROM a12e/docker-qt:6.4-linux as build

ENV DISPLAY=172.23.144.1:0
RUN echo 'export DISPLAY=172.23.144.1:0' >> /home/user/.bashrc

# Скопируем директорию /src в контейнер
ADD ./src /app/src

# Установим рабочую директорию для сборки проекта
WORKDIR /app/build

# Выполним сборку нашего проекта
RUN cmake ../src && \
    cmake --build .

# Установим точку входа
ENTRYPOINT ["./hello_world_app"]
