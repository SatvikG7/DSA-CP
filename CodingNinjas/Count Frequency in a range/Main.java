import java.util.Scanner;

public class Main {
  public class Solution {
    public static int[] countFrequency(int n, int x, int[] nums) {
      // Write your code here.
      int[] intArray = new int[x];

      for (int i = 0; i < nums.length; i++) {
        intArray[nums[i] - 1] += 1;
      }

      int[] result = new int[n];
      for (int i = 0; i < n; i++) {
        result[i] = intArray[i];
      }

      return result;
    }
  }

  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    int x = s.nextInt();

    int[] nums = new int[n];
    for (int i = 0; i < n; i++) {
      nums[i] = s.nextInt();
    }
    s.close();
    int[] result = Solution.countFrequency(n, x, nums);
    for (int i = 0; i < x; i++) {
      System.out.print(result[i] + " ");
    }
  }
}