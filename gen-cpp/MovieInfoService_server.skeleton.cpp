// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "MovieInfoService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace  ::movies;

class MovieInfoServiceHandler : virtual public MovieInfoServiceIf {
 public:
  MovieInfoServiceHandler() {
    // Your initialization goes here
  }

  void GetMoviesByIds(std::vector<std::string> & _return, const std::vector<std::string> & movie_ids) {
    // Your implementation goes here
    printf("GetMoviesByIds\n");
  }

  void GetMovieNames(std::string& _return, const std::string& title) {
    // Your implementation goes here
    printf("GetMovieNames\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::std::shared_ptr<MovieInfoServiceHandler> handler(new MovieInfoServiceHandler());
  ::std::shared_ptr<TProcessor> processor(new MovieInfoServiceProcessor(handler));
  ::std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

