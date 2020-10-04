#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
struct pos{
    ll x,y;
};

struct line{
    pos p;
    ll height;
    bool type;
};

bool cmp(line &a, line &b){
    if(a.p.x==b.p.x){
        return a.type ? true: false;
    }
    return a.p.x<b.p.x;
}

int n,m;
pos red, blue;
vector<line>lines;
void input(){
    cin>>n>>m;
    ll x,y;
    cin>>y;
    red = {0,y};
    for(int i=0;i<n;i++){
        int pre = y;
        cin>>x>>y;
        lines.push_back({{x,y},y-pre, true});
    }
    cin>>y;
    blue = {0,y};
    for(int i=0;i<m;i++){
        int pre = y;
        cin>>x>>y;
        lines.push_back({{x,y}, y-pre, false});
    }
    sort(lines.begin(), lines.end(), cmp);
}

int main(void){
    bool open = false;
    ll k=0,w=0;
    ll tmp = 0;
    input();
    for(line l:lines){
        //cout<<l.p.x<<" "<<l.p.y<<" "<<l.height<<" "<<l.type<<"\n";
        if(l.type){
            //red
            if(open){
                if(l.p.y>=blue.y){
                    k++;
                    tmp += (blue.y-red.y)*(l.p.x-max(blue.x,red.x));
                    w += tmp;
                    tmp = 0;
                    open = false;
                }
                else{
                    tmp += (blue.y-red.y)*(l.p.x-max(blue.x,red.x));
                }
            }
            else if(blue.y<=red.y && l.p.y<blue.y){
                open = true;
            }
            red = l.p;
        }
        else{
            //blue
            if(open){
                if(l.p.y<=red.y){
                    k++;
                    tmp+=(blue.y-red.y)*(l.p.x-max(blue.x,red.x));
                    w += tmp;
                    tmp = 0;
                    open = false;
                }
                else{
                    tmp+=(blue.y-red.y)*(l.p.x-max(blue.x,red.x));
                } 
            }
            else if(blue.y<=red.y && l.p.y>red.y){
                open = true;
            }
            blue = l.p;
        }
    }
    cout<<k<<" "<<w<<"\n";
    return 0;
}
