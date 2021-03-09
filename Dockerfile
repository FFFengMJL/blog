FROM ubuntu:20.04
RUN sed -i 's/archive.ubuntu.com/mirrors.tuna.tsinghua.edu.cn/g' /etc/apt/sources.list \
&& sed -i 's/deb http:\/\/security/#/g' /etc/apt/sources.list \
&& apt update \
&& apt-get install -y tcpdump \ 
&& apt-get install -y net-tools \
&& apt-get install -y iproute2 \
&& apt-get install -y iputils-ping \
&& apt-get install -y nmap \
&& apt-get install -y dsniff \
&& apt-get install -y driftnet \
&& apt-get install -y ssh nano tmux