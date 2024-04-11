public class ContaCorrente extends Conta {
    public ContaCorrente(int idAgencia, int idConta, float saldo, String titular) {
        super(idAgencia, idConta, saldo, titular);
        this.setTipo("corrente");
    }
}
