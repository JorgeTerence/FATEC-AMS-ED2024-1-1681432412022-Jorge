public class Main {
    public static void main(String[] args) {
        Brinquedo batata = (Brinquedo) Produto.getInstance("brinquedo", "Mr. Potato Head", 60);
        batata.faixaEtaria = 8;

        Bola tenis = (Bola) Produto.getInstance("bola", "Bola de tênis", 30);
        tenis.tamanho = 10;

        BolaDeFutebol jabulani = (BolaDeFutebol) Produto.getInstance("bola-futebol", "Jabulani", 130);
        jabulani.tamanho = 30;
        jabulani.qtdGomos = 14;

        System.out.println(batata);
        System.out.println(tenis);
        System.out.println(jabulani);

        batata.alterar(70);
        System.out.println(batata);

        batata.atualizar(10);
        tenis.atualizar(8);
        jabulani.atualizar(16);

        System.out.println(batata);
        System.out.println(tenis);
        System.out.println(jabulani);

        for (Produto p : Produto.repository) {
            System.out.println(p);
        }

        Produto.excluir(0);
        for (Produto p : Produto.repository) {
            System.out.println(p);
        }

        try {
            Produto.excluir(10);
        } catch (IndexOutOfBoundsException e) {
            System.err.println(e.getMessage());
        }
    }
}