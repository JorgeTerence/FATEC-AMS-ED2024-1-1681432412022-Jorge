public class Main {
    public static void main(String[] args) {
        Produto prod = new Produto("Shampoo");
        Brinquedo brinqs = new Brinquedo("Mr. Potato Head", 10);
        Bola bola = new Bola("Bola de tênis", 10);
        BolaDeFutebol bolao = new BolaDeFutebol("Jabulani", 10, 20);

        System.out.println(prod.toString() + "\n");
        System.out.println(brinqs.toString() + "\n");
        System.out.println(bola.toString() + "\n");
        System.out.println(bolao.toString() + "\n");
    }
}