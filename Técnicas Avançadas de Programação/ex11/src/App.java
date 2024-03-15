public class App {
    public static void main(String[] args) {
        Amigo cara = new Amigo("Breninho", 18, "+55 (11) 98765-4321");
        cara.aniversario();
        System.out.println("Idade: " + cara.idade + " anos");
        System.out.println("Idade: " + cara.idadeEmMeses() + " meses");

        for (int i = 0; i < 10; i++)
            new Amigo("", 0, "");

        System.out.println("População de amigos: " + Amigo.populacao);
    }
}
