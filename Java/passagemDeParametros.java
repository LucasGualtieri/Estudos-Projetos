package Java;

public class passagemDeParametros {
	public static void teste(int teste) {
		teste = 20;
		System.out.println(teste);
	}

	public static void main(String[] args) {
		int idade = 0;
		teste(idade);
		System.out.println(idade);
	}
}

// Não existe passagem por referencia AT ALL?????