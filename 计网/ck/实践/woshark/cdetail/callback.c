#include "head.h"
#include <netinet/in.h>
#include <pcap/pcap.h>
#include <stdio.h>
#include <sys/types.h>
#include <time.h>

// 各首部的长度
 u_int eth_len = sizeof(struct eth_hd);
 u_int ip_len = sizeof(struct ip_hd);
 u_int tcp_len = sizeof(struct tcp_hd);
 u_int udp_len = sizeof(struct udp_hd);
 

void ip_deal(u_char* arg,const struct pcap_pkthdr * packet_head,const u_char* packet_content);
void tcp_callback(u_char* arg,const struct pcap_pkthdr*  packet_head,const u_char* packet_content);
void udp_callback(u_char* arg,const struct pcap_pkthdr*  packet_head,const u_char* packet_content);
void arp_callback(u_char* arg,const struct pcap_pkthdr*  packet_head,const u_char* packet_content);
void icmp_callback(u_char* arg,const struct pcap_pkthdr*  packet_head,const u_char* packet_content);


void pcap_callback(unsigned char* arg,const struct pcap_pkthdr * packet_head,const unsigned char *packet_content)
{
   // 数据包ID
   static  int id = 1;
   printf("\n------------------Info----------------\n");
   printf("ID: %d\n",id++);

   //pcap_dump(arg,packet_head, packet_content);
   
   // 报文基础信息
   printf("Packet length : %d\n",packet_head->len);
   printf("Number of bytes : %d\n",packet_head->caplen);
   printf("Received time : %s\n",ctime((const time_t*)&packet_head->ts.tv_sec));
   
   
   // 以太网首部
   printf("-------------Data Link Layer----------------\n");

   eth = (eth_hd*) packet_content;
   printf("Src MAC : %02x-%02x-%02x-%02x-%02x-%02x\n",eth->src_mac[0],eth->src_mac[1],eth->src_mac[2],eth->src_mac[3],eth->src_mac[4],eth->src_mac[5]);
   printf("Dst MAC : %02x-%02x-%02x-%02x-%02x-%02x\n",eth->dst_mac[0],eth->dst_mac[1],eth->dst_mac[2],eth->dst_mac[3],eth->dst_mac[4],eth->dst_mac[5]);
   printf("ethernet type: %u\n",eth->eth_type);
   
   u_short protocol = ntohs(eth->eth_type);
   
   printf("-------------Network Layer------------------\n");
   switch (protocol)
   {
      case 0x0800:	
	  printf("IPV4 protocol\n");
          ip_deal(arg,packet_head,packet_content);
          break;
     
      case 0x86DD:          
          printf("IPV6 protocol\n");
          break; 

      case 0x0806:
	  printf("ARP protocol!\n");
	//  arp_callback(arg, pcap_pkt, packet);
	  break;

      case 0x8035:
	  printf("RARP protocol!\n");
	  break;

      case 0x880B:
	  printf("PPP protocol!\n");
          break;
      
      default:
	  printf("Other Network Layer protocol is used!\n");
	  break;	
   
   }

   
   /* 
     if(ntohs(eth->eth_type) == 0x0800 ) {
        
      printf("IPV4 : \n");
      ip = (ip_hd*)(packet_content+eth_len);
      printf("src ip: %d.%d.%d.%d\n",ip->srcIP[0],ip->srcIP[1],ip->srcIP[2],ip->srcIP[3]);
      printf("dst ip: %d.%d.%d.%d\n",ip->dstIP[0],ip->dstIP[1],ip->dstIP[2],ip->dstIP[3]);
      if (ip->protocol == 6) {
	 tcp = (tcp_hd*) (packet_content+eth_len+ip_len);
	 printf("TCP src port : %u\n",tcp->sport);
	 printf("TCP dst port : %u\n",tcp->dport);
      }
      else if (ip->protocol == 17) {
	 udp = (udp_hd*) (packet_content + eth_len + ip_len);
	 printf("UDP src port : %u\n",udp->sport);
	 printf("UDP dst port : %u\n",udp->dport);
      }
      else printf("other transport protocol is used\n");
   }
   else printf("IPV6 is used\n");
  */
    

   ip = (ip_hd*)(packet_content+eth_len);
   protocol = ip->protocol;
    if (0x01 == protocol)
    {
        printf("ICMP Protocol!\n");
	icmp_callback(arg,packet_head, packet_content);
    }
   printf("---------------Transtions Layer----------------\n");
   switch (protocol)
   {
	case 0x06:
             
	     printf("TCP protocol\n");
             tcp_callback(arg,packet_head,packet_content);
	     break;

	case 0x11:
	     printf("UDP protocol\n");
             udp_callback(arg,packet_head,packet_content);
	     break;
        
	default:
	     printf("Other protocol\n");
	     break;

   }
 /*
   // 报文编码
   printf("----------------------------------------------\n");
   for (int i = 0;i < packet_head->caplen;i ++) {
       printf(" %02x",packet_content[i]);
       if ((i+1)%16 == 0) printf("\n");
   }
   printf("\n----------------------------------------------\n");
*/


}

void ip_deal(u_char* arg,const struct pcap_pkthdr*  packet_head,const u_char* packet_content){
 
      ip = (ip_hd*)(packet_content+eth_len);
      printf("src ip: %d.%d.%d.%d\n",ip->srcIP[0],ip->srcIP[1],ip->srcIP[2],ip->srcIP[3]);
      printf("dst ip: %d.%d.%d.%d\n",ip->dstIP[0],ip->dstIP[1],ip->dstIP[2],ip->dstIP[3]);
     
}

void tcp_callback(u_char* arg,const struct pcap_pkthdr*  packet_head,const u_char* packet_content){
      
         tcp = (tcp_hd*) (packet_content+eth_len+ip_len);
	 printf("TCP src port : %u\n",tcp->sport);
	 printf("TCP dst port : %u\n",tcp->dport);
	 

	  switch (tcp->sport) {
	  case 80:
		printf("HTTP\n");
	 	break;
	  case 20:
	  case 21:
		printf("FTP\n");
		break;
	  case 53:
		printf("DNS\n");
	 }

}

void udp_callback(u_char* arg,const struct pcap_pkthdr*  packet_head,const u_char* packet_content){
         udp = (udp_hd*) (packet_content + eth_len + ip_len);
	 printf("UDP src port : %u\n",udp->sport);
	 printf("UDP dst port : %u\n",udp->dport);
         switch (udp->sport) {
	  case 80:
		printf("HTTP\n");
	 	break;
	  case 20:
	  case 21:
		printf("FTP\n");
		break;
	  case 53:
		printf("DNS\n");
	 }

   
}
 
void arp_callback(u_char* arg,const struct pcap_pkthdr*  packet_head,const u_char* packet_content)
{

}

void icmp_callback(u_char* arg,const struct pcap_pkthdr*  packet_head,const u_char* packet_content)
{

}
