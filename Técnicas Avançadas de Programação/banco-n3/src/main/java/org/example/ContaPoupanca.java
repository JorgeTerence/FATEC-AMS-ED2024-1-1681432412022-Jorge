package org.example;

import java.security.InvalidParameterException;

public class ContaPoupanca extends Conta {
    public ContaPoupanca(int idAgencia, int idConta, float saldo, String titular) {
        super(idAgencia, idConta, saldo, titular);
        this.setTipoConta("poupança");
    }

    @Override
    public void depositar(float quantia) throws InvalidParameterException {
        if (quantia < 0)
            throw new InvalidParameterException("Depositando quantia negativa");

        super.saldo += quantia;
    }
}

