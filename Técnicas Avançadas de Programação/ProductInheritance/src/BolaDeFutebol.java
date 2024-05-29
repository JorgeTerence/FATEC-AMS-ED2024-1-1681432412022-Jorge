public class BolaDeFutebol extends Bola {
    private int qtdGomos;

    public BolaDeFutebol(String nome, float tamanho, int qtdGomos) {
        super(nome, tamanho);
        this.qtdGomos = qtdGomos;
    }

    public int getQtdGomos() {
        return qtdGomos;
    }

    public void setQtdGomos(int qtdGomos) {
        this.qtdGomos = qtdGomos;
    }

    public String toString() {
        return super.toString() + "\nqtdGomos=" + qtdGomos;
    }
}
