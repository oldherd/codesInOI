import java.util.*;

public class Main {
	static final int maxn = 12345678;
	static Scanner in = new Scanner(System.in);
	static long[] a = new long[maxn];
	static boolean[] ispri = new boolean[maxn];

	public static void main(String[] args) {
		int t = in.nextInt();
		seive();
		for(int i = 2; i <= 10000000; ++i) {
			a[i] += a[i - 1];
		}
		while((t--) > 0) {
			System.out.println(a[in.nextInt()]);
		}
	}
	static void seive() {
		Arrays.fill(ispri, true);
		for(int i = 2; i <= 10000000; ++i) {
			if(ispri[i]) {
				a[i] = i;
				for(int j = i; (long)j * i <= 10000000; ++j) {
					if(ispri[i * j]) {
						ispri[i * j] = false;
						a[i * j] = i;
					}
				}
			}
		}
	}
	
}
