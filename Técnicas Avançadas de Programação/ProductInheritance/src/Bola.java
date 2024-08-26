public class Bola extends Produto {
    public float tamanho;

    public Bola(String nome, float preco, float tamanho) {
        super(nome, preco);
        this.tamanho = tamanho;
    }


    @Override
    public void atualizar(int tamanho) {
        this.tamanho = tamanho;
    }

    @Override
    public String toString() {
        return String.format("%s, tamanho=%f", super.toString(), tamanho);
    }
}
