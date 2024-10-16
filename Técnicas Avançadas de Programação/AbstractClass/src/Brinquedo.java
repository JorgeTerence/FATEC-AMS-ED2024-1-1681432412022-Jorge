public class Brinquedo extends Produto {
    private int faixaEtaria;

    @Override
    public void atualizar(int idade) {
        this.faixaEtaria = idade;
    }

    public int getFaixaEtaria() {
        return faixaEtaria;
    }

    public void setFaixaEtaria(int faixaEtaria) {
        this.faixaEtaria = faixaEtaria;
    }

    @Override
    public String toString() {
        return String.format("%s, faixa etária: %d", super.toString(), faixaEtaria);
    }
}
