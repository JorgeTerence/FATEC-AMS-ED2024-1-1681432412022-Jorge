package org.example;

public class Main {
    public static void main(String[] args) {
        ContaCorrente estudante = new ContaCorrente(1, 1, 1000, "Andrew");
        ContaPoupanca professor = new ContaPoupanca(2, 2, 10000, "Fletcher");

        estudante.consultar();
        professor.consultar();

        System.out.printf("Total de contas abertas: %d\n", Conta.getQuantidadeTotal());

        System.out.printf("Transferindo de %s para %s...\n", professor.getTitular(), estudante.getTitular());
        professor.transferir(estudante, 100);

        System.out.printf("Novo saldo de %s: R$%.2f\n", professor.getTitular(), professor.getSaldo());
        System.out.printf("Novo saldo de %s: R$%.2f\n", estudante.getTitular(), estudante.getSaldo());

        System.out.printf("Compra de R$1200,00 por %s...\n", estudante.getTitular());
        try {
            estudante.sacar(1200);
        } catch (UnsupportedOperationException e) {
            System.err.println(e.toString());
        }

        estudante.sacar(400);
        professor.sacar(900);

        estudante.consultar();
        professor.consultar();

        SeguroDeVida seguro = new SeguroDeVida();

        CalculadorImposto calc = new CalculadorImposto();

        calc.addColeta(estudante);
        calc.addColeta(seguro);

        System.out.printf("Imposto coletado: R$%.2f \n", calc.getTotal());
    }
}