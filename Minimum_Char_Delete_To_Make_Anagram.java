import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the makeAnagram function below.
    static int makeAnagram(String str1, String str2) {
        int count1[] = new int[26];  
        int count2[] = new int[26]; 
        for (int i = 0; i < str1.length() ; i++) 
            count1[str1.charAt(i) -'a']++; 
        for (int i = 0; i < str2.length() ; i++) 
            count2[str2.charAt(i) -'a']++; 
        int result = 0; 
        for (int i = 0; i < 26; i++) 
            result += Math.abs(count1[i] - count2[i]); 
        return result;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String a = scanner.nextLine();

        String b = scanner.nextLine();

        int res = makeAnagram(a, b);

        bufferedWriter.write(String.valueOf(res));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
