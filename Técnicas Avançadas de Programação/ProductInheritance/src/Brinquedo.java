public class Brinquedo extends Produto {
    public int faixaEtaria;

    protected Brinquedo(String nome, float preco, int faixaEtaria) {
        super(nome, preco);
        this.faixaEtaria = faixaEtaria;
    }

    @Override
    public void atualizar(int faixaEtaria) {
        this.faixaEtaria = faixaEtaria;
    }

    @Override
    public String toString() {
        return String.format("%s, faixaEtaria=%d", super.toString(), faixaEtaria);
    }
}
