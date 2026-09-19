class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int y = y1;
        for(int x = x1;x<=x2;x++){
            int r = ((y-yCenter)*(y-yCenter)+(x-xCenter)*(x-xCenter));
            if(r<=radius*radius){
                return true;
            }
        }
        y=y2;
        for(int x = x1;x<=x2;x++){
            int r = ((y-yCenter)*(y-yCenter)+(x-xCenter)*(x-xCenter));
            if(r<=radius*radius){
                return true;
            }
        }
        int x = x1;
        for(y=y1;y<=y2;y++){
            int r = ((y-yCenter)*(y-yCenter)+(x-xCenter)*(x-xCenter));
            if(r<=radius*radius){
                return true;
            }
    }
        x=x2;
        for(y=y1;y<=y2;y++){
            int r = ((y-yCenter)*(y-yCenter)+(x-xCenter)*(x-xCenter));
            if(r<=radius*radius){
                return true;
            }
    }
                 if(xCenter >= x1 && xCenter <= x2 && yCenter >= y1 && yCenter <= y2) return true;
    return false;
    }
};