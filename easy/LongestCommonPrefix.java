class Solution {
    public String longestCommonPrefix(String[] strs) {
       String commonprefix=strs[0];
       for(int i=1;i<strs.length;i++){
        String c=strs[i];
        StringBuilder temp=new StringBuilder();
        for(int j=0;j<Math.min(c.length(),commonprefix.length());j++){
            char c1=strs[i].charAt(j);
            char c2=commonprefix.charAt(j);
            if(c1!=c2)
              break;
              temp.append(c1);
        }
        commonprefix=temp.toString();
       }
       return commonprefix;
       //tc: o(n*m)
    }
}