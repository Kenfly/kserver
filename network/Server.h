#ifndef __KIT_SERVER_H__
#define __KIT_SERVER_H__

namespace kit {

class Server
{
public:
	Server();
	bool startUp(const char* ip, int32_t port);

private:
	Socket socket_;
};

} // namespcae kit
