FROM ubuntu:18.04

WORKDIR /home

COPY . .

RUN apt -y update
RUN apt -y install emacs perl gcc python

ENV TIGRESS_HOME /home/tigress/3.3.2
ENV PATH "/home/tigress/3.3.2:$PATH"

# COMMAND: tigress --Environment=x86_64:Linux:Gcc:4.6 --Transform=Virtualize --Functions=main,fib,fac --out=result.c /home/tigress/3.3.2/test1.c