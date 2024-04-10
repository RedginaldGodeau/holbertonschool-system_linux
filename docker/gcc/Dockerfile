FROM ubuntu
RUN apt-get update && \
    apt-get install -yq git make vim clang build-essential curl cmake python3.10-dev && \
    apt-get install -yq gcc-4.8

RUN git clone https://github.com/hs-hq/Betty.git
RUN cd Betty && ./install.sh

RUN git clone https://github.com/justmao945/vim-clang.git \
    && cp vim-clang/plugin/* /usr/share/vim/addons/

RUN curl -fLo /root/.vim/autoload/plug.vim --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
RUN git clone https://github.com/VundleVim/Vundle.vim.git /root/.vim/bundle/Vundle.vim

CMD bash