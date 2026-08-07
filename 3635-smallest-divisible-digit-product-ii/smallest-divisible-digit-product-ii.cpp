class Solution {
    int e2[10],e3[10],e5[10],e7[10];   // prime exponents of each digit 1..9
    int A,B;
    vector<vector<int>> memo;
    int a,b,c,d_;                      // t = 2^a 3^b 5^c 7^d

    void initE(){
        auto s=[&](int d,int p,int q,int r,int w){e2[d]=p;e3[d]=q;e5[d]=r;e7[d]=w;};
        s(1,0,0,0,0);s(2,1,0,0,0);s(3,0,1,0,0);s(4,2,0,0,0);s(5,0,0,1,0);
        s(6,1,1,0,0);s(7,0,0,0,1);s(8,3,0,0,0);s(9,0,2,0,0);
    }
    int dp23(int x,int y){             // min #digits from {2,3,4,6,8,9} covering x twos, y threes
        if(x<=0&&y<=0) return 0;
        int &r=memo[x][y];
        if(r>=0) return r;
        int best=INT_MAX;
        for(int d:{2,3,4,6,8,9}){
            int nx=max(0,x-e2[d]), ny=max(0,y-e3[d]);
            if(nx+ny<x+y) best=min(best,1+dp23(nx,ny));
        }
        return r=best;
    }
    vector<int> build23(int x,int y){  // lex-min sorted multiset achieving dp23(x,y)
        vector<int> res; int budget=dp23(x,y);
        while(budget>0)
            for(int d:{2,3,4,6,8,9}){
                int nx=max(0,x-e2[d]), ny=max(0,y-e3[d]);
                if(nx+ny<x+y && dp23(nx,ny)==budget-1){ res.push_back(d); x=nx;y=ny;budget--; break; }
            }
        return res;
    }
    long long heavyCount(int n2,int n3,int n5,int n7){ return (long long)n5+n7+dp23(n2,n3); }
    vector<int> heavyList(int n2,int n3,int n5,int n7){
        vector<int> h=build23(n2,n3);
        for(int i=0;i<n5;i++) h.push_back(5);
        for(int i=0;i<n7;i++) h.push_back(7);
        sort(h.begin(),h.end());
        return h;
    }

public:
    string smallestNumber(string num, long long t) {
        initE();
        a=b=c=d_=0;
        while(t%2==0){a++;t/=2;} while(t%3==0){b++;t/=3;}
        while(t%5==0){c++;t/=5;} while(t%7==0){d_++;t/=7;}
        if(t>1) return "-1";           // t has a prime outside {2,3,5,7} -> impossible

        A=a;B=b; memo.assign(A+1,vector<int>(B+1,-1));
        int L=num.size();

        // Candidate 0: num itself, if zero-free and already divisible
        {
            int g2=0,g3=0,g5=0,g7=0; bool zeroFree=true;
            for(char ch:num){ int dd=ch-'0'; if(dd==0){zeroFree=false;break;}
                g2+=e2[dd];g3+=e3[dd];g5+=e5[dd];g7+=e7[dd]; }
            if(zeroFree && g2>=a&&g3>=b&&g5>=c&&g7>=d_) return num;
        }

        // Case A: smallest zero-free valid number of the SAME length, strictly > num
        int firstZero=L; for(int i=0;i<L;i++) if(num[i]=='0'){firstZero=i;break;}
        vector<int> p2(L+1,0),p3(L+1,0),p5(L+1,0),p7(L+1,0);   // prefix prime exponents
        for(int i=0;i<min(L,firstZero+1);i++){
            int dd=num[i]-'0'; int u=dd?dd:1;                  // dd==0 only at firstZero, contributes nothing
            p2[i+1]=p2[i]+e2[u]; p3[i+1]=p3[i]+e3[u];
            p5[i+1]=p5[i]+e5[u]; p7[i+1]=p7[i]+e7[u];
        }
        for(int i=min(L-1,firstZero); i>=0; --i){              // largest break position = smallest result
            int r=L-1-i;                                       // suffix slots
            for(int dd=(num[i]-'0')+1; dd<=9; ++dd){           // strictly larger digit here
                int n2=max(0,a-p2[i]-e2[dd]), n3=max(0,b-p3[i]-e3[dd]);
                int n5=max(0,c-p5[i]-e5[dd]), n7=max(0,d_-p7[i]-e7[dd]);
                if(heavyCount(n2,n3,n5,n7)<=r){
                    vector<int> h=heavyList(n2,n3,n5,n7);
                    string s=num.substr(0,i); s+=char('0'+dd);
                    s+=string(r-(int)h.size(),'1');
                    for(int x:h) s+=char('0'+x);
                    return s;
                }
            }
        }

        // Case B: smallest zero-free valid number LONGER than num
        long long k=heavyCount(a,b,c,d_);
        long long M=max((long long)L+1,k);
        vector<int> h=heavyList(a,b,c,d_);
        string s=string(M-(long long)h.size(),'1');
        for(int x:h) s+=char('0'+x);
        return s;
    }
};