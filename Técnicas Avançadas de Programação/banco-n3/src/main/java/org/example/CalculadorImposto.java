package org.example;

import java.util.ArrayList;
import java.util.List;

public class CalculadorImposto {
    private final List<Double> coleta = new ArrayList<>();

    public void addColeta(Tributavel ativo) {
        this.coleta.add(ativo.getValorImposto());
    }

    public double getTotal() {
        double total = 0;
        for (Double imposto: this.coleta) {
            total += imposto;
        }

        return total;
    }
}
