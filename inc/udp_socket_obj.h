#include "main.h"


static int sock;
static struct sockaddr_in addr;

void udp_socket_create();
void udp_socket_send_byte_array(uint8_t *byte_array, int length);
