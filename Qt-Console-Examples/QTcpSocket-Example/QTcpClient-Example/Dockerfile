FROM a12e/docker-qt:6.4-linux as build

#ARG IP_ADDRESS
#ENV DISPLAY_IP_ADDRESS $IP_ADDRESS

ENV DISPLAY=192.168.239.192:0
RUN echo 'export DISPLAY=192.168.239.192:0' >> /home/user/.bashrc

WORKDIR /app/build

ADD . /app/source

RUN cmake ../source && cmake --build .
	
#ENTRYPOINT ["./QTcpClient-Example"]

#EXPOSE 8000
