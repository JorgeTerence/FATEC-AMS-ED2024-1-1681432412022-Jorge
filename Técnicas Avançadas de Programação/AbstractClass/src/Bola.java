public class Bola extends Produto {
    private int qtdGomos;

    @Override
    public void atualizar(int qtd) {
        this.qtdGomos = qtd;
    }

    public int getQtdGomos() {
        return qtdGomos;
    }

    public void setQtdGomos(int qtdGomos) {
        this.qtdGomos = qtdGomos;
    }

    @Override
    public String toString() {
        return String.format("%s, gomos: %d", super.toString(), qtdGomos);
    }
}
