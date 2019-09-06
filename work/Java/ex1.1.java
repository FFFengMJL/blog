import java.util.Scanner;

public class test {
	public static void sort(char target[][]) 
	{
		for(int i = 0; i < 4; i++) {
			if(target[i][1] < target[i+1][1]) {
				char temp = target[i][0];
				target[i][0] = target[i+1][0];
				target[i+1][0] = temp;
				temp = target[i][1];
				target[i][1] = target[i+1][1];
				target[i+1][1] = temp;
			}
		}
	}
	
	public static void matrix(int a, int b)
	{
		char[][] target = {{'C', '0'}, {'D', '0'}, {'E', '0'}, {'G', '0'}, {'A', '0'}};
		for (int i = 0; i < a; i++) {
			Scanner scanner = new Scanner(System.in);
			String s = scanner.nextLine();
			for(int j = 0; j < b; j++) {
				switch(s.charAt(j)) {
				case 'C':target[0][1]++;break;
				case 'D':target[1][1]++;break;
				case 'E':target[2][1]++;break;
				case 'G':target[3][1]++;break;
				case 'A':target[4][1]++;break;
				}
			}
		}
		sort(target);
		for(int i = 0; i < 5; i++) {
			System.out.printf("%c %c ", target[i][0], target[i][1]);
		}
		System.out.print('\n');

	}
	

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		// TODO Auto-generated method stub
		while(true) {
			int a = scanner.nextInt();
			// System.out.println(a);
			int b = scanner.nextInt();
			// System.out.println(b);
			if(!(a == 0 && b == 0)) {
				matrix(a, b);
			}
			else {
				break;
			}
		}
	}

}
