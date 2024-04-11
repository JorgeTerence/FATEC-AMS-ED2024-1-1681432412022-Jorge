public class ContaPoupanca extends Conta {
    public ContaPoupanca(int idAgencia, int idConta, float saldo, String titular) {
        super(idAgencia, idConta, saldo, titular);
        this.setTipo("poupança");
    }
}
