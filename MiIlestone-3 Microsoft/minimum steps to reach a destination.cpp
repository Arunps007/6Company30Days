int minSteps(int D){
        // code here
        int step =0 , pos=0  ; 
        while(pos < D || (pos-D)%2 !=0){
            step++ ; 
            pos += step ; 
        }
        return step ; 
    }