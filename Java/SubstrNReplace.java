package Java;

// import TrabalhosPraticos.Lib;

// clear && javac SubstrNReplace.java && java SubstrNReplace.java
class SubstrNReplace {
	
	public static String substr(int start, int end, String str) {
		if (end > str.length()) {
			// throw new Exception("End index out of bounds");
		}
		
		String aux = "";
		for (int i = start; i < end; i++) {
			aux += str.charAt(i);
		}

		return aux;
	}

	public static boolean isEqual(String str1, String str2) {
		if (str1.length() != str2.length()) return false;

		for (int i = 0; i < str1.length(); i++) {
			if (str1.charAt(i) != str2.charAt(i)) return false;
		}

		return true;
	}

	public static String replaceAll(String baseStr, String newStr, String str) {
		String aux = "";
		int strLen = str.length();
		int baseStrLen = baseStr.length();
		for (int i = 0; i < strLen; i++) {
			if (i < strLen - baseStrLen && isEqual(baseStr, substr(i, i + baseStrLen, str))) {
				aux += newStr;
				i += baseStrLen - 1;
			} else {
				aux += str.charAt(i);
			}
		}
		return aux;
	}

	public static void main(String[] args) {
		// Deve retornar Lucas Gualtieri Firace
		String nome = replaceAll("()", " ", "Lucas()Gualtieri()Firace");
		System.out.printf("Nome: %s\n", nome);
	}
}