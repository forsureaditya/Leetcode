class BusBooking {
    int row;
    unordered_map<string,int>mpp;
public:
    int cnt = 0;
    int ans = 0;
    BusBooking(int n) {
        this->row = n;
    }
    
    void toggle(string seat) {
        if(mpp.find(seat)==mpp.end()){
            cnt++;
            if(seat[0]=='B' || seat[0]=='C'){
                ans+=1;
                mpp[seat] = 1;
            }
            else if(seat[0]=='A' ){
             string str = 'B'+seat.substr(1);
              if(mpp.find(str)!=mpp.end()) {
                  ans+=3;
                  mpp[seat] = 3;
              }
                else {
                    ans+=1;
                    mpp[seat] = 1;
                }
            }
            else{
                string str = 'C'+seat.substr(1);
                if(mpp.find(str)!=mpp.end()){
                    mpp[seat] = 3;
                    ans+=3;
                }
                else{
                    ans+=1;
                 mpp[seat] = 1;
                }
            }
        }
        else {
            cnt--;
            ans-=mpp[seat];
            mpp.erase(seat);
        }
    }
    
    int getTotalTime() {
        return ans;
    }
    
    int getMinTime() {
        return cnt;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */