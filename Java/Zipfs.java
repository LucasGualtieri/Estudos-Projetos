package Java;

import java.io.*;
import java.util.*;

// clear && javac Zipfs.java && java Zipfs.java

class Zipfs {

	static class Pair<K, V> {
		private K key;
		private V value;
	
		// Constructor
		public Pair(K key, V value) {
			this.key = key;
			this.value = value;
		}
	
		// Getter for key
		public K getKey() {
			return key;
		}
	
		// Setter for key
		public void setKey(K key) {
			this.key = key;
		}
	
		// Getter for value
		public V getValue() {
			return value;
		}
	
		// Setter for value
		public void setValue(V value) {
			this.value = value;
		}
	
		// Override equals() method
		@Override
		public boolean equals(Object o) {
			if (this == o) return true;
			if (o == null || getClass() != o.getClass()) return false;
	
			Pair<?, ?> pair = (Pair<?, ?>) o;
	
			if (key != null ? !key.equals(pair.key) : pair.key != null) return false;
			return value != null ? value.equals(pair.value) : pair.value == null;
		}
	
		// Override hashCode() method
		@Override
		public int hashCode() {
			int result = key != null ? key.hashCode() : 0;
			result = 31 * result + (value != null ? value.hashCode() : 0);
			return result;
		}
	
		// Override toString() method
		@Override
		public String toString() {
			return "{ '" + key + "', " + value + " }";
		}
	}

	static final String filePath = "Java/";

	public static void main(String[] args) throws IllegalArgumentException {

		clearScreen();

		String text = readFromFile(filePath + "texto.txt");

		// System.out.println(text);

		HashMap<Character, Integer> hash = new HashMap<>();

		for (char c : text.toCharArray()) {

			Integer value = hash.get(c);

			if (value != null) hash.put(c, ++value);

			else hash.put(c, 1);
		}

		List<Pair<Character, Integer>> list = new ArrayList<>(hash.size());

		for (Map.Entry<Character, Integer> entry : hash.entrySet()) {
            Pair<Character, Integer> pair = new Pair<>(entry.getKey(), entry.getValue());
            list.add(pair);
        }

		list.sort((x, y) -> {
			return -x.value.compareTo(y.value);
		});

		for (Pair<Character, Integer> p : list) {
			System.out.println(p);
		}
	}

	/**
	 * Clears the console screen by printing the ANSI escape code for clearing the screen.
	 */
	public static void clearScreen() {
		System.out.print("\033[H\033[2J");
		System.out.flush();
	}

	/**
	 * Reads the content of a file from the given file path.
	 *
	 * @param filePath The path to the file to be read.
	 * @return The content of the file as a string.
	 */
	static String readFromFile(String filePath) {

		StringBuilder content = new StringBuilder();

		try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
			String line;
			while ((line = reader.readLine()) != null) {
				content.append(line).append("\n");
			}
		}

		catch (IOException e) {
			// e.printStackTrace();
			System.out.println("Error: File not found.");
			System.exit(-1);
		}

		return content.toString();
	}
}