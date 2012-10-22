#ifndef _FC_TCP_SOCKET_HPP_
#define _FC_TCP_SOCKET_HPP_
#include <fc/utility.hpp>
#include <fc/fwd.hpp>

namespace fc {
  namespace ip { class endpoint; } 
  class tcp_socket {
    public:
      tcp_socket();
      ~tcp_socket();

      void   connect_to( const fc::ip::endpoint& e );

      void   write( const char* buffer, size_t len );
      size_t readsome( char* buffer, size_t max );
      size_t read( char* buffer, size_t s );

      bool   is_open()const;

      void flush();

    private:
      friend class tcp_server;
      class impl;
      fc::fwd<impl,32> my;
  };

  class tcp_server {
    public:
      tcp_server(uint16_t port=0);
      ~tcp_server();

      void close();
      bool accept( tcp_socket& s );
//      void listen( uint16_t port );
    
    private:
      class impl;
      fc::fwd<impl,32> my;
  };

} // namesapce fc

#endif // _FC_TCP_SOCKET_HPP_
