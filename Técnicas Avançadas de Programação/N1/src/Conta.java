public class Conta {
    private int idAgencia;
    private int idConta;
    private float saldo;
    private String titular;
    private String tipo;
    private static int quantidadeTotal;

    public Conta(int idAgencia, int idConta, float saldo, String titular) {
        this.idAgencia = idAgencia;
        this.idConta = idConta;
        this.saldo = saldo;
        this.titular = titular;
        Conta.quantidadeTotal++;
    }

    public void depositar(float quantia) {
        this.saldo += quantia;
    }

    public void sacar(float quantia) throws UnsupportedOperationException {
        if (this.saldo - quantia < 0)
            throw new UnsupportedOperationException("Operação cancelada. Saldo insuficiente.");
        else
            this.saldo -= quantia;
    }

    public void transferir(Conta recipiente, float quantia) {
        try {
            this.sacar(quantia);
            recipiente.depositar(quantia);
        } catch (UnsupportedOperationException e) {
            System.err.println(e.toString());
        }
    }

    public void consultar() {
        System.out.printf("Conta %d sob o nome de %s tem saldo de R$%.2f\n", this.idConta, this.titular, this.saldo);
    }

    public int getIdAgencia() {
        return idAgencia;
    }

    public void setIdAgencia(int idAgencia) {
        this.idAgencia = idAgencia;
    }

    public int getIdConta() {
        return idConta;
    }

    public void setIdConta(int idConta) {
        this.idConta = idConta;
    }

    public float getSaldo() {
        return saldo;
    }

    public void setSaldo(float saldo) {
        this.saldo = saldo;
    }

    public String getTitular() {
        return titular;
    }

    public void setTitular(String titular) {
        this.titular = titular;
    }

    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public static int getQuantidadeTotal() {
        return quantidadeTotal;
    }
}
