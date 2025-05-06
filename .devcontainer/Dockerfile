# 导入基础镜像GCC
FROM --platform=amd64 gcc
# 导入基础镜像Clang
# FROM silkeh/clang

# 更新包数据库
RUN apt-get update
# 安装必要的软件包
RUN apt-get install -y gdb build-essential curl sed unzip git jq libssl-dev ca-certificates
# 安装cf-tool
RUN mkdir ~/tool && mkdir ~/tool/bin




RUN VERSION=$(curl -s https://api.github.com/repos/dianhsu-official/ccs/releases/latest | jq ".tag_name" | cut -d '"' -f 2) \
    && if [ $(uname -m) = 'x86_64' ]; then ARCH="amd64"; else ARCH="aarch64"; fi \
    && URL=https://github.com/dianhsu-official/ccs/releases/download/${VERSION}/ccs-linux-${ARCH}.zip \
    && curl -L $URL -o dist.zip \
    && unzip dist.zip \
    && rm dist.zip \
    && mv ccs ~/tool/bin/ccs \
    && chmod +x ~/tool/bin/ccs

RUN if [ $(uname -m) = 'x86_64' ]; then \
        curl -L $(curl -s https://api.github.com/repos/clangd/clangd/releases/latest | jq ".assets[0].browser_download_url" | cut -d '"' -f 2) -o dist.zip \
        && unzip dist.zip \
        && rm dist.zip \
        && mv clangd_*/ ~/tool/clangd \
        && ln -s ~/tool/clangd/bin/clangd /usr/bin/clangd; \
    else \
        apt-get install -y clangd; \
    fi 

# RUN apt-get install -y zsh
# RUN apt-get install -y git zsh \
#     && git clone https://github.com/ohmyzsh/ohmyzsh.git ~/.oh-my-zsh \
#     && cp ~/.oh-my-zsh/templates/zshrc.zsh-template ~/.zshrc \
#     && usermod -s /bin/zsh root
RUN ln -s ~/tool/bin/ccs /usr/bin/ccs

RUN apt autoremove -y \
    && apt clean -y \
    && rm -rf /var/lib/apt/lists/*

CMD ["/usr/bin/ccs", "-w", "/workspaces/algorithm", "-v", "-t", "/workspaces/algorithm/sol.cpp", "-s", "--log-file", "/workspaces/algorithm/ccs.log"]