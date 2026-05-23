import java.util.Scanner;
class basic_hashing{
    public static void main (String [] args ){
        int n ;
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        int array[] = new int[n];
        int hash[]= new int[51];
        for (int i =0 ;i< n;i++){
            array[i] = scanner.nextInt();
            hash[array[i]] = hash[array[i]]+1;
        }
        System.out.println("Enter the query\n");
        int q = scanner.nextInt();
        System.out.println(hash[q]);
    }
}
