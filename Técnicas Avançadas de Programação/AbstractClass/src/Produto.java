public abstract class Produto {
    private String nome;
    private float preco;

    public void incluir(String nome, float preco) {
        this.nome = nome;
        this.preco = preco;
    }

    public void alterar(float preco) {
        this.preco = preco;
    }

    public void excluir() {
        this.nome = null;
        this.preco = 0;
    }

    public abstract void atualizar(int value);

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public float getPreco() {
        return preco;
    }

    public void setPreco(float preco) {
        this.preco = preco;
    }

    @Override
    public String toString() {
        return String.format("nome: '%s', preço: %.2f", nome, preco);
    }
}
