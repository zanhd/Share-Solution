import java.io.*;
import java.util.*;

class Res {
	static String max = "";
}

public class UserMainCode {

	public static String maximiser(String input1, int input2) {

		Res r = new Res();
		r.max = input1;
		help(input1.toCharArray(), input2, r);
		return r.max;
	}

	public static void help(char a[], int k, Res r) {
		if (k == 0) return;
		int n = a.length;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (a[j] > a[i]) {
					char tmp = a[i];
					a[i] = a[j];
					a[j] = tmp;

					String st = new String(a);

					if (r.max.compareTo(st) < 0) {
						r.max = st;
					}

					help(a, k - 1, r);

					tmp = a[i];
					a[i] = a[j];
					a[j] = tmp;
				}

			}
		}
	}

}
