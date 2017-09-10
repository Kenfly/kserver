#include "Server.h"
#include "Socket.h"

namespace kit {

Server::Server()
: socket_(NULL)
{
}

void Server::startup(const char* ip, int32_t port)
{
	if (socket_)
	{
		shutDown();
	}

	socket_ = new Socket(AF_INET, SOCK_STREAM, 0);
	if (!socket_ or socket_->getHandle() == DSOCKERR)
	{
		return;
	}
}

void Server::shutdown()
{
	if (socket_)
	{
		socket_->close();
		socket_ = NULL;
	}

	for (int i = 0; i < CONNECTION_LIMIT; ++i)
	{
		if (socket_list_[i] != NULL)
		{
			socket_list_[i]->close();
			socket_list_[i] = NULL
		}
	}
}

}
