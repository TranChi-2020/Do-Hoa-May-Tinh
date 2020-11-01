//UDP_receiver
    SOCKET sock;
    struct sockaddr_in si_other;
    WSADATA wsa;
    char buf[512];
    int slen = sizeof(si_other);

void inticonn()
{
    WSAStartup(MAKEWORD(2,1),&wsa);
    //Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    //setup address structure
    memset((char *) &si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(8888);
    si_other.sin_addr.s_addr = inet_addr("127.0.0.1");
        //start communication
    connect(sock,(struct sockaddr *)&si_other,sizeof(struct sockaddr));
}
//
char* receiveit(int &len){
    memset(buf,'\0', 512);
    //server of udp must RECEIVE GREETINGS FIRST
    len = recv(sock, buf, 512,0);
    return buf;
}
void sendit(string data)
{
   int len = data.length();
   data[len]='\0';
    //int n = send(sock,req.c_str(),len,0);
    int n = send(sock, data.c_str(), len, 0);
    //cout<<"sent greetings:-"<<n<<endl;
}
//////
void endconn()
{
    closesocket(sock);
    WSACleanup();
}
/////////////////////////////////////////////




