#ifndef HEAD_H
#define HEAD_H

#include <sys/types.h>
#include <netinet/in.h>
#include <pcap.h>
#include <time.h>
#include <arpa/inet.h>
#include <string.h>

// 以太网协议头部
// 目的地址和源地址各占6个字节
// 类型占两个字节
typedef struct eth_hd
{
  u_char src_mac[6]; 
  u_char dst_mac[6]; 
  u_short eth_type;
}eth_hd;
eth_hd *eth;
// ip 头部
//版本号4位，头部长度4位，服务类型8位
//总长度16位，标识16位，标识位和偏移量共16位
//TTl 8位，协议字段8位，头部检验和16位
//源地址，目的地址各占32位
//固定长度共20字节
#define IP_RF 0x8000
#define IP_DF 0x4000
#define IP_MF 0x2000

typedef struct ip_hd{
  u_char vl; // 这里使用位域来定义
 // u_char header_len; // 这两个占用一个字节
  
  u_char tos;
  u_short total_len;
  u_short id;
 
  u_short flags: 16;
 
  u_char ttl;
  u_char protocol;
  u_short checksum;
  u_char srcIP[4];
  u_char dstIP[4];
}ip_hd;
ip_hd *ip;

// tcp头部
// 源端口和目的端口各占 16位
//序号和 确认号各占32位
//头部长度占4位
 #define TH_FIN 0x01
 #define TH_SYN 0x02
 #define TH_RST 0x04
 #define TH_PUSH 0x08
 #define TH_ACK 0x10
 #define TH_URG 0x20
 #define TH_ECE 0x40
 #define TH_CWR 0x80
 #define TH_FLAGS (TH_FIN|TH_SYN|TH_RST|TH_PUSH|TH_ACK|TH_URG)

typedef struct tcp_hd{
  u_char sport;
  u_char dport;
  u_int  seq;
  u_int  ack;
  u_char header_len;
  u_char flags;
  u_short win_size;
  u_short checksum;
  u_short urg_ptr;

} tcp_hd;
tcp_hd* tcp;

// udp 头部
typedef struct udp_hd{
  u_short sport;
  u_short dport;
  u_short total_len;
  u_short checksum;
}udp_hd;
udp_hd* udp;



#endif
