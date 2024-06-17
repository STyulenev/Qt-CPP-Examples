FROM a12e/docker-qt:6.4-linux as build

WORKDIR /app/build

ADD . /app/source

RUN cmake ../source && cmake --build .
	
#CMD ./bin/QTcpServer-Example

#EXPOSE 8000