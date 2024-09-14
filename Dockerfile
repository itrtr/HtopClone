FROM ubuntu:22.04

RUN apt-get update && apt-get install -y build-essential scons && rm -rf /var/lib/apt/lists/*

WORKDIR /usr/src/app

COPY . .

RUN scons

CMD ["./htop"]