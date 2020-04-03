#include<iostream>//Ö»ÓÐ50·Ö 
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
#define R register int 
int n,m,fx,fy;
bool qiang[4];
struct node{
    int x;
    int y;
    int fangx;
};
int map[51][51];
int dis[51][51];
bool vis[51][51][4];
queue<node> q;
int min(int a,int b){
    if(a>b)return b;
    return a;
}
void za(int x,int y){
    map[x][y]=1;
    map[x-1][y]=1;
    map[x][y-1]=1;
    map[x-1][y-1]=1;
}
int find(int x){
    if(x==1)return 0;
    else if(x==2)return 1;
    else if(x==-1)return 2;
    else return 3;
}
int zhuan(int f1,int f2){
    if(f1==-f2)return 2;
    else if(f1==f2)return 0;
    else return 1;
}
int bfs(node n1){
    dis[n1.x][n1.y]=0;
    vis[n1.x][n1.y][find(n1.fangx)]=true;
    q.push(n1);
    while(!q.empty()){
    	qiang[0]=false;
    	qiang[1]=false;
    	qiang[2]=false;
    	qiang[3]=false;
        node nn=q.front();q.pop();
        if(dis[fx][fy]!=-1)
            return dis[fx][fy];
        for(R j=1;j<=3;j++){
            int t;
            node tt;
            if(qiang[0]==false){
                    if(map[nn.x][nn.y-j]==0&&(nn.y-j>0)){
						if(vis[nn.x][nn.y-j][0]!=true){
                    		t=zhuan(nn.fangx,1);
                    		tt.x=nn.x;tt.y=nn.y-j;tt.fangx=1;
                    		
                    		if(dis[nn.x][nn.y-j]!=-1){
                    			if(dis[nn.x][nn.y-j]>dis[nn.x][nn.y]+1+t){
                    				q.push(tt);
                    				dis[nn.x][nn.y-j]=dis[nn.x][nn.y]+1+t;
								}
							}
                    		else if(dis[nn.x][nn.y-j]==-1){
                    			dis[nn.x][nn.y-j]=dis[nn.x][nn.y]+1+t;
								q.push(tt);
							}
                    		vis[nn.x][nn.y-j][0]=true;
               			}	
                    }
                    else{
                    	qiang[0]=true;
					}
                }
                if(qiang[1]==false){
                    if(map[nn.x+j][nn.y]==0&&(nn.x+j<n)){
                    	if(vis[nn.x+j][nn.y][1]!=true){
                       		t=zhuan(nn.fangx,2);
                    		tt.x=nn.x+j;tt.y=nn.y;tt.fangx=2;
                    		if(dis[nn.x+j][nn.y]!=-1){
                    			if(dis[nn.x+j][nn.y]>dis[nn.x][nn.y]+1+t){
                    				q.push(tt);
                    				dis[nn.x+j][nn.y]=dis[nn.x][nn.y]+1+t;
								}
                    		}
                    		else{
								q.push(tt);
                    		    dis[nn.x+j][nn.y]=dis[nn.x][nn.y]+1+t;
                    		}
                    		vis[nn.x+j][nn.y][1]=true;
                		}
                    }
                    else{
                    	qiang[1]=true;
					}
                }
                if(qiang[3]==false){
                    if(map[nn.x-j][nn.y]==0&&(nn.x-j>0)){
                    	if(vis[nn.x-j][nn.y][3]!=true){
                    		t=zhuan(nn.fangx,-2);
                    		tt.x=nn.x-j;tt.y=nn.y;tt.fangx=-2;
                    		
                    		if(dis[nn.x-j][nn.y]!=-1){
                    			if(dis[nn.x-j][nn.y]>dis[nn.x][nn.y]+1+t){
                    				dis[nn.x-j][nn.y]=dis[nn.x][nn.y]+1+t;
                    				q.push(tt);
								}
							}
                    		else{
                    			dis[nn.x-j][nn.y]=dis[nn.x][nn.y]+1+t;q.push(tt);
							}
                    		    
                    		vis[nn.x-j][nn.y][3]=true;
						}
                        
                    }
                    else{
                    	qiang[3]=true;
					}
                }
                if(qiang[2]==false){
                    if(map[nn.x][nn.y+j]==0&&(nn.y+j<m)){
                    	if(vis[nn.x][nn.y+j][2]!=true){
                    		t=zhuan(nn.fangx,-1);
                    		tt.x=nn.x;tt.y=nn.y+j;tt.fangx=-1;
                    		
                    		if(dis[nn.x][nn.y+j]!=-1){
                    			if(dis[nn.x][nn.y+j]>dis[nn.x][nn.y]+1+t){
                    				q.push(tt);
                    				dis[nn.x][nn.y+j]=dis[nn.x][nn.y]+1+t;
								}
							}
                    		else{
                    			dis[nn.x][nn.y+j]=dis[nn.x][nn.y]+1+t;q.push(tt);
							}
                    		vis[nn.x][nn.y+j][2]=true;
						}
                        
                    }
                    else{
                    	qiang[2]=true;
					}
                }
        }
    }
    return -1;
}
int main(){
    cin >> n >> m ;
    memset(dis,-1,sizeof(dis));
    memset(map,0,sizeof(map));
    memset(vis,false,sizeof(vis));
    int temp;
    for(R i=1;i<=n;i++){
        for(R j=1;j<=m;j++){
            cin >> temp;
            if(temp==1)
                za(i,j);
        }
    }
    node n1;
    cin >> n1.x >> n1.y >> fx >> fy;
    char ch;
    cin >> ch;
    if(ch=='N')n1.fangx=1;
    else if(ch=='E')n1.fangx=2;
    else if(ch=='W')n1.fangx=-2;
    else n1.fangx=-1;
    int res=bfs(n1);
    cout << res;
    return 0;
}
