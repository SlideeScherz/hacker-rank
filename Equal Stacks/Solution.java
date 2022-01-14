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
    
    public static int list_sum(List<Integer> list) {
        int sum = 0;
        for (int i: list) {
            sum += i;
        }
        return sum;
    }

    /*
     * Complete the 'equalStacks' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. INTEGER_ARRAY h1
     *  2. INTEGER_ARRAY h2
     *  3. INTEGER_ARRAY h3
     */

    public static int equalStacks(List<Integer> h1, List<Integer> h2, List<Integer> h3) {
        Stack<Integer> st1 = new Stack<Integer>();
        Stack<Integer> st2 = new Stack<Integer>();
        Stack<Integer> st3 = new Stack<Integer>();

        int st1TotalHeight = 0, st2TotalHeight = 0, st3TotalHeight = 0;

        // pushing consolidated height into the stack instead of individual cylinder
        // height
        for (int i = h1.size() - 1; i >= 0; i--) {
            st1TotalHeight += h1.get(i);
            st1.push(st1TotalHeight);
        }
        for (int i = h2.size() - 1; i >= 0; i--) {
            st2TotalHeight += h2.get(i);
            st2.push(st2TotalHeight);
        }
        for (int i = h3.size() - 1; i >= 0; i--) {
            st3TotalHeight += h3.get(i);
            st3.push(st3TotalHeight);
        }

        while (true) {

            // If any stack is empty
            if (st1.isEmpty() || st2.isEmpty() || st3.isEmpty())
                return 0;

            st1TotalHeight = st1.peek();
            st2TotalHeight = st2.peek();
            st3TotalHeight = st3.peek();

            // If sum of all three stack are equal.
            if (st1TotalHeight == st2TotalHeight && st2TotalHeight == st3TotalHeight)
                return st1TotalHeight;

            // Finding the stack with maximum sum and
            // removing its top element.
            if (st1TotalHeight >= st2TotalHeight && st1TotalHeight >= st3TotalHeight)
                st1.pop();
            else if (st2TotalHeight >= st1TotalHeight && st2TotalHeight >= st3TotalHeight)
                st2.pop();
            else if (st3TotalHeight >= st2TotalHeight && st3TotalHeight >= st1TotalHeight)
                st3.pop();
        }

    }
}
        
        

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int n1 = Integer.parseInt(firstMultipleInput[0]);

        int n2 = Integer.parseInt(firstMultipleInput[1]);

        int n3 = Integer.parseInt(firstMultipleInput[2]);

        List<Integer> h1 = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        List<Integer> h2 = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        List<Integer> h3 = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        int result = Result.equalStacks(h1, h2, h3);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
