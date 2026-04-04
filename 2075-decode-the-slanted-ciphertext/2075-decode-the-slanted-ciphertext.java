class Solution {
    public String decodeCiphertext(String str , int rows) {
        
        int i=0,n=(str.length())/rows;
        int j=0,jgbl=1;
        StringBuilder ans=new StringBuilder();
       
        while(j<n){
            // if(i==rows && j==n-1)
            //     break;

            int strIdx=(i*n+j);
              ans.append(str.charAt(strIdx));
            //  System.out.println("i="+i+"j="+j+"idx="+strIdx+" "+   ans);
            i++;
            j++;

            if(i==rows){
                i=0;
                j=jgbl;
                jgbl++;
            }
            // if(jgbl==n+1)
            //     break;

        }
    
        return ans.toString().stripTrailing();

    }
}