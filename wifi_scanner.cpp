#include <bits/stdc++.h>
using namespace std;
string x(string c){char b[999];string r;FILE*f=popen(c.c_str(),"r");while(fgets(b,999,f))r+=b;pclose(f);return r;}
void wifi_scaner(){
#ifdef _WIN32
    system("echo 65001>nul");
    cout<<x("netsh wlan show networks mode=Bssid");
#else
    cout<<x("nmcli dev wifi list || iwlist scan");
#endif
    cout<<"\nYour IP: "<<x("ip route get 1|grep src|awk '{print $7}' || ipconfig|findstr IPv4").substr(0,40);
    cout<<"\n\nDevices in local network:\n";
    string ip=x("ip route|grep default|awk '{print $3}'").substr(0,40),b=ip.substr(0,ip.rfind('.')+1);
    for(int i=1;i<255;i++)system(("ping -n1 -w200 "+b+to_string(i)+" >nul 2>&1 || ping -c1 -W1 "+b+to_string(i)+" >/dev/null 2>&1").c_str());
    cout<<x("arp -a || ip neigh");
}