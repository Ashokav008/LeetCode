class Solution {
    public String decodeCiphertext(String str , int rows) {
        
        int i=0,n=(str.length())/rows,j=0,jgbl=0;
      
        StringBuilder ans=new StringBuilder();
       
        while(j<n){
            int strIdx=(i*n+j);
              ans.append(str.charAt(strIdx));
            //  System.out.println("i="+i+"j="+j+"idx="+strIdx+" "+   ans);
            i++;
            j++;

            if(i==rows){
                i=0;
                jgbl++;
                j=jgbl;
                
            }
        }
    
        return ans.toString().stripTrailing();

    }
}