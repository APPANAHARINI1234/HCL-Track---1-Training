import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;



class Result {

    /*
     * Complete the 'countAffordablePairs' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. INTEGER_ARRAY prices
     *  2. INTEGER budget
     */
    public static int merge(List<Integer>prices, int low, int mid, int high, int target){
        int i = low;
    int j = high;
    int count = 0;
    while (i <= mid && j >= mid + 1) {
        if (prices.get(i) + prices.get(j) <= target) {
            count += (j - mid); // all elements from mid+1 to j
            i++;
        } else {
            j--;
        }
    }
         int[]temp = new int[high - low + 1];
         i = low;
         j = mid + 1;
        int k = 0;
        while(i <= mid && j <= high){
            if(prices.get(i) < prices.get(j)){
                temp[k ++] = prices.get(i);
                i ++;
            }
            else{
                temp[k ++] = prices.get(j);
                j ++;
            }
        }
        while(i <= mid){
                temp[k ++] = prices.get(i);
                i ++;
        }
         while(j <= high){
                temp[k ++] = prices.get(j);
                j ++;
        }
        k = 0;
        while(k < temp.length){
            prices.set(low + k, temp[k]);
            k ++;
        }
        return count;
    }
   public static int mergesort(List<Integer>prices, int low, int high, int target){
    if(low == high)
      return 0;
    int mid = low + (high - low)/2;
    int count = mergesort(prices, low, mid, target);
    count += mergesort(prices, mid + 1, high, target);
    count += merge(prices, low, mid, high, target);
    return count;
   }
    public static int countAffordablePairs(List<Integer> prices, int budget) {
    // Write your code here
       if(prices.size() == 0)
         return 0;
      return mergesort(prices, 0, prices.size() - 1, budget);

    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int pricesCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> prices = IntStream.range(0, pricesCount).mapToObj(i -> {
            try {
                return bufferedReader.readLine().replaceAll("\\s+$", "");
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        })
            .map(String::trim)
            .map(Integer::parseInt)
            .collect(toList());

        int budget = Integer.parseInt(bufferedReader.readLine().trim());

        int result = Result.countAffordablePairs(prices, budget);

        System.out.println(result);

        bufferedReader.close();
    }
}
