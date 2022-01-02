#include <pcap.h>
#include <pcap/pcap.h>
#include <stdio.h>
#include "callback.c"
#include <time.h>

extern int ID;

char filter_exp[256];

int main (int argc,char* argv[])
{
  
  char errBuf[PCAP_ERRBUF_SIZE];//储存错误信息
  char* dev;  // 设备名称
  pcap_if_t *alldevs; // 所有网络设备
  
  // device = pcap_lookupdev(errBuf);
  
  

  if (pcap_findalldevs(&alldevs,errBuf) == -1  ) 
  {
     printf("error: %s \n",errBuf);
     return 1;
  }
 
  dev = alldevs->name;//默认为第一个网络设备
  
  //if (device) 	  printf("success: device : %s\n", device);
  //else           { printf("error: %s\n",errBuf) ; exit(1); }
  
  
  pcap_t *  devopen = pcap_open_live(dev,65535,1,0,errBuf);

  if (! devopen ) {printf("error: pcap_open_live(): %s \n",errBuf ); return 1;}
  
  //struct pcap_pkthdr packet;

  //const u_char * pktStr = pcap_next(dev,&packet);

 /*
  if (! pktStr )
  {
	 printf("did not capture a packet \n");
	 exit(1); 
  } 

  printf("len: %d \n byte: %d \n",packet.len,packet.caplen);
*/
  
  if (argc > 1)
    {
        int i;
        for (i = 1; i < argc; i++)
        {
            strncat(filter_exp, argv[i], 100);
            strncat(filter_exp, " ", 100);
        }
    }
  
  struct bpf_program bpf_p;  
  
  bpf_u_int32 net;
  bpf_u_int32 mask;

  if (pcap_lookupnet(dev, &net, &mask, errBuf) == -1)
  {
     printf("Could not get netmask for device!\n");
     net = 0;
     mask = 0;
  }

  if (pcap_compile(devopen, &bpf_p, filter_exp, 0,net) == -1)
    {
        printf("Could not parse filter\n");
        return 1;
    }
  if(pcap_setfilter(devopen, &bpf_p) == -1)
    {
        printf("Could not install filter\n");
        return 1;
    }

  pcap_loop(devopen,-1,pcap_callback,NULL);
  
  pcap_close(devopen);


  return 0;
}
