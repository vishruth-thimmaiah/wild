ARG BASE_IMAGE=ghcr.io/wild-linker/wild/ci-ubuntu-amd64:latest
FROM ${BASE_IMAGE}

ENV WINESERVER=/usr/lib/x86_64-linux-gnu/wine/wineserver

RUN eatmydata apt-get update \
    && eatmydata apt-get -y install \
        binutils-aarch64-linux-gnu \
        binutils-loongarch64-linux-gnu \
        binutils-mingw-w64-x86-64 \
        binutils-powerpc64le-linux-gnu \
        binutils-riscv64-linux-gnu \
        clang-18 \
        g++-aarch64-linux-gnu \
        g++-loongarch64-linux-gnu \
        g++-mingw-w64-x86-64 \
        g++-powerpc64le-linux-gnu \
        g++-riscv64-linux-gnu \
        gcc-aarch64-linux-gnu \
        gcc-loongarch64-linux-gnu \
        gcc-mingw-w64-x86-64 \
        gcc-powerpc64le-linux-gnu \
        gcc-riscv64-linux-gnu \
        lld-18 \
        llvm-18-dev \
        qemu-user \
        wine64 \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

RUN curl -fsSL https://toolchains.bootlin.com/downloads/releases/toolchains/riscv32-ilp32d/tarballs/riscv32-ilp32d--glibc--stable-2026.08-1.tar.xz \
        | tar -xJ --strip-components=1 --exclude='*/lib64' --exclude='lib64' -C /usr \
    && sh /usr/relocate-sdk.sh \
    && rm /usr/relocate-sdk.sh \
    && for f in /usr/bin/riscv32-buildroot-linux-gnu-*; do \
        mv "$f" "/usr/bin/riscv32-linux-gnu-${f##*riscv32-buildroot-linux-gnu-}"; \
    done \
    && mv /usr/riscv32-buildroot-linux-gnu/sysroot /usr/riscv32-linux-gnu \
    && ln -s /usr/riscv32-linux-gnu /usr/riscv32-buildroot-linux-gnu/sysroot \
    && mv /usr/lib/gcc/riscv32-buildroot-linux-gnu /usr/lib/gcc/riscv32-linux-gnu \
    && ln -s riscv32-linux-gnu /usr/lib/gcc/riscv32-buildroot-linux-gnu \
    && mkdir -p /usr/riscv32-linux-gnu/bin \
    && ln -sf /usr/bin/riscv32-linux-gnu-ld /usr/riscv32-linux-gnu/bin/ld

RUN eatmydata rustup toolchain install nightly \
        --allow-downgrade \
        --target x86_64-unknown-linux-gnu,x86_64-unknown-linux-musl,aarch64-unknown-linux-gnu,aarch64-unknown-linux-musl,riscv64gc-unknown-linux-gnu,riscv64gc-unknown-linux-musl,loongarch64-unknown-linux-gnu,loongarch64-unknown-linux-musl,powerpc64le-unknown-linux-gnu,powerpc64le-unknown-linux-musl \
        --component rustc-codegen-cranelift-preview
