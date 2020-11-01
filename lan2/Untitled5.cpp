struct ToaDo{
	int x,y;
};

void VietHoTen(){
	settextstyle(0,0,2);
	setcolor(YELLOW);
	outtextxy(getmaxx() - 500, getmaxy()-50, "Tran Van Nghia 18CNTT2");
}

void VeHinh(ToaDo A,ToaDo B, ToaDo C, ToaDo D, ToaDo E, ToaDo F, ToaDo G){
	line(A.x,A.y,B.x,B.y);
	line(B.x,B.y,C.x,C.y);
	line(C.x,C.y,D.x,D.y);
	line(D.x,D.y,A.x,A.y);
	line(D.x,D.y,G.x,G.y);
	line(G.x,G.y,F.x,F.y);
	line(F.x,F.y,C.x,C.y);
	line(F.x,F.y,E.x,E.y);
	line(B.x,B.y,E.x,E.y);
}

void ToMauBCFE(ToaDo B, ToaDo C, ToaDo F, ToaDo E){
	setcolor(BLUE);
	int x, minX, maxX;
	ToaDo M[] ={B,B,C,F,E};
	minX = M[1].x;
	maxX = M[1].x;
	for(int i = 2; i <=4;i++){
		if(M[i].x < minX) minX = M[i].x;
		if(M[i].x > maxX) maxX = M[i].x;
	}
	for(x = minX + 1; x <= maxX-1;x++){
		int m = 0, z[50]; // so giao diem
		for(int i = 1; i<=4;i++){
			int t = i + 1; if(i == 4) t = 1;
			int s = i - 1; if(i == 1) s = 4;
			if(x == M[i].x){
				if((x>min(M[s].x,M[t].x)) && (x < max(M[s].x,M[t].x))){
					m++;
					z[m] = M[i].y;
				}else{
					m++;
					z[m] = M[i].y;
					m++;
					z[m] = M[i].y;
				}	
			}else if((x > min(M[i].x, M[t].x)) &&(x < max(M[t].x, M[i].x))){
					m++;
					float r;
					r = (float)(M[t].y - M[i].y) / (M[t].x - M[i].x);
					z[m] = (int) (r * (x - M[i].x)+ M[i].y);
				}
			}
		for(int i = 1 ; i <m;i ++){
			for(int k = i+1; k < m;k++){
				if(z[i] > z[k]) swap(z[i],z[k]);
			}
		}
		for(int k = 1; k <= m - 1;k++){
			if(k%2!= 0)line(x,z[k],x,z[k+1]);
		}
	}
}
