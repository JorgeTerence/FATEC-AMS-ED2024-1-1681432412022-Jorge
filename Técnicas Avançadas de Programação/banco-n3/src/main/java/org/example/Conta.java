package org.example;

import java.security.InvalidParameterException;

public abstract class Conta {
    private int idAgencia;
    private int idConta;
    protected float saldo;
    private String titular;
    private String tipoConta;
    private static int quantidadeTotal;

    public Conta(int idAgencia, int idConta, float saldo, String titular) {
        this.idAgencia = idAgencia;
        this.idConta = idConta;
        this.saldo = saldo;
        this.titular = titular;
        Conta.quantidadeTotal++;
    }

    public abstract void depositar(float quantia);

    public void sacar(float quantia) throws UnsupportedOperationException, InvalidParameterException {
        if (quantia < 0)
            throw new InvalidParameterException("Sacando quantia negativa");
        if (this.saldo - quantia < 0)
            throw new UnsupportedOperationException("Saldo insuficiente");

        this.saldo -= quantia;
    }

    public void transferir(Conta recipiente, float quantia) {
        try {
            this.sacar(quantia);
            recipiente.depositar(quantia);
        } catch (Exception e) {
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

    public String getTitular() {
        return titular;
    }

    public void setTitular(String titular) {
        this.titular = titular;
    }

    public String getTipoConta() {
        return tipoConta;
    }

    public void setTipoConta(String tipoConta) {
        this.tipoConta = tipoConta;
    }

    public static int getQuantidadeTotal() {
        return quantidadeTotal;
    }
}
