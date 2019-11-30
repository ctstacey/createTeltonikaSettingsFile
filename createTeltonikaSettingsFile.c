#include <stdio.h>
#include <string.h>

#define MAX_FILE_LEN 10000
#define FILENAME "wireless"

int main(int argc, char** argv){

  if (argc < 3) {
    // program name *argv[0] does NOT include full file path
    fprintf(stdout, "%s%s%s", "Usage: ", argv[0], " <ssid> <pwd>");

    return 0;
  }

  char txt[MAX_FILE_LEN];
  memset(txt, '\0', MAX_FILE_LEN);

  strcat(txt,"\n"
             "config wifi-device 'radio0'\n"
             "\toption type 'mac80211'\n"
             "\toption hwmode '11ng'\n"
             "\toption path 'platform/ar933x_wmac'\n"
             "\tlist ht_capab 'LDPC'\n"
             "\tlist ht_capab 'SHORT-GI-20'\n"
             "\tlist ht_capab 'SHORT-GI-40'\n"
             "\tlist ht_capab 'TX-STBC'\n"
             "\tlist ht_capab 'RX-STBC1'\n"
             "\tlist ht_capab 'DSSS_CCK-40'\n"
             "\toption country 'AU'\n"
             "\toption disabled '0'\n"
             "\toption channel 'auto'\n"
             "\toption txpower '16'\n"
             "\toption htmode 'HT20'\n"
             "\n"
             "config wifi-iface\n"
             "\toption device 'radio0'\n"
             "\toption network 'lan'\n"
             "\toption mode 'ap'\n"
             "\toption isolate '0'\n"
             "\toption hotspotid 'hotspot1'\n"
             "\toption encryption 'psk2+tkip+ccmp'\n"
             "\toption key '");
  strcat(txt,argv[2]);
  strcat(txt,"'\n"
             "\toption user_enable '1'\n"
             "\toption ttl_increase '0'\n"
             "\toption ssid '");
  strcat(txt,argv[1]);
  strcat(txt,"'\n"
             "\n"
             "\0");

  // writing binary means \n are printed as LF (not CRLF on Windows)
  FILE * fh3 = fopen(FILENAME, "wb");

  // // writing text means \n are printed as CRLF on Windows and LF on Unix
  // FILE * fh3 = fopen(FILENAME, "w");

  fwrite(txt, sizeof(char), strlen(txt), fh3);

  fclose(fh3);

  fprintf(stderr, "%s", "Teltonika Settings File '" FILENAME "' Created");

  return 0;
}
