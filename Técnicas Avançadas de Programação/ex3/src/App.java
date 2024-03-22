public class App {
    public static void main(String[] args) throws Exception {
        Brinquedo presente = new Brinquedo(0, "Lego Death Star", "O melhor brinquedo de todos os tempo", 10000);
        presente.setId(101);
        presente.show();
        System.out.println(presente.getId());
    }
}
