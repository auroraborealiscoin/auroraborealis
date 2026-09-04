FROM amd64/ubuntu:20.04 AS base

LABEL org.opencontainers.image.authors="Aurora Borealis Coin <auroraborealiscoin@gmail.com>"

EXPOSE 17332/tcp
EXPOSE 17333/tcp

ENV DEBIAN_FRONTEND=noninteractive

#Install runtime dependencies
RUN apt-get update && \
	apt-get install -y --no-install-recommends \
	bash wget net-tools libminiupnpc17 \
	libevent-2.1 libevent-pthreads-2.1 \
	libboost-system1.71 libboost-filesystem1.71 libboost-chrono1.71 \
	libboost-program-options1.71 libboost-thread1.71 \
	libzmq5 && \
	apt-get clean

FROM base AS build

#Install build dependencies
RUN apt-get update && \
	apt-get install -y --no-install-recommends \
	bash net-tools build-essential libtool autotools-dev automake \
	pkg-config libssl-dev libevent-dev bsdmainutils python3 \
	libboost-system1.71-dev libboost-filesystem1.71-dev libboost-chrono1.71-dev \
	libboost-program-options1.71-dev libboost-test1.71-dev libboost-thread1.71-dev \
	libzmq3-dev libminiupnpc-dev && \
	apt-get clean

#Copy source dir
COPY . /home/auroraborealis/build/auroraborealis/
WORKDIR /home/auroraborealis/build/auroraborealis

#build db4 from source
WORKDIR /home/auroraborealis/build/auroraborealis/contrib
RUN ./install_db4.sh ../../

# build Aurora Borealis Core
WORKDIR /home/auroraborealis/build/auroraborealis
RUN ./autogen.sh && ./configure --disable-tests BDB_LIBS="-L/home/auroraborealis/build/db4/lib -ldb_cxx-4.8" BDB_CFLAGS="-I/home/auroraborealis/build/db4/include" --with-gui=no  && make -j4

FROM base AS final

#Add our service account user
RUN useradd -ms /bin/bash auroraborealis && \
	mkdir /var/lib/auroraborealis && \
	chown auroraborealis:auroraborealis /var/lib/auroraborealis && \
	ln -s /var/lib/auroraborealis /home/auroraborealis/.auroraborealis && \
	chown -h auroraborealis:auroraborealis /home/auroraborealis/.auroraborealis

VOLUME /var/lib/auroraborealis

#Copy the compiled binaries from the build
COPY --from=build /home/auroraborealis/build/auroraborealis/src/auroraborealisd /usr/local/bin/auroraborealisd
COPY --from=build /home/auroraborealis/build/auroraborealis/src/auroraborealis-cli /usr/local/bin/auroraborealis-cli

WORKDIR /home/auroraborealis
USER auroraborealis

CMD /usr/local/bin/auroraborealisd -datadir=/var/lib/auroraborealis -printtoconsole -onlynet=ipv4
