class Solution { 
    
    private Boolean isPresent(String s1, String s2){
    int cnt=0;
    for(int i=0;i<s1.length();i++){
        if(s1.charAt(i)!=s2.charAt(i))
            cnt++;
        if(cnt>2)
            return false;
    }
    return true;
}



    public List<String> twoEditWords(String[] queries, String[] dictionary) {
        List <String> ans=new ArrayList<>();

        for(String query:queries){
            for(String word : dictionary){
                if(isPresent(query,word)==true){
                    ans.add(query);
                    break;
                }

            }
        }
        return ans;
    }
}