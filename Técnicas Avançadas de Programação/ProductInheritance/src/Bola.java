public class Bola extends Produto {
    private float tamanho;

    public Bola(String nome, float tamanho) {
        super(nome);
        this.tamanho = tamanho;
    }

    public float getTamanho() {
        return tamanho;
    }

    public void setTamanho(float tamanho) {
        this.tamanho = tamanho;
    }
    public String toString() {
        return super.toString() + "\ntamanho=" + tamanho;
    }
}
