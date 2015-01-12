#pragma once

#if defined( _WIN32 )
#include <WS2tcpip.h>
#include <Windows.h>
#include <Iphlpapi.h>
#pragma comment( lib, "Ws2_32.lib" )
#pragma comment( lib, "Iphlpapi.lib" )
#else
#include <sys/time.h>
#endif

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <cstdlib>
#include <cstring>
