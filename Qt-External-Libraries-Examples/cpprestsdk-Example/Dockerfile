FROM atom63/qt-docker:linux-buster-x86_64-qt5 as build

WORKDIR /app/build

ADD . /app/source

RUN conan install /app/source/conanfile.txt --install-folder=/app/build && \
    cmake ../source && \
    cmake --build .

ENTRYPOINT ["./cpprestsdk-Example"]

EXPOSE 8000
