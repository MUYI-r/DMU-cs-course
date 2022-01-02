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
 
static  int id = 1; 

void ip_deal(u_char* arg,const struct pcap_pkthdr * packet_head,const u_char* packet_content);
void tcp_callback(u_char* arg,const struct pcap_pkthdr*  packet_head,const u_char* packet_content);
void udp_callback(u_char* arg,const struct pcap_pkthdr*  packet_head,const u_char* packet_content);


void pcap_callback(unsigned char* arg,const struct pcap_pkthdr * packet_head,const unsigned char *packet_content)
{
   // 数据包ID
  // printf("\n------------------Info----------------\n");
   printf("\nID: %d  ",id++);

   //pcap_dump(arg,packet_head, packet_content);
   
   // 报文基础信息
  // printf("Packet length : %d\n",packet_head->len);
  // printf("Number of bytes : %d\n",packet_head->caplen);
   
   time_t rawtime;
   struct tm *info;
      
   time(&rawtime);
      /* 获取 GMT 时间 */
   info = gmtime(&rawtime );
  
   printf("time : %2d:%02d ", (info->tm_hour+8)%24, info->tm_min );
   
   
   // 以太网首部
   //printf("\n-------------------Data Link Layer ----------------\n");

   eth = (eth_hd*) packet_content;
//   printf("Src MAC : %02x-%02x-%02x-%02x-%02x-%02x\n",eth->src_mac[0],eth->src_mac[1],eth->src_mac[2],eth->src_mac[3],eth->src_mac[4],eth->src_mac[5]);
  // printf("Dst MAC : %02x-%02x-%02x-%02x-%02x-%02x\n",eth->dst_mac[0],eth->dst_mac[1],eth->dst_mac[2],eth->dst_mac[3],eth->dst_mac[4],eth->dst_mac[5]);
  // printf("\t ethernet type: %u  ",eth->eth_type);
   
   u_short protocol = ntohs(eth->eth_type);
   
  // printf("\n-----------------Network Layer------------------\n");
  /*
   switch (protocol)
   {
      case 0x0800:	
	  printf("IPV4  ");
    //      ip_deal(arg,packet_head,packet_content);
          break;
     
      case 0x86DD:          
          printf("IPV6  ");
          break; 
      
   
   }
  */
      ip = (ip_hd*)(packet_content+eth_len);
      printf("src ip: %d.%d.%d.%d  ",ip->srcIP[0],ip->srcIP[1],ip->srcIP[2],ip->srcIP[3]);
      printf("dst ip: %d.%d.%d.%d  ",ip->dstIP[0],ip->dstIP[1],ip->dstIP[2],ip->dstIP[3]);  
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
    
 //  printf("---------------Transtions Layer----------------\n");

   ip = (ip_hd*)(packet_content+eth_len);
   protocol = ip->protocol;
   switch (protocol)
   {
	case 0x06:
             
	     printf("TCP ");
    //         tcp_callback(arg,packet_head,packet_content);
	     break;

	case 0x11:
	     printf("UDP ");
      //       udp_callback(arg,packet_head,packet_content);
	     break;
        
	default:
	     printf("Others ");
	     break;

   }
   // 报文编码
 /*  printf("----------------------------------------------\n");
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

}

void udp_callback(u_char* arg,const struct pcap_pkthdr*  packet_head,const u_char* packet_content){
         udp = (udp_hd*) (packet_content + eth_len + ip_len);
	 printf("UDP src port : %u\n",udp->sport);
	 printf("UDP dst port : %u\n",udp->dport);
            
}
 
