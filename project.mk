PROJECT=PcapTools
PROJECT_NAME=PcapTools
PROJECT_VERSION=20150111
PROJECT_EMAIL=jeffk@jdkoftinoff.com
PROJECT_LICENSE=BSD
PROJECT_MAINTAINER=jeffk@jdkoftinoff.com
PROJECT_COPYRIGHT=Copyright 2015
PROJECT_DESCRIPTION=Wireshark Pcap utility functions in C++
PROJECT_WEBSITE=https://github.com/jdkoftinoff/PcapTools
PROJECT_IDENTIFIER=com.jdkoftinoff.pcaptools
TOP_LIB_DIRS+=.
CONFIG_TOOLS+=
PKGCONFIG_PACKAGES+=

CXXFLAGS+=-std=c++11 -stdlib=libc++

