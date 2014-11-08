PROJECT=pcap
PROJECT_NAME=pcap
PROJECT_VERSION=20141005
PROJECT_EMAIL=jeffk@jdkoftinoff.com
PROJECT_LICENSE=BSD
PROJECT_MAINTAINER=jeffk@jdkoftinoff.com
PROJECT_COPYRIGHT=Copyright 2014
PROJECT_DESCRIPTION=Wireshark Pcap utility functions in C++
PROJECT_WEBSITE=https://github.com/jdkoftinoff/pcap
PROJECT_IDENTIFIER=com.jdkoftinoff.pcap
TOP_LIB_DIRS+=.
CONFIG_TOOLS+=
PKGCONFIG_PACKAGES+=

CXXFLAGS+=-std=c++11 -stdlib=libc++

