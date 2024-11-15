#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/tcp.h>

void print_tcp_info(int sockfd) {
    struct tcp_info info;
    socklen_t info_len = sizeof(info);

    if (getsockopt(sockfd, IPPROTO_TCP, TCP_INFO, &info, &info_len) == 0) {
        //printf("TCP status: %u\n", info.state);
        //printf("RTT: %u microseconds\n", info.rtt);
        //printf("RTT variance: %u microseconds\n", info.rttvar);
        printf("Retransmits: %u\n", info.tcpi_retransmits);
        printf("Total retransmits: %u\n", info.tcpi_total_retrans);
        //printf("Unacked packets: %u\n", info.unacked);
        printf("Last data sent: %u\n", info.tcpi_last_data_sent);
        printf("Last data received: %u\n", info.tcpi_last_data_recv);
        printf("Last ack received: %u\n", info.tcpi_last_ack_recv);
        //printf("Forward retransmits: %u\n", info.tcpi_forward_retrans);
        //printf("TCP window: %u\n", info.rcv_wnd);
        // 其他信息可以继续打印
    } else {
        perror("getsockopt");
    }
}

#define SERV_IP "127.0.0.1"
#define SERV_PORT 80

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    // 连接到服务器...
    
    struct sockaddr_in serv_addr;
    char buf[BUFSIZ] = {"GET /sldkf HTTP1.1\r\nHost: www.baidu.com\r\n\r\n"};
    bzero(&serv_addr, sizeof(serv_addr)); 
    serv_addr.sin_family = AF_INET;      
    inet_pton(AF_INET, SERV_IP, &serv_addr.sin_addr.s_addr);   
    serv_addr.sin_port = htons(SERV_PORT);                    

    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    
    write(sockfd, buf, strlen(buf));       

    sleep(5);
    print_tcp_info(sockfd);

    close(sockfd);
    return 0;
}
