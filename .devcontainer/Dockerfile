FROM gcc:14.1.0

RUN apt update && apt install -y \
    python3-pip \
    pipx \
    cmake \
    clang \
    clang-tools \
    clangd

RUN pipx ensurepath && \
    pipx install conan
