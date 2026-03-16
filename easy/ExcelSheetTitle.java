class Solution {
    public String convertToTitle(int columnNumber) {
        StringBuilder ans = new StringBuilder();
        while(columnNumber > 0){
            int col = columnNumber % 26;
            if(col == 0){
                ans.append('Z');
                columnNumber --;
            }
            else
            ans.append((char)('A' + col - 1));
            columnNumber =  columnNumber / 26;
        }
        return ans.reverse().toString();
    }
}