using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/socket.h>

#define PORT 8080

class connection {
    int socket_file_descriptor, domain, protocal;
    char communication_type;

    int connection_optional_level, connection_optional_name; 
    int set_socket_option;

    // class constructor
    public:
        connection() {
            domain = AF_INET;
            protocal = 0;
            communication_type = SOCK_STREAM;
            socket_file_descriptor = NULL;
            connection_optional_level = 1;
            connection_optional_name = SOL_SOCKET;
            set_socket_option = NULL;
        }

    // This function creates socket for connection initialization
    public:
        int create_socket() {
            socket_file_descriptor = socket(domain, communication_type, protocal);

            if (socket_file_descriptor == 0) {
                perror("The socket unexpectedly refused to build up!");
                exit(EXIT_FAILURE);
            }

            // force for socket bind on the defined PORT
            set_socket_option = setsockopt(socket_file_descriptor, connection_optional_name, SO_REUSEADDR | SO_REUSEPORT, &connection_optional_level, sizeof(connection_optional_level));

            if (set_socket_option) {
                perror("The socket unexpectedly refused to rebuild up!");
                exit(EXIT_FAILURE);
            }

            return socket_file_descriptor;
        }
    
    
};
