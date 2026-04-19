class Solution {
    public String convert(String s, int n) {
        int i =  2*(n-1), j = 0, k = 0, z = 0;
        StringBuilder sb = new StringBuilder();

        int len = s.length();

        if(n==1){
            return s;
        }

        while(i>=0 && k <len){
            sb.append(s.charAt(k));
            z = k;
            while(z < len){
                if(z+i != z && z+i < len){
                    sb.append(s.charAt(z+i));
                }
                z += i;
                if(z+j != z && z+j < len){
                    sb.append(s.charAt(z+j));
                }
                z+= j;
            }
            k++;
            i -= 2;
            j += 2;
        }
        return sb.toString();
    }
}