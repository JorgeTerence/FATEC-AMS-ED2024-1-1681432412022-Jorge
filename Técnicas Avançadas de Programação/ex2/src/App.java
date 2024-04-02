public class App {
    public static void main(String[] args) throws Exception {
        Amigo amigo1 = new Amigo("João", 20, "1234-5678");
        System.out.println("Idade em meses: " + amigo1.idadeEmMeses());
        amigo1.aniversario();
        System.out.println("Nova idade: " + amigo1.getIdade());
    }
}
