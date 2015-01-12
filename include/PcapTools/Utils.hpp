#pragma once

/*
Copyright (c) 2014, Jeff Koftinoff
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "PcapTools/World.hpp"

namespace PcapTools
{
uint64_t get_current_time_in_microseconds();

/* wireshark PCAP file header from
 * http://wiki.wireshark.org/Development/LibpcapFileFormat#File_Format */
struct pcap_hdr_t
{
    uint32_t magic_number;  /* magic number */
    uint16_t version_major; /* major version number */
    uint16_t version_minor; /* minor version number */
    int32_t thiszone;       /* GMT to local correction */
    uint32_t sigfigs;       /* accuracy of timestamps */
    uint32_t snaplen;       /* max length of captured packets, in octets */
    uint32_t network;       /* data link type */
};

/* wireshark PCAP record header from
 * http://wiki.wireshark.org/Development/LibpcapFileFormat#File_Format */

struct pcaprec_hdr_t
{
    uint32_t ts_sec;  /* timestamp seconds */
    uint32_t ts_usec; /* timestamp microseconds */
    int32_t incl_len; /* number of octets of packet saved in file */
    int32_t orig_len; /* actual length of packet */
};

typedef std::vector<uint8_t> PcapFilePacket;

inline uint32_t PcapFileSwap( uint32_t v )
{
    uint32_t r = 0;

    r |= ( ( v >> 24 ) & 0x000000ff );
    r |= ( ( v >> 8 ) & 0x0000ff00 );
    r |= ( ( v << 8 ) & 0x00ff0000 );
    r |= ( ( v << 24 ) & 0xff000000 );
    return r;
}

class File
{
  public:
    File( std::string const &filename, std::string const &mode )
        : m_filename( filename )
    {
        m_f = fopen( m_filename.c_str(), mode.c_str() );
    }

    virtual ~File()
    {
        if ( m_f )
        {
            fclose( m_f );
        }
    }

    FILE *open( std::string const &filename, std::string const &mode )
    {
        if ( m_f )
        {
            fclose( m_f );
        }
        m_filename = filename;
        m_f = fopen( m_filename.c_str(), mode.c_str() );
        return m_f;
    }

    void close()
    {
        if ( m_f )
        {
            fclose( m_f );
            m_f = 0;
        }
    }

    FILE *get() { return m_f; }

    std::string const &getFilename() const { return m_filename; }

  private:
    std::string m_filename;
    FILE *m_f;
};
}
