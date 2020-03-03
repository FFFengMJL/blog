import java.util.*;
public class Main 
{

	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		String s = scanner.nextLine();
		String res = "\"";
		String [] ss = s.split("\"");
		for (String ss_r : ss) {
			String [] sss = ss_r.split(" ");
			for (String sss_r : sss) {
				res += StringBuffer(sss_r).reverse().toString + " ";
			}
		}
		System.out.println(res);
	}

}
