//UDP_sender
    SOCKET sock,Connect;
    struct sockaddr_in server, si_other;
    WSADATA wsa;
    int slen = sizeof(si_other);

void inticonn()
{
    WSAStartup(MAKEWORD(2,1),&wsa);
    //Create a socket
    sock = socket(AF_INET , SOCK_STREAM , 0 );
    Connect = socket(AF_INET, SOCK_STREAM, 0);
    cout<<"Socket Created. \n";
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );
    //Bind
    bind(sock ,(struct sockaddr *)&server , sizeof(server));
    cout<<"Bind Done. \n";
    listen(sock,1);
    cout<<"Listening...\n";

    int size=sizeof(server);
    for(;;)
        {
            if(Connect = accept(sock,(SOCKADDR*)&server,&size)){
                cout<<"Connection is reached!!!\n";
                break;
            }
        }

}
//
char* receiveit(int &len){
    char buf[512];
    //server of udp must RECEIVE GREETINGS FIRST
    int n = recv(Connect, buf, 512, 0);
    //buf[n]='0x0';
    len = n;
    //gotoxy(4,30);cout<<"n:"<<n<<endl;
    return buf;
}
void sendit(string data)
{
   int len = data.size();
    //int n = send(sock,req.c_str(),len,0);
    int n = send(Connect, data.c_str(), len, 0);
    //gotoxy(5,1);cout<<"sent:"<<n<<"bytes       ";

}
//////
void endconn()
{
    closesocket(sock);
    closesocket(Connect);
    WSACleanup();
}
/////////////////////////////////////////////




