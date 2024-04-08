FROM ubuntu
RUN apt-get update && \
    apt-get install -yq git make vim clang build-essential && \
    apt-get install -yq gcc-4.8

RUN git clone https://github.com/hs-hq/Betty.git
RUN cd Betty && ./install.sh

RUN git clone https://github.com/justmao945/vim-clang.git \
    && cp vim-clang/plugin/* /usr/share/vim/addons/


CMD bash