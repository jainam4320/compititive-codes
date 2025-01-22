import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the isValid function below.
    static String isValid(String s) {
        int[] arr = new int[26];
        int[] a = new int[100001];
        int i,index = 0,max=0,k=0;
        for(i=0;i<s.length();i++)
        {
            arr[((int)s.charAt(i)) - 97]++;
        }
        for(i=0;i<26;i++)
        {
            if(arr[i] != 0)
            {
                a[arr[i]]++;
            }
        }
        for(i=0;i<10001;i++)
        {
            if( a[i] > max )
            {
                max = a[i];
                index = i;
            }
        }
        for(i=0;i<26;i++)
        {
            if(k > 1)
                return "NO";
            if( arr[i] != 0 && arr[i] != index )
            {
                k++;
                max = i;
            }
        }
        if( k == 0 )
            return "YES";
        if( (arr[max] - 1) == index || (arr[max] - 1) == 0 )
            return "YES";
        else
            return "NO";

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = scanner.nextLine();

        String result = isValid(s);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
