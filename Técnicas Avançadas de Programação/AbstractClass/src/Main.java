public class Main {
    public static void main(String[] args) {
        Brinquedo toy = new Brinquedo();
        System.out.println(toy.toString());
        toy.incluir("Dobble", 55.99f);
        toy.atualizar(14);

        Bola ball = new Bola();
        System.out.println(ball.toString());
        ball.incluir("Jabulani", 140.00f);
        ball.atualizar(12);

        System.out.println(toy.toString());
        System.out.println(ball.toString());

        toy.alterar(toy.getPreco() * 0.75f);
        ball.alterar(ball.getPreco() * 0.75f);
        System.out.println(toy.toString());
        System.out.println(ball.toString());

        toy.excluir();
        ball.excluir();
        System.out.println(toy.toString());
        System.out.println(ball.toString());
    }
}