class Robot {


    int x=0,y=0,n=0,m=0;
    String dir="East";


    public Robot(int width, int height) {
        n=width;
        m=height;
    }
    
    public void step(int num) {
         int cycle = 2 * (n + m - 2);
        num = num % cycle;

          if (num == 0 && x == 0 && y == 0) {
            dir = "South";
            return;
        }
        if(num==0)
            return;

        if(dir=="East"){
            // System.out.println("Dir "+dir+"X:"+x+"Y:"+y);
            if(x+num>=n){
                // int consumedDist=Math.abs(num-x)-1;
                int x1=x;
                 int consumedDist=n-1-x1; 
                 x=n-1;
                 dir="North";
                //   System.out.println("Dir2 "+dir+"X:"+x+"Y:"+y+"COnsumedDist"+consumedDist);
                 step(num-consumedDist);
            }  
            else
                x=x+num;
            
        }
        else if(dir=="North"){
            //   System.out.println("Dir "+dir+"X:"+x+"Y:"+y);
            if(y+num>=m){ //(5,2)
                int y1=y;
                int consumedDist=m-1-y1; 

                //  int consumedDist=Math.abs(num-m)-1; 
                 y=m-1;
                dir="West";
                //   System.out.println("Dir2 "+dir+"X:"+x+"Y:"+y+"COnsumedDist"+consumedDist);
                step(num-consumedDist);

            }else
                y=y+num;

        }
        else if(dir=="West"){
            //   System.out.println("Dir "+dir+"X:"+x+"Y:"+y+"Num:"+num);
            if(x-num<0){

                int x1=x;
                int consumedDist = x;   
                //  int consumedDist=num-x;
                //  int consumedDist=Math.abs(num-n)-1; 
                 x=0;
                 dir="South";
                //    System.out.println("Dir2 "+dir+"X:"+x+"Y:"+y);
                  step(num-consumedDist);
            }else{
                x=x-num;
            }
        }else if(dir=="South"){
            //   System.out.println("Dir "+dir+"X:"+x+"Y:"+y);
            if(y-num<0){
                int y1=y;
                // int consumedDist=m-1-y1; 
                  int consumedDist=y; 
                //  int consumedDist=num-y;
                // int consumedDist=Math.abs(num-y)-1; 
                 y=0;
                 dir="East";
                //    System.out.println("Dir2 "+dir+"X:"+x+"Y:"+y);
                   step(num-consumedDist);

            }else
                y=y-num;
        }
    }
    
    public int[] getPos() {
        int []arr ={x,y};
        return arr;
    }
    
    public String getDir() {
           
        return dir;
    }
}

/**
 * Your Robot object will be instantiated and called as such:
 * Robot obj = new Robot(width, height);
 * obj.step(num);
 * int[] param_2 = obj.getPos();
 * String param_3 = obj.getDir();
 */