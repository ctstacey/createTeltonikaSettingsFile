import sys

filename = 'wireless'

def main():

  if len(sys.argv) < 3:
    
    print("usage:", sys.argv[0], "<ssid> <pwd>")

    return

  txt = ("\n"
        + "config wifi-device 'radio0'\n"
        + "\toption type 'mac80211'\n"
        + "\toption hwmode '11ng'\n"
        + "\toption path 'platform/ar933x_wmac'\n"
        + "\tlist ht_capab 'LDPC'\n"
        + "\tlist ht_capab 'SHORT-GI-20'\n"
        + "\tlist ht_capab 'SHORT-GI-40'\n"
        + "\tlist ht_capab 'TX-STBC'\n"
        + "\tlist ht_capab 'RX-STBC1'\n"
        + "\tlist ht_capab 'DSSS_CCK-40'\n"
        + "\toption country 'AU'\n"
        + "\toption disabled '0'\n"
        + "\toption channel 'auto'\n"
        + "\toption txpower '16'\n"
        + "\toption htmode 'HT20'\n"
        + "\n"
        + "config wifi-iface\n"
        + "\toption device 'radio0'\n"
        + "\toption network 'lan'\n"
        + "\toption mode 'ap'\n"
        + "\toption isolate '0'\n"
        + "\toption hotspotid 'hotspot1'\n"
        + "\toption encryption 'psk2+tkip+ccmp'\n"
        +f"\toption key '{sys.argv[2]}'\n"
        + "\toption user_enable '1'\n"
        + "\toption ttl_increase '0'\n"
        +f"\toption ssid '{sys.argv[1]}'\n"
        + "\n"
        )

  # newline='' means \n are printed as LF (not CRLF on Windows)
  with open(filename, "w", newline='') as fd:
    print(txt, file=fd, end='')

  # # writing binary means \n are printed as LF (not CRLF on Windows)
  # with open(filename, "wb") as fd:
  # fd.write(bytes(txt, 'UTF-8'))

  print(f"Teltonika Settings File '{filename}' Created", file=sys.stderr)

if __name__=='__main__':
  main()
