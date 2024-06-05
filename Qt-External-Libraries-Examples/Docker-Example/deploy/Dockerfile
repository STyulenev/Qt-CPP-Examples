# Сборка ---------------------------------------

# В качестве базового образа для сборки используем docker-qt
FROM a12e/docker-qt:6.4-linux as build

ENV DISPLAY=192.168.176.1:0
RUN echo 'export DISPLAY=192.168.176.1:0' >> /home/user/.bashrc

# Скопируем проект в контейнер
ADD . /app/src

# Установим рабочую директорию для сборки проекта
WORKDIR /app/build

# Выполним сборку нашего проекта
RUN cmake ../src && \
    cmake --build .

# Установим точку входа
ENTRYPOINT ["./bin/Docker-Example"]
