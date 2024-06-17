FROM a12e/docker-qt:6.4-linux as build

ARG IP_ADDRESS
ENV DISPLAY_IP_ADDRESS $IP_ADDRESS

ENV DISPLAY=${IP_ADDRESS}:0
RUN echo 'export DISPLAY=${DISPLAY_IP_ADDRESS}:0' >> /home/user/.bashrc

WORKDIR /app/build

ADD . /app/source

RUN cmake ../source && cmake --build .
	