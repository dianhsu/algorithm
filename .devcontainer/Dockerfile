# 导入基础镜像GCC
# FROM gcc
# 导入基础镜像Clang
FROM silkeh/clang

# 更新包数据库
RUN apt-get update
# 安装必要的软件包
RUN apt-get install -y gdb build-essential curl sed unzip
# 安装cf-tool
RUN mkdir ~/tool && mkdir ~/tool/bin
RUN curl -L $(curl -s https://api.github.com/repos/dianhsu/cf-tool/releases/latest | grep /cf_linux_x64.zip | cut -d '"' -f 4) -o dist.zip && unzip dist.zip && rm dist.zip && mv cf ~/tool/bin/cf && chmod +x ~/tool/bin/cf
RUN curl -L $(curl -s https://api.github.com/repos/clangd/clangd/releases/latest | grep /clangd-linux-[0-9\.]*\.zip | cut -d '"' -f 4) -o dist.zip && unzip dist.zip && rm dist.zip && mv clangd_*/ ~/tool/clangd
RUN echo "export PATH=$PATH:~/tool/clangd/bin:~/tool/bin" >> ~/.bashrc