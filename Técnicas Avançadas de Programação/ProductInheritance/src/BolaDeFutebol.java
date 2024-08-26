public class BolaDeFutebol extends Bola {
    public int qtdGomos;

    public BolaDeFutebol(String nome, float preco, float tamanho, int qtdGomos) {
        super(nome, preco, tamanho);
        this.qtdGomos = qtdGomos;
    }

    @Override
    public void atualizar(int qtdGomos) {
        this.qtdGomos = qtdGomos;
    }

    @Override
    public String toString() {
        return String.format("%s, qtdGomos=%d", super.toString(), qtdGomos);
    }
}
