FROM ubuntu:latest

RUN apt-get update && \
    apt-get install -y build-essential

CMD ["/bin/bash"]
