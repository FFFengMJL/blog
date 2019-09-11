import java.util.Scanner;

public class Main {
	public static void sort(char [] tar_char, int [] tar_int) 
	{
		for (int j = 0; j < 4; j++) {
			for (int i = 0; i < 4 - i; i++) {
				if(tar_int[i] < tar_int[i + 1]) {
					char t_c = tar_char[i];
					tar_char[i] = tar_char[i + 1];
					tar_char[i + 1] = t_c;
					int t_i = tar_int[i];
					tar_int[i] = tar_int[i + 1];
					tar_int[i + 1] = t_i;
				}
			}
		}
	}
	
	public static void matrix(int a, int b, Scanner scanner)
	{
		// char[][] target = {{'A', 'C', 'D', 'E', 'G'}, {'0', '0', '0', '0', '0'}};
		// union [] target = {union('A', 0), union('C', 0), union('D', 0), union('E', 0), union('G', 0)};
		char [] tar_char = {'A', 'C', 'D', 'E', 'G'};
		int [] tar_int = {0, 0, 0, 0, 0};
		// Scanner scanner = new Scanner(System.in);
		for (int i = 0; i < a; i++) {
			// System.out.println(s);
			String s = scanner.nextLine();
			// System.out.print(s.length());
			for(int j = 0; j < b; j++) {
				switch(s.charAt(j)) {
				case 'A':tar_int[0]++;break;
				case 'C':tar_int[1]++;break;
				case 'D':tar_int[2]++;break;
				case 'E':tar_int[3]++;break;
				case 'G':tar_int[4]++;break;
				default: break;
				}
			}
		}
		scanner.close();
		sort(tar_char, tar_int);
		// String res = "";
		for(int i = 0; i < 5; i++) {
			// res = res + tar_char[i] + ' ' + tar_int[i] + ' ';
			System.out.printf("%c %d ", tar_char[i], tar_int[i]);
		}
		System.out.println();

	}
	

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		while(true) {
			int a = scanner.nextInt();
			int b = scanner.nextInt();
			if((a == 0) && (b == 0)) break;
			matrix(a, b, scanner);
		}
		scanner.close();
	}

}