package org.example;

import java.security.InvalidParameterException;

public class ContaCorrente extends Conta implements Tributavel {
    public ContaCorrente(int idAgencia, int idConta, float saldo, String titular) {
        super(idAgencia, idConta, saldo, titular);
        this.setTipoConta("corrente");
    }

    @Override
    public void depositar(float quantia) throws InvalidParameterException {
        if (quantia < 0)
            throw new InvalidParameterException("Depositando quantia negativa");

        this.saldo += quantia;
    }

    @Override
    public void sacar(float quantia) {
        super.sacar(quantia + 0.2f);
    }

    @Override
    public double getValorImposto() {
        return getSaldo() * 0.01;
    }
}
