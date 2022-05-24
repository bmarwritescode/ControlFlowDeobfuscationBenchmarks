FROM ubuntu:18.04

# Avoid warnings by switching to noninteractive
ENV DEBIAN_FRONTEND=noninteractive

# Configure apt and install packages
RUN apt-get update && apt-get upgrade -y
RUN apt-get -y install --no-install-recommends apt-utils 2>&1 \
    #
    # Verify git, process tools, lsb-release (common in install instructions for CLIs) installed
    && apt-get -y install git procps lsb-release \
    && apt-get -y install python3 python3-pip vim build-essential

# Clean up
RUN apt-get autoremove -y \
    && apt-get clean -y \
    && rm -rf /var/lib/apt/lists/*

# Switch back to dialog for any ad-hoc use of apt-get
ENV DEBIAN_FRONTEND=dialog

ARG TIGRESS_VER=3.3.2

# Install TIGRESS
COPY ./tigress /tigress/
ENV TIGRESS_HOME=/tigress/${TIGRESS_VER}
ENV PATH="/tigress/${TIGRESS_VER}:${PATH}"
