public class Amigo {
	String nome;
	int idade;
	String telefone;
	
	static int populacao = 0;
	
	public Amigo(String nome, int idade, String telefone) {
		this.nome = nome;
		this.idade = idade;
		this.telefone = telefone;
		Amigo.populacao++;
	}
	
	public void aniversario() {
		this.idade++;
	}
	
	int idadeEmMeses() {
		return this.idade * 12;
	}
}
