// This is a basic to understand how to use hashMap data structure in java //
import java.util.HashMap;
import java.util.Scanner;
class hash_Map{
    public static void main (String [] args){
        int n ;
        Scanner scan = new Scanner(System.in);
        n = scan.nextInt();
        HashMap<Integer,Integer>map = new HashMap<>();
        int array[] = new int[n];
        for (int i =0 ;i<n;i++){
            array[i] = scan.nextInt();
            int g = map.getOrDefault(array[i],0);
            map.put(array[i],g+1);
        }
        int q = scan.nextInt();
        System.out.println("The frequency of " + q + " is " + map.getOrDefault(q,0));
    }
}