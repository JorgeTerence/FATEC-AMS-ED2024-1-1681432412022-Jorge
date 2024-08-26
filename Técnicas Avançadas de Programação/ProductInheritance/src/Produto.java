import java.util.*;

public abstract class Produto {
    public String nome;
    public float preco;
    public static List<Produto> repository = new ArrayList<>();

    protected Produto(String nome, float preco) {
        this.nome = nome;
        this.preco = preco;
    }

    public static Produto getInstance(String tipo, String nome, float preco) {
        Produto prod = switch (tipo.toLowerCase()) {
            case "brinquedo" -> new Brinquedo(nome, preco, 0);
            case "bola" -> new Bola(nome, preco, 0);
            case "bola-futebol" -> new BolaDeFutebol(nome, preco, 0, 0);
            default -> throw new IllegalArgumentException("Tipo não suportado");
        };

        repository.add(prod);
        return prod;
    }

    public void alterar(float preco) {
        this.preco = preco;
    }

    public static void excluir(int index) {
        if (repository.size() > index && index >= 0) {
            repository.set(index, null);
        } else {
            throw new IndexOutOfBoundsException("Índice de produto não encontrado: "  + index);
        }
    }

    public abstract void atualizar(int parameter);

    @Override
    public String toString() {
        return String.format("nome='%s'", nome);
    }
}
