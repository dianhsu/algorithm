# 导入基础镜像GCC
FROM gcc
# 导入基础镜像Clang
# FROM silkeh/clang

# 更新包数据库
RUN apt-get update
# 安装必要的软件包
RUN apt-get install -y gdb build-essential curl sed unzip git jq libssl-dev ca-certificates
# 安装cf-tool
RUN mkdir ~/tool && mkdir ~/tool/bin
RUN mkdir ~/tool/clangd




RUN VERSION=$(curl -s https://api.github.com/repos/dianhsu-official/ccs/releases/latest | jq ".tag_name" | cut -d '"' -f 2) \
    && if [ $(uname -m) = 'x86_64' ]; then ARCH="amd64"; else ARCH="aarch64"; fi \
    && URL=https://github.com/dianhsu-official/ccs/releases/download/${VERSION}/ccs-linux-${ARCH}.zip \
    && curl -L $URL -o dist.zip \
    && unzip dist.zip -d ~/tool/bin \
    && rm dist.zip \
    && chmod +x ~/tool/bin/ccs

RUN VERSION=$(curl -s https://api.github.com/repos/dianhsu-official/clangd-auto-build/releases/latest | jq ".tag_name" | cut -d '"' -f 2) \
    && if [ $(uname -m) = 'x86_64' ]; then ARCH="amd64"; else ARCH="aarch64"; fi \
    && URL=https://github.com/dianhsu-official/clangd-auto-build/releases/download/${VERSION}/ubuntu-latest-${ARCH}.zip \
    && curl -L $URL -o dist.zip \
    && unzip dist.zip -d ~/tool/clangd\
    && rm dist.zip \
    && chmod +x ~/tool/clangd/bin/clangd


# RUN apt-get install -y zsh
# RUN apt-get install -y git zsh \
#     && git clone https://github.com/ohmyzsh/ohmyzsh.git ~/.oh-my-zsh \
#     && cp ~/.oh-my-zsh/templates/zshrc.zsh-template ~/.zshrc \
#     && usermod -s /bin/zsh root
RUN ln -s ~/tool/bin/ccs /usr/bin/ccs
RUN ln -s ~/tool/clangd/bin/clangd /usr/bin/clangd

RUN apt autoremove -y \
    && apt clean -y \
    && rm -rf /var/lib/apt/lists/*

CMD ["/usr/bin/ccs", "-w", "/workspaces/algorithm", "-v", "-t", "/workspaces/algorithm/sol.cpp", "-s", "--log-file", "/workspaces/algorithm/ccs.log"]